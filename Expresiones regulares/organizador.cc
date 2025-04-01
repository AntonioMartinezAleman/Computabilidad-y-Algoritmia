// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Pr´actica 2: Cadenas y lenguajes
// Autor: Antonio Martinez Aleman
// Correo: alu0101548029@ull.edu.es
// Fecha: 17/09/2024
// Archivo organizador_codigo.cc: programa cliente.
// Contiene la funci´on main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interes
// Historial de revisiones
// 03/10/2024 - Creacion (primera versi´on) del c´odigo

#include "organizador.h"
#include <algorithm>
#include <cctype>

Organizador::Organizador() : tienemain_(false) {}

void Organizador::BuscaVariables(const std::string& contenido, std::ofstream& output_file) {
  std::regex variable_regex(R"(^\s*(int|double)\s+([a-zA-Z_]\w*)\s*(=\s*[^;]+)?\s*;?\s*$)");
  std::smatch match;
  std::istringstream stream(contenido);
  std::string line;
  int line_number = 1;
  output_file << "VARIABLES:\n";
  while (std::getline(stream, line)) {
    if (std::regex_search(line,match, variable_regex)) {
      std::string tipo = match.str(1);
      std::string nombre = match.str(2);
      std::string valor = match.str(3);
      std::transform(tipo.begin(), tipo.end(), tipo.begin(), [](unsigned char c) { return std::toupper(c); });
      output_file << "[Line " << line_number << "] " << tipo << ": " << nombre;
      if (valor.find('=') != std::string::npos) {
        output_file << " = " << valor.substr(valor.find('=') + 1);  // Si hay valor, lo añade
      }
      output_file << "\n";
      variables_.push_back(nombre);
    }
    ++line_number;
  }
}

void Organizador::BuscaBucles(const std::string& contenido, std::ofstream& output_file) {
  std::regex loop_regex(R"(^\s*(for|while)\s*)");
  std::smatch match;
  std::istringstream stream(contenido);
  std::string line;
  int line_number = 1;
  output_file << "STATEMENTS:\n";
  while (std::getline(stream, line)) {
    if (std::regex_search(line, match, loop_regex)) {
      output_file << "[Line " << line_number << "] LOOP: " << match.str(1) << "\n";
      bucles_.push_back(match.str(1));
    }
    ++line_number;
  }
  output_file << "\n";
}


bool Organizador::BuscaMain(const std::string& contenido, std::ofstream& output_file) {
  std::regex main_regex(R"(int\s+main\s*\(\s*\))");
  tienemain_ = std::regex_search(contenido, main_regex);
  output_file << "MAIN : \n" << (tienemain_ ? "True" : "False") << "\n";
  output_file << "\n";
  return tienemain_;
}

void Organizador::BuscaComentarios(const std::string& contenido, std::ofstream& output_file) {
  std::regex comment_regex(R"(^//.*$)");
  std::smatch match;
  std::istringstream stream(contenido);
  std::string line;
  int line_number = 1;
  while (std::getline(stream, line)) {
    if (std::regex_search(line, match, comment_regex)) {
      output_file << "[Line " << line_number << "] " << match.str(0) << "\n";
    }
    ++line_number;
  }
}

void Organizador::BuscaComentariosDoxygen(const std::string& contenido, std::ofstream& output_file) {
  std::regex doxygen_regex(R"((/\*\*[\s\S]*?\*/|///.*?$))");
  std::smatch match;
  std::string::const_iterator search_start(contenido.cbegin());
  int line_number = 1;
  int start_line = 0;
  bool in_block = false;
  output_file << "COMMENTS:\n";
  while (std::regex_search(search_start, contenido.cend(), match, doxygen_regex)) {
    if (!in_block) {
      start_line = line_number;
      in_block = true;
    }
    search_start = match.suffix().first;
    std::string comment = match[0].str();
    for (const char& c : comment) {
      if (c == '\n') {
        line_number++;
      }
    }
  }
  if (start_line > 0) {
    output_file << "[Line " << start_line << " - " << line_number << "] DESCRIPTION\n";
  }
}

void Organizador::ImprimirDescripcion(const std::string& contenido, std::ofstream& output_file) {
  std::regex doxygen_regex(R"((^/\*\*[\s\S]*?\*/|///.*?$))");
  std::smatch match;
  std::string::const_iterator search_start(contenido.cbegin());
  output_file << "DESCRIPTION:\n";
  while (std::regex_search(search_start, contenido.cend(), match, doxygen_regex)) {
    output_file << match[0].str() << "\n";
    search_start = match.suffix().first;
  }
  output_file << "\n";
}


//modificacion
void Organizador::BuscaConst(const std::string& contenido, std::ofstream& output_file) {
  std::regex variable_regex(R"(\bconst\s(int|double)\s[A-Za-z]*)");
  std::smatch match;
  std::istringstream stream(contenido);
  std::string line;
  int line_number = 1;
  while (std::getline(stream, line)) {
    if (std::regex_search(line,match, variable_regex)) {
      std::string tipo = match.str();
      output_file << "[Line " << line_number << "] " << tipo;
      output_file << "\n";
    }
    ++line_number;
  }
  output_file << "\n";
}