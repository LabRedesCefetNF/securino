byte* AddRoundKey(byte state[][4], byte roundkey[][4]){
  for (int i = 0; i < 4; i++)
  {
    for(int j=0; j < 4; j++)
    {
      state[i][j] ^= roundkey[i][j];     
    }
  }
}
