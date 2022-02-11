#include<iostream>

#include"../headers/Alu.h"
#include"../headers/BancoRegistradores.h"

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

string Alu::decode(vector<int> registradores, vector<int> comando, char tipo) {
  if(tipo == 'R') return decodeTypeR(registradores, comando);
  if(tipo == 'I') return decodeTypeI(registradores, comando);
    return decodeTypeJ(registradores, comando);
}

// ADD, SUB, AND, OR, SLT, SLL
string  Alu::decodeTypeR(vector<int> registradores, vector<int> comando){
    int rs = comando[1];
    int rt = comando[2];
    int rd = comando[3];
    int shamt = comando[4];
    int funct = comando[5];
    
    string saida;
    switch (funct)
    {
    case 100: //ADD
        registradores[rd] = rs + rt;
        saida = to_string(rs) + " + " + to_string(rt) + " = " + to_string(rs+rt);
        return saida;
        
    case 200: //SUB
        registradores[rd] = rs - rt; 
        saida = to_string(rs) + " - " + to_string(rt) + " = " + to_string(rs-rt);
        return saida;
        
    case 300: //AND
        if(rs == 1 && rt == 1){
            registradores[rd] = 1;
            saida = to_string(rs) + " AND " + to_string(rt) + " = TRUE";
            return saida;
        }else{
            registradores[rd] = 0;
            saida = to_string(rs) + " AND " + to_string(rt) + " = FALSE";
            return saida;
        }
        
    case 400: //OR
        if(rs == 1 || rt == 1){
            registradores[rd] = 1;
            saida = to_string(rs) + " OR " + to_string(rt) + " = TRUE";
            return saida;
        }else{
            registradores[rd] = 0;
            saida = to_string(rs) + " OR " + to_string(rt) + " = FALSE";
            return saida;
        }
        
    case 500: //SLT
        if(rs < rt){
            registradores[rd] = 1;
            saida = to_string(rs) + " SLT " + to_string(rt) + " = TRUE";
            return saida;
        }else{
            registradores[rd] = 0;
            saida = to_string(rs) + " SLT " + to_string(rt) + " = FALSE";
            return saida;
        }
       
    case 600 : //SLL
        registradores[rd] = rt + shamt;
        saida = to_string(rt) + " OR " + to_string(shamt) + " = FALSE";
        return saida;
    
        
    case 1300: //JR

        break;

    default:
        break;
    }
    saida = "ERRO DECODE TYPE R";
    return saida;
}

// ADDI, LW, SW, BEQ, BNE
string Alu::decodeTypeI(vector<int> registradores, vector<int> comando){
    int op = comando[0];
    int rs = comando[1];
    int rt = comando[2];
    int adress = comando[3];
    string saida;

    switch (op)
    {
    case 700: //ADDI
        registradores[rs] =  rt + adress;
        saida = to_string(rt) + " ADDI " + to_string(adress);
        return saida;
    
    case 800: //LW
        registradores[rs] = registradores[adress + rt ];
        saida = "leitura do registrador " + to_string(adress + rt);
        return saida;
    
    case 900: //SW
        registradores[adress + rt ] = registradores[rs];
        saida = "Escrita no registrador " + to_string(adress + rt);
        return saida;
        
    case 1000: //BEQ
        if(rs == rt){
            registradores[rs] =  adress;
            saida = to_string(rs) + " BER " + to_string(rt) + " = TRUE";
            return saida;
        }
        saida = to_string(rs) + " BER " + to_string(rt) + " = FALSE";
        return saida; 
        
    
    case 1100: //BNE
        if(rs != rt){
            registradores[rs] =  adress; 
            saida = to_string(rs) + " BNE " + to_string(rt) + " = TRUE";
            return saida;
        }
        saida = to_string(rs) + " BER " + to_string(rt) + " = FALSE";
        return saida;   
        break;
    
    default:
        break;
    }
    saida = "ERRO DECODE TYPE I";
    return saida;
}     
//J, JAL
string Alu::decodeTypeJ(vector<int> registradores, vector<int> comando) {
    int op = comando[0];
    int adress = comando[1];
    string saida;
    switch (op)
    {
    case 1200: //J
        saida = "Deslocamento de " + to_string(adress);
        return saida;
    case 1400: //JAL
        saida = "Deslocamento de " + to_string(adress) + "e link ";
        return saida;
    default:
        break;
    }
    saida = "ERRO DECODE TYPE J";
    return saida;
}


