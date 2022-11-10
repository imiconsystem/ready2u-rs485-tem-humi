test(allpins)
{
  int pins[] = {R1, R2, R3, R4};
  int cycle[] = {HIGH, LOW};
  int cycleLength = 2;
  uint8_t val;
  for (int i = 0; i < 3; i++)
  {
    pinMode(pins[i], OUTPUT);
    for (int j = 0; j < cycleLength; j++)
    {
      digitalWrite(pins[i], cycle[j]);
      delay(300);
      val = digitalRead(pins[i]);
#if defined(EPOXY_DUINO)
      val = digitalWriteValue(pins[i]);
#endif
      assertEqual(cycle[j], val);
    }
  }
}
// TEST default value
test(defAPssid){
  uint8_t size = APssid.length();
  assertMore(size,2);
}
test(defAPpassword){
  uint8_t size = APpassword.length();
  assertMore(size,7);
}

test(defdevice_name){
  uint8_t size = device_name.length();
  assertMore(size,4);
}
test(switch)
{
  pinMode(SW, INPUT);

  assertEqual(1, digitalRead(SW));
}

test(controlTemp)
{
  uint8_t val1, val2;
  setTemLoHi(30.00, 35, 50);
  controlRelay();
  val1 = digitalRead(R1);
  val2 = digitalRead(R2);
#if defined(EPOXY_DUINO)
  val1 = digitalWriteValue(R1);
  val2 = digitalWriteValue(R2);
#endif
  Serial.println(val1);
  assertEqual(1, val1);
  assertEqual(0, val2);
}