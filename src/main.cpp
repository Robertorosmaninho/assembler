#include <iostream>

#include "montador.h"

int main(int argc, char *argv[]) {
    string fileName;
    if (argc != 2) {
      cout << "Usage montador [file]\n";
      return 1;
    } else {
      fileName = argv[1];
    }

    auto *montador = new Assembler();
    montador->setInputFile(fileName);
    montador->buildSymbolTable();
    montador->buildOperandsTable();
    montador->firstFase();
    montador->secondFase();
    montador->writeOutputFile();
    return 0;
}