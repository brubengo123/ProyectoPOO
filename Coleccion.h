#pragma once

#include "Excepciones.h"
#include <cstddef>
#include <vector>

template <typename T>
class Coleccion {
private:
  std::vector<T> elementos;
  inline static std::size_t instancias = 0;

public:
  Coleccion() { ++instancias; }
  Coleccion(const Coleccion &otra) : elementos(otra.elementos) { ++instancias; }
  Coleccion &operator=(const Coleccion &otra) {
    if (this != &otra) {
      elementos = otra.elementos;
    }
    return *this;
  }
  ~Coleccion() { --instancias; }

  void agregar(const T &elemento) { elementos.push_back(elemento); }
  std::size_t cantidad() const { return elementos.size(); }

  T &operator[](std::size_t posicion) {
    if (posicion >= elementos.size()) {
      throw IndiceInvalidoException(posicion);
    }
    return elementos[posicion];
  }

  const T &operator[](std::size_t posicion) const {
    if (posicion >= elementos.size()) {
      throw IndiceInvalidoException(posicion);
    }
    return elementos[posicion];
  }

  static std::size_t cantidadInstancias() { return instancias; }
};

template <typename T>
std::size_t cantidadDe(const Coleccion<T> &coleccion) {
  return coleccion.cantidad();
}
