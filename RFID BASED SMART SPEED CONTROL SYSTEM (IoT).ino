#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 5
#define RST_PIN 22

MFRC522 rfid(SS_PIN, RST_PIN);

// Motor pins
#define IN1 26
#define IN2 27
#define IN3 32
#define IN4 33
#define ENA 14
#define ENB 12

// Speed values
int normalSpeed = 200;
int slowSpeed = 120;

void setup() {
  Serial.begin(115200);
  SPI.begin();
  rfid.PCD_Init();

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.println("System Ready");
}

void loop() {

  moveForward(normalSpeed);  // default movement

  if (!rfid.PICC_IsNewCardPresent())
    return;

  if (!rfid.PICC_ReadCardSerial())
    return;

  String tagID = "";

  for (byte i = 0; i < rfid.uid.size; i++) {
    tagID += String(rfid.uid.uidByte[i], HEX);
  }

  Serial.println(tagID);

  //  CHANGE THESE UID VALUES
  if (tagID == "a37f9b21") {
    Serial.println("School Zone - Slow Speed");
    moveForward(slowSpeed);
    delay(5000);
  }
  else if (tagID == "934c8a11") {
    Serial.println("Hospital Zone - Medium Speed");
    moveForward(150);
    delay(5000);
  }
  else {
    Serial.println("Normal Zone");
    moveForward(normalSpeed);
  }
}

//  Movement Functions

void moveForward(int speedVal) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
