# Makefile para Grammar2CNF

# Nombre del compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++11 -Wall -Wextra

# Archivos fuente y de cabecera
SOURCES = Grammar2CNF.cc main_Grammar2CNF.cc
HEADERS = Grammar2CNF.h

# Archivo de salida
EXECUTABLE = GRAMMAR2CNF

# Regla para compilar todo
all: $(EXECUTABLE)

# Regla para compilar el ejecutable
$(EXECUTABLE): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(SOURCES)

# Regla para limpiar los archivos generados
clean:
	rm -f $(EXECUTABLE) *.o

# Regla para ejecutar el programa
run: $(EXECUTABLE)
	./$(EXECUTABLE) input.gra output.gra
