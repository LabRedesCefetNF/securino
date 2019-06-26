void dec(byte plainText[][4], byte chave[][4])

{
  //PRIMEIRO ROUND
  InvKeySchedule(chave, 10);

  AddRoundKey(plainText, chave);

  //DEMAIS ROUNDS

  for(int i=9; i>=1; i--)

  {  

    invShiftRows(plainText);

    InvSubBytes(plainText);

    InvKeySchedule(chave, i);

    AddRoundKey(plainText, chave);

    MixColumnsInversa(plainText);

  }

  //ULTIMO ROUND

    invShiftRows(plainText);

    InvSubBytes(plainText);

    InvKeySchedule(chave, 0);

    AddRoundKey(plainText, chave);

}
