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

    void decode(vector<int> comando, char tipo);

    void decodeTypeR(vector<int> comando);
    void decodeTypeI(vector<int> comando);
    void decodeTypeJ(vector<int> comando);
};

#endif
