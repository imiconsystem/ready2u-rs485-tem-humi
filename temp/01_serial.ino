const int numBytes = 8;
const byte modbusQuery[numBytes] = { 0x02, 0x03, 0x00, 0x00, 0x00, 0x02, 0xC4, 0x38 };  // RS FS wind speed
byte buffQuery[numBytes];

byte ByteArray[9];
int ByteData[9];

void serialSetup() {
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);  //
}

void serialLoop() {

  SerialProcessData();
  delay(5000);
}

void SerialProcessData() {

  for (int j = 0; j < numBytes; j++) {
    Serial2.write(modbusQuery[j]);
  }
  int a = 0;
  while (Serial2.available() > 0) {
    ByteArray[a] = Serial2.read();
    a++;
  }

  ByteData[0] = ByteArray[3] * 256 + ByteArray[4];

  float Data1,knot;
  Data1 = ByteData[0] * 0.1;


  // Serial.print(ByteArray[0]);
  // Serial.print(" ");
  // Serial.print(Data1);
  // Serial.print(" ");
  // Serial.print(Data2);
  // Serial.print(" ");

  if (ByteData[0] > 0) {
    WINSPD = Data1 * 3.6;  //metre per second to kilometre per hour multiply the speed value by 3.6
    knot = Data1 / 30.867;//for an approximate result, divide the speed value by 30.867


     Serial.print("SP =  ");
     Serial.print(WINSPD);
     Serial.println(" km/h");


     Serial.print(knot);
     Serial.println(" Knot");

    if (knot <= 1) alarmlev = { "Calm", "&#128512;" };
    else if (knot > 1 && knot <= 3) alarmlev = { "Light Air", "&#128512;" };
    else if (knot >= 4 && knot <= 6) alarmlev = { "Light Breeze", "&#128512;" };
    else if (knot >= 7 && knot <= 10) alarmlev = { "Gentle Breeze", "&#128512;" };
    else if (knot >= 11 && knot <= 16) alarmlev = { "Moderate Breeze", "&#128524;" };
    else if (knot >= 17 && knot <= 21) alarmlev = { "Fresh Breeze", "&#128524;" };
    else if (knot >= 22 && knot <= 27) alarmlev = { "Strong Breeze", "&#128528;" };
    else if (knot >= 28 && knot <= 33) alarmlev = { "Near Gale", "&#128528;" };
    else if (knot >= 34 && knot <= 40) alarmlev = { "Gale", "&#128531;" };
    else if (knot >= 41 && knot <= 47) alarmlev = { "Severe Gale", "&#128534;" };
    else if (knot >= 48 && knot <= 55) alarmlev = { "Storm", "&#128565;" };
    else if (knot >= 56 && knot <= 63) alarmlev = { "Violent Storm", "&#128561;" };
    else if (knot >= 64 && knot <= 71) alarmlev = { "Hurricane", "&#127756;" };
  }
}