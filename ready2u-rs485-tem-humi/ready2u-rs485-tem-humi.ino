#include <Arduino.h>


// INPUTS
// กำหนดตัวแปรสำหรับการสื่อสารผ่านโปรโตคอล Modbus RTU
#define RXD2 16 // กำหนดหมายเลข GPIO 16 สำหรับขา Rx
#define TXD2 17 // กำหนดหมายเลข GPIO 17 สำหรับขา Tx

#define SW 2 // Custom swithch

// OUTPUTS
#define R1 23
#define R2 19
#define R3 18
#define R4 32

String APssid = "485THDevkit";
String APpassword = "dddddddd";

int SETMODE = 0;

String WiFissid = "";
String WiFipassword = "";

String WiFiRSSI;
String myIP;
String webTitle = "RS485 Temperature & Humidity Station";
String device_name = "485th";

int32_t setVar1, setVar2, setVar3, setVar4;
float_t TEMP, HUMI;

struct ALARMLEV
{
  String word;
  String icon;
};
struct ALARMLEV alarmlev = {};

// RELAYS

void relayHi(int relay)
{

  digitalWrite(relay, 1);
}

void relayLo(int relay)
{
  digitalWrite(relay, 0);
}

bool relayIsOn(int relay)
{
  return digitalRead(relay) == 0;
}

void relaySetup()
{
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);

  relayLo(R1);
  relayLo(R2);
  relayLo(R3);
  relayLo(R4);
}

void controlRelay()
{
  Serial.println("Controll run");
  Serial.println(TEMP);
  Serial.println(setVar1);
  Serial.println(setVar2);
  if (TEMP <= setVar1 && setVar1 > 0)
    relayHi(R1);
  else
    relayLo(R1);

  if (TEMP >= setVar2 && setVar2 > 0)
    relayHi(R2);
  else
    relayLo(R2);

  if (HUMI <= setVar3 && setVar3 > 0)
    relayHi(R3);
  else
    relayLo(R3);

  if (HUMI >= setVar4 && setVar4 > 0)
    relayHi(R4);
  else
    relayLo(R4);
}
void setTemLoHi(float tem,int lo, int hi){
    TEMP = tem;
    setVar1 = lo;
    setVar2 = hi;
    controlRelay();
}
void _setup()
{
  // serialSetup();
  relaySetup();
  // resetbuttonSetup();
  // storageSetup();

  TEMP = 0;
  HUMI = 0;

  if (SETMODE == 1) // SET
  {
    SETMODE = true;
    // wifiapSetup();
  }
  else if (SETMODE == 2)
  { // RESET FACTORY
    // storageClear();
    //  ESP.restart();
  }
  else
  {
    // RUN
    // webserverSetup();
  }
}

void _loop()
{

  if (SETMODE == 0)
  {

    // webserverLoop();
    // clientLoop();
    // serialLoop();
    // controlRelay();
  }
  else if (SETMODE == 1) // SET
  {
    Serial.println("SET MODE.");
    // clientLoop();
    // blinkSet();
  }
  else if (SETMODE == 2)
  { // RESET
    // blinkReset();
  }
  else
  {
    Serial.println("CLIENT MODE.");
    // clientLoop();
  }
}
#if defined(EPOXY_DUINO)
#include <AUnit.h>
using aunit::TestRunner;
#include "tests/test.ino"
#endif
void setup()
{

  Serial.begin(115200);
  while (!Serial); // Wait until Serial is ready - Leonardo/Micro

  _setup();
}

void loop()
{
  _loop();
#if defined(EPOXY_DUINO)
  aunit::TestRunner::run();
#endif
}