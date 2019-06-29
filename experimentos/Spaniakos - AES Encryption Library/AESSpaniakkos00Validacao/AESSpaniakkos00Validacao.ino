#include <AES.h>
#include "./printf.h"

AES aes ;

byte key[16]  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte iv[16] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte plain[16] ={0x6a,0x84,0x86,0x7c,0xd7,0x7e,0x12,0xad,0x07,0xea,0x1b,0xe8,0x95,0xc5,0x3f,0xa3};

//byte *key = (unsigned char*)"0123456789010123";
//byte plain[] = "Add NodeAdd NodeAdd NodeAdd NodeAdd Node";

int plainLength = sizeof(plain)-1;  // don't count the trailing /0 of the string !
int padedLength = plainLength + N_BLOCK - plainLength % N_BLOCK;

//real iv = iv x2 ex: 01234567 = 0123456701234567
//unsigned long long int my_iv = 36753562;

void setup ()
{
  Serial.begin (9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  printf_begin();
  delay(500);
  printf("\n===testing mode\n") ;

//  otfly_test () ;
//  otfly_test256 () ;
}

void loop () 
{
  prekey_test () ;
  delay(2000);
}

void prekey (int bits)
{
  delay(1000);
  //aes.iv_inc();
  //byte iv [N_BLOCK] ;
  byte plain_p[padedLength];
  byte cipher [padedLength] ;
  byte check [padedLength] ;
  unsigned long ms = micros ();

show("Plain:",plain);
show("Key:",key);
// show("MyIV:",my_iv);
 show("IV:",iv);
  //aes.set_IV(my_iv);
  //aes.get_IV(iv);

  cbc_encrypt  ( byte *  plain,
byte *  cipher,
int   n_block,
byte  iv[N_BLOCK] 
)   

  aes.do_aes_encrypt(plain,128,cipher,key,128,iv);

  show("Cipher:",cipher);
  /*
  Serial.print("Encryption took: ");
  Serial.println(micros() - ms);
  ms = micros ();
  aes.set_IV(my_iv);
  aes.get_IV(iv);
  aes.do_aes_decrypt(cipher,padedLength,check,key,bits,iv);
  Serial.print("Decryption took: ");
  Serial.println(micros() - ms);
  printf("\n\nPLAIN :");
  aes.printArray(plain,(bool)true);
  printf("\nCIPHER:");
  aes.printArray(cipher,(bool)false);
  printf("\nCHECK :");
  aes.printArray(check,(bool)true);
  printf("\nIV    :");
  aes.printArray(iv,16);
  printf("\n============================================================\n");*/
  delay(10000);
}

void prekey_test ()
{
  prekey (128) ;
}


void show(String a, byte vet[]){
  Serial.print(a);  
  for(int i=0; i < 16; i++)
  {
      Serial.print(vet[i], HEX);
      Serial.print(" ");  
  }
  Serial.println();  
}
