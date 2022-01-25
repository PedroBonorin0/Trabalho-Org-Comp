#include<iostream>
#include "../headers/Mips.h"

#define ZERO = 0;

//? Cosntrutor e Destrutor
Mips::Mips(int isLeitura) {
  if(isLeitura == 1) this->isLeitura = true;
  else this->isLeitura = false;
}

Mips::~Mips() {}

void Mips::inicia() {
  reset();

  if(this->isLeitura) iniciaComLeitura();
  else iniciaSemLeitura();
}

void Mips::iniciaComLeitura() {
  char path;
  cout << "\nDigite o caminho do arquivo a ser lido: " << endl;
  // Implementar
}

void Mips::iniciaSemLeitura() {
  int tam = 20;
  char* instrucoes = new char[tam];
  int escolha = 0;

  for(int i = 0; i < tam; i++) {
    instrucoes[i] = leInstrucao();

    if(instrucoes[i] == -1) break;
  }

  for(int i = 0; i < tam; i++) {
    cout << i << " - " << instrucoes[i] << endl;;
  }

  delete instrucoes;
}


//? Getters e Setters
char Mips::getInstrucao() {
  return this->instrucao;
}

void Mips::reset() {
  cout << "\nLimpando memória\n";
  
  // Limpar memória/registradores
  
  cout << "\nMemória Limpa\n";
}

char Mips::leInstrucao() {
  char instrucaoAtual;

  cout << "\nDigite a instrução: " << endl;

  // Ler instrucao;

  return instrucao;
}