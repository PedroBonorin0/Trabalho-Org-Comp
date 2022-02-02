#ifndef MEMINSTRUCOES_H
#define MEMINSTRUCOES_H

#include<string>
#include<string.h>
#include<vector>
#include<fstream>

using namespace std;

class MemInstrucoes {
  private:
    int pc;

  public:
    vector<vector<int> > seqInstrucoes;
    vector<string> seqInstrucoesString;

    MemInstrucoes();
    ~MemInstrucoes() {};

    void somaPC() {this->pc += 4;};
    void subPC() {if(this->pc > 0) this->pc -= 4;};

    int getPC() {return this->pc;};

    void setInstrucoesString();
    
    string getProximaInstrucao();
};  

#endif
