byte* SubBytes(byte state[]){
  setEstado(rotaciona(state));
  return getEstado();
}
