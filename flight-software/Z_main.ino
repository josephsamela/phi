void setup() {
  setup_serial();
  setup_led();
  showcolor("red");
  setup_radio();
}

void loop() {
  // Light LED to indicate transmitting
  digitalWrite(LED,LOW);

  // Build and transmit telemetry datagram
  build_telemetry_datagram();  
  rf95.send((uint8_t *)telemetry.c_str(), telemetry.length());
  rf95.waitPacketSent();
  Serial.println(telemetry);

  digitalWrite(LED,HIGH);
  
  showcolor("blue");
}
