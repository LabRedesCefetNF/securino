byte matrizTeste[4][4] = { {0xd4, 0xe0, 0xb8, 0x1e},
                           {0xbf, 0xb4, 0x41, 0x27},
                           {0x5d, 0x52, 0x11, 0x98},
                           {0x30, 0xae, 0xf1, 0xe5} };

void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  //Serial.println("teste");
  // put your main code here, to run repeatedly:
Serial.println("texto a ser cifrado: ");  
for(int i=0; i < 4; i++)
{
  for(int j=0; j < 4; j++)
  {
    Serial.print("\t");
    Serial.print(matrizTeste[i][j], HEX);
    
  }
  Serial.println();
}
delay(600);
Serial.println();
Serial.println("texto cifrado: ");
for(int i=0; i < 4; i++)
{
  for(int j=0; j < 4; j++)
  {
    MixColumns(matrizTeste);
  }
}
for(int i=0; i < 4; i++)
{
  for(int j=0; j < 4; j++)
  {
      Serial.print("\t");
      Serial.print(matrizTeste[i][j], HEX);
  }
  Serial.println();
}
delay(60000);
}



void MixColumns(byte matrizEntrada[][4])
{
 // byte matrizResultante[4][4];
  byte matrizGalois[4][4] = { {0x02, 0x03, 0x01, 0x01},
                              {0x01, 0x02, 0x03, 0x01},
                              {0x01, 0x01, 0x02, 0x03},
                              {0x03, 0x01, 0x01, 0x02} };
  
  for(int i = 0; i < 4; i++)
  {
    for (int j = 0; j <4; j++)
    {
       matrizEntrada[j][i] = ((matrizGalois[i][j] & matrizEntrada[i][0]) ^ (matrizGalois[i][j] & matrizEntrada[i][1]) ^ (matrizGalois[i][j] & matrizEntrada[i][2]) ^ (matrizGalois[i][j] & matrizEntrada[i][3]));
    }
  }
  
  //return matrizEntrada;
  
}
