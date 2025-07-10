#include <SPI.h>
#include <LoRa.h>

#define ss 5
#define rst 14
#define dio0 2

int counter = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Sender");

  LoRa.setPins(ss, rst, dio0);

  while (!LoRa.begin(433E6)) {
    Serial.println("LoRa initialization failed. Retrying...");
    delay(500);
  }

  LoRa.setSyncWord(0xF3);
  LoRa.setTxPower(20); 
  LoRa.setSpreadingFactor(7);

  Serial.println("LoRa Sender Initialized!");
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  LoRa.beginPacket();
  LoRa.print("Packet ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;
  delay(1000); // 1 second between packets
}