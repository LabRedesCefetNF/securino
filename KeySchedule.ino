byte subchaves[11][16];
byte vettemp_key[16];

void KeySchedule(byte key[]){
 //chave de criptografia armazenada na linha 0 da matriz de subchaves
  for(int i =0; i<16; i++){
    subchaves[0][i]=key[i];
 }
 genSubkeys();
}



void genSubkeys(){

  //OBS: NESTA FUNCAO VCS DEVEM COLOCAR O PROCESSO DE GERACAO DE SUBCHAVES...
  //CADA UMA DAS SUBCHAVES GERADAS DEVE SER ARMAZENADA NA MATRIZ subchaves
  //REVISE O PROCESSO NO VIDEO DE FUNCIONAMENTO DO RIJNDAEL
  
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
}
