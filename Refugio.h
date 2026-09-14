#ifndef REFUGIO_H
#define REFUGIO_H

#include "Adoptante.h"
#include "Animal.h"
#include "Coleccion.h"
#include "SolicitudAdopcion.h"
#include <string>


// Clase encargada de orquestar la lógica del refugio
class Refugio {
private:
  Coleccion<Animal *> animales;             // Colección de punteros a Animales
  Coleccion<Adoptante> adoptantes;          // Colección de Adoptantes
  Coleccion<SolicitudAdopcion> solicitudes; // Colección de Solicitudes

public:
  Refugio();
  ~Refugio();

  // Gestión de Animales
  void registrarPerro(std::string nombre, int edad, std::string salud,
                      std::string raza, std::string tamano);
  void registrarGato(std::string nombre, int edad, std::string salud,
                     std::string colorPelaje, bool esDeInterior);
  void listarAnimales() const;
  Animal *buscarAnimalPorId(int id) const;

  // Gestión de Adoptantes
  void registrarAdoptante(int id, std::string nombre, std::string contacto,
                          std::string tipoVivienda);
  void listarAdoptantes() const;
  Adoptante *buscarAdoptantePorId(int id);

  // Gestión de Solicitudes
  void crearSolicitud(int idAdoptante, int idAnimal);
  void mostrarSolicitudes() const;
};

#endif
```eof

```cpp : refugio.cpp
#include "Excepciones.h"
#include "Refugio.h"
#include <iostream>
#include <stdexcept>

          using namespace std;

// Contador estático para generar IDs automáticos de animales
static int contadorIdAnimal = 100;

Refugio::Refugio() {}

// El destructor se encarga de liberar la memoria de los animales instanciados
// dinámicamente
Refugio::~Refugio() {
  for (int i = 0; i < animales.cantidad(); i++) {
    delete animales[i];
  }
}

void Refugio::registrarPerro(string nombre, int edad, string salud, string raza,
                             string tamano) {
  int nuevoId = ++contadorIdAnimal;
  animales.agregar(new Perro(nuevoId, nombre, edad, salud, raza, tamano));
  cout << "Perro registrado exitosamente con ID: " << nuevoId << endl;
}

void Refugio::registrarGato(string nombre, int edad, string salud,
                            string colorPelaje, bool esDeInterior) {
  int nuevoId = ++contadorIdAnimal;
  animales.agregar(
      new Gato(nuevoId, nombre, edad, salud, colorPelaje, esDeInterior));
  cout << "Gato registrado exitosamente con ID: " << nuevoId << endl;
}

void Refugio::listarAnimales() const {
  if (animales.cantidad() == 0) {
    cout << "No hay animales registrados en el refugio." << endl;
    return;
  }
  for (int i = 0; i < animales.cantidad(); i++) {
    animales[i]->mostrarInfo();
  }
}

Animal *Refugio::buscarAnimalPorId(int id) const {
  for (int i = 0; i < animales.cantidad(); i++) {
    if (animales[i]->getId() == id) {
      return animales[i];
    }
  }
  return nullptr;
}

void Refugio::registrarAdoptante(int id, string nombre, string contacto,
                                 string tipoVivienda) {
  adoptantes.agregar(Adoptante(id, nombre, contacto, tipoVivienda));
  cout << "Adoptante registrado exitosamente." << endl;
}

void Refugio::listarAdoptantes() const {
  if (adoptantes.cantidad() == 0) {
    cout << "No hay adoptantes registrados." << endl;
    return;
  }
  for (int i = 0; i < adoptantes.cantidad(); i++) {
    cout << "ID: " << adoptantes[i].getId()
         << " | Nombre: " << adoptantes[i].getNombre() << endl;
  }
}

Adoptante *Refugio::buscarAdoptantePorId(int id) {
  for (int i = 0; i < adoptantes.cantidad(); i++) {
    if (adoptantes[i].getId() == id) {
      return &adoptantes[i];
    }
  }
  return nullptr;
}

void Refugio::crearSolicitud(int idAdoptante, int idAnimal) {
  Animal *anim = buscarAnimalPorId(idAnimal);
  if (anim == nullptr) {
    throw invalid_argument("El ID del animal no existe.");
  }

  if (!anim->isDisponible()) {
    throw AnimalNoDisponibleException();
  }

  Adoptante *adop = buscarAdoptantePorId(idAdoptante);
  if (adop == nullptr) {
    throw invalid_argument("El ID del adoptante no existe.");
  }

  // Marcar el animal como no disponible (adoptado)
  anim->setDisponible(false);

  // Guardar la solicitud
  solicitudes.agregar(SolicitudAdopcion(*adop, anim));
  cout << "¡Solicitud creada exitosamente para " << adop->getNombre() << "!"
       << endl;
}

void Refugio::mostrarSolicitudes() const {
  if (solicitudes.cantidad() == 0) {
    cout << "No hay solicitudes registradas." << endl;
    return;
  }
  for (int i = 0; i < solicitudes.cantidad(); i++) {
    solicitudes[i].mostrarSolicitud();
  }
}

#endif // REFUGIO_H