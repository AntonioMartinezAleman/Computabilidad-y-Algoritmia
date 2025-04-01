// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de autómatas
// Autor: Antonio Martinez Aleman
// Archivo: estado.h
// Descripción: Definición de la clase Estado.

#ifndef ESTADO_H_
#define ESTADO_H_

#include <string>
#include <vector>
#include "transicion.h"

class Estado {
 public:
  Estado() = default;
  Estado(const std::string& id_estado, bool es_estado_final);

  std::string getNombre() const;
  bool esEstadoFinal() const;

  void agregarTransicion(const Transicion& transicion);
  const std::vector<Transicion>& getTransiciones() const;

 private:
  std::string id_estado_;           // Identificador del estado
  bool es_estado_final_;            // Indica si es un estado final
  std::vector<Transicion> transiciones_; // Lista de transiciones del estado
};

#endif  // ESTADO_H_
