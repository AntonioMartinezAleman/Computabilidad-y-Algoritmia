# Makefile para el simulador de autómatas finitos

# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
OBJ = main.o alfabeto.o estado.o transicion.o automata.o

# Nombre del ejecutable
TARGET = p06_automata_simulador

# Regla por defecto
all: $(TARGET)

# Regla para crear el ejecutable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Reglas para compilar los archivos objeto
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

# Limpiar los archivos generados
clean:
	rm -f $(OBJ) $(TARGET)

# Reglas para compilar cada archivo
alfabeto.o: alfabeto.h
estado.o: estado.h
transicion.o: transicion.h
automata.o: automata.h

.PHONY: all clean
