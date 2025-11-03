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

# Archivos
HEADERS=polinom.h AritPol.h
OBJS=polinom.o AritPol.o Prueba.o

# Regla por defecto
all: Prueba

# Enlazar el ejecutable
Prueba: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilar objetos con dependencias
Prueba.o: Prueba.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

AritPol.o: AritPol.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

polinom.o: polinom.cpp polinom.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJS) Prueba

.PHONY: all clean