byte* AddRoundKey(byte state[], byte roundkey[]){
  setEstado(rotaciona(state));
  return getEstado();
}
