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
#include "alfabeto.h"

// Constructor que inicializa los símbolos a partir de una cadena
Alfabeto::Alfabeto(const std::string& cadena) {
  for (char simbolo : cadena) {
    simbolos_.insert(simbolo);  // Inserto el símbolo en el conjunto
  }
}

// Convierte el conjunto de símbolos a un std::string
std::string Alfabeto::to_string() const {
  std::string result = "{";
  for (auto it = simbolos_.begin(); it != simbolos_.end(); ++it) {
    result += *it;  // Agrego el símbolo
    if (std::next(it) != simbolos_.end()) {
      result += ", ";  // Agrego coma si no es el último símbolo
    }
  }
  result += "}";  // Cierro la representación
  return result;  // Devuelvo el resultado
}
