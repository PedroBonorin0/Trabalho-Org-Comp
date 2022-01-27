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
  string caminhoArquivo, linha;
  int comando;

  cout << "\nDigite o caminho a partir da pasta atual para o arquivo a ser lido\n";
  cin >> caminhoArquivo;

  ifstream arq;
  arq.open(caminhoArquivo);

  if(!arq.is_open()) {
    cout << "\nArquivo não foi aberto corretamente!\n";
    return;
  }

  while(getline(arq, linha)) {
    comando = stoi(linha);
    this->instrucoes.push_back(comando);
  }

}

void Mips::iniciaSemLeitura() {
    int instrucao = leInstrucao();
}


//? Getters e Setters
int Mips::getInstrucao() {
  return this->instrucao;
}

void Mips::reset() {
  cout << "\nLimpando memória\n";
  
  // Limpar memória/registradores
  
  cout << "\nMemória Limpa\n";
}

int Mips::leInstrucao() {
  int instrucaoAtual = 0;

  cout << "\nDigite a instrução: " << endl;

  cin >> instrucaoAtual;

  return instrucaoAtual;
}