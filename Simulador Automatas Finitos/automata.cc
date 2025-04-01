#include "automata.h"
#include <fstream>
#include <iostream>
#include <sstream>

bool Automata::cargarDesdeArchivo(const std::string& nombre_archivo) {
  std::ifstream archivo(nombre_archivo);
  if (!archivo.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo " << nombre_archivo << std::endl;
    return false;
  }
  std::string linea;
  std::getline(archivo, linea);
  std::istringstream iss(linea);
  char simbolo;
  while (iss >> simbolo) {
    if (simbolo != '&') {
      alfabeto_.insertarSimbolo(simbolo);
    } else {
      std::cerr << "No se puede poner el simbolo & en el alfabeto" << std::endl;
      return 0;
    }
  }
  int numero_estados;
  archivo >> numero_estados;
  std::string estado_inicial_id;
  archivo >> estado_inicial_id;
  if (estado_inicial_id.length() != 1) {
    std::cerr << "Error: El estado inicial debe contener exactamente un símbolo." << std::endl;
    return false;
  }
  if (numero_estados <= 0) {
    std::cerr << "Error: El número de estados debe ser mayor que cero." << std::endl;
    return false;
  }
  for (int i = 0; i < numero_estados; ++i) {
    std::string id_estado;
    int es_final;
    int num_transiciones;
    archivo >> id_estado >> es_final >> num_transiciones;
    Estado estado(id_estado, es_final == 1);
    mapa_estados_[id_estado] = estado;
    estados_.push_back(estado);
    for (int j = 0; j < num_transiciones; ++j) {
      char simbolo_entrada;
      std::string estado_destino;
      archivo >> simbolo_entrada >> estado_destino;
      if (alfabeto_.contiene(simbolo_entrada) || simbolo_entrada == '&') {
        Transicion transicion(simbolo_entrada, estado_destino);
        mapa_estados_[id_estado].agregarTransicion(transicion);
      } else {
        std::cerr << "Error: La transición hacia el estado '" << estado_destino << "' con el símbolo '" << simbolo_entrada << "' no es válida." << std::endl;
        return false;
      }
    }
  }
  if (mapa_estados_.find(estado_inicial_id) == mapa_estados_.end()) {
    std::cerr << "Error: El estado inicial '" << estado_inicial_id << "' no está definido." << std::endl;
    return false;
  }
  estado_inicial_ = mapa_estados_[estado_inicial_id];
  archivo.close();
  return true;
}

bool Automata::procesarCadena(const std::string& cadena) {
  std::vector<Estado> estados_actuales;
  estados_actuales.push_back(estado_inicial_);
  
  for (const char& simbolo : cadena) {
    std::vector<Estado> nuevos_estados;

    for (Estado estado_actual : estados_actuales) {
      bool transicion_encontrada = false;

      for (const Transicion& transicion : estado_actual.getTransiciones()) {
        if (transicion.getSimboloEntrada() == simbolo) {
          nuevos_estados.push_back(obtenerEstado(transicion.getEstadoDestino()));
          transicion_encontrada = true;
        } else if (transicion.getSimboloEntrada() == '&') {
          nuevos_estados.push_back(obtenerEstado(transicion.getEstadoDestino()));
        }
      }
      
      if (!transicion_encontrada && estado_actual.esEstadoFinal()) {
        return true;
      }
    }
    estados_actuales = nuevos_estados;
    if (estados_actuales.empty()) {
      return false;
    }
  }
  for (Estado estado_final : estados_actuales) {
    if (estado_final.esEstadoFinal()) {
      return true;
    }
  }
  return false;
}

Estado Automata::obtenerEstado(const std::string& id_estado) {
  return mapa_estados_.at(id_estado);
}

// modificacion. Detectar dentro del NFA cuando dos estados tienen mismo comportamiento

bool Automata::sonEstadosIguales(const Estado& estado1, const Estado& estado2) {
  if (estado1.esEstadoFinal() != estado2.esEstadoFinal()) { //compruebo que los dos estados son de aceptacion o de negacion
    return false;
  }
  if (estado1.getTransiciones().size() != estado2.getTransiciones().size()) { // compruebo que tienen mismo numero de transiciones
    return false;
  } 
  for (const auto& transicion : estado1.getTransiciones()) { // compruebo cada transicion si es igual
    bool encontrado = false;
    for (const auto& transicion2 : estado2.getTransiciones()) {
      if (transicion.getSimboloEntrada() == transicion2.getSimboloEntrada() &&
          transicion.getEstadoDestino() == transicion2.getEstadoDestino()) {
        encontrado = true;
        break;
      }
    }
    if (!encontrado) {
      return false;
    }
  }
}