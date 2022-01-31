#ifndef INSTRUCAO_H
#define INSTRUCAO_H

#include<string>
#include<string.h>
#include<vector>
#include<fstream>

using namespace std;

/**
 * INSTRUCOES: 
 * 1 - ADD
 * 2 - SUB
 * 3 - AND
 * 4 - OR
 * 5 - SLT
 * 6 - SLL
 * 7 - ADDI
 * 8 - LW
 * 9 - SW
 * 10 - BEQ
 * 11 - BNE
 * 12 - J
 * 13 - JR
 * 14 - JAL
*/

class Instrucao {
  private:
    int instrucao; //Lista de valores comentado acima
    int reg1, reg2, re3;
    bool isImeddiate;
    char tipoInstrucao;

  public:
    Instrucao(vector<int> instrucao);
    ~Instrucao();
    
    int getInstrucao();
    void setInstrucao(vector<int> comando);

    char getTipoInstrucao();
    void setTipoInstrucao(char tipo);

    int getOpcode(vector<int> comando);
    int getFunct(vector<int> comando);

    int converteBinParaDec(int digitos);
};  

#endif
