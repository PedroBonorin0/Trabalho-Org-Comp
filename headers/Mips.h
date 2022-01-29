#ifndef MIPS_H
#define MIPS_H

#include<string>
#include<string.h>
#include<vector>
#include<fstream>

using namespace std;

class Mips {
  private:
    int instrucao;
    bool isLeitura;
    vector< vector<int> > instrucoes;

  public:
    Mips(int isLeitura);
    ~Mips();

    //? Getters e Setters
    int getInstrucao();

    void reset();

    int leInstrucao();

    void inicia();
    void iniciaComLeitura();
    void iniciaSemLeitura();
};  

#endif
