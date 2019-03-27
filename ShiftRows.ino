byte ShiftRows(byte state[]){
  //setEstado(rotaciona(state));

//rotaciona segunda linha da Matriz
   byte aux = state[4];
  state[4]=state[5];
  state[5]=state[6];
  state[6]=state[7];
  state[7]=state[4];

//rotaciona terceira linha da Matriz
  aux = state[8];
  state[8]=state[9];
  state[9]=state[10];
  state[10]=state[11];
  state[7]=state[8];

   aux = state[8];
  state[8]=state[9];
  state[9]=state[10];
  state[10]=state[11];
  state[7]=state[8];

//rotaciona quarta linha da Matriz
   aux = state[12];
  state[13]=state[14];
  state[14]=state[15];
  state[15]=state[16];
  state[16]=state[12];

   aux = state[12];
  state[13]=state[14];
  state[14]=state[15];
  state[15]=state[16];
  state[16]=state[12];

   aux = state[12];
  state[13]=state[14];
  state[14]=state[15];
  state[15]=state[16];
  state[16]=state[12];
  
  //return getEstado();
  return state;
}
