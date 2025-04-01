// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de autómatas
// Autor: Antonio Martinez Aleman
// Archivo: transicion.h
// Descripción: Definición de la clase Transicion.

#ifndef TRANSICION_H_
#define TRANSICION_H_
#include "alfabeto.h"

class Transicion {
 public:
  Transicion(char simbolo_entrada, const std::string& estado_destino);
  char getSimboloEntrada() const;
  std::string getEstadoDestino() const;

 private:
  char simbolo_entrada_;
  std::string estado_destino_;
};

#endif  // TRANSICION_H_
