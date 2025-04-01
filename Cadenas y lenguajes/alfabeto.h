// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Antonio Martinez Aleman
// Correo: alu0101548029@ull.edu.es
// Fecha: 17/09/2024
// Archivo cya-P02-strings.cc: programa cliente.
// Contiene la funci´on main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interes
// Historial de revisiones
// 17/09/2024 - Creacion (primera versi´on) del c´odigo

#include "cadena.h"
#include <set>
#include <string>

class Alfabeto {
 public:
  // Constructor que inicializa el alfabeto con los símbolos únicos de una cadena
  Alfabeto(const std::string& cadena);

  // Convierte el conjunto de símbolos a un std::string
  std::string to_string() const;

 private:
  // Conjunto que almacena los símbolos del alfabeto
  std::set<char> simbolos_;
};
