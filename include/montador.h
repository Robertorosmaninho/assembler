#ifndef MONTADOR_H
#define MONTADOR_H

#include <vector>
#include <string>
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

  Assembler();
  ~Assembler() = default;

  map<string, int> getSymbolTable();
  map<string, int> getPseudosTable();
  map<string, int> getOperandsTable();

  void setInputFile(const string& fileName);
  fstream getOutputFile();

  void incrementPC();
  void incrementPC(int inc);
  int getPC();

  void incrementAP();
  void incrementAP(int inc);
  int getAP();

  void setPEPZero(bool val);
  int getPEPZero();

  void setPEPNegativo(bool val);
  int getPEPNegativo();

  void setRegister(int idx, int val);
  int getRegisterVal(int idx);

  void buildSymbolTable();
  void buildPseudosTable();
  void buildOperandsTable();
  void readInputFile();
  void ignoreComments();
  void setLinesIntoTokens();
  void writeOutputFile();
  void firstFase();
  void secondFase();

  static bool isNum(const string& num);
  int codeGen(vector<string> token);
};

#endif
