/*
 * Copyright (C) 2015 Southern Storm Software, Pty Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

/*
This example runs tests on the AES implementation to verify correct behaviour.
*/

#include <Crypto.h>
#include <AES.h>
#include <string.h>

struct TestVector
{
    const char *name;
    byte key[32];
    byte plaintext[16];
    byte ciphertext[16];
};

// Define the ECB test vectors from the FIPS specification.
static TestVector const testVectorAES128 = {
    .name        = "AES-128-ECB",
    .key         = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    .plaintext   = {0x6a,0x84,0x86,0x7c,0xd7,0x7e,0x12,0xad,0x07,0xea,0x1b,0xe8,0x95,0xc5,0x3f,0xa3},
    .ciphertext  = {0x69, 0xC4, 0xE0, 0xD8, 0x6A, 0x7B, 0x04, 0x30,
                    0xD8, 0xCD, 0xB7, 0x80, 0x70, 0xB4, 0xC5, 0x5A}



};

AES128 aes128;

byte buffer[16];

void testCipher(BlockCipher *cipher, const struct TestVector *test)
{
    crypto_feed_watchdog();
  /*  Serial.print(test->name);
    Serial.print(" Encryption ... ");*/
    cipher->setKey(test->key, cipher->keySize());
    cipher->encryptBlock(buffer, test->plaintext);
  
   
/*
    Serial.print(test->name);
    Serial.print(" Decryption ... ");
    cipher->decryptBlock(buffer, test->ciphertext);
    if (memcmp(buffer, test->plaintext, 16) == 0)
        Serial.println("Passed");
    else
        Serial.println("Failed");

        */

    show("Key:\t\t",testVectorAES128.key);
    show("PlainText:\t",testVectorAES128.plaintext);
    show("CipherText:\t",buffer);
    
}


void setup()
{
    Serial.begin(9600);

  /*  Serial.println();

    Serial.println("State Sizes:");
    Serial.print("AES128 ... ");
    Serial.println(sizeof(AES128));
    Serial.print("AES192 ... ");
    Serial.println(sizeof(AES192));
    Serial.print("AES256 ... ");
    Serial.println(sizeof(AES256));
    Serial.println();


    Serial.println("Test Vectors:");
    testCipher(&aes128, &testVectorAES128);

/*    testCipher(&aes192, &testVectorAES192);
    testCipher(&aes256, &testVectorAES256);
*/

    Serial.println("Start");
    /*

    Serial.println("Performance Tests:");
    perfCipher(&aes128, &testVectorAES128);
    perfCipher(&aes192, &testVectorAES192);
    perfCipher(&aes256, &testVectorAES256);
    */
    
}

void loop()
{
      Serial.println("Test Vectors:");
    testCipher(&aes128, &testVectorAES128);
    delay(100000000);

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
