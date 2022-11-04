int packetnum = 0;

void setup() {
  setup_serial();
  setup_led();
  showcolor("red");
  setup_radio();
  setup_imu();
  Serial.println("INITIALIZATION: Complete.");
}

void loop() {
  // Light LED to indicate transmitting
  digitalWrite(LED,LOW);

  // Build and transmit telemetry datagram
  build_telemetry_datagram();  
  rf95.send((uint8_t *)telemetry.c_str(), telemetry.length());
  rf95.waitPacketSent();
  
//  Serial.println(telemetry);

  digitalWrite(LED,HIGH);
  
  showcolor("blue");
}

void build_telemetry_datagram() {
  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp;
  dso32.getEvent(&accel, &gyro, &temp);
  
  packetnum += 1;
  DynamicJsonDocument datagram(500);
  datagram["id"] = packetnum;
  datagram["dt"] = millis();
 
  datagram["imu_accel_x"] = accel.acceleration.x;
  datagram["imu_accel_y"] = accel.acceleration.y;
  datagram["imu_accel_z"] = accel.acceleration.z;
  datagram["imu_accel_unit"] = "m/s^2";

  datagram["imu_gyro_x"] = gyro.gyro.x;
  datagram["imu_gyro_y"] = gyro.gyro.y;
  datagram["imu_gyro_z"] = gyro.gyro.z;
  datagram["imu_gyro_unit"] = "radians/s";

  datagram["imu_temp"] = temp.temperature;
  datagram["imu_temp_unit"] = "deg C";
  
  telemetry = "";
  serializeJson(datagram, telemetry);
}
