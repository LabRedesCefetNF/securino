#include <bcal-cbc.h>
#include <aes256_dec.h>
#include <blockcipher_descriptor.h>
#include <bcal_aes128.h>
#include <aes128_enc.h>
#include <bcal_aes256.h>
#include <aes_types.h>
#include <gf256mul.h>
#include <bcal_aes192.h>
#include <keysize_descriptor.h>
#include <aes192_dec.h>
#include <bcal-basic.h>
#include <bcal-ofb.h>
#include <aes_invsbox.h>
#include <aes_enc.h>
#include <aes192_enc.h>
#include <aes256_enc.h>
#include <aes.h>
#include <aes_sbox.h>
#include <bcal-cmac.h>
#include <memxor.h>
#include <aes128_dec.h>
#include <AESLib.h>
#include <aes_dec.h>
#include <aes_keyschedule.h>



byte key[16]  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte iv[16] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte data[16] ={0x6a,0x84,0x86,0x7c,0xd7,0x7e,0x12,0xad,0x07,0xea,0x1b,0xe8,0x95,0xc5,0x3f,0xa3};


void setup() {
Serial.begin(9600);

}

void loop() {
delay(1000);
Serial.print("key:");
for(int i=0; i<16; i++){
  Serial.print(key[i],HEX);  
  Serial.print(" ");  
}
Serial.println("");
Serial.print("plaintext:");
for(int i=0; i<16; i++){
  Serial.print(data[i],HEX);  
  Serial.print(" ");  
}
Serial.println("");
//aes128_enc_single(key, data);
aes128_cbc_enc(key, iv, data, 16);
Serial.print("encrypted:");
for(int i=0; i<16; i++){
  Serial.print(data[i],HEX);  
  Serial.print(" ");  
}
Serial.println("");

aes128_dec_single(key, data);
Serial.print("decrypted:");
for(int i=0; i<16; i++){
  Serial.print(data[i],HEX);  
  Serial.print(" ");  
}
Serial.println("");
delay(10000);

}
