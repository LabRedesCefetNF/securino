#include <Rijndael.h>
#include <Rijndael_Consts.h>

enum RIJNDAEL_TYPE;



void setup() {
  // put your setup code here, to run once:
  void Schedule_Keys(enum RIJNDAEL_TYPE AES_128, const unsigned char* key, const int keylen, unsigned char* sched_keys);
//  void Encrypt(enum RIJNDAEL_TYPE AES_128, const unsigned char* plaintext, const int plaintext_len, const unsigned char* keys,  unsigned char* cipher);
 // void Decrypt(enum RIJNDAEL_TYPE AES_128, const unsigned char* ciphertext, const int plaintext_len, const unsigned char* keys,  unsigned char* plain);

}

void loop() {
  // put your main code here, to run repeatedly:

}
