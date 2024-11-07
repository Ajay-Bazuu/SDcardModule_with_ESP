/*Pin Connections
HW-125 SD Card Module	ESP32 GPIO Pin
VCC	3.3V (Power)
GND	GND (Ground)
MISO (Master In Slave Out)	GPIO 19 (SPI MISO)
MOSI (Master Out Slave In)	GPIO 23 (SPI MOSI)
SCK (Clock)	GPIO 18 (SPI CLK)
CS (Chip Select)	GPIO 5 (or any available GPIO pin, as specified in the code)*/

#include <SPI.h>
#include <SD.h>

#define SD_CS_PIN 5  // Adjust this to match your CS pin

File myFile;

void setup() {
  Serial.begin(115200);
  
  // Attempt to initialize the SD card
  Serial.println("Initializing SD card...");
  while (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD card initialization failed. Retrying...");
    delay(1000);  // Retry every second
  }
  Serial.println("SD card initialized successfully.");
}

void loop() {
  // Continuously search for the 'piano.wav' file
  if (SD.exists("/piano.wav")) {
    Serial.println("File 'piano.wav' found!");
  } else {
    Serial.println("File 'piano.wav' not found.");
  }
  delay(2000);  // Adding a small delay to reduce the frequency of checks and avoid flooding the serial output
}
