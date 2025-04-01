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

Cadena::Cadena() : cadena_() {}
Cadena::Cadena(const std::vector<char>& cadena) : cadena_(cadena) {}
Cadena::Cadena(const std::string& cadena) : cadena_(cadena.begin(), cadena.end()) {}

// comparación para usar el .insert en el set
bool Cadena::operator<(const Cadena& otra) const {
  return cadena_ < otra.cadena_; 
}

// longitud de la cadena
size_t Cadena::longitud() const {
  return cadena_.size();
}

// Invierto la cadena
Cadena Cadena::invertir() const {
  std::vector<char> cadena_invertida(cadena_.rbegin(), cadena_.rend());
  return Cadena(cadena_invertida);
}

// Obtengo todos los prefijos, incluyendo la cadena vacía representada por '&'
std::set<Cadena> Cadena::prefijos() const {
  std::set<Cadena> cadena_prefijos;
  cadena_prefijos.insert(Cadena(std::vector<char>{char('&')}));  // Inserto '&' para cadena vacía
  for (size_t i = 1; i <= cadena_.size(); i++) {
    cadena_prefijos.insert(Cadena(std::vector<char>(cadena_.begin(), cadena_.begin() + i)));
  }
  return cadena_prefijos;
}

// Obtengo todos los sufijos, incluyendo la cadena vacía representada por '&'
std::set<Cadena> Cadena::sufijos() const {
  std::set<Cadena> cadena_sufijos;
  cadena_sufijos.insert(Cadena(std::vector<char>{char('&')}));  // Inserto '&' para cadena vacía
  for (size_t i = 0; i <= cadena_.size(); i++) {
    cadena_sufijos.insert(Cadena(std::vector<char>(cadena_.begin() + i, cadena_.end())));
  }
  return cadena_sufijos;
}

// Convierto la cadena a un string
std::string Cadena::to_string() const {
  return std::string(cadena_.begin(), cadena_.end());
}
