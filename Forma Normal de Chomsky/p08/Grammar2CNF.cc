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

 /**
  * @brief carga la gramatica desde un archivo de entrada
  * @param archivo_entrada flujo de archivo de entrada donde se encuentra la gramatica
  */
void Gramatica::CargarDesdeArchivo(std::ifstream& archivo_entrada) {
  int n_terminales, v_no_terminales, p_producciones;
  std::string linea;
  archivo_entrada >> n_terminales;
  // leo los simbolos terminales del archivo
  for (int i = 0; i < n_terminales; ++i) {
    archivo_entrada >> linea;
    if (linea.size() == 1) {
      simbolos_terminales_.insert(linea[0]);
    } else {
      std::cerr << "Error: cada simbolo terminal debe ser un unico caracter." << std::endl;
      return;
    }
  }
  archivo_entrada >> v_no_terminales;
  // leo los simbolos no terminales del archivo
  for (int i = 0; i < v_no_terminales; ++i) {
    archivo_entrada >> linea;
    simbolos_no_terminales_.insert(linea);
  }
  archivo_entrada >> p_producciones;
  std::getline(archivo_entrada, linea); // consome el salto de linea despues del numero de producciones
  // leo las producciones del archivo
  for (int i = 0; i < p_producciones; ++i) {
    std::getline(archivo_entrada, linea);
    std::istringstream iss(linea);
    std::string izquierda, derecha;
    iss >> izquierda >> derecha;

    // verifico que el lado izquierdo sea un simbolo no terminal
    if (simbolos_no_terminales_.find(izquierda) == simbolos_no_terminales_.end()) {
      std::cerr << "Error: simbolo en el lado izquierdo de una produccion no es un simbolo no terminal." << std::endl;
      return;
    }
    // verifico que no se use la cadena vacia en la parte izquierda
    if (izquierda == "&") {
      std::cerr << "Error: la cadena vacia ('&') no puede usarse en la parte izquierda de una produccion." << std::endl;
      return;
    }
    // verifico que no se use la cadena vacia en la parte derecha
    if (derecha == "&") {
      std::cerr << "Error: la cadena vacia ('&') no puede usarse en la parte derecha de una produccion." << std::endl;
      return;
    }
    // verifico que no haya producciones unitarias (por ejemplo, A -> B)
    if (derecha.size() == 1 && simbolos_no_terminales_.find(derecha) != simbolos_no_terminales_.end()) {
      std::cerr << "Error: no se permiten producciones unitarias (por ejemplo, A -> B)." << std::endl;
      return;
    }
    // si todo esta bien, añado la produccion
    producciones_.emplace_back(izquierda, derecha);
  }
}

/**
 * @brief imprime la gramatica en un archivo de salida
 * @param os flujo de archivo de salida donde se imprimira la gramatica
 */
void Gramatica::Imprimir(std::ofstream& os) const {
  os << simbolos_terminales_.size() << std::endl;
  for (const auto& terminal : simbolos_terminales_) {
    os << terminal << std::endl;
  }
  os << simbolos_no_terminales_.size() << std::endl;
  for (const auto& no_terminal : simbolos_no_terminales_) {
    os << no_terminal << std::endl;
  }
  os << producciones_.size() << std::endl;
  for (const auto& produccion : producciones_) {
    os << produccion.first << " " << produccion.second << std::endl;
  }
}

/**
 * @brief convierte la gramatica a su forma normal de Chomsky (FNC)
 */
void Gramatica::ConvertirAFNC() {
  char letra_no_terminal = 'A';
  // Paso 1: Creo no terminales para terminales que aparecen junto a no terminales
  for (const char& terminal : simbolos_terminales_) {
    // Si no existe un no terminal asociado al terminal, lo creo
    if (terminal_a_no_terminal_.find(terminal) == terminal_a_no_terminal_.end()) {
      std::string nuevo_no_terminal(1, letra_no_terminal++); // asigno el siguiente carácter como no terminal
      terminal_a_no_terminal_[terminal] = nuevo_no_terminal; // mapeo el terminal al nuevo no terminal
      simbolos_no_terminales_.insert(nuevo_no_terminal); // agrego el nuevo no terminal al conjunto de no terminales
      
      // creo una producción de tipo nuevo_no_terminal -> terminal
      producciones_.emplace_back(nuevo_no_terminal, std::string(1, terminal));
    }
  }

  // Paso 2: Transformo producciones para que cumplan con la FNC
  std::vector<std::pair<std::string, std::string>> nuevas_producciones; // lista de nuevas producciones
  std::vector<std::pair<std::string, std::string>> producciones_aux; // lista auxiliar para producciones caracterorales

  // Recorro cada producción actual
  for (auto& produccion : producciones_) {
    std::string izquierda = produccion.first;
    std::string derecha = produccion.second;

    // Si la producción tiene más de un símbolo en el lado derecho
    if (derecha.size() > 1) {
      // Reemplazo los terminales en la producción por sus no terminales asociados
      for (size_t i = 0; i < derecha.size(); ++i) {
        char simbolo = derecha[i];
        // Si el símbolo es un terminal, lo reemplazo por su no terminal correspondiente
        if (simbolos_terminales_.find(simbolo) != simbolos_terminales_.end()) {
          derecha.replace(i, 1, terminal_a_no_terminal_[simbolo]);
        }
      }
    }

    // Descompongo producciones que tienen más de dos símbolos en el lado derecho
    while (derecha.size() > 2) {
      bool ya_existe = false;

      // Compruebo si ya existe una producción equivalente en la lista auxiliar
      for (auto& prod : producciones_aux) {
        if (prod.second == derecha.substr(0, 2)) {
          // Si ya existe, uso el no terminal asociado en lugar de crear uno nuevo
          derecha = prod.first + derecha.substr(2);
          ya_existe = true;
          break;
        }
      }

      // Si no existe una producción equivalente, creo un nuevo no terminal
      if (!ya_existe) {
        std::string nuevo_no_terminal(1, letra_no_terminal++); // genero el siguiente no terminal
        simbolos_no_terminales_.insert(nuevo_no_terminal); // añado el nuevo no terminal al conjunto de no terminales
        
        // Añado la nueva producción de tipo nuevo_no_terminal -> primeros dos símbolos
        nuevas_producciones.emplace_back(nuevo_no_terminal, derecha.substr(0, 2));
        producciones_aux.emplace_back(nuevo_no_terminal, derecha.substr(0, 2)); // guardo la nueva producción en la lista auxiliar
        
        // Actualizo el lado derecho de la producción con el nuevo no terminal
        derecha = nuevo_no_terminal + derecha.substr(2);
      }
    }

    // Añadimos la producción final transformada a la lista de nuevas producciones
    nuevas_producciones.emplace_back(izquierda, derecha);
  }

  // Actualizo el conjunto de producciones con las nuevas producciones en FNC
  producciones_ = nuevas_producciones;

  std::cout << "Transformación a FNC completada." << std::endl;
}


void Gramatica::DetectarNoTerminalesGeneradores() {
  std::set<std::string> no_terminales_generadores;
  bool cambios = true;
  while (cambios) {
    cambios = false;
    for (const auto& prod : producciones_) { //recorro cada produccion
      const std::string& izquierda = prod.first;
      const std::string& derecha = prod.second;
      bool tiene_solo_terminales = true;
      for (char c : derecha) { //recorre cada caracter de la produccion derecha
        if (simbolos_no_terminales_.find(std::string(1, c)) != simbolos_no_terminales_.end()) {
          tiene_solo_terminales = false;
          break;
        }
      }
      if (tiene_solo_terminales) { // si la parte derecha son solo terminales lo inserto y vuelvo al bucle con otra produccion
        if (no_terminales_generadores.find(izquierda) == no_terminales_generadores.end()) {
          no_terminales_generadores.insert(izquierda);
          cambios = true;
        }
      } else {
        bool es_generadora = true;
        //compruebo que los no terminales anteriores son o no generadores
        for (char c : derecha) {
          std::string caracter(1, c);
          if (simbolos_no_terminales_.find(caracter) != simbolos_no_terminales_.end() &&
              no_terminales_generadores.find(caracter) == no_terminales_generadores.end()) {
            es_generadora = false;
            break;
          }
        }
        // si cumple todas las condiciones lo inserto. 
        if (es_generadora && no_terminales_generadores.find(izquierda) == no_terminales_generadores.end()) {
          no_terminales_generadores.insert(izquierda);
          cambios = true;
        }
      }
    }
  }
  for (const auto& no_terminal : no_terminales_generadores) {
    std::cout << no_terminal << std::endl;
  }
}
