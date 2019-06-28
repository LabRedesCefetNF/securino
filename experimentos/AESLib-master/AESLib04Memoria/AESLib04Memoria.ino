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

#include <Thread.h>
#include <ThreadController.h>
#define MEGA_SRAM 2048

ThreadController schedule;
Thread memory_monitor;
Thread program;

byte data[16] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff};
byte key[16]  = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f};    


void show_memory_consumption()
{
  Serial.println( memory_usage() );
}

void algorithm()
{
//aes128_enc_single(key, data);
//aes128_dec_single(key, data);
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
