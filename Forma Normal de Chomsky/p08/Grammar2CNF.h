// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Antonio Martinez Aleman
// Correo: alu0101548029@ull.edu.es
// Fecha: 17/09/2024
// Archivo main.cc: programa cliente.
// Contiene la funci´on main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interes
// Historial de revisiones
// 03/10/2024 - Creacion (primera versi´on) del c´odigo


#ifndef GRAMMAR2CNF_H
#define GRAMMAR2CNF_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <map>
#include <cstdlib>

class Gramatica {

public:
  Gramatica() = default;
  void CargarDesdeArchivo(std::ifstream& archivo_entrada);
  void Imprimir(std::ofstream& archivo_salida) const;
  void ConvertirAFNC();



  void DetectarNoTerminalesGeneradores(); //modificacion



 private:
  std::set<char> simbolos_terminales_;  //E*
  std::set<std::string> simbolos_no_terminales_;// v'
  std::vector<std::pair<std::string, std::string>> producciones_; // vector que almacena dos datos A -> B
  std::map<char, std::string> terminal_a_no_terminal_; //la relacion entre terminales y no terminales
};


#endif // GRAMMAR2CNF_H
