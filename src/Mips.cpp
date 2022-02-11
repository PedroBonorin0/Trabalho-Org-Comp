#include<iostream>
#include "../headers/Mips.h"

#include"../headers/BancoRegistradores.h"
#include"../headers/MemInstrucoes.h"
#include"../headers/Alu.h"
#include"../headers/Memoria.h"

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
  // cout << "\nDigite o caminho a partir da pasta atual para o arquivo a ser lido\n";
  // cin >> caminhoArquivo;
  caminhoArquivo = "./comandos.txt";

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
  bool sair = false;
  int positivo;


  while(!sair){
    cout << "\nDigite a instrução: " << endl;   
    cin  >> instrucao; 

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
            cout << "O programa sera reiniciado para a parte de leitura de instrucao via teclado!" << endl;
            return iniciaSemLeitura();
          }
        }
    }

    if (row.size() != 32){
      cout << "Foi inserido um valordiferente de 32 caracteres na instrucao. O programa nao pode ser executado!" << endl;
      cout << "O programa sera reiniciado para a parte de leitura de instrucao via teclado!" << endl;
      return iniciaSemLeitura();
    }
    instrucoes.push_back(row);
    
    positivo = 0 ;
    
    cout << " Deseja digitar mais uma instrucao?\n1->SIM\nQualquer outro comando sera tratado com NAO! " << endl;
    cin  >> positivo;  

    if(positivo == 1){
      positivo = 0;
      sair = false;    
    }else{
      positivo = 1;
      sair = true;
    }
    
  }

  MemInstrucoes* memoriaInstrucoes = new MemInstrucoes();
  
  memoriaInstrucoes->seqInstrucoes.push_back(instrucoes[0]);
  memoriaInstrucoes->somaPC();
  
  memoriaInstrucoes->setInstrucoesString();
  iniciaSimulacao(*memoriaInstrucoes);
  delete memoriaInstrucoes;
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
  Memoria* memoria = new Memoria();

  string ifAtual, idAtual, exeAtual, memAtual, wbAtual;
  int indiceIF = 0, indiceID = -1, indiceEXE = -2, indiceMEM = -3, indiceWB = -4;

  int retornoAlu;

  vector<string> estados;
  estados.resize(5);

  vector<int> regs;
  for (int a = 0; a < memInstrucoes.seqInstrucoesString.size() + 5; a++){
    // WB (Write Back): Escrita do resultado
    if(indiceWB < 0 || indiceWB >= memInstrucoes.seqInstrucoesString.size()) {
      estados[4] = "vazio";
    } else {
      if(bancoRegs->getInstrucaoParaALU()[0] == 800 || !bancoRegs->getTipoInstrucao() == 'R')
        estados[4] = "Não está ativo";
      else {
        bancoRegs->registradores[bancoRegs->getInstrucaoParaALU()[3]] = retornoAlu;
        estados[4] = "Escrevendo em um registrador";
      }
    }

    // MEM: Acesso à memória de dados
    if(indiceMEM < 0 || indiceMEM >= memInstrucoes.seqInstrucoesString.size()) {
      estados[3] = "vazio";
    } else {
      if(bancoRegs->getInstrucaoParaALU()[0] == 800) {
        memoria->getValorDaMemoria(retornoAlu);
        estados[3] = "Acesso de leitura da memória";
      }
      else if(bancoRegs->getInstrucaoParaALU()[0] == 900) {
        memoria->escreveNaPosicao(retornoAlu, bancoRegs->getInstrucaoParaALU()[2]);
        estados[3] = "Acesso de escrita na memória";
      }
      else
        estados[3] = "Não é acessada";
    }
    
    // EXE: Execução ou cálculo do endereço
    if(indiceEXE < 0 || indiceEXE >= memInstrucoes.seqInstrucoesString.size()) {
      estados[2] = "vazio";
    } else {
      retornoAlu = alu->decode(bancoRegs->registradores, bancoRegs->getInstrucaoParaALU(), bancoRegs->getTipoInstrucao());
      estados[2] = "Calculando instrução " + to_string(a - 1);
    }
    
    // ID : Decodificação de instruções e leitura de registradores
    if(indiceID < 0 || indiceID >= memInstrucoes.seqInstrucoesString.size()) {
      estados[1] = "vazio";
    } else {
      if(this->instrucoes[a - 1].size() == 32) {
        bancoRegs->setInstrucao(this->instrucoes[a - 1]);
        estados[1] = bancoRegs->getTipoInstrucao();
      }
    }
    
    // IF : Busca de instruções
    if(indiceIF >= memInstrucoes.seqInstrucoesString.size()) {
      estados[0] = "vazio";
    } else {
        ifAtual = memInstrucoes.getProximaInstrucao(a);
        estados[0] = ifAtual;
    }

    impressao(memInstrucoes.getPC(),estados, a, bancoRegs);
    
    indiceIF++;
    indiceID++;
    indiceEXE++;
    indiceMEM++;
    indiceWB++;
  }
  
  delete bancoRegs;
  cout << endl;
  cout << "---------------------------------------------------" <<endl;
  cout << "- Execução do simulador de Pipeline finalizadada! -" << endl;
  cout << "---------------------------------------------------" <<endl;
  cout << endl;
  cout << "--------------------------------------------------" <<endl;
  cout << "- Os mesmos valores que foram exibido no console -" << endl;
  cout << "-- tambem estão diponiveis no arquivo saida.txt --" << endl;
  cout << "--------------------------------------------------" <<endl;
}

void Mips::impressao(int pc, vector<string> estados, int a, BancoRegistradores* bancoRegs){
  ofstream arquivotxt("saida.txt",ios::app);

  if(a == 0) {
    cout << "\n====================INÍCIO DE EXECUÇÃO====================\n";
    arquivotxt << "\n====================INÍCIO DE EXECUÇÃO====================\n";
  }

  // IMPRESSAO DE CADA ETAPA 
  cout << "\n--------------------------------\n";
  cout << "PC = " << pc << "\n";
  cout << "Instrucao no IF => " << estados[0] << "\n";
  
  if(estados[1] == "vazio"){
    cout << "Instrucao no ID =>  " << estados[1] <<  "\n";
  }else{
    cout << "Instrucao no ID => tipo " << estados[1] <<  "\n";
  }
  cout << "Instrucao no EXE => " << estados[2] <<  "\n";
  cout << "Instrucao no MEM => " << estados[3] <<  "\n";
  cout << "Instrucao no WB => " << estados[4] <<  "\n";

  cout << "\nBanco de registradores: \n";
  for(int i = 0; i < bancoRegs->registradores.size(); i++) {
    if(i == 0) {
      cout << "Reg " << i << ": 0" << endl;
      continue;
    }
    if(bancoRegs->registradores[i] != -1)
      cout << "Reg " << i << ": " << bancoRegs->registradores[i] << endl;
    else 
      cout << "Reg " << i << " não utilizado" << endl;
  }

  // ESCRITA DE CADA ETAPA 

  arquivotxt << "\n--------------------------------\n";
  arquivotxt << "PC = " << pc << "\n";
  //   arquivotxt << "Banco de Regs = \n";
  arquivotxt << "Instrucao no IF => " << estados[0] << "\n";
  if(estados[1] == "vazio"){
    arquivotxt << "Instrucao no ID =>  " << estados[1] <<  "\n";
  }else{
    arquivotxt << "Instrucao no ID => tipo " << estados[1] <<  "\n";
  }
  arquivotxt << "Instrucao no EXE => " << estados[2] <<  "\n";
  arquivotxt << "Instrucao no MEM => " << estados[3] <<  "\n";
  arquivotxt << "Instrucao no WB => " << estados[4] <<  "\n";

  arquivotxt << "\nBanco de registradores: \n";
  for(int i = 0; i < bancoRegs->registradores.size(); i++) {
    if(i == 0) {
      arquivotxt << "Reg " << i << ": 0" << endl;
      continue;
    }
    if(bancoRegs->registradores[i] != -1)
      arquivotxt << "Reg " << i << ": " << bancoRegs->registradores[i] << endl;
    else 
      arquivotxt << "Reg " << i << " não utilizado" << endl;
  }

  arquivotxt.close();
}