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
// 17/09/2024 - Creaci´on (primera versi´on) del c´odigo

#include <iostream>
#include <vector>
#include <set>
#include <string>

class Cadena {
 public:
  Cadena(); // constructor por defecto
  Cadena(const std::vector<char>& cadena); //constructor para vector<char>
  Cadena(const std::string& cadena); // Constructor para string

  bool operator<(const Cadena& otra) const; //sobrecarga del operador < para comparar dos cadenas

  size_t longitud() const;
  Cadena invertir() const;

  std::set<Cadena> prefijos() const;
  std::set<Cadena> sufijos() const;

  
  std::string to_string() const; // Método para convertir a std::string

 private:
  std::vector<char> cadena_; // vector que almacena la cadena
};