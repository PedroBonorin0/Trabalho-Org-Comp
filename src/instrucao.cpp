#include"../headers/Instrucao.h"
#include<math.h>
#include<string>
#include<string.h>

#define ADD 1
#define SUB 2
#define AND 3
#define OR 4
#define SLT 5
#define SLL 6
#define ADDI 7
#define LW 8
#define SW 9
#define BEQ 10
#define BNE 11
#define J 12
#define JR 13
#define JAL 14

Instrucao::Instrucao(vector<int> instrucao) {
  setInstrucao(instrucao);
}

Instrucao::~Instrucao() {

}

vector<int> Instrucao::getInstrucao() {
  return this->instrucao;
}

void Instrucao::setInstrucao(vector<int> comando) {
  this->instrucao.resize(1);
  int opcode = getOpcode(comando);

  if(opcode == 0) setTipoInstrucao('R');

  if(opcode == 4) {
    setTipoInstrucao('I');
    this->instrucao[0] = BEQ;
  } 

  if(opcode == 5) {
    setTipoInstrucao('I');
    this->instrucao[0] = BNE;
  } 

  if(opcode == 8) {
    setTipoInstrucao('I');
    this->instrucao[0] = ADDI;
  } 

  if(opcode == 35) {
    setTipoInstrucao('I');
    this->instrucao[0] = LW;
  } 

  if(opcode == 43) {
    setTipoInstrucao('I');
    this->instrucao[0] = SW;
  }

  if(opcode == 2) {
    setTipoInstrucao('J');
    this->instrucao[0] = J;
  }

  if(opcode == 3) {
    setTipoInstrucao('J');
    this->instrucao[0] = JAL;
  }

  if(getTipoInstrucao() == 'R') setCodesR(comando);
  if(getTipoInstrucao() == 'I') setCodesI(comando);
  if(getTipoInstrucao() == 'J') setCodesJ(comando);
    
}

int Instrucao::converteBinParaDec(string binario) {
  unsigned long decimal = 0;
  int tam, i = 0;

  tam = binario.size();
  while(tam--) {
    if( binario[tam] == '0' || binario[tam] == '1' ) 
      decimal = decimal + pow(2, i++) * (binario[tam] - '0');
  }

  return decimal;
}

int Instrucao::getOpcode(vector<int> comando) {
  string digitos = "";

  for(int i = 0; i < 6; i++) {
    digitos += to_string(comando[i]);
  }
  
  return converteBinParaDec(digitos);
}


void Instrucao::setCodesR(vector<int> comando) {
  this->instrucao.resize(6);
  this->instrucao[0] = 0;
  
  string digitos = "";
  int i = 6;

  while(i < 11) { // RS
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucao[1] = converteBinParaDec(digitos);
  digitos = "";

  while(i < 16) { // RT
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucao[2] = converteBinParaDec(digitos);
  digitos = "";

  while(i < 21) { // RD
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucao[3] = converteBinParaDec(digitos);
  digitos = "";

  while(i < 26) { // SHAMT
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucao[4] = converteBinParaDec(digitos);
  digitos = "";

  while(i < 32) { // FUNCT
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucao[5] = converteBinParaDec(digitos);
  digitos = "";

}

void Instrucao::setCodesI(vector<int> comando) {
  this->instrucao.resize(4);
  string digitos = "";
  int i = 6;

  while(i < 11) { // RS
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucao[1] = converteBinParaDec(digitos);
  digitos = "";
  
  while(i < 16) { // RT
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucao[2] = converteBinParaDec(digitos);
  digitos = "";

  while(i < 32) { // IMMEDIATE
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucao[3] = converteBinParaDec(digitos);
  digitos = "";

}

void Instrucao::setCodesJ(vector<int> comando) {
  this->instrucao.resize(2);
  string digitos = "";
  int i = 6;

  while(i < 32) { // Target
    digitos += to_string(comando[i]);
    i++;
  }
  this->instrucao[1] = converteBinParaDec(digitos);
  digitos = "";
  
}

void Instrucao::setTipoInstrucao(char tipo) {
  this->tipoInstrucao = tipo;
}

char Instrucao::getTipoInstrucao() {
  return this->tipoInstrucao;
}

