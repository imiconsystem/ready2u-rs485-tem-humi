void testOutput(int out) {
    pinMode(out, OUTPUT);
    int cycleCount = 1;
    int cycleLength = 2;
    int cycle[] = { HIGH, LOW };

    for (int i = 0; i < cycleCount; i++) {
        for (int j = 0; j < cycleLength; j++) {
            digitalWrite(out, cycle[j]);
            delay(300);             
            assertEqual(cycle[j], digitalRead(out),"case cycle =" << cycle[j]);
        }
    }
}

void testInput(int in, int state) {
    pinMode(in, INPUT);

    assertEqual(state, digitalRead(in),"case state =" << state);
}

// TEST Relay output pins
test(pinR1) {
    testOutput(R1);
}
test(pinR2) {
    testOutput(R2);
}
test(pinR3) {
    testOutput(R3);
}
test(pinR4) {
    testOutput(R4);
}

// // TEST UART pins
// test(pinRXD2) {
//     testOutput(RXD2);
// }
// test(pinTXD2) {
//     testOutput(TXD2);
// }
// TEST custom Switch
test(pinSW) {
    testInput(SW,LOW);
}
// TEST default value
test(defAPssid){
  unsigned int size = APssid.length();
  assertMore(size,2,"case size of =" << size);
}

test(defAPpassword){
  unsigned int size = APpassword.length();
  assertMore(size,7,"case size of =" << size);
}

test(defdevice_name){
  unsigned int size = device_name.length();
  assertMore(size,4,"case size of =" << size);
}
// TEST functions
void setTemLoHi(float tem,int lo, int hi){
    TEMP = round(tem);
    setVar1 = lo;
    setVar2 = hi;
    controlRelay();
}


test(controlTemp){
  //  int temLo = 0;
  //  int temHi = 100;
  //  float ranTem = 0.0;
  //  for(int i = 0; i <= 100 ;i++){
  //    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
      
  //    setVar1 = temLo;
  //    setVar2 = temHi;
  //    TEMP = ranTem;
  //    Serial.print(setVar1);
  //    Serial.print(" | ");
  //    Serial.print(setVar2);
  //    Serial.print(" | ");
  //    Serial.println(TEMP);
  //    temLo = temLo+1;
  //    temHi = temHi-1;
  //    ranTem = ranTem+1+r;
  //    if(ranTem > 100) ranTem -= 100; 
  //}
    setTemLoHi(30.00,35,50); 
    assertEqual(1,digitalRead(R1));
    assertEqual(0,digitalRead(R2));    

    setTemLoHi(35.55,20,30); 
    assertEqual(0,digitalRead(R1));
    assertEqual(1,digitalRead(R2));

    setTemLoHi(35.23,40,20); 
    assertEqual(1,digitalRead(R1));
    assertEqual(1,digitalRead(R2));  

    setTemLoHi(45.99,40,20); 
    assertEqual(0,digitalRead(R1));
    assertEqual(1,digitalRead(R2)); 

    setTemLoHi(35.00,0,0); 
    assertEqual(0,digitalRead(R1));
    assertEqual(0,digitalRead(R2));

    setTemLoHi(1,0,0); 
    assertEqual(0,digitalRead(R1));
    assertEqual(0,digitalRead(R2));

    setTemLoHi(0.1,1,0); 
    assertEqual(1,digitalRead(R1));
    assertEqual(0,digitalRead(R2));

    setTemLoHi(0.2,1,1); 
    assertEqual(1,digitalRead(R1));
    assertEqual(0,digitalRead(R2));

    setTemLoHi(1,1,0); 
    assertEqual(1,digitalRead(R1));
    assertEqual(0,digitalRead(R2));

    setTemLoHi(100,100,100); 
    assertEqual(1,digitalRead(R1));
    assertEqual(1,digitalRead(R2));       
   
}

void setHumLoHi(float hum,int lo, int hi){
    HUMI = round(hum);
    setVar3 = lo;
    setVar4 = hi;
    controlRelay();
}
test(controlHum){

    setHumLoHi(50.00,50,50); 
    assertEqual(1,digitalRead(R3));
    assertEqual(1,digitalRead(R4));    

    setHumLoHi(35.55,20,30); 
    assertEqual(0,digitalRead(R3));
    assertEqual(1,digitalRead(R4));

    setHumLoHi(35.23,40,20); 
    assertEqual(1,digitalRead(R3));
    assertEqual(1,digitalRead(R4));  

    setHumLoHi(45.99,40,20); 
    assertEqual(0,digitalRead(R3));
    assertEqual(1,digitalRead(R4)); 

    setHumLoHi(35.00,0,0); 
    assertEqual(0,digitalRead(R3));
    assertEqual(0,digitalRead(R4));

    setHumLoHi(1,0,0); 
    assertEqual(0,digitalRead(R3));
    assertEqual(0,digitalRead(R4));

    setHumLoHi(0.1,1,0); 
    assertEqual(1,digitalRead(R3));
    assertEqual(0,digitalRead(R4));

    setHumLoHi(0.2,1,1); 
    assertEqual(1,digitalRead(R3));
    assertEqual(0,digitalRead(R4));

    setHumLoHi(1,1,0); 
    assertEqual(1,digitalRead(R3));
    assertEqual(0,digitalRead(R4));

    setHumLoHi(100,100,100); 
    assertEqual(1,digitalRead(R3));
    assertEqual(1,digitalRead(R4));       
   
}


