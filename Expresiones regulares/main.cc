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

#include <iostream>
#include <fstream>
#include <sstream>
#include "organizador.h"

void CheckCorrectParameters(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Error: Número incorrecto de parámetros.\n";
    std::cerr << "Modo de empleo: ./p04_code_analyer code.cc codescheme.txt\n";
    exit(1);
  }
}

int main(int argc, char* argv[]) {
  CheckCorrectParameters(argc, argv);
  
  // Lectura del archivo de entrada
  std::string fichero_entrada = argv[1];
  std::ifstream input_file(fichero_entrada);
  if (!input_file.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo " << fichero_entrada << std::endl;
    return 1;
  }

  // Lectura del archivo de salida
  std::string fichero_salida = argv[2];
  std::ofstream output_file(fichero_salida);
  if (!output_file.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo " << fichero_salida << std::endl;
    return 1;
  }

  // Cargar todo el contenido del archivo en una string
  std::stringstream buffer;
  buffer << input_file.rdbuf();
  std::string contenido = buffer.str();

  // Crear una instancia de Organizador
  Organizador organizador;

  // Buscar las distintas estructuras en el contenido del archivo
  output_file << "PROGRAM : code.cc\n"; 
  organizador.ImprimirDescripcion(contenido, output_file);
  organizador.BuscaVariables(contenido, output_file);
  organizador.BuscaConst(contenido, output_file);
  organizador.BuscaBucles(contenido, output_file);
  organizador.BuscaMain(contenido, output_file);
  organizador.BuscaComentariosDoxygen(contenido, output_file);
  organizador.BuscaComentarios(contenido, output_file);

  // Cerrar los archivos
  input_file.close();
  output_file.close();

  return 0;
}
