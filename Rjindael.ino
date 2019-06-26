void enc(byte plainText[][4], byte chave[][4])
{
  //PRIMEIRO ROUND
  AddRoundKey(plainText, chave);

  //DEMAIS ROUNDS
  for(int i=1; i<10; i++)
  {
    subBytes(plainText);
    
    ShiftRows(plainText);
    
    MixColumns(plainText);
    
    KeySchedule(chave, i);
    
    AddRoundKey(plainText, chave);
  }
  //ULTIMO ROUND
  subBytes(plainText);
  
  ShiftRows(plainText);
  
  KeySchedule(chave, 10);
  
  AddRoundKey(plainText, chave);
}
