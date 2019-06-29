

#include <Thread.h>
#include <ThreadController.h>

ThreadController schedule;
Thread memory_monitor;
Thread program;


#include <Crypto.h>
#include <AES.h>
#include <string.h>

#define MEGA_SRAM 2048


struct TestVector
{
    const char *name;
    byte key[32];
    byte plaintext[16];
    byte ciphertext[16];
};
static TestVector const testVectorAES128 = {
    .name        = "AES-128-ECB",
    .key         = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
                    0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F},
    .plaintext   = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
                    0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF},
    .ciphertext  = {0x69, 0xC4, 0xE0, 0xD8, 0x6A, 0x7B, 0x04, 0x30,
                    0xD8, 0xCD, 0xB7, 0x80, 0x70, 0xB4, 0xC5, 0x5A}
};
AES128 aes128;
byte buffer[16];
void testCipher(BlockCipher *cipher, const struct TestVector *test)
{
    crypto_feed_watchdog();
    cipher->setKey(test->key, cipher->keySize());
    cipher->encryptBlock(buffer, test->plaintext);
    cipher->decryptBlock(buffer, test->ciphertext);    
}



void show_memory_consumption()
{
  Serial.println( memory_usage() );
}

void algorithm()
{
 testCipher(&aes128, &testVectorAES128);
}

void setup() {

  Serial.begin(9600);

  memory_monitor.setInterval(50);
  memory_monitor.onRun( show_memory_consumption );

  program.setInterval(500);
  program.onRun( algorithm );

  schedule.add( &memory_monitor );
  schedule.add( &program );

  Serial.println( "INICIO" );
}

void loop() {
  schedule.run();
}

unsigned int memory_usage(void)
{
    return MEGA_SRAM - free_sram();
}

static int free_sram()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int)&v-(__brkval ==0?(int)&__heap_start:(int) __brkval);
}
