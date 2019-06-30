#define clockCyclesPerMicrosecond ( F_CPU / 1000000L );
#include <AES.h>

AES aes ;

byte data[16] ={0x6a,0x84,0x86,0x7c,0xd7,0x7e,0x12,0xad,0x07,0xea,0x1b,0xe8,0x95,0xc5,0x3f,0xa3};
byte key[16]  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte my_iv[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

byte cipher [4*N_BLOCK] ;

void loop () 
{
   prekey_test () ;
  }


void setup ()
{
  Serial.begin (9600) ;

 
  
}

void prekey (int bits, int blocks)
{
  byte iv [N_BLOCK] ;
   delay(1000);
  unsigned long inicio = micros();

      aes.set_key (key, bits) ;
 //   aes.encrypt (data, cipher) ;
  aes.decrypt (cipher, data) ;
  
  unsigned long fim = micros();
  unsigned long result = (fim-inicio)*clockCyclesPerMicrosecond;
  Serial.println(result);
  delay(1000);
  
      

}

void prekey_test ()
{
  prekey (128, 4) ;
/*  prekey (192, 3) ;
  prekey (256, 2) ;
  prekey (128, 1) ;
  prekey (192, 1) ;
  prekey (256, 1) ;*/
  
}
