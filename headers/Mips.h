#ifndef MIPS_H
#define MIPS_H

using namespace std;

class Mips {
  private:
    long int instrucao;
    bool isLeitura;

  public:
    Mips(int isLeitura);
    ~Mips();

    //? Getters e Setters
    char getInstrucao();

    void reset();

    char leInstrucao();

    void inicia();
    void iniciaComLeitura();
    void iniciaSemLeitura();
};  

#endif
