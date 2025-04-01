// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de autómatas
// Autor: Antonio Martinez Aleman
// Fecha: 17/10/2024
// Archivo alfabeto.cc: implementación de la clase Alfabeto.

#include "alfabeto.h"

void Alfabeto::insertarSimbolo(char simbolo) {
  alfabeto_.insert(simbolo);
}

bool Alfabeto::contiene(char simbolo) const {
  return std::find(alfabeto_.begin(), alfabeto_.end(), simbolo) != alfabeto_.end();
}
