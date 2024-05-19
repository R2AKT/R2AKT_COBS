#include <r2akt_cobs.h>

void setup() {
  Serial.begin (9600);
}

void loop() {
  uint8_t Buff[] = {0x0, 0x2, 0x0, 0x1, 0xC0, 0x66, 0x2D, 0x0, 0xCC};
    uint8_t COBSBuff[sizeof (Buff)/sizeof(Buff[0])] = {};
    uint8_t DeCOBSBuff[sizeof (Buff)/sizeof(Buff[0])] = {};

    Serial.print ("\nData:\n");

    for (uint8_t Count = 0; Count < sizeof (Buff)/sizeof(Buff[0]); Count++) {
        Serial.print (Buff[Count], HEX);
    }

    size_t COBS_Len = StuffData (COBSBuff,Buff, sizeof (Buff)/sizeof(Buff[0]));

    Serial.print ("\nCOBS Data:\n");

    for (uint8_t Count = 0; Count < COBS_Len; Count++) {
       Serial.print (COBSBuff[Count], HEX);
    }

    size_t DeCOBS_Len = DeStuffData (DeCOBSBuff, COBSBuff, COBS_Len);

    Serial.print ("\nDeCOBS Data:\n");

    for (uint8_t Count = 0; Count < DeCOBS_Len; Count++) {
        Serial.print (DeCOBSBuff[Count], HEX);
    }
}
