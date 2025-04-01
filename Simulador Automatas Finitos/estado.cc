// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de autómatas
// Autor: Antonio Martinez Aleman
// Archivo: estado.cc
// Descripción: Implementación de la clase Estado.

#include "estado.h"

Estado::Estado(const std::string& id_estado, bool es_estado_final) : id_estado_(id_estado), es_estado_final_(es_estado_final) {}

std::string Estado::getNombre() const {
  return id_estado_;
}

bool Estado::esEstadoFinal() const {
  return es_estado_final_;
}

void Estado::agregarTransicion(const Transicion& transicion) {
  transiciones_.push_back(transicion);
}

const std::vector<Transicion>& Estado::getTransiciones() const {
  return transiciones_;
}
