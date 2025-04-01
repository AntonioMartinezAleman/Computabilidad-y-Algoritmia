# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
TARGET = p02_strings
OBJECTS = main.o cadena.o alfabeto.o

# Regla principal para compilar todo
all: $(TARGET)

# Regla para generar el ejecutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regla para compilar main.o
main.o: main.cc cadena.h alfabeto.h
	$(CXX) $(CXXFLAGS) -c main.cc

# Regla para compilar cadena.o
cadena.o: cadena.cc cadena.h
	$(CXX) $(CXXFLAGS) -c cadena.cc

# Regla para compilar alfabeto.o
alfabeto.o: alfabeto.cc alfabeto.h
	$(CXX) $(CXXFLAGS) -c alfabeto.cc

# Regla para limpiar los archivos generados
clean:
	rm -f $(OBJECTS) $(TARGET)
