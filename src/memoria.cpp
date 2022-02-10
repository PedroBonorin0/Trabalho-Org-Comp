#include"../headers/Memoria.h"

Memoria::Memoria(){}

Memoria::~Memoria(){}

int Memoria::getValorDaMemoria(int posicao) {
  return this->memoria[posicao];
}

void Memoria::escreveNaPosicao(int posicao, int valor) {
  if(posicao >= this->memoria.size()) {
    this->memoria.resize(posicao + 1);
  }

  this->memoria[posicao] = valor;
}
