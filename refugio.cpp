#include "Refugio.h"
#include <iostream>

// Constructor por defecto
Refugio::Refugio() : nombre("Sin Nombre"), direccion("Sin Dirección") {}

// Constructor parametrizado
Refugio::Refugio(std::string nombre, std::string direccion)
    : nombre(nombre), direccion(direccion) {}

// Destructor: Libera la memoria de las mascotas si fueron creadas dinámicamente
Refugio::~Refugio() {
  for (Mascota *m : inventarioMascotas) {
    delete m;
  }
  inventarioMascotas.clear();
}

// Getters y Setters
std::string Refugio::getNombre() const { return nombre; }

void Refugio::setNombre(const std::string &nuevoNombre) {
  nombre = nuevoNombre;
}

std::string Refugio::getDireccion() const { return direccion; }

void Refugio::setDireccion(const std::string &nuevaDireccion) {
  direccion = nuevaDireccion;
}

// Agregar mascota al inventario
void Refugio::agregarMascota(Mascota *mascota) {
  if (mascota != nullptr) {
    inventarioMascotas.push_back(mascota);
    std::cout << "Mascota agregada con exito al refugio " << nombre << ".\n";
  }
}

// Eliminar mascota por ID
bool Refugio::eliminarMascota(int idMascota) {
  for (auto it = inventarioMascotas.begin(); it != inventarioMascotas.end();
       ++it) {
    if ((*it)->getId() ==
        idMascota) { // Asume que Mascota tiene un método getId()
      delete *it;    // Liberar memoria
      inventarioMascotas.erase(it);
      std::cout << "Mascota con ID " << idMascota << " removida del refugio.\n";
      return true;
    }
  }
  std::cout << "No se encontro la mascota con ID " << idMascota << ".\n";
  return false;
}

// Buscar mascota por ID
Mascota *Refugio::buscarMascota(int idMascota) const {
  for (Mascota *m : inventarioMascotas) {
    if (m->getId() == idMascota) {
      return m;
    }
  }
  return nullptr;
}

// Mostrar lista de mascotas
void Refugio::mostrarMascotas() const {
  std::cout << "\n=== Mascotas en el Refugio: " << nombre << " ===\n";
  if (inventarioMascotas.empty()) {
    std::cout << "Actualmente no hay mascotas en el refugio.\n";
    return;
  }
  for (const Mascota *m : inventarioMascotas) {
    m->mostrarInformacion(); // Asume que Mascota tiene mostrarInformacion()
    std::cout << "-----------------------------------\n";
  }
}

// Obtener cantidad total de mascotas
int Refugio::getCantidadMascotas() const {
  return static_cast<int>(inventarioMascotas.size());
}