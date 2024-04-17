#ifndef FINGERPRINTMANAGER_H
#define FINGERPRINTMANAGER_H

#include <Adafruit_Fingerprint.h>

extern Adafruit_Fingerprint finger; // Declare external reference to fingerprint object
extern uint8_t id;
uint8_t getFingerprintEnroll(uint8_t id);
uint8_t getFingerprintID();
uint8_t countStoredFingerprints();
#endif
