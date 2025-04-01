#ifndef AUTOMATA_H_
#define AUTOMATA_H_

#include <vector>
#include <string>
#include <map>
#include "estado.h"
#include "alfabeto.h"

class Automata {
 public:
  Automata() = default;
  bool cargarDesdeArchivo(const std::string& nombre_archivo);
  bool procesarCadena(const std::string& cadena);
  bool sonEstadosIguales(const Estado& estado1, const Estado& estado2); //modificacion
 private:
  Alfabeto alfabeto_;
  std::vector<Estado> estados_;
  std::map<std::string, Estado> mapa_estados_;
  Estado estado_inicial_;
  Estado obtenerEstado(const std::string& id_estado);
};

#endif  // AUTOMATA_H_
