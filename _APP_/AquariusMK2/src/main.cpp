/*
  Sketch to generate the setup() calibration values, these are reported
  to the Serial Monitor.

  The sketch has been tested on the ESP8266 and screen with XPT2046 driver.
*/
#include "FingerprintManager.h"
#include <SPI.h>
#include <TFT_eSPI.h>      // Hardware-specific library
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
//#include <XPT2046_Touchscreen.h>

#define BUTTON_HEIGHT 60
#define BUTTON_WIDTH 100
#define BUTTON_GAP 20

// Button areas
#define BUTTON1_X 20
#define BUTTON1_Y 40
#define BUTTON2_X 20
#define BUTTON2_Y (BUTTON1_Y + BUTTON_HEIGHT + BUTTON_GAP)
#define BUTTON3_X 20
#define BUTTON3_Y (BUTTON2_Y + BUTTON_HEIGHT + BUTTON_GAP)

struct TouchPoint {
  uint16_t x;
  uint16_t y;
  bool valid; // Indicates if the touch coordinates are valid
};

#define mySerial Serial2

/*===Water Flow Part===*/
#define WATER_FLOW_SENSOR_PIN 34 // Example pin
volatile int flowPulseCount = 0; // Pulse count from the sensor
// Constants for flow rate calculation
float totalWater = 0;
float waterFlow = 0;
const float calibrationFactor = 4.5; // Calibration factor for the sensor
const int sampleTime = 1000; // Sample time in milliseconds
/*===Prototype===*/
void waterFlowTask(void *pvParameters);
void fingerprintTask(void *pvParameters);
void touchTask(void *pvParameters);
bool isTouchWithinArea(TouchPoint p, int x, int y, int width, int height);
void drawMenu();
TouchPoint getTouchCoordinates();
uint8_t readnumber(void);


uint8_t id = 0;
uint8_t action;

TFT_eSPI tft = TFT_eSPI(); // Invoke custom library
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup() {
  Serial.begin(9600);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
   // Set the data rate for the sensor serial port
  finger.begin(57600);

  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }
  Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
  Serial.print(F("Sys ID: 0x")); Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacity: ")); Serial.println(finger.capacity);
  Serial.print(F("Security level: ")); Serial.println(finger.security_level);
  Serial.print(F("Device address: ")); Serial.println(finger.device_addr, HEX);
  Serial.print(F("Packet len: ")); Serial.println(finger.packet_len);
  Serial.print(F("Baud rate: ")); Serial.println(finger.baud_rate);
  Serial.print("there are fingers stored"); Serial.println(countStoredFingerprints());

  id = countStoredFingerprints();
  
  /*===TFT init part===*/
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.println("AquariusMK2");
  //calibration
  // Use this calibration code in setup():
  uint16_t calData[5] = { 417, 3384, 359, 3388, 3 };
  tft.setTouch(calData);

  /*===FreeRTOS Tasks===*/
  xTaskCreatePinnedToCore(
    touchTask,   /* Task function */
    "Touch Task", /* Name of task */
    2048,       /* Stack size of task */
    NULL,        /* Parameter of the task */
    1,           /* Priority of the task */
    NULL,        /* Task handle to keep track of created task */
    0);          /* Pin task to core 0 */ 

  xTaskCreatePinnedToCore(
    fingerprintTask,   
    "Fingerprint Task", 
    2048,       
    NULL,        
    1,           
    NULL,        
    1);          /* Pin task to core 1 */ 

    xTaskCreatePinnedToCore(
    waterFlowTask,     /* Task function */
    "Water Flow Task", /* Name of task */
    2048,              /* Stack size of task */
    NULL,              /* Parameter of the task */
    1,                 /* Priority of the task */
    NULL,              /* Task handle */
    0);                /* Core where the task should run */
}

void loop() {
  // Empty loop since tasks are running
}

void IRAM_ATTR flowPulseCounter() {
  flowPulseCount++;
}

void waterFlowTask(void *pvParameters) {
  pinMode(WATER_FLOW_SENSOR_PIN, INPUT_PULLUP); // Set the sensor pin as input
  attachInterrupt(digitalPinToInterrupt(WATER_FLOW_SENSOR_PIN), flowPulseCounter, RISING); // Attach the interrupt

  while (1) {
    int count = flowPulseCount; // Get the current pulse count
    

    float flowRate = (count / calibrationFactor) * (1000.0 / sampleTime); // Calculate the flow rate in L/min
    float volume = flowRate * (sampleTime / 60000.0); // Calculate the volume in liters
    totalWater += volume;
    waterFlow  = flowRate;
    Serial.print("Flow rate: ");
    Serial.print(flowRate);
    Serial.println(" L/min");

    Serial.print("Volume: ");
    Serial.print(volume);
    Serial.println(" L");
    flowPulseCount = 0; // Reset the pulse count

    vTaskDelay(sampleTime / portTICK_PERIOD_MS); // Wait for the next sample
  }
}

void touchTask(void *pvParameters) {
  drawMenu(); // Draw the initial menu

  while (1) {
    TouchPoint touchPoint = getTouchCoordinates();
    if (touchPoint.valid) {
      if (isTouchWithinArea(touchPoint, BUTTON1_X, BUTTON1_Y, BUTTON_WIDTH, BUTTON_HEIGHT)) {
        // Enroll action
        action = 1;
        Serial.println("Enroll button pressed");
      } else if (isTouchWithinArea(touchPoint, BUTTON2_X, BUTTON2_Y, BUTTON_WIDTH, BUTTON_HEIGHT)) {
        // Verify action
        action = 2;
        Serial.println("Verify button pressed");
      } else if (isTouchWithinArea(touchPoint, BUTTON3_X, BUTTON3_Y, BUTTON_WIDTH, BUTTON_HEIGHT)) {
        // Delete action
        action = 3;
        Serial.println("Delete button pressed");
      }
      else{
        action = -1;
      }
    }
    if (waterFlow != 0)
    {
      tft.fillRect(160,160,160,140,ILI9341_BLACK);
    }
    tft.setCursor(120, 60);
    tft.print("L/min: ");
    tft.print(waterFlow);
    tft.setCursor(120, 80);
    tft.print("Total: ");
    tft.print(totalWater);
    
    
    delay(20); // Adjust delay as needed
  }
}


void fingerprintTask(void *pvParameters) {
  while (1) {
      switch (action) {
      case 1:
        Serial.println("Ready to enroll a fingerprint!");
        id++;
        if (id == 0) {
            return;
        }
        Serial.print("Enrolling ID #");
        Serial.println(id);

        // Call the function from the separate file
        while (!getFingerprintEnroll(id));
        action = -1;
        break;
      case 2:
          Serial.println("Put your finger");
          id = 0;
          while (!(id = getFingerprintID()));
          Serial.println(id);
          action = -1;
          break;
      case 3:
          if (finger.emptyDatabase() == FINGERPRINT_OK) {
            Serial.println("Successfully cleared all fingerprints from sensor!");
          } else {
            Serial.println("Failed to clear fingerprints from sensor.");
          }
          action = -1;
          break;
      default:
          //Serial.println("Invalid action selected");
          break;
    }
    delay(100); // Adjust delay as needed
  }
}

uint8_t readnumber(void) {
  uint8_t num = 0;

  while (num == 0) {
    while (!Serial.available());
    num = Serial.parseInt();
  }
  return num;
}

TouchPoint getTouchCoordinates() {
  TouchPoint touchPoint;
  uint16_t z = 600U; // Variable to hold the pressure value
  touchPoint.valid = tft.getTouch(&touchPoint.x, &touchPoint.y, z);
  return touchPoint;
}


void drawMenu() {
  // Draw the menu buttons
  tft.fillRect(BUTTON1_X, BUTTON1_Y, BUTTON_WIDTH, BUTTON_HEIGHT, ILI9341_BLUE);
  tft.fillRect(BUTTON2_X, BUTTON2_Y, BUTTON_WIDTH, BUTTON_HEIGHT, ILI9341_GREEN);
  tft.fillRect(BUTTON3_X, BUTTON3_Y, BUTTON_WIDTH, BUTTON_HEIGHT, ILI9341_RED);

  // Add text labels for each button
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setCursor(BUTTON1_X + 10, BUTTON1_Y + 20);
  tft.print("Enroll");
  tft.setCursor(BUTTON2_X + 10, BUTTON2_Y + 20);
  tft.print("Verify");
  tft.setCursor(BUTTON3_X + 10, BUTTON3_Y + 20);
  tft.print("Delete");
  
  

}

bool isTouchWithinArea(TouchPoint p, int x, int y, int width, int height) {
  
  return (p.x >= x && p.x <= x + width && p.y >= y && p.y <= y + height);
}





