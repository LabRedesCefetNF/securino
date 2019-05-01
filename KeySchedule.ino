byte subchaves[4][40];
byte vettemp_key[4][4];
int _Wi = 4;
int _ColunaRcon = 0;
byte SubBytesKey(byte c[]);

static const byte Rcon[4][10]  = {{0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36},
                                  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
                                  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
                                  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
                                  };

void KeySchedule(byte key[4][4]){
  int linha=4, coluna, i;
  
  
//subchaves recebe a chave original
if(_Wi == 4)
  {
     for(linha=0; linha<4 ; linha++){
    for(coluna=0;coluna<4; coluna++){
      subchaves[linha][coluna] = key[linha][coluna];     
    }    
  }
  }
  
  //RotWord
  byte rotword[4][1] = { {subchaves[1][_Wi-1]}, {subchaves[2][_Wi-1]}, {subchaves[3][_Wi-1]}, {subchaves[0][_Wi-1]} };
  //Passando da matriz rotword para o vetor chave 
  byte chave[4] = {rotword[0][0],rotword[1][0],rotword[2][0],rotword[3][0]};
  
  //SubByte na Coluna WI
  SubBytesKey(chave);

  //XOR
  for(linha=0; linha<4 ; linha++){      
      chave[linha] = subchaves[linha][_Wi-4] ^ chave[linha] ^ Rcon[linha][_ColunaRcon];
  }
  
  //incrementando Rcon
  _ColunaRcon++;

  //subchaves recebe Wi
   for(linha=0; linha<4 ; linha++){      
      subchaves[linha][_Wi] = chave[linha];
  }

  //incrementando wi
  _Wi++;

  // XOR Wi-4 ^ Wi-1
   i = 0;
   while(i<3){
     for(linha=0; linha<4 ; linha++){      
      subchaves[linha][_Wi] = subchaves[linha][_Wi-4] ^ subchaves[linha][_Wi-1];     
  }
  _Wi++;
  i++;  
  }

  
  //carregando vetemp_key
  for(linha=0; linha<4 ; linha++){
    for(coluna=0;coluna<4; coluna++){
      vettemp_key[linha][coluna]= subchaves[linha][_Wi-4+coluna];
    }
  }

  

  //imprimindo vetemp_key
 /* Serial.println("VTEMP_KEY");
      for(linha=0; linha<4 ; linha++){
    for(coluna=0;coluna<4; coluna++){
      Serial.print(vettemp_key[linha][coluna]);
      Serial.print(" "); 
    }
    Serial.println();
  }*/

   
  
 


 //chave de criptografia armazenada na linha 0 da matriz de subchaves
 /* for(int i =0; i<16; i++){
    subchaves[0][i]=key[i];
  }
 genSubkeys();*/
}


 

/*
void genSubkeys(){

 
  
  //INICIO DE CÓDIO ALEATORIO
  for(int i=1;i<12;i++){
    setSubKey(i,rotaciona(getSubkey(i-1)));
  }
  exibeSubchaves();
   /// FIM DE CONDIGO ALEATORIO
  

}



void setSubKey(int k, byte key[]){
  for(int i =0; i<16; i++){
    subchaves[k][i]=key[i];
 }
}

byte* getSubkey(int k){
  for(int i =0; i<16; i++){
    vettemp_key[i]=subchaves[k][i];
 }
 return vettemp_key;
}*/
