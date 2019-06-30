#include <Crypto.h>
CryptoAES ZAES;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}


byte data[16] ={0x6a,0x84,0x86,0x7c,0xd7,0x7e,0x12,0xad,0x07,0xea,0x1b,0xe8,0x95,0xc5,0x3f,0xa3};
byte key[16]  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};


byte out[16];
byte out2[16];
void loop() {
  delay(2000);
  show("GatinhoKey:",key);
  ZAES.Initialize(key,key);
show("Plain:",data);
ZAES.Encrypt(data,16,out,1);
  show("Cipher:",out);
ZAES.Decrypt(out,16,out2,1);
show("Plain:",out2);
// pt your main code here, to run repeatedly:
//Serial.println(data);
delay(200000000);
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
