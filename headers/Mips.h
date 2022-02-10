#ifndef MIPS_H
#define MIPS_H

#include<string>
#include<string.h>
#include<vector>
#include<fstream>

#include"../headers/MemInstrucoes.h"
#include"../headers/BancoRegistradores.h"

using namespace std;

class Mips {
  private:
    bool isLeitura;
    vector<vector<int>> instrucoes;

  public:
    Mips(int isLeitura);
    ~Mips();

    //? Getters e Setters
    long long int getInstrucao();

    void reset(BancoRegistradores* regs);

    long long int leInstrucao();

    void inicia();
    void iniciaComLeitura();
    void iniciaSemLeitura();

    void iniciaSimulacao(MemInstrucoes& memoria);

    void impressao(int pc, vector<string> estados, int a);
};  

#endif
