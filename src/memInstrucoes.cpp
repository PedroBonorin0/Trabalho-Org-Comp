#include<iostream>

#include"../headers/MemInstrucoes.h"

using namespace std;

MemInstrucoes::MemInstrucoes() {
  this->pc = 0;
}

string MemInstrucoes::getProximaInstrucao() {
  subPC();
  return seqInstrucoesString.at(0);
}

void MemInstrucoes::setInstrucoesString() {
  string comando = "";

  for(int i = 0; i < seqInstrucoes.size(); i++) {
    for(int j = 0; j < 32; j++)
      comando += to_string(seqInstrucoes[i][j]); 

    seqInstrucoesString.push_back(comando);
  } 
  
}