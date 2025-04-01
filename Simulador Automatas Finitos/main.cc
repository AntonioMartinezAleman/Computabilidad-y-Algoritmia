// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de autómatas
// Autor: Antonio Martinez Aleman
// Archivo: main.cc
// Descripción: Programa principal que usa las clases Automata y Alfabeto para simular DFA y NFA.

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "automata.h"

// Función para verificar los parámetros de entrada
bool CheckCorrectParameters(int argc, char* argv[]) {
  if (argc > 1 && std::strcmp(argv[1], "--help") == 0) {
    std::cout << "Este programa simula autómatas finitos deterministas (DFA) y no deterministas (NFA).\n";
    std::cout << "Modo de empleo: ./p06_automata_simulator input.fa input.txt\n";
    return false;
  } else if (argc != 3) {
    std::cout << "Modo de empleo: ./p06_automata_simulator input.fa input.txt\n";
    std::cout << "Pruebe './p06_automata_simulator --help' para más información.\n";
    return false;
  }
  return true;
}

int main(int argc, char* argv[]) {
  if (!CheckCorrectParameters(argc, argv)) {
    return 1;
  }
  
  Automata automata;
  std::string fichero_automata = argv[1];
  if (!automata.cargarDesdeArchivo(fichero_automata)) {
    std::cerr << "Error: No se pudo cargar el autómata desde el archivo " << fichero_automata << std::endl;
    return 1;
  }
  
  std::string fichero_cadenas = argv[2];
  std::ifstream archivo_cadenas(fichero_cadenas);
  if (!archivo_cadenas.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo de cadenas " << fichero_cadenas << std::endl;
    return 1;
  }
  
  std::string cadena;
  while (std::getline(archivo_cadenas, cadena)) {
    bool resultado = automata.procesarCadena(cadena);
    if (resultado) {
      std::cout << cadena << " --- Accepted\n";
    } else {
      std::cout << cadena << " --- Rejected\n";
    }
  }

  archivo_cadenas.close();
  return 0;
}
