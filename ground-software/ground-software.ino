// Phi Telemetry - LoRa RFM95x_RX

#include <SPI.h>
#include <RH_RF95.h>
#include <ArduinoJson.h>
#include <FastLED.h>

CRGB leds[1];

#define LED 2

#define RFM95_CS 15
#define RFM95_RST 16
#define RFM95_INT 5
#define RF95_FREQ 915.0

// Singleton instance of the radio driver
RH_RF95 rf95(RFM95_CS, RFM95_INT);

void setup() {
  // Setup RGB LED
  FastLED.addLeds<NEOPIXEL, 2>(leds, 1);
  showcolor("white");

  // Declare pins
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, HIGH);

  // Initialize Serial
  Serial.begin(9600);
  delay(100);
  Serial.println("Phi telemetry Ground Station starting...");

  // Check radio to confirm initialized
  digitalWrite(RFM95_RST, LOW);
  delay(10);
  digitalWrite(RFM95_RST, HIGH);
  delay(10);
  while (!rf95.init()) {
    Serial.println("LoRa radio init failed");
    while (1);
  }
  Serial.println("LoRa radio init OK!");
  if (!rf95.setFrequency(RF95_FREQ)) {
    Serial.println("setFrequency failed");
    while (1);
  }
  Serial.print("Set Freq to: ");
  Serial.println(RF95_FREQ);
  // The default transmitter power is 13dBm, using PA_BOOST.
  // If you are using RFM95 / 96/97/98 modules using the transmitter pin PA_BOOST, then
  // you can set transmission powers from 5 to 23 dBm:
  rf95.setTxPower(23, false);
}

void showcolor(String color) {
  if (color == "white") {
    FastLED.showColor(CRGB(255, 255, 255));
  }
  else if (color == "red") {
    FastLED.showColor(CRGB(10, 0, 0));
  }
  else if (color == "magenta") {
    FastLED.showColor(CRGB(255, 0, 255));
  }
  else if (color == "yellow") {
    FastLED.showColor(CRGB(255, 255, 0));
  }
  else {
    FastLED.showColor(CRGB(0, 0, 0));
  }
}

void loop() {
  // Blink LED to indicate comms
  digitalWrite(LED, HIGH);

  if (rf95.available()) {
    // Should be a message for us now
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);

    if (rf95.recv(buf, &len)) {
      // Light LED to indicate recieving
      digitalWrite(LED, LOW);
      showcolor("magenta");

      DynamicJsonDocument telemetry(200);
      deserializeJson(telemetry, (char*)buf);

      DynamicJsonDocument datagram(200);
      datagram["ts"] = millis();
      datagram["rssi"] = rf95.lastRssi();
      datagram["fc"] = telemetry;
      serializeJson(datagram, Serial);
      Serial.println("");
    } else {
      Serial.println("Receive failed");
      // Set status LED to show
      showcolor("yellow");
    }
  } else {
    // No message recieved, listening...
    showcolor("red");
  }
}
