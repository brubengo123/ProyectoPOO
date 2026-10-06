#pragma once

#include <string>

class Adoptante {
private:
  int id;
  std::string nombre;
  std::string telefono;
  std::string correo;
  std::string tipoVivienda;

public:
  Adoptante();
  Adoptante(int id, std::string nombre, std::string telefono,
            std::string correo, std::string tipoVivienda);
  Adoptante(const Adoptante &otro);

  int getId() const;
  std::string getNombre() const;
  std::string getTelefono() const;
  std::string getCorreo() const;
  std::string getTipoVivienda() const;
  void mostrarInfo() const;
};