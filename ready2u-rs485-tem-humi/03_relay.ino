void relaySetup()
{
    pinMode(R1, OUTPUT);
    pinMode(R2, OUTPUT);
    pinMode(R3, OUTPUT);
    pinMode(R4, OUTPUT);

}

void relayHi(int relay){

    digitalWrite(relay, HIGH);
}

void relayLo(int relay){
    digitalWrite(relay, LOW);
}