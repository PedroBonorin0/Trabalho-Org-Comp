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

int Instrucao::getInstrucao() {
  return this->instrucao;
}

void Instrucao::setInstrucao(vector<int> comando) {
  int opcode = converteBinParaDec(getOpcode(comando));

  if(opcode == 0) setTipoInstrucao('R');

  if(opcode == 4) {
    setTipoInstrucao('I');
    this->instrucao = BEQ;
  } 

  if(opcode == 5) {
    setTipoInstrucao('I');
    this->instrucao = BNE;
  } 

  if(opcode == 8) {
    setTipoInstrucao('I');
    this->instrucao = ADDI;
  } 

  if(opcode == 35) {
    setTipoInstrucao('I');
    this->instrucao = LW;
  } 

  if(opcode == 43) {
    setTipoInstrucao('I');
    this->instrucao = SW;
  }

  if(opcode == 2) {
    setTipoInstrucao('J');
    this->instrucao = J;
  }

  if(opcode == 3) {
    setTipoInstrucao('J');
    this->instrucao = JAL;
  }
  
  if(getTipoInstrucao() == 'R') {
    int funcao = converteBinParaDec(getFunct(comando));

    if(funcao == 0) this->instrucao = SLL;
    if(funcao == 8) this->instrucao = JR;
    if(funcao == 32) this->instrucao = ADD;
    if(funcao == 34) this->instrucao = SUB;
    if(funcao == 36) this->instrucao = AND;
    if(funcao == 37) this->instrucao = OR;
    if(funcao == 42) this->instrucao = SLT;
  }

}

int Instrucao::converteBinParaDec(int binario) {
   int decimal = 0;

  for(int i = 0; binario > 0; i++) {
    decimal = decimal + pow(2, i) * (binario % 10);
    binario = binario / 10;
  }
  
  return decimal;
}

int Instrucao::getOpcode(vector<int> comando) {
  string digitos = "";

  for(int i = 0; i < 6; i++) {
    digitos += to_string(comando[i]);
  }

  return stoi(digitos);
}

int Instrucao::getFunct(vector<int> comando) {
  string digitos = "";

  for(int i = 26; i < 32; i++) {
    digitos += to_string(comando[i]);
  }

  return stoi(digitos);
}

void Instrucao::setTipoInstrucao(char tipo) {
  this->tipoInstrucao = tipo;
}

char Instrucao::getTipoInstrucao() {
  return this->tipoInstrucao;
}

