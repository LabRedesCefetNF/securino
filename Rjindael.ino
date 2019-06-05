void enc(byte plainText[][4], byte chave[][4])
{
  //PRIMEIRO ROUND
  AddRoundKey(plainText, chave);
  Serial.println(F("After First AddRoundKey: "));
  imprime(plainText);

  //DEMAIS ROUNDS
  for(int i=1; i<10; i++)
  {
    subBytes(plainText);
   Serial.println(F("After SubBytes: "));
   imprime(plainText);
    
    ShiftRows(plainText);
    Serial.println(F("After ShitfRows: "));
    imprime(plainText);
    
    MixColumns(plainText);
   Serial.println(F("After MixColumns: "));
   imprime(plainText);
    
    KeySchedule(chave);
    
    AddRoundKey(plainText, chave);
    Serial.println(F("After AddRoundKey: "));
    imprime(plainText);
  }
  //ULTIMO ROUND
  subBytes(plainText);
  Serial.println(F("Last SubBytes: "));
  imprime(plainText);
  
  ShiftRows(plainText);
  Serial.println(F("Last ShiftRows: "));
  imprime(plainText);
  
  //KeySchedule(chave);
  
  AddRoundKey(plainText, chave);
  Serial.println(F("Last AddRoundKey: "));
  imprime(plainText);
}

void dec(byte plainText[][4], byte chave[][4])
{
  //PRIMEIRO ROUND
  KeySchedule(chave, 11);
  AddRoundKey(plainText, chave);
  Serial.println(F("After First AddRoundKey: "));
  imprime(plainText);

  //DEMAIS ROUNDS
  for(int i=10; i>1; i--)
  {  
    invShiftRows(plainText);
    Serial.println(F("After InvShitfRows: "));
    imprime(plainText);

    invSubBytes(plainText);
    Serial.println(F("After InvSubBytes: "));
    imprime(plainText);
    
    KeySchedule(chave, i);
    
    AddRoundKey(plainText, chave);
    Serial.println(F("After AddRoundKey: "));
    imprime(plainText);

    MixColumnsInversa(plainText);
    Serial.println(F("After InvMixColumns: "));
    imprime(plainText);
  }
  //ULTIMO ROUND
    invShiftRows(plainText);
    Serial.println(F("After Last InvShitfRows: "));
    imprime(plainText);

    invSubBytes(plainText);
    Serial.println(F("After Last InvSubBytes: "));
    imprime(plainText);
    
    KeySchedule(chave, 1);
    
    AddRoundKey(plainText, chave);
    Serial.println(F("After Last AddRoundKey: "));
    imprime(plainText);
}

void imprime(byte texto[][4])
{
  for(int i=0; i < 4; i++)
  {
    for(int j=0; j < 4; j++)
    {
      Serial.print(F("\t"));
      Serial.print(texto[i][j], HEX);
    }
    Serial.println();
  }
  Serial.println();  
}
