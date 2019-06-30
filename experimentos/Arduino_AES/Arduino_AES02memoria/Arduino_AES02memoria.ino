#define clockCyclesPerMicrosecond ( F_CPU / 1000000L );
#include <AES.h>

#include <Thread.h>
#include <ThreadController.h>
#define MEGA_SRAM 2048

ThreadController schedule;
Thread memory_monitor;
Thread program;

AES aes ;

byte data[16] ={0x6a,0x84,0x86,0x7c,0xd7,0x7e,0x12,0xad,0x07,0xea,0x1b,0xe8,0x95,0xc5,0x3f,0xa3};
byte key[16]  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
byte my_iv[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

byte cipher [4*N_BLOCK] ;





void prekey (int bits, int blocks)
{
  byte iv [N_BLOCK] ;
  
      aes.set_key (key, bits) ;
   aes.encrypt (data, cipher) ;
 // aes.decrypt (cipher, data) ;
  
 
  
      

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



void show_memory_consumption()
{
  Serial.println( memory_usage() );
}

void algorithm()
{
prekey_test () ;
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
