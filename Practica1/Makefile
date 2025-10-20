# Detectar el sistema operativo
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
    OS=Linux
endif
ifeq ($(UNAME_S),Darwin)
    OS=macOS
endif
ifeq ($(OS),)
    OS=Windows
endif

# Compilador
CXX=g++

# Banderas del compilador
CXXFLAGS=-std=c++11 -Wall -Wextra -g

# Extensión del ejecutable (según SO)
ifeq ($(OS),Windows)
    EXE_EXT=.exe
else
    EXE_EXT=
endif

# Archivos de origen y objetos
SOURCES=$(wildcard Ej*.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLES=$(SOURCES:.cpp=$(EXE_EXT))

# Reglas individuales para cada ejercicio
EJ1=Ej1$(EXE_EXT)
EJ2=Ej2$(EXE_EXT)
EJ3=Ej3$(EXE_EXT)
EJ4=Ej4$(EXE_EXT)
EJ5=Ej5$(EXE_EXT)

# Regla por defecto: compila todos los ejecutables
all: $(EXECUTABLES)

# Reglas individuales para compilar y ejecutar cada ejercicio
ej1: $(EJ1)
	@echo "=== Ejecutando Ej1 ===" && ./$(EJ1)

ej2: $(EJ2)
	@echo "=== Ejecutando Ej2 ===" && ./$(EJ2)

ej3: $(EJ3)
	@echo "=== Ejecutando Ej3 ===" && ./$(EJ3)

ej4: $(EJ4)
	@echo "=== Ejecutando Ej4 ===" && ./$(EJ4)

ej5: $(EJ5)
	@echo "=== Ejecutando Ej5 ===" && ./$(EJ5)

# Regla para compilar solo (sin ejecutar)
build-Ej1: $(EJ1)
build-Ej2: $(EJ2)
build-Ej3: $(EJ3)
build-Ej4: $(EJ4)
build-Ej5: $(EJ5)

# Regla para generar ejecutables
%$(EXE_EXT): %.o
	$(CXX) $(CXXFLAGS) $< -o $@

# Regla para generar archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para ejecutar todos los programas
run: all
	@for exe in $(EXECUTABLES); do \
		echo "=== Ejecutando $$exe ==="; \
		./$$exe; \
		echo ""; \
	done

# Regla para limpiar archivos generados
clean:
	rm -rf $(OBJECTS) $(EXECUTABLES)

# Regla para mostrar variables (debug)
info:
	@echo "SO detectado: $(OS)"
	@echo "Extensión ejecutable: $(EXE_EXT)"
	@echo "Archivos fuente: $(SOURCES)"
	@echo "Ejecutables a generar: $(EXECUTABLES)"

.PHONY: all clean run info ej1 ej2 ej3 ej4 ej5 build-ej1 build-ej2 build-ej3 build-ej4 build-ej5
