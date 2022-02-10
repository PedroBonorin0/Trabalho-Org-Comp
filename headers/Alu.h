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

    void decode(vector<int> registradores, vector<int> comando, char tipo);

    int decodeTypeR(vector<int> registradores, vector<int> comando);
    int decodeTypeI(vector<int> registradores, vector<int> comando);
    int decodeTypeJ(vector<int> registradores, vector<int> comando);
};

#endif
