#ifndef MEMINSTRUCOES_H
#define MEMINSTRUCOES_H

#include<string>
#include<string.h>
#include<vector>
#include<fstream>

#include"../headers/Instrucao.h"

using namespace std;

class MemInstrucoes {
  private:
    int pc;

  public:
    vector<vector<int>> seqInstrucoes;

    MemInstrucoes() {this->pc = 0;};
    ~MemInstrucoes();

    void somaPC() {this->pc += 4;};
};  

#endif
