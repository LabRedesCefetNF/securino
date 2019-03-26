byte* MixColumns(byte state[]){
  setEstado(rotaciona(state));
  return getEstado();
}




/*
byte MixColumns(byte matrizEntrada[][4])
{
  byte matrizResultante[4][4];
  byte matrizGalois[4][4] = { {B00010, B00011, B00001, B00001},
                              {B00001, B00010, B00011, B00001},
                              {B00001, B00001, B00010, B00011},
                              {B00011, B00001, B00001, B00010} };
  
  for(int i = 0; i < 4; i++)
  {
    for (int j = 0; j <4; j++)
    {
       matrizResultante[j][i] = (matrizGalois[i][j] & matrizEntrada[i][0]) ^ (matrizGalois[i][j] & matrizEntrada[i][1]) ^
                                (matrizGalois[i][j] & matrizEntrada[i][2]) ^ (matrizGalois[i][j] & matrizEntrada[i][3]);
    }
  }
  
  return matrizResultante;
}

//https://forum.arduino.cc/index.php?topic=220385.0
//https://www.gta.ufrj.br/grad/10_1/aes/index_files/Page588.htm
*/
