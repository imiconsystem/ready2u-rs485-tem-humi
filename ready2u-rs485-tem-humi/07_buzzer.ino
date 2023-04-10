void buzzer_setup(){
   pinMode(5, OUTPUT);
}
void beep(){
  tone(5,3000,300);
}

void beepWiFiLoss() {
  buzzer_setup();
  for (int i = 1; i <= 3; i++) {
    beep();
    delay(500);
  }
}