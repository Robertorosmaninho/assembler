#include "montador.h"

Assembler::Assembler() {

}

void Assembler::setInputFile(const string& fileName) {
  fstream file(fileName);
  if (!file.is_open()) {
    cout << "Erro ao abrir aquivo " << fileName << "!\n";
  } else {
    inputFile = &file;
    readInputFile();
  }
  // Depois de lido o arquivo não precisa mais ficar aberto!
  file.close();
}

void Assembler::readInputFile() {
  string line;
  while (std::getline(*inputFile, line))
    lines.push_back(line);

  ignoreComments();
  setLinesIntoTokens();
}

void Assembler::ignoreComments() {
  string aux;
  for (auto & i : lines) {
    string line = i;
    auto pos = line.find(';');
    if (pos != std::string::npos)
      i = line.substr(0, pos);
  }
}

void Assembler::setLinesIntoTokens() {
  vector<string> aux;
  for (const auto& line : lines){
    string token;
    istringstream ss(line);
    while(ss >> token)
      aux.push_back(token);
  }
  tokens.push_back(aux);
}

void Assembler::buildSymbolTable() {
  symbolTable["HALT"] = 0;
  symbolTable["LOAD"] = 1;
  symbolTable["STORE"] = 2;
  symbolTable["READ"] = 3;
  symbolTable["WRITE"] = 4;
  symbolTable["COPY"] = 5;
  symbolTable["PUSH"] = 6;
  symbolTable["POP"] = 7;
  symbolTable["ADD"] = 8;
  symbolTable["SUB"] = 9;
  symbolTable["MUL"] = 10;
  symbolTable["DIV"] = 11;
  symbolTable["MOD"] = 12;
  symbolTable["AND"] = 13;
  symbolTable["OR"] = 14;
  symbolTable["NOT"] = 15;
  symbolTable["JUMP"] = 16;
  symbolTable["JZ"] = 17;
  symbolTable["JN"] = 18;
  symbolTable["CALL"] = 19;
  symbolTable["RET"] = 20;
}

void Assembler::buildOperandsTable() {
  operandsTable["R0"] = 0;
  operandsTable["R1"] = 1;
  operandsTable["R2"] = 2;
  operandsTable["R3"] = 3;
}
