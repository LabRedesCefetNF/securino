void InvKeySchedule(byte chave[][4], int rodada){  
  
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      chave[i][j] = keyCopia[i][j];
    }
  }
      
  for(int i=1; i<=rodada; i++)
  {
      KeySchedule(chave, i);
  }
}
