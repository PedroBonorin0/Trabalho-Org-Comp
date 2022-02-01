#include"../headers/BancoRegistradores.h"
#include<string>
#include<string.h>

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
#define S3 18
#define S4 19
#define S5 20
#define S6 21
#define S7 22
#define S8 23

// Ponteiro Global
#define GP 28

// Ponteiro para pilha
#define SP 29

// Endereço de retorno
#define RA 31


BancoRegistradores::BancoRegistradores() {
  for(int i = 0; i < 32; i++) {
    if(i == 1 || i == 26 || i == 27 || i == 30) this->registradores.push_back(-1);
    else this->registradores.push_back(0);
  }
}

BancoRegistradores::~BancoRegistradores() {

}

int BancoRegistradores::getValorDoReg(int reg) {
  return this->registradores[reg];
}

void BancoRegistradores::setValorDoReg(int reg, int valor) {
  this->registradores[reg] = valor;
}