void setup() {
  setup_serial();
  setup_led();
  showcolor("red");
  setup_radio();
}

void loop() {
  delay(1000);
  build_telemetry_datagram();
  Serial.println("Transmitting...");  
  Serial.println(telemetry);
  rf95.send((uint8_t *)telemetry.c_str(), telemetry.length());
  rf95.waitPacketSent();
  showcolor("blue");
}
