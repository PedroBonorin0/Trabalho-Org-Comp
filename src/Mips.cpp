#include<iostream>
#include "../headers/Mips.h"

#include"../headers/BancoRegistradores.h"
#include"../headers/MemInstrucoes.h"
#include"../headers/Alu.h"

#define ZERO = 0;

//? Cosntrutor e Destrutor
Mips::Mips(int isLeitura) {
  if(isLeitura == 1) this->isLeitura = true;
  else this->isLeitura = false;
}

Mips::~Mips() {}

void Mips::inicia() {
  BancoRegistradores* bancoRegs = new BancoRegistradores();
  reset(bancoRegs);

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

  int linhas = 0;

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

    if (row.size() != 32){
          cout << "Foi inserido menos de 32 caracteres na instrucao.O programa nao pode ser executado!" << endl;
          return;
    }
    instrucoes.push_back(row);
    row.clear();

    linhas++;
  }
  
  MemInstrucoes* memoriaInstrucoes = new MemInstrucoes();
  for(int i = 0; i < linhas; i++) {
    memoriaInstrucoes->seqInstrucoes.push_back(instrucoes[i]);
    memoriaInstrucoes->somaPC();
  }
  memoriaInstrucoes->setInstrucoesString();
  iniciaSimulacao(*memoriaInstrucoes);
  delete memoriaInstrucoes;
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
      if(comando == 49) {
        row.push_back(1);
      } else {
        cout << "Foi inserido no codigo das instrucoes valores diferentes de binario(0 ou 1)" << endl;
        return;
      }
    }
  }

    if (row.size() != 32){
      cout << "Foi inserido menos de 32 caracteres na instrucao.O programa nao pode ser executado!" << endl;
      return;
    }
    instrucoes.push_back(row);
}

void Mips::reset(BancoRegistradores* regs) {
  cout << "\nLimpando memória\n";
  
  regs->resetRegs();
  
  cout << "\nMemória Limpa\n";
}

void Mips::iniciaSimulacao(MemInstrucoes& memInstrucoes) {
  cout << "\nIniciando simulação de Máquina MIPS\n";
  
  BancoRegistradores* bancoRegs = new BancoRegistradores();
  Alu* alu = new Alu();

  string ifAtual, idAtual, exeAtual, memAtual, wbAtual;
  int indiceIF = 0, indiceID = 0, indiceEXE = 0, indiceMEM = 0, indiceWB = 0;

  vector<string> estados;
  estados.resize(5);

  vector<int> regs;
  // string estadoIF;
  // string estadoID;
  // string estadoEXE;
  // string estadoMEM;
  // string estadoWB;

  for (int a = 0; a < memInstrucoes.seqInstrucoesString.size() + 4; a++){
    if(indiceWB <= -1) {
      estados[4] = "vazio";
    } else {

      
      estados[4] = estados[3];
    }

    if(indiceMEM <= -1) {
      estados[3] = "vazio";
    } else {


      estados[3] = estados[2];
    }

    if(indiceEXE <= -1) {
      estados[2] = "vazio";
    } else {
      
      estados[2] = estados[1];
    }

    if(indiceID <= -1) {
      estados[1] = "vazio";
    } else {
      bancoRegs->setInstrucao(this->instrucoes[a - 1]);
      alu->decode(bancoRegs->getInstrucaoParaALU(), bancoRegs->getTipoInstrucao());
      estados[1] = estados[0];
    }

    if(indiceIF >= memInstrucoes.seqInstrucoesString.size()) {
      estados[0] = "vazio";
    }

    ifAtual = memInstrucoes.getProximaInstrucao();
    estados[0] = ifAtual;

    
    cout << "PC = " << memInstrucoes.getPC() << "\n";
  //   cout << "Banco de Regs = \n";
    cout << "Instrucao no IF = " << estados[0] << "\n";
    cout << "Instrucao no ID = " << estados[1] <<  "\n";
    cout << "Instrucao no EXE = " << estados[2] <<  "\n";
    cout << "Instrucao no MEM = " << estados[3] <<  "\n";
    cout << "Instrucao no WB = " << estados[4] <<  "\n";

    indiceIF++;
    indiceID = indiceIF - 1;
    indiceEXE = indiceID - 1;
    indiceMEM = indiceEXE - 1;
    indiceWB = indiceMEM - 1;
  }
  
  delete bancoRegs;
}

