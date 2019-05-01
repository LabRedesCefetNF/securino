void ShiftRows(byte state[][4]){
  
//rotaciona segunda linha da Matriz
  byte aux = state[1][0];
  state[1][0]=state[1][1];
  state[1][1]=state[1][2];
  state[1][2]=state[1][3];
  state[1][3]=aux;

//rotaciona terceira linha da Matriz
  aux = state[2][0];
  state[2][0]=state[2][1];
  state[2][1]=state[2][2];
  state[2][2]=state[2][3];
  state[2][3]=aux;

  aux = state[2][0];
  state[2][0]=state[2][1];
  state[2][1]=state[2][2];
  state[2][2]=state[2][3];
  state[2][3]=aux;

//rotaciona quarta linha da Matriz
  aux = state[3][0];
  state[3][0]=state[3][1];
  state[3][1]=state[3][2];
  state[3][2]=state[3][3];
  state[3][3]=aux;
  
  aux = state[3][0];
  state[3][0]=state[3][1];
  state[3][1]=state[3][2];
  state[3][2]=state[3][3];
  state[3][3]=aux;
  
  aux = state[3][0];
  state[3][0]=state[3][1];
  state[3][1]=state[3][2];
  state[3][2]=state[3][3];
  state[3][3]=aux;
  
  //return getEstado();
}

void invShiftRows(byte state [][4]){
  //rotaciona segunda linha da Matriz
  byte aux = state[1][3];
  state[1][3]=state[1][2];
  state[1][2]=state[1][1];
  state[1][1]=state[1][0];
  state[1][0]=aux;

  //rotaciona terceira linha da Matriz
  aux = state[2][3];
  state[2][3]=state[2][2];
  state[2][2]=state[2][1];
  state[2][1]=state[2][0];
  state[2][0]=aux;

  aux = state[2][3];
  state[2][3]=state[2][2];
  state[2][2]=state[2][1];
  state[2][1]=state[2][0];
  state[2][0]=aux;

  //rotaciona quarta linha da Matriz
  aux = state[3][3];
  state[3][3]=state[3][2];
  state[3][2]=state[3][1];
  state[3][1]=state[3][0];
  state[3][0]=aux;
  
  aux = state[3][3];
  state[3][3]=state[3][2];
  state[3][2]=state[3][1];
  state[3][1]=state[3][0];
  state[3][0]=aux;

  aux = state[3][3];
  state[3][3]=state[3][2];
  state[3][2]=state[3][1];
  state[3][1]=state[3][0];
  state[3][0]=aux;
}
