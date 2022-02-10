#include"../headers/BancoRegistradores.h"
#include<string>
#include<string.h>
#include<math.h>

// Instruções
#define ADD 100
#define SUB 200
#define AND 300
#define OR 400
#define SLT 500
#define SLL 600
#define ADDI 700
#define LW 800
#define SW 900
#define BEQ 1000
#define BNE 1100
#define J 1200
#define JR 1300
#define JAL 1400

// Registrador ZERO
#define ZERO 0

// retorno de funcoes
#define V0 2
#define V1 3

// argumentos
#define A0 4
#define A1 5
#define A2 6
#define A3 7

// Temporarios
#define T0 8
#define T1 9
#define T2 10
#define T3 11
#define T4 12
#define T5 13
#define T6 14
#define T7 15
#define T8 24
#define T9 25

// Temporarios Salvos
#define S0 16
#define S1 17
#define S2 18
#define S3 19
#define S4 20
#define S5 21
#define S6 22
#define S7 23

// Ponteiro Global
#define GP 28

// Ponteiro para pilha
#define SP 29

// Endereço de retorno
#define RA 31


BancoRegistradores::BancoRegistradores() {
  resetRegs();
}

BancoRegistradores::~BancoRegistradores() {

}

int BancoRegistradores::getValorDoReg(int reg) {
  return this->registradores[reg];
}

void BancoRegistradores::setValorDoReg(int reg, int valor) {
  this->registradores[reg] = valor;
}

void BancoRegistradores::resetRegs() {
  for(int i = 0; i < 32; i++) {
    if(i == 1 || i == 26 || i == 27 || i == 30) this->registradores.push_back(-1);
    else this->registradores.push_back(0);
  }
}

void BancoRegistradores::setInstrucao(vector<int> comando) {
  this->instrucaoFinal.resize(1);
  int opcode = getOpcode(comando);

  if(opcode == 0) setTipoInstrucao('R');

  if(opcode == 4) {
    setTipoInstrucao('I');
    this->instrucaoFinal[0] = BEQ;
  } 

  if(opcode == 5) {
    setTipoInstrucao('I');
    this->instrucaoFinal[0] = BNE;
  } 

  if(opcode == 8) {
    setTipoInstrucao('I');
    this->instrucaoFinal[0] = ADDI;
  } 

  if(opcode == 35) {
    setTipoInstrucao('I');
    this->instrucaoFinal[0] = LW;
  } 

  if(opcode == 43) {
    setTipoInstrucao('I');
    this->instrucaoFinal[0] = SW;
  }

  if(opcode == 2) {
    setTipoInstrucao('J');
    this->instrucaoFinal[0] = J;
  }

  if(opcode == 3) {
    setTipoInstrucao('J');
    this->instrucaoFinal[0] = JAL;
  }

  if(getTipoInstrucao() == 'R') setCodesR(comando);
  if(getTipoInstrucao() == 'I') setCodesI(comando);
  if(getTipoInstrucao() == 'J') setCodesJ(comando);

}

int BancoRegistradores::converteBinParaDec(string binario) {
  unsigned long decimal = 0;
  int tam, i = 0;

  tam = binario.size();
  while(tam--) {
    if( binario[tam] == '0' || binario[tam] == '1' ) 
      decimal = decimal + pow(2, i++) * (binario[tam] - '0');
  }

  return (int)decimal;
}

int BancoRegistradores::getOpcode(vector<int> comando) {
  string digitos = "";

  for(int i = 0; i < 6; i++) {
    digitos += to_string(comando[i]);
  }
  
  return converteBinParaDec(digitos);
}

int BancoRegistradores::getFunct(string comando) {
  string digitos = "";

  for(int i = 26; i < 32; i++) {
    digitos += comando[i];
  }
  
  switch(converteBinParaDec(digitos)) {
    case 0:
      return SLL;
    case 8:
      return JR;
    case 32:
      return ADD;
    case 34:
      return SUB;
    case 36:
      return AND;
    case 37:
      return OR;
    case 42:
      return SLT;
  }
}


void BancoRegistradores::setCodesR(vector<int> comando) {
  this->instrucaoFinal.resize(6);
  this->instrucaoParaALU.resize(6);
  this->instrucaoFinal[0] = 0;
  
  string digitos = "";
  int i = 6;

  while(i < 11) { // RS
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucaoFinal[1] = converteBinParaDec(digitos);
  digitos = "";

  while(i < 16) { // RT
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucaoFinal[2] = converteBinParaDec(digitos);
  digitos = "";

  while(i < 21) { // RD
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucaoFinal[3] = converteBinParaDec(digitos);
  digitos = "";

  while(i < 26) { // SHAMT
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucaoFinal[4] = converteBinParaDec(digitos);
  digitos = "";

  while(i < 32) { // FUNCT
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucaoFinal[5] = getFunct(digitos);
  digitos = "";

  this->instrucaoParaALU[0] = this->instrucaoFinal[0];
  this->instrucaoParaALU[1] = this->registradores[this->instrucaoFinal[1]];
  this->instrucaoParaALU[2]= this->registradores[this->instrucaoFinal[2]];
  this->instrucaoParaALU[3]= this->instrucaoFinal[3];
  this->instrucaoParaALU[4]= this->registradores[this->instrucaoFinal[4]];
  this->instrucaoParaALU[5] = this->instrucaoFinal[5];
}

void BancoRegistradores::setCodesI(vector<int> comando) {
  this->instrucaoFinal.resize(4);
  this->instrucaoParaALU.resize(4);
  string digitos = "";
  int i = 6;

  while(i < 11) { // RS
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucaoFinal[1] = converteBinParaDec(digitos);
  digitos = "";
  
  while(i < 16) { // RT
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucaoFinal[2] = converteBinParaDec(digitos);
  digitos = "";

  while(i < 32) { // IMMEDIATE
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucaoFinal[3] = converteBinParaDec(digitos);
  digitos = "";

  this->instrucaoParaALU[0] = this->instrucaoFinal[0];
  this->instrucaoParaALU[1] = this->registradores[this->instrucaoFinal[1]];
  this->instrucaoParaALU[2]= this->registradores[this->instrucaoFinal[2]];
  this->instrucaoParaALU[3]= this->instrucaoFinal[3];
  
}

void BancoRegistradores::setCodesJ(vector<int> comando) {
  this->instrucaoFinal.resize(2);
  this->instrucaoParaALU.resize(2);
  string digitos = "";
  int i = 6;

  while(i < 32) { // Target
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucaoFinal[1] = converteBinParaDec(digitos);
  digitos = "";
  
  this->instrucaoParaALU[0] = this->instrucaoFinal[0];
  this->instrucaoParaALU[1] = this->instrucaoFinal[1];
}

void BancoRegistradores::setTipoInstrucao(char tipo) {
  this->tipoInstrucao = tipo;
}

char BancoRegistradores::getTipoInstrucao() {
  return this->tipoInstrucao;
}

vector<int> BancoRegistradores::getInstrucaoParaALU() {
  return this->instrucaoParaALU;
}

