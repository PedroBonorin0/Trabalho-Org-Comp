#ifndef BANCOREGISTRADORES_H
#define BANCOREGISTRADORES_H

#include<string>
#include<string.h>
#include<vector>
#include<fstream>

using namespace std;

class BancoRegistradores {
  private:
    char tipoInstrucao;
    string instrucao;
    vector<int> instrucaoParaALU;
    vector<int> instrucaoFinal;

  public:
    vector<int> registradores;
    
    BancoRegistradores();
    ~BancoRegistradores();

    int getValorDoReg(int reg);
    void setValorDoReg(int reg, int valor);

    void resetRegs();
    void setInstrucao(vector<int> instrucao);

    char getTipoInstrucao();
    void setTipoInstrucao(char tipo);

    int getOpcode(vector<int> comando);
    int getFunct(string comando);

    int converteBinParaDec(string digitos);

    void setCodesR(vector<int> comando);
    void setCodesI(vector<int> comando);
    void setCodesJ(vector<int> comando);

    vector<int> getInstrucaoParaALU();
};

#endif

