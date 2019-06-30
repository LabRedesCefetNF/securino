#include "aes.h"
#include "key.h"

unsigned char  key[176];

void setup() {
  Serial.begin(9600);
  loadKey(key,30);
}

void loop() {
  unsigned char  key[176] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
  unsigned char  wrd[16] = {0x6a,0x84,0x86,0x7c,0xd7,0x7e,0x12,0xad,0x07,0xea,0x1b,0xe8,0x95,0xc5,0x3f,0xa3};

  //unsigned char  wrd[16];
  unsigned char  tmp[16];
   AES_encrypt_128(wrd, key, tmp);
   AES_decrypt_128(wrd, key, tmp);
   
  Serial.print("KEY:");
  for(unsigned char i=0;i<16;i++)
    Serial.print(key[i],HEX);
  Serial.println("");
  
  
  Serial.print("Plain:");
  for(unsigned char i=0;i<16;i++)
    Serial.print(wrd[i],HEX);
  Serial.println("");
  AES_encrypt_128(wrd, key, tmp);
  Serial.print("Cipher:");
  for(unsigned char i=0;i<16;i++)
    Serial.print(wrd[i],HEX);
  Serial.println("");
  AES_decrypt_128(wrd, key, tmp);
  Serial.print("WRD:");
  for(unsigned char i=0;i<16;i++)
    Serial.print(wrd[i],HEX);
  Serial.print("\n\n");
  delay(1000);
  
}
