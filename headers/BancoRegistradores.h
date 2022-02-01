#ifndef BANCOREGISTRADORES_H
#define BANCOREGISTRADORES_H

#include<string>
#include<string.h>
#include<vector>
#include<fstream>

using namespace std;

class BancoRegistradores {
  private:
    vector<int> instrucao;
    char tipoInstrucao;
    vector<int> registradores;
    vector<int> instrucaoFinal;

  public:
    BancoRegistradores();
    ~BancoRegistradores();

    void setInstrucaoFinal(vector<int> instrucao);
    vector<int> getInstrucaoFinal();

    int getValorDoReg(int reg);
    void setValorDoReg(int reg, int valor);

    void resetRegs();
    void setInstrucao(vector<int> comando);

    char getTipoInstrucao();
    void setTipoInstrucao(char tipo);

    int getOpcode(vector<int> comando);

    int converteBinParaDec(string digitos);

    void setCodesR(vector<int> comando);
    void setCodesI(vector<int> comando);
    void setCodesJ(vector<int> comando);
};

#endif

