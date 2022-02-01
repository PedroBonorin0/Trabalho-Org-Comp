#ifndef ALU_H
#define ALU_H

#include<string>
#include<string.h>
#include<vector>
#include<fstream>
#include<iostream>

#include"../headers/Instrucao.h"

using namespace std;


void decodeTypeR(int rs,int rt,int rd,int shamt,int funct){
    switch (funct)
    {
    case 1: //ADD
        cout << "Realizando ADD! " << endl;
        rd = rs + rt; 
        break;
    case 2: //SUB
        cout << "Realizando SUB! " << endl;
        rd = rs - rt; 
        break;
    case 3: //AND
        if(rs == 1 && rt == 1){
            rd = 1;
        }else{
            rd = 0;
        }
        break;
    case 4: //OR
        if(rs == 1 || rt == 1){
            rd = 1;
        }else{
            rd = 0;
        }
        break;
    case 5: //SLT
        if(rs < rt){
            rd = 1;
        }else{
            rd = 0;
        }
        break;
       
    case 6 : //SLL
        rd = rt + shamt;
        break;

    default:
        break;
    }
}
  //        add, sub, and, or, slt,sll,
       
#endif
