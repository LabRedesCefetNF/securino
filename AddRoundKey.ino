byte* AddRoundKey(byte state[], byte roundkey[]){
  //setEstado(rotaciona(state));
  //return getEstado();
  for (int i = 0; i < 16; i++)
    state[i] ^= round_key[i];
  }
}
