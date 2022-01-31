#include<iostream>
#include "../headers/Mips.h"

#include"../headers/Instrucao.h"

#define ZERO = 0;

//? Cosntrutor e Destrutor
Mips::Mips(int isLeitura) {
  if(isLeitura == 1) this->isLeitura = true;
  else this->isLeitura = false;
}

Mips::~Mips() {}

void Mips::inicia() {
  reset();

  if(this->isLeitura) iniciaComLeitura();
  else iniciaSemLeitura();

}

void Mips::iniciaComLeitura() {
  string caminhoArquivo, linha;
  int comando;
  caminhoArquivo = "./comandos.txt";
  // cout << "\nDigite o caminho a partir da pasta atual para o arquivo a ser lido\n";
  // cin >> caminhoArquivo;

  ifstream arquivo;
  arquivo.open(caminhoArquivo);

  if(!arquivo) {
    cout << "\nArquivo não foi aberto corretamente!\n";
    return;
  }

  vector<int> row;
  while(getline(arquivo, linha)) {
    for (int i = 0; i < linha.size(); i++){
      comando = linha[i];
      if(comando == 48){   // = 0
        row.push_back(0);
      
      }else {
        if(comando == 49){
          row.push_back(1);
        }else{
          cout << "Foi inserido no codigo das instrucoes valores diferentes de binario(0 ou 1)" << endl;
          return;
        }
      }
      
    }
    cout << row.size()<<endl; 
    if (row.size() != 32){
          cout << "Foi inserido menos de 32 caracteres na instrucao.O programa nao pode ser executado!" << endl;
          return;
    }
    instrucoes.push_back(row);
    row.clear();  
    
  }
}

void Mips::iniciaSemLeitura() {
  string instrucao;
  int comando;
  cout << "\nDigite a instrução: " << endl;   
  cin >> instrucao; 

  vector<int> row;

  for (int i = 0; i < instrucao.size(); i++){
    comando = instrucao[i];
    if(comando == 48){   // = 0
        row.push_back(0);
      
    }else {
      if(comando == 49){
        row.push_back(1);
      }else{
          cout << "Foi inserido no codigo das instrucoes valores diferentes de binario(0 ou 1)" << endl;
          return;
        }
      }

    
  }
  cout << row.size()<<endl; 
    if (row.size() != 32){
      cout << "Foi inserido menos de 32 caracteres na instrucao.O programa nao pode ser executado!" << endl;
      return;
    }
    instrucoes.push_back(row);

  MemInstrucoes* memoriaInstrucoes = new MemInstrucoes();
  for(int i = 0; i < instrucoes.size(); i++) {
    Instrucao* instrucao = new Instrucao(instrucoes[i]);
    instrucao->getInstrucao();
    
    memoriaInstrucoes->seqInstrucoes.push_back(instrucao);
    
    delete instrucao;
  }
}


//? Getters e Setters
long long int Mips::getInstrucao() {
  return this->instrucao;
}

void Mips::reset() {
  cout << "\nLimpando memória\n";
  
  // Limpar memória/registradores
  
  cout << "\nMemória Limpa\n";
}

