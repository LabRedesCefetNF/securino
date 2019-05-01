/*byte tempteste[16];

void exibeVetor(String txt, byte x[]){
      Serial.print(txt);
for (int i = 0; i < 16; i++) {
    Serial.print(x[i],HEX);
    Serial.print(" ");
  }
  Serial.println();
}

void exibeSubchaves(){
  String txt;
  for(int i=0;i<12;i++){
    txt = "subKey "+String(i)+" ";
    exibeVetor(txt,getSubkey(i));
  }
  Serial.println();
}

byte* rotaciona(byte data[]){
  int x;
  for (int i = 0; i < 16; i++) {
    x=(i+1) % 16;
    tempteste[i] = data[x];
  }
  //exibeVetor("rot: ",tempteste);
  return tempteste;
}

void exibeVetorrodada(String txt, int i, byte x[]){
  String strx = txt+" "+String(i)+":";
  exibeVetor(strx,x);

}

void espacovazio(){
    Serial.println();
    Serial.println();
    Serial.println();
}*/
