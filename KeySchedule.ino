void KeySchedule(byte chave[][4], int round){  
  byte Rcon[10] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36};
  
  byte sub(byte valor);

  byte copia[4];
  byte matrizcopia[4][4];

  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      matrizcopia[i][j] = chave[i][j];
    }
  }

  for(int i=0; i<4; i++){    
      copia[i] = chave[i][3];      
  }


  byte aux = copia[0];
  copia[0] = copia[1];
  copia[1] = copia[2];
  copia[2] = copia[3];
  copia[3] = aux;

  for(int i=0; i<4; i++){
    copia[i] = sub(copia[i]);
  }
  
  /*if(round == 1){
     for(int i=0; i<4; i++){
      if(i==0){
        matrizcopia[i][0] = chave[i][0] ^ copia[i] ^ 0x01;  
      }else{
        matrizcopia[i][0] = chave[i][0] ^ copia[i] ^ 0x00;
      }
  }  
  }*/
  
   if(round < 9){
    for(int i=0; i<4; i++){
      if(i==0){
        matrizcopia[i][0] = chave[i][0] ^ copia[i] ^ Rcon[round -1];  
      }else{
        matrizcopia[i][0] = chave[i][0] ^ copia[i] ^ 0x00;
      }
  }  
   }else if(round == 9){
    for(int i=0; i<4; i++){
      if(i==0){
        matrizcopia[i][0] = chave[i][0] ^ copia[i] ^ 0x1b;  
      }else{
        matrizcopia[i][0] = chave[i][0] ^ copia[i] ^ 0x00;
      }
    }
   }else {
    for(int i=0; i<4; i++){
      if(i==0){
        matrizcopia[i][0] = chave[i][0] ^ copia[i] ^ 0x36;  
      }else{
        matrizcopia[i][0] = chave[i][0] ^ copia[i] ^ 0x00;
      }
   }}

  for(int i=1; i<4; i++){
    matrizcopia[0][i] = chave[0][i] ^ matrizcopia[0][i-1];
    matrizcopia[1][i] = chave[1][i] ^ matrizcopia[1][i-1];
    matrizcopia[2][i] = chave[2][i] ^ matrizcopia[2][i-1];
    matrizcopia[3][i] = chave[3][i] ^ matrizcopia[3][i-1];
  }
for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      chave[i][j] = matrizcopia[i][j];
    }
  }
   
}
