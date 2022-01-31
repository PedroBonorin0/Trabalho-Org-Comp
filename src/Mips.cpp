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
  long long int comando;

  cout << "\nDigite o caminho a partir da pasta atual para o arquivo a ser lido\n";
  cin >> caminhoArquivo;

  ifstream arq;
  arq.open(caminhoArquivo);

  if(!arq.is_open()) {
    cout << "\nArquivo não foi aberto corretamente!\n";
    return;
  }

  while(getline(arq, linha)) {
    comando = stol(linha);
    this->instrucoes.push_back(comando);
  }

}

void Mips::iniciaSemLeitura() {
  long long int instrucao = leInstrucao();

  cout << "\nInstrução digitada: " <<  to_string(instrucao) << endl;
}


//? Getters e Setters
long long int Mips::getInstrucao() {
  return this->instrucao;
}

void Mips::reset() {
  cout << "\nLimpando memória\n";
  
  // Limpar memória/registradores
  
  cout << "\nMemória Limpa\n";
}

long long int Mips::leInstrucao() {
  long long int instrucaoAtual = 0;

  cout << "\nDigite a instrução: " << endl;

  cin >> instrucaoAtual;

  return instrucaoAtual;
}