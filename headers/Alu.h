#ifndef ALU_H
#define ALU_H

#include<string>
#include<string.h>
#include<vector>
#include<fstream>
#include<iostream>

#include"../headers/Instrucao.h"

using namespace std;

// ADD, SUB, AND, OR, SLT, SLL
void decodeTypeR(int rs,int rt,int rd,int shamt,int funct){
    switch (funct)
    {
    case 1: //ADD
        cout << "Realizando a instrucao ADD! " << endl;
        rd = rs + rt; 
        break;
    case 2: //SUB
        cout << "Realizando a instrucao SUB! " << endl;
        rd = rs - rt; 
        break;
    case 3: //AND
        cout << "Realizando a instrucao AND! " << endl;
        if(rs == 1 && rt == 1){
            rd = 1;
        }else{
            rd = 0;
        }
        break;
    case 4: //OR
        cout << "Realizando a instrucao OR! " << endl;
        if(rs == 1 || rt == 1){
            rd = 1;
        }else{
            rd = 0;
        }
        break;
    case 5: //SLT
        cout << "Realizando a instrucao SLT! " << endl;
        if(rs < rt){
            rd = 1;
        }else{
            rd = 0;
        }
        break;
       
    case 6 : //SLL
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
    case 7: //ADDI
        cout << "Realizando a instrucao ADDI! " << endl;

        break;
    
    case 8: //LW
        cout << "Realizando a instrucao LW! " << endl;

        break;
    
    case 9: //SW
        cout << "Realizando a instrucao SW! " << endl;

        break;
    
    case 10: //BEQ
        cout << "Realizando a instrucao BEQ! " << endl;

        break;
    
    case 11: //BNE
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
    case 12: //J
        cout << "Realizando a instrucao J! " << endl;

        break;
    case 13: //JR
        cout << "Realizando a instrucao JR! " << endl;

        break;
    case 14: //JAL
        cout << "Realizando a instrucao JAL! " << endl;

        break;
    default:
        break;
    }
}
#endif
