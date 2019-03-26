byte* ShiftRows(byte state[]){
  setEstado(rotaciona(state));
  return getEstado();
}
