/*
  Securino.h - Security Library for Arduino.
    Version 1.0.0
  Created by  
        Rocha, IF
        Verly, PFS
        Schott, RI
        Lazarin, NM   nilson.lazarin@cefet-rj.br
  Released into the public domain.

*/

#ifndef Securino_h
#define Securino_h
#define quatro 4
#define dezesseis 16
#include "Arduino.h"

class Securino{
  public:
    Securino();
    byte *encript(String operacao, byte in[dezesseis], byte k[dezesseis] );
    byte *decript(String operacao, byte in[dezesseis], byte k[dezesseis] );
  private:
    byte plaintext[quatro][quatro];
    byte key[quatro][quatro];                 
    byte keyCopia[quatro][quatro];
    void setKey(byte x[dezesseis]);
    void setData(byte x[dezesseis]);
    byte *getData();
    void encAES128ecb(byte plainText[][quatro], byte chave[][quatro]);
    void decAES128ecb(byte plainText[][quatro], byte chave[][quatro]);
    byte* AddRoundKey(byte state[][quatro], byte roundkey[][quatro]);
    byte tableS(byte linha, byte coluna);
    byte tableInvS(byte linha, byte coluna);
    byte subX(byte valor);
    byte invSub(byte valor);
    void subBytes(byte state[][quatro]);
    void InvSubBytes(byte state[][quatro]);
    void SubBytesKey(byte chave[]);
    void ShiftRows(byte state[][quatro]);
    void invShiftRows(byte state [][quatro]);
    byte tableE(byte linha, byte coluna);
    byte tableL(byte linha, byte coluna);
    byte L(byte valor);
    byte E(byte valor);
    byte calculaLE(byte valor1, byte valor2);
    void MixColumns(byte matrizEntrada[][quatro]);
    void MixColumnsInversa(byte matrizResultante[][quatro]);
    void KeySchedule(byte chave[][quatro], int round);
    void InvKeySchedule(byte chave[][quatro], int rodada);
};

#endif
