#ifndef ALU_H
#define ALU_H

#include<string>
#include<string.h>
#include<vector>
#include<fstream>
#include<iostream>

using namespace std;

class Alu {
  private:

  public:
    Alu();
    ~Alu();

    string decode(vector<int> registradores,vector<int> comando, char tipo);

    string decodeTypeR(vector<int> registradores,vector<int> comando);
    string decodeTypeI(vector<int> registradores,vector<int> comando);
    string decodeTypeJ(vector<int> registradores,vector<int> comando);
};

#endif
// 10001101001010000000010010110000
// 00001000000000000000000011110101
// 10000000000010001010101010101010
// 10000000000010001010101010101010
// 00001000000000000000000011110101
// 10001101001010000000010010110000
// 10000000000010001010101010101010
// 10000000000010001010101010101010
// 00001000000000000000000011110101