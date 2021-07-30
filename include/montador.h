#ifndef MONTADOR_H
#define MONTADOR_H

#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
#include <map>
#include <sstream>
#include <istream>
#include <fstream>
#include <iostream>

using namespace std;

// TODO: structs, classes, e outras definições.
// Vamos precisar d eum arquivo de entrada e um de saída
// Uma estrutura de dados com o resultado que estamos construindo, isso é
// importante principalmante para uma segunda passagem marcando os labels
// precisaremos primeiro construir as traduções diretas em um map para depois
// aplicarmos

class Assembler {

private:
  map<string, int> symbolTable;
  map<string, int> pseudosTable;
  map<string, int> operandsTable;

  fstream *inputFile;
  fstream *outputFile;

  vector<string> lines;
  vector<vector<string>> tokens;
  vector<int> numbers;

  /// Registradores
  int PC; //ILC? --> Contador de programas: contém o endereço da próxima
          // instrução a ser executada;
  int AP = 999; // Apontador da pilha: aponta para o elemento no topo da pilha;
  int PEP[2]; // palavra de estado do processador): consiste em 2 bits que
  // armazenam o estado da última operação lógico/aritmética realizada na máquina,
  // sendo um dos bits para indicar que a última operação resultou em zero,
  // e outro bit para indicar que a última operação resultou num resultado negativo;

  int R[4]; // Registradores de propósito geral R0, R1, R2, R3

public:

  Assembler(string fileName);
  ~Assembler() = default;

  void setInputFile(const string& fileName);

  void buildSymbolTable();
  void buildOperandsTable();
  void readInputFile();
  void ignoreComments();
  void setLinesIntoTokens();
  void writeOutputFile();
  void firstFase();
  void secondFase();
  void assemble();

  static bool isNum(const string& num);
  string cleanString(string str);
  int codeGen(vector<string> token);
};

#endif
