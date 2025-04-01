// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Antonio Martinez Aleman
// Correo: alu0101548029@ull.edu.es
// Fecha: 17/09/2024
// Archivo organizador_codigo.h: programa cliente.
// Contiene la funci´on main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interes
// Historial de revisiones
// 03/10/2024 - Creacion (primera versi´on) del c´odigo

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <regex>

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>

class Organizador {
 public:
  Organizador(); // constructor
  void BuscaVariables(const std::string& contenido, std::ofstream& output_file);
  void BuscaBucles(const std::string& contenido, std::ofstream& output_file);
  bool BuscaMain(const std::string& contenido, std::ofstream& output_file);
  void BuscaComentarios(const std::string& contenido, std::ofstream& output_file);
  void BuscaComentariosDoxygen(const std::string& contenido, std::ofstream& output_file);
  void ImprimirDescripcion(const std::string& contenido, std::ofstream& output_file);
  void BuscaConst(const std::string& contenido, std::ofstream& output_file);


 private:
  std::vector<std::string> variables_;
  std::vector<std::string> bucles_;
  std::vector<std::string> comentarios_;
  bool tienemain_;
};
