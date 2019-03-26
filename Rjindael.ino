 byte estado[16];


void enc(byte data[], byte key[]){
exibeVetor("estado INICIAL: ", data);
exibeVetor("chave INICIAL: ", key); 
espacovazio();
  
//EXPANSÃO DE CHAVES
  KeySchedule(key);
espacovazio();
  
//1ª RODADA
setEstado(AddRoundKey(data,getSubkey(0)));
exibeVetor("1ª Rodada: ", getEstado());

espacovazio();
//LOOP
for(int i=1;i<10;i++){
  setEstado(SubBytes(getEstado()));
    exibeVetorrodada("afterSubBytes",i, getEstado());
  setEstado(ShiftRows(getEstado()));
    exibeVetorrodada("afterShiftRows",i, getEstado());
  setEstado(MixColumns(getEstado()));
    exibeVetorrodada("afterMixColumns",i, getEstado());
  setEstado(AddRoundKey(getEstado(),getSubkey(i+1)));
   exibeVetorrodada("afterAddRoundKey",i, getEstado());
   espacovazio();
}


// Rodada Final
  setEstado(SubBytes(getEstado()));
  exibeVetor("last SubBytes: ", getEstado());
  setEstado(ShiftRows(getEstado()));
  exibeVetor("last ShiftRows: ", getEstado());
  setEstado(AddRoundKey(getEstado(),getSubkey(10)));
  exibeVetor("last AddRoundKey: ", getEstado());
  
  espacovazio();
  
  exibeVetor("FINAL: ", getEstado());


}

String dec(String data, String key){
  return data;
}



void setEstado(byte x[]){
  for(int i=0;i<16;i++){
    estado[i]=x[i];
  }
}

byte* getEstado(){
  return estado;
}
