#include "montador.h"

Assembler::Assembler() {

}

void Assembler::setInputFile(const string& fileName) {
  fstream file(fileName);
  if (!file.is_open()) {
    cout << "Erro ao abrir aquivo " << fileName << "!\n";
  } else {
    this->inputFile = &file;
    readInputFile();
  }
  // Depois de lido o arquivo não precisa mais ficar aberto!
  file.close();
}

void Assembler::readInputFile() {
  string line;
  while (std::getline(*this->inputFile, line))
    lines.push_back(line);

  ignoreComments();
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