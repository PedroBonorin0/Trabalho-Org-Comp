#ifndef MIPS_H
#define MIPS_H

#include<string>
#include<string.h>
#include<vector>
#include<fstream>

using namespace std;

class Mips {
  private:
    long long int instrucao;
    bool isLeitura;
    vector<int> instrucoes;

  public:
    Mips(int isLeitura);
    ~Mips();

    //? Getters e Setters
    long long int getInstrucao();

    void reset();

    long long int leInstrucao();

    void inicia();
    void iniciaComLeitura();
    void iniciaSemLeitura();
};  

#endif
