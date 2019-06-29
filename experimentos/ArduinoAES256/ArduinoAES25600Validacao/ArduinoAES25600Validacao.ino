#include "aes256.h" //Include library files
#define DUMP(str, i, buf, sz) { Serial.println(str); \
                               for(i=0; i<(sz); ++i) { if(buf[i]<0x10) Serial.print('0'); Serial.print(char(buf[i]), HEX); } \
                               Serial.println(); } //Help function for printing the Output
                               
aes256_context ctxt;

void setup() {
  int i;
  Serial.begin(9600);
  
  Serial.println("Initializing AES256... ");

  uint8_t key[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f};
  uint8_t data[] = {0x00,0x11,0x22,0x33,0x44,0x45,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff};                    
  
  aes256_init(&ctxt, key);

Serial.println("AESLib - CIFRANDO...");
Serial.print("plaintext: \t");
for(int i=0; i<16; i++)
{
  Serial.print(data[i],HEX);
    Serial.print(" ");
}
Serial.println("");

Serial.print("key: \t\t");
for(int i=0; i<32; i++)
{
  Serial.print(key[i],HEX);
    Serial.print(" ");
}
Serial.println("");

   aes256_encrypt_ecb(&ctxt, data);

Serial.print("output: \t");
for(int i=0; i<16; i++)
{
  Serial.print(data[i],HEX);
    Serial.print(" ");
}
Serial.println("\n");

  
 Serial.println("AESLib - DECIFRANDO...");
//cifrando
Serial.print("ciphertext: \t");
for(int i=0; i<16; i++)
{
  Serial.print(data[i],HEX);
    Serial.print(" ");
}
Serial.println("");
//decifrando


Serial.print("key: \t\t");
for(int i=0; i<32; i++)
{
  Serial.print(key[i],HEX);
    Serial.print(" ");
}
Serial.println("");
  
  aes256_decrypt_ecb(&ctxt, data);
 
Serial.print("output: \t");
for(int i=0; i<16; i++)
{
  Serial.print(data[i],HEX);
  Serial.print(" ");
}
Serial.println("");

  aes256_done(&ctxt);
}

void loop() {
}
