// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de autómatas
// Autor: Antonio Martinez Aleman
// Correo: alu0101548029@ull.edu.es
// Fecha: 17/10/2024
// Archivo alfabeto.h: definición de la clase Alfabeto.

#pragma once
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

class Alfabeto {
 public:
  Alfabeto() = default;
  void insertarSimbolo(char simbolo);
  bool contiene(char simbolo) const;
 private:
  std::set<char> alfabeto_;
};
