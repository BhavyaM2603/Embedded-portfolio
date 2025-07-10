#include <SPI.h>
#include <LoRa.h>
#include <math.h>

#define ss 5
#define rst 14
#define dio0 2

const int totalPackets = 50;
const float txPower = 20.0; // Transmitter Power in dBm (modify according to your setup)

float rssiValues[totalPackets];
int packetCount = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Receiver");

  LoRa.setPins(ss, rst, dio0);
  while (!LoRa.begin(433E6)) {
    Serial.println("LoRa initialization failed. Retrying...");
    delay(500);
  }
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initialized!");

  // Clear buffer
  while (LoRa.parsePacket()) {}
}

void loop() {
  int packetSize = LoRa.parsePacket();

  if (packetSize > 0 && packetCount < totalPackets) {
    String LoRaData = LoRa.readString();
    float rssi = LoRa.packetRssi();

    Serial.print("Data: ");
    Serial.print(LoRaData);
    Serial.print(" - RSSI: ");
    Serial.println(rssi);

    rssiValues[packetCount] = rssi;
    packetCount++;
  }

  if (packetCount == totalPackets) {
    calculateMeanMedianVarianceAndAttenuation();
    packetCount = 0;  // reset for next batch
    Serial.println("\n[READY FOR NEXT BATCH]\n");

    while (LoRa.parsePacket()) {}  // flush buffer
  }
}

// Function to calculate Mean, Median, Variance, and Estimated Attenuation
void calculateMeanMedianVarianceAndAttenuation() {
  float sum = 0, mean, variance = 0;

  for (int i = 0; i < totalPackets; i++) {
    sum += rssiValues[i];
  }
  mean = sum / totalPackets;

  for (int i = 0; i < totalPackets; i++) {
    variance += pow(rssiValues[i] - mean, 2);
  }
  variance /= totalPackets;

  float sorted[totalPackets];
  memcpy(sorted, rssiValues, sizeof(rssiValues));
  for (int i = 0; i < totalPackets - 1; i++) {
    for (int j = i + 1; j < totalPackets; j++) {
      if (sorted[i] > sorted[j]) {
        float temp = sorted[i];
        sorted[i] = sorted[j];
        sorted[j] = temp;
      }
    }
  }

  float median = (totalPackets % 2 == 0) ?
                 (sorted[totalPackets / 2 - 1] + sorted[totalPackets / 2]) / 2
                 : sorted[totalPackets / 2];

  // Calculate Estimated Attenuation
  float estimatedAttenuation = txPower - mean;

  Serial.println("\n====== RSSI Analysis ======");
  Serial.print("Packets Processed: ");
  Serial.println(totalPackets);
  Serial.print("Mean RSSI (dBm): ");
  Serial.println(mean);
  Serial.print("Median RSSI (dBm): ");
  Serial.println(median);
  Serial.print("RSSI Variance: ");
  Serial.println(variance);
  Serial.print("Estimated Attenuation (dB): ");
  Serial.println(estimatedAttenuation);
  Serial.println("==========================");
}