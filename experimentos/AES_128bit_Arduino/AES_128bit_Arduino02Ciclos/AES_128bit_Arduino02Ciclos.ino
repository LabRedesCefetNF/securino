
#define clockCyclesPerMicrosecond ( F_CPU / 1000000L );
#include "aes.h"
#include "key.h"


  unsigned char  key[176] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
  unsigned char  wrd[16] = {0x6a,0x84,0x86,0x7c,0xd7,0x7e,0x12,0xad,0x07,0xea,0x1b,0xe8,0x95,0xc5,0x3f,0xa3};
  unsigned char  tmp[16];

void setup() {
  Serial.begin(9600);
}

void loop() {


   delay(1000);
  unsigned long inicio = micros();
   AES_encrypt_128(wrd, key, tmp);
   AES_decrypt_128(wrd, key, tmp);
  unsigned long fim = micros();
  unsigned long result = (fim-inicio)*clockCyclesPerMicrosecond;
  Serial.println(result);
  delay(1000);

  
}
