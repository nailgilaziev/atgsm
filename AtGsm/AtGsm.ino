#include "Arduino.h"
#include "SoftwareSerialEcho.hpp"
#include "SerialRouter.hpp"



//#include <SoftwareSerial.h>


#define WARNING_NOT_STARTED_YET 2

SoftwareSerial gsmSerial(3, 2); // RX, TX

SerialRouter router(&gsmSerial);

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
    gsmSerial.begin(9600);
    
    Serial.println("------Program started------");
    
}

//0 - while reading
//1 - completed results
//1+ - error codes
byte executionStatusCode = WARNING_NOT_STARTED_YET;

void checkExecStatus(){
    if (executionStatusCode < 2) return;
    static unsigned long lastReportTime = 1;
    if (millis() - lastReportTime>5000) {
        lastReportTime = millis();
        for (int i = 0; i<executionStatusCode; i++) {
            digitalWrite(LED_BUILTIN, HIGH);
            delay(100);
            digitalWrite(LED_BUILTIN, LOW);
            delay(200);
        }
    }
}

void loop()
{
    checkExecStatus();
    if (gsmSerial.available())
        executionStatusCode = router.readInput();
    if (Serial.available())
        while (Serial.available()) {
            gsmSerial.write(Serial.read());
        }
    //delay(500);
    
}
