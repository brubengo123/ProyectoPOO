#pragma once

#include <stdexcept>
#include <string>

class IdDuplicadoException : public std::runtime_error {
public:
  explicit IdDuplicadoException(int id)
      : std::runtime_error("ID duplicado: " + std::to_string(id)) {}
};

class IndiceInvalidoException : public std::out_of_range {
public:
  explicit IndiceInvalidoException(int indice)
      : std::out_of_range("Indice invalido: " + std::to_string(indice)) {}
  explicit IndiceInvalidoException(std::size_t indice)
      : std::out_of_range("Indice invalido: " + std::to_string(indice)) {}
};

class AnimalNoDisponibleException : public std::runtime_error {
public:
  explicit AnimalNoDisponibleException(int id)
      : std::runtime_error("El animal " + std::to_string(id) +
                           " no esta disponible") {}
};
