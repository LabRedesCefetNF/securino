#define clockCyclesPerMicrosecond ( F_CPU / 1000000L );
#include <aes.h>
aes_128_context_t context;


byte data[16] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff};
byte key[16]  = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f};    


void setup() {
  Serial.begin(9600);
}

void loop() {


   delay(1000);
  unsigned long inicio = micros();
aes_128_init(&context,key);
 aes_128_encrypt(&context,data);
  aes_128_decrypt(&context,data);
  
  unsigned long fim = micros();
  unsigned long result = (fim-inicio)*clockCyclesPerMicrosecond;
  Serial.println(result);
  delay(1000);
  
  
}

// AES-128
void aes_128_init    (aes_128_context_t *context, uint8_t key[16]);
void aes_128_encrypt (aes_128_context_t *context, uint8_t block[16]);
void aes_128_decrypt (aes_128_context_t *context, uint8_t block[16]);
