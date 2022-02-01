#ifndef ALU_H
#define ALU_H

#include<string>
#include<string.h>
#include<vector>
#include<fstream>
#include<iostream>

using namespace std;

// ADD, SUB, AND, OR, SLT, SLL
void decodeTypeR(int rs,int rt,int rd,int shamt,int funct){
    switch (funct)
    {
    case 100: //ADD
        cout << "Realizando a instrucao ADD! " << endl;
        rd = rs + rt; 
        break;
    case 200: //SUB
        cout << "Realizando a instrucao SUB! " << endl;
        rd = rs - rt; 
        break;
    case 300: //AND
        cout << "Realizando a instrucao AND! " << endl;
        if(rs == 1 && rt == 1){
            rd = 1;
        }else{
            rd = 0;
        }
        break;
    case 400: //OR
        cout << "Realizando a instrucao OR! " << endl;
        if(rs == 1 || rt == 1){
            rd = 1;
        }else{
            rd = 0;
        }
        break;
    case 500: //SLT
        cout << "Realizando a instrucao SLT! " << endl;
        if(rs < rt){
            rd = 1;
        }else{
            rd = 0;
        }
        break;
       
    case 600 : //SLL
        cout << "Realizando a instrucao SLL! " << endl;
        rd = rt + shamt;
        break;

    default:
        break;
    }
}

// ADDI, LW, SW, BEQ, BNE
void decodeTypeI(int op,int rs,int rt,int adress){
    switch (op)
    {
    case 700: //ADDI
        cout << "Realizando a instrucao ADDI! " << endl;

        break;
    
    case 800: //LW
        cout << "Realizando a instrucao LW! " << endl;

        break;
    
    case 900: //SW
        cout << "Realizando a instrucao SW! " << endl;

        break;
    
    case 1000: //BEQ
        cout << "Realizando a instrucao BEQ! " << endl;

        break;
    
    case 1100: //BNE
        cout << "Realizando a instrucao BNE! " << endl;

        break;
    
    default:
        break;
    }

}     
//J, JR, JAL
void decodeTypeJ(int op,int address){
    switch (op)
    {
    case 1200: //J
        cout << "Realizando a instrucao J! " << endl;

        break;
    case 1300: //JR
        cout << "Realizando a instrucao JR! " << endl;

        break;
    case 1400: //JAL
        cout << "Realizando a instrucao JAL! " << endl;

        break;
    default:
        break;
    }
}
#endif
