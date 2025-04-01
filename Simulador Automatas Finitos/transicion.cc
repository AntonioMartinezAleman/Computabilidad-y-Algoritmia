// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de autómatas
// Autor: Antonio Martinez Aleman
// Archivo: transicion.cc
// Descripción: Implementación de la clase Transicion.

#include "transicion.h"

Transicion::Transicion(char simbolo_entrada, const std::string& estado_destino)
    : simbolo_entrada_(simbolo_entrada), estado_destino_(estado_destino) {}

char Transicion::getSimboloEntrada() const {
  return simbolo_entrada_;
}

std::string Transicion::getEstadoDestino() const {
  return estado_destino_;
}
