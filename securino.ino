byte plaintext[4][4] = {
                        {0x32,0x88,0x31,0xE0},
                        {0x43,0x5A,0x31,0x37},
                        {0xF6,0x30,0x98,0x07},
                        {0xA8,0x8D,0xA2,0x34}
                       };
byte key[4][4] = {
                  {0x2B,0x28,0xAB,0x09},
                  {0x7E,0xAE,0xF7,0xCF},
                  {0x15,0xD2,0x15,0x4F},
                  {0x16,0xA6,0x88,0x3C}
                 };
//void enc(byte x[][4],byte y[][4]); 
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);     
      
} 

// the loop routine runs over and over again forever:
void loop() {

  delay(3000);
  Serial.println(F("State: "));

  for(int i=0; i < 4; i++)
  {
    for(int j=0; j < 4; j++)
    {
      Serial.print(F("\t"));
      Serial.print(plaintext[i][j], HEX);
    }
    Serial.println();
  }
  Serial.println();

  enc(plaintext,key);

  Serial.println(F("Output: "));
  for(int i=0; i < 4; i++)
  {
    for(int j=0; j < 4; j++)
    {
      Serial.print(F("\t"));
      Serial.print(plaintext[i][j], HEX);
    }
    Serial.println();
  }
  delay(5000);

  Serial.println(F("Decriptando..."));

  dec(plaintext, key);

  Serial.println(F("Texto decriptado: "));
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      Serial.println(F("\t"));
      Serial.print(plaintext[i][j], HEX);
    }
    Serial.println();
  }

    delay(500000);

}
