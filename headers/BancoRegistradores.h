#ifndef BANCOREGISTRADORES_H
#define BANCOREGISTRADORES_H

#include<string>
#include<string.h>
#include<vector>
#include<fstream>

using namespace std;

class BancoRegistradores {
  private:
    vector<int> registradores;

  public:
    BancoRegistradores();
    ~BancoRegistradores();

    int getValorDoReg(int reg);
    void setValorDoReg(int reg, int valor);
};

#endif

