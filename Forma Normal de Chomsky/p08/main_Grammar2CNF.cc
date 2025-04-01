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


#include "Grammar2CNF.h"


int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Uso: " << argv[0] << " <archivo_entrada> <archivo_salida>" << std::endl;
    return 1;
  }
  std::string nombre_archivo_entrada = argv[1];
  std::ifstream archivo_entrada(nombre_archivo_entrada);
  if (!archivo_entrada.is_open()) {
    std::cerr << "Error al abrir el archivo de entrada: " << nombre_archivo_entrada << std::endl;
    return 1;
  }
  std::string nombre_archivo_salida = argv[2];
  std::ofstream archivo_salida(nombre_archivo_salida);
  if (!archivo_salida.is_open()) {
    std::cerr << "Error al abrir el archivo de salida: " << nombre_archivo_salida << std::endl;
    return 1;
  }

  Gramatica gramatica;
  gramatica.CargarDesdeArchivo(archivo_entrada);
  gramatica.ConvertirAFNC();
  gramatica.Imprimir(archivo_salida);
  gramatica.DetectarNoTerminalesGeneradores();

  archivo_entrada.close();
  archivo_salida.close();
  return 0;
}

