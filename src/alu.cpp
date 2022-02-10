#include<iostream>

#include"../headers/Alu.h"

// Instruções
#define ADD 100 // R
#define SUB 200 // R
#define AND 300 // R
#define OR 400 // R
#define SLT 500 // R
#define SLL 600 // R
#define JR 1300 // R

#define ADDI 700 // I
#define LW 800 // I
#define SW 900 // I
#define BEQ 1000 // I
#define BNE 1100 // I

#define J 1200 // J
#define JAL 1400 // J


Alu::Alu() {}

Alu::~Alu() {}

void Alu::decode(vector<int> comando, char tipo) {
  if(tipo == 'R') decodeTypeR(comando);
  if(tipo == 'I') decodeTypeI(comando);
  if(tipo == 'J') decodeTypeJ(comando);
}

// ADD, SUB, AND, OR, SLT, SLL
int  Alu::decodeTypeR(vector<int> comando){
    int rs = comando[1];
    int rt = comando[2];
    int rd = comando[3];
    int shamt = comando[4];
    int funct = comando[5];

    switch (funct)
    {
    case 100: //ADD
        return rs + rt; 
        break;
    case 200: //SUB
        return rs - rt; 
        break;
    case 300: //AND
        if(rs == 1 && rt == 1){
            return 1;
        }else{
            return 0;
        }
        break;
    case 400: //OR
        if(rs == 1 || rt == 1){
            return 1;
        }else{
            return 0;
        }
        break;
    case 500: //SLT
        if(rs < rt){
            return 1;
        }else{
            return 0;
        }
        break;
       
    case 600 : //SLL
        return rt + shamt;
        break;
        
    case 1300: //JR

        break;

    default:
        break;
    }
}

// ADDI, LW, SW, BEQ, BNE
int Alu::decodeTypeI(vector<int> comando){
    int op = comando[0];
    int rs = comando[1];
    int rt = comando[2];
    int adress = comando[3];

    switch (op)
    {
    case 700: //ADDI
        return rt + adress;
        break;
    
    case 800: //LW
        return rt + rs;
    
    case 900: //SW
        return rt + rs;
        break;
    
    case 1000: //BEQ
        if(rs == rt)
            return adress;
        break;
    
    case 1100: //BNE
        if(rs != rt)
            return adress; 
        break;
    
    default:
        break;
    }

}     
//J, JAL
int Alu::decodeTypeJ(vector<int> comando) {
    int op = comando[0];
    int adress = comando[1];
    switch (op)
    {
    case 1200: //J
        break;
    case 1400: //JAL

        break;
    default:
        break;
    }
}


