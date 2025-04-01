// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Antonio Martinez Aleman
// Correo: alu0101548029@ull.edu.es
// Fecha: 17/09/2024
// Archivo cya-P02-strings.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 17/09/2024 - Creación (primera versión) del código

#include "alfabeto.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

// ayuda en --help
void ShowHelp() {
  std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode\n";
  std::cout << "Opciones:\n";
  std::cout << "--help: Muestra esta ayuda.\n";
  std::cout << "filein.txt: Archivo de entrada que contiene cadenas y alfabetos.\n";
  std::cout << "fileout.txt: Archivo de salida.\n";
  std::cout << "opcode: Código de operación a ejecutar.\n";
  std::cout << "1: Alfabeto.\n";
  std::cout << "2: Longitud.\n";
  std::cout << "3: Inversa.\n";
  std::cout << "4: Prefijos.\n";
  std::cout << "5: Sufijos.\n";
}

// verificar parámetros
void CheckCorrectParameters(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode\n";
    std::cout << "Pruebe './p02_strings --help' para más información.\n";
    exit(1);
  }
  if (std::string(argv[1]) == "--help") {
    ShowHelp();
    exit(0);
  }
  if (argc != 5) {
    std::cerr << "Error: Número incorrecto de parámetros.\n";
    std::cerr << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode\n";
    exit(1);
  }
}

int main(int argc, char* argv[]) {
  CheckCorrectParameters(argc, argv);
  std::string filein = argv[1];
  std::ifstream input_file(filein);

  if (!input_file.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo " << filein << std::endl;
    return 1;
  }

  std::string fileout = argv[2];
  int opcode = std::stoi(argv[3]);
  int numero = std::stoi(argv[4]);

  std::ofstream output_file(fileout);
  if (!output_file.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo " << fileout << std::endl;
    return 1;
  }

  std::string line;
  while (std::getline(input_file, line)) {
    std::istringstream iss(line);
    std::string cadena_str, alfabeto_str;

    if (iss >> cadena_str >> alfabeto_str) {
      Cadena cadena(cadena_str);
      Alfabeto alfabeto(alfabeto_str);

      switch (opcode) {
        case 1:  // Alfabeto
          output_file << alfabeto.to_string() << "\n";
          break;
        case 2:  // Longitud
          output_file << cadena.longitud() << "\n";
          break;
        case 3:  // Inversa
          output_file << cadena.invertir().to_string() << "\n";
          break;
        case 4: {  // Prefijos
          std::set<Cadena> prefijos = cadena.prefijos();
          output_file << "{";
          bool first = true;
          for (const Cadena& prefijo : prefijos) {
            if (!first) output_file << ", ";
            output_file << prefijo.to_string();
            first = false;  // Cambiamos a false después de imprimir el primer elemento
          }
          output_file << "}\n";
          break;
        }
        case 5: {  // Sufijos
          std::set<Cadena> sufijos = cadena.sufijos();
          output_file << "{";
          
          bool first = true;
          for (const Cadena& sufijo : sufijos) {
            if (sufijo.to_string() == "&") {
              output_file << sufijo.to_string();  // El símbolo vacío se imprime sin coma
            } else {
              if (!first) {
                output_file << ", ";  // Añade coma antes de los sufijos no vacíos
              }
              output_file << sufijo.to_string();
              first = false;
            }
          }
          output_file << "}\n";
          break;
        }
        case 6: {  // Modificación
          std::set<Cadena> prefijos = cadena.prefijos();
          std::set<Cadena> sufijos = cadena.sufijos();
          std::set<Cadena> resultado;

          for (const Cadena& prefijo : prefijos) {
            if (prefijo.to_string().size() == numero) {
              resultado.insert(prefijo);
            }
          }

          for (const Cadena& sufijo : sufijos) {
            if (sufijo.to_string().size() == numero) {
              resultado.insert(sufijo); 
            }
          }

          output_file << "{";
          bool first = true;
          for (const Cadena& res : resultado) {
            if (!first) {
              output_file << ", ";  
            }
            output_file << res.to_string();
            first = false; 
          }
          output_file << "}\n";
          break;
        }
        default:
          output_file << "Opcode incorrecto para la línea: " << line << std::endl;
          break;
      }
    } else {
      output_file << "Error: Formato incorrecto en la línea: " << line << std::endl;
    }
  }

  input_file.close();
  output_file.close();
  return 0;
}
