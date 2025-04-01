# Makefile para el proyecto de Antonio Martinez Aleman
# Compilará los archivos en un ejecutable llamado p04_code_analyer

# Nombre del compilador
CXX = g++

# Opciones de compilación
CXXFLAGS = -Wall -g -std=c++17

# Archivos fuente y objeto
SRCS = main.cc organizador.cc
OBJS = $(SRCS:.cc=.o)

# Nombre del ejecutable
TARGET = p04_code_analyer

# Regla por defecto: compilar el proyecto
all: $(TARGET)

# Compilar el ejecutable a partir de los archivos objeto
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regla para compilar cada archivo fuente
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla clean: limpiar archivos objeto y el ejecutable
clean:
	rm -f $(OBJS) $(TARGET)

# Instrucciones adicionales
# - make: compila todo el proyecto
# - make clean: limpia los archivos objeto y el ejecutable
