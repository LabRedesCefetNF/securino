#define clockCyclesPerMicrosecond ( F_CPU / 1000000L );
#include <Crypto.h>
CryptoAES ZAES;

void setup() {
  Serial.begin(9600);
}


byte data[16] ={0x6a,0x84,0x86,0x7c,0xd7,0x7e,0x12,0xad,0x07,0xea,0x1b,0xe8,0x95,0xc5,0x3f,0xa3};
byte key[16]  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte out[16];

void loop() {

   delay(1000);
  unsigned long inicio = micros();
  ZAES.Initialize(key,key);
  ZAES.Encrypt(data,16,out,1);
  ZAES.Decrypt(out,16,out,1);
  unsigned long fim = micros();
  unsigned long result = (fim-inicio)*clockCyclesPerMicrosecond;
  Serial.println(result);
  delay(1000);
  
  
}
