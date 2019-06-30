#include <aes.h>
aes_128_context_t context;


byte data[16] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff};
byte key[16]  = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f};    


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  aes_128_init(&context,key);
  show("Key:",key);
  show("PlainText:",data);
  aes_128_encrypt(&context,data);
  show("CipherText: ",data);
  aes_128_decrypt(&context,data);
  show("PlainText: ",data);
  delay(10000);
}

// AES-128
void aes_128_init    (aes_128_context_t *context, uint8_t key[16]);
void aes_128_encrypt (aes_128_context_t *context, uint8_t block[16]);
void aes_128_decrypt (aes_128_context_t *context, uint8_t block[16]);


void show(String a, byte vet[]){
  Serial.print(a);  
  for(int i=0; i < 16; i++)
  {
      Serial.print(vet[i], HEX);
      Serial.print(" ");  
  }
  Serial.println();  
}
