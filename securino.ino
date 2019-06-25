byte plaintext[4][4] = {
                        /*{0x00,0x44,0x88,0xcc},
                        {0x11,0x55,0x99,0xdd},
                        {0x22,0x66,0xaa,0xee},
                        {0x33,0x77,0xbb,0xff}*/
                        {0x69, 0x6a, 0xd8, 0x70},
                        {0xc4,0x7b, 0xcd, 0xb4},
                        {0xe0, 0x04, 0xb7, 0xc5},
                        {0xd8, 0x30, 0x80, 0x5a}
                       };                       

byte key[4][4] = {
                  {0x00,0x04,0x08,0x0c},
                  {0x01,0x05,0x09,0x0d},
                  {0x02,0x06,0x0a,0x0e},
                  {0x03,0x07,0x0b,0x0f}
                 };
                 
const byte keyCopia[4][4] = {
                             {0x00,0x04,0x08,0x0c},
                             {0x01,0x05,0x09,0x0d},
                             {0x02,0x06,0x0a,0x0e},
                             {0x03,0x07,0x0b,0x0f}
                            };
                       
                       
void enc(byte x[][4], byte y[][4]); 
void dec(byte x[][4], byte y[][4]);
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);     
      
}

// the loop routine runs over and over again forever:
void loop() {

  delay(3000);
  Serial.println("State: ");

  for(int i=0; i < 4; i++)
  {
    for(int j=0; j < 4; j++)
    {
      Serial.print("\t");
      Serial.print(plaintext[i][j], HEX);
    }
    Serial.println();
  }
  Serial.println();

//enc(plaintext,key);
dec(plaintext,key);

  Serial.println("Output: ");
  for(int i=0; i < 4; i++)
  {
    for(int j=0; j < 4; j++)
    {
      Serial.print("\t");
      Serial.print(plaintext[i][j], HEX);
    }
    Serial.println();
  }
  delay(5000000);
}

/*byte plaintext[16] = {0x32,0x43,0xF6,0xA8,0x88,0x5A,0x30,0x8D,0x31,0x31,0x98,0xA2,0xE0,0x37,0x07,0x34};
byte key[16] = {0x2B,0x7E,0x15,0x16,0x28,0xAE,0xD2,0xA6,0xAB,0xF7,0x15,0x88,0x09,0xCF,0x4F,0x3C};


// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
      Serial.begin(9600);     
      
}

// the loop routine runs over and over again forever:
void loop() {

 delay(3000);
 

enc(plaintext,key);



delay(5000000);

}*/
