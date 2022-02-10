#ifndef MEMORIA_H
#define MEMORIA_H

#include<string>
#include<string.h>
#include<vector>
#include<fstream>
#include<iostream>

using namespace std;

class Memoria {
  private:
    vector<int> memoria;

  public:
    Memoria();
    ~Memoria();

    int getValorDaMemoria(int endereco);
    void escreveNaPosicao(int posicao, int valor);
};

#endif
