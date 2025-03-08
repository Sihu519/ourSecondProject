#include "HUSKYLENS.h"
#include "Wire.h"

HUSKYLENS huskylens;

void setup() {
    Serial.begin(115200); // 시리얼 모니터 속도 조정
    Wire.begin();       // I2C 통신 시작

    if (!huskylens.begin(Wire)) {
        Serial.println("HuskyLens 초기화 실패!");
        while (1);
    }
    Serial.println("HuskyLens 연결 성공!");
}

void loop() {
    if (huskylens.request()) {
        while (huskylens.available()) {
            HUSKYLENSResult result = huskylens.read();
            
            Serial.print("Object ID: ");
            Serial.println(result.ID);

            printLabel(result.ID);
        }
    }
    delay(200);
}

void printLabel(int id) {
    switch (id) {
        case 1: Serial.println("→ Apple"); break;
        case 2: Serial.println("→ Banana"); break;
        case 3: Serial.println("→ Car"); break;
        case 4: Serial.println("→ Person"); break;
        default: Serial.println("→ Unknown Object"); break;
    }
}