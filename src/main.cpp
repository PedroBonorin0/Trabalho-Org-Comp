#include<iostream>
#include<string>
#include<string.h>
#include "../headers/Mips.h"

using namespace std;

int main(int argc, char const *argv[]) {
  
  cout << "\nPROGRAMA INICIADO" << endl;

  int leitura = 1;

  do{
    // cout << "\nDigite: " << endl;
    // cout << "1 - Leitura de arquivo;" << endl;
    // cout << "2 - Digitação de comandos;" << endl;

    // cin >> leitura;

    if(leitura != 1 && leitura != 2)
      cout << "\nValor inválido..." << endl;

  } while (leitura != 1 && leitura != 2);

  Mips* m = new Mips(leitura);

  m->inicia();

  delete m;


}







