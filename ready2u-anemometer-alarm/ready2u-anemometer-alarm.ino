#define R1 23
#define R2 19
#define R3 18
#define R4 32

// กำหนดตัวแปรสำหรับการสื่อสารผ่านโปรโตคอล Modbus RTU
#define RXD2 16  // กำหนดหมายเลข GPIO 16 สำหรับขา Rx
#define TXD2 17  // กำหนดหมายเลข GPIO 17 สำหรับขา Tx

String APssid = "AnemoDevkit";
String APpassword = "dddddddd";

int SETMODE = 0;

String WiFissid = "";
String WiFipassword = "";

String WiFiRSSI;
String myIP;
String webTitle = "Anemometer Alarm";
String device_name = "anemo";

int32_t maxSpd1, maxSpd2, maxSpd3, maxSpd4;
float_t WINSPD;


struct ALARMLEV {
  String word;
  String icon;
};
struct ALARMLEV alarmlev = {};

void setup() {

  Serial.begin(115200);  // For debug
  Serial.println("ESP start.");
  serialSetup();
  relaySetup();
  resetbuttonSetup();
  storageSetup();

  WINSPD = 0;

  if (SETMODE == 1)  // SET
  {
    SETMODE = true;
    wifiapSetup();



  } else if (SETMODE == 2) {  // RESET FACTORY
    storageClear();
    // ESP.restart();
  } else {
    // RUN
    webserverSetup();
  }
}

void controlRelay() {
  if (WINSPD > maxSpd1 && maxSpd1 > 0) relayHi(R1);
  else relayLo(R1);

  if (WINSPD > maxSpd2 && maxSpd2 > 0) relayHi(R2);
  else relayLo(R2);

  if (WINSPD > maxSpd3 && maxSpd3 > 0) relayHi(R3);
  else relayLo(R3);

  if (WINSPD > maxSpd4 && maxSpd4 > 0) relayHi(R4);
  else relayLo(R4);
}


void loop() {
  if (SETMODE == 0) {

    webserverLoop();
    clientLoop();
    serialLoop();
    controlRelay();
  } else if (SETMODE == 1)  // SET
  {
    Serial.println("SET MODE.");
    clientLoop();
    blinkSet();
  }
  else if (SETMODE == 2) {  //RESET
    blinkReset();
  }
  else {
    Serial.println("CLIENT MODE.");
    clientLoop();
  }
}