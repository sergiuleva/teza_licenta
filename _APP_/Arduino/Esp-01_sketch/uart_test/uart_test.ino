#include <ESP8266WiFi.h>

#define UART_BAUD_RATE 9600
#define LED_BUILTIN 0 // GPIO2 is the built-in LED on ESP-01

void setup() {
  //Serial.begin(UART_BAUD_RATE);
  pinMode(LED_BUILTIN, OUTPUT);
  
}
void loop() {
  /*if (Serial.available() > 0) {
    String receivedString = Serial.readStringUntil('\n');
    receivedString.trim();

    if (receivedString == "toggle") {
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN)); // Toggle the LED
      //Serial.print("OK");
    }
  }*/
  digitalWrite(LED_BUILTIN, 1);
  delay(500);
  digitalWrite(LED_BUILTIN, 0);
}
