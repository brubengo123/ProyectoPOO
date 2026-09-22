#include "Refugio.h"
#include <iostream>

using namespace std;

static int contadorIdAnimal = 100;

Refugio::Refugio() = default;

// Destructor: Libera la memoria de las mascotas si fueron creadas dinámicamente
Refugio::~Refugio() {
  for (Animal *m : animales) {
    delete m;
  }
  animales.clear();
}

void Refugio::registrarPerro(string nombre, int edad, string salud,
                             string raza, string tamano) {
  int nuevoId = ++contadorIdAnimal;
  animales.push_back(new Perro(nuevoId, nombre, edad, salud, raza, tamano));
  cout << "Perro registrado exitosamente con ID: " << nuevoId << endl;
}

void Refugio::registrarGato(string nombre, int edad, string salud,
                            string colorPelaje, bool esDeInterior) {
  int nuevoId = ++contadorIdAnimal;
  animales.push_back(
      new Gato(nuevoId, nombre, edad, salud, colorPelaje, esDeInterior));
  cout << "Gato registrado exitosamente con ID: " << nuevoId << endl;
}

void Refugio::listarAnimales() const {
  if (animales.empty()) {
    cout << "No hay animales registrados en el refugio." << endl;
    return;
  }
  for (const Animal *animal : animales) {
    animal->mostrarInfo();
  }
}

void Refugio::listarAnimalesDisponibles() const {
  bool hayDisponibles = false;

  for (const Animal *animal : animales) {
    if (animal->isDisponible()) {
      animal->mostrarInfo();
      hayDisponibles = true;
    }
  }

  if (!hayDisponibles) {
    cout << "No hay animales disponibles en este momento." << endl;
  }
}

Animal *Refugio::buscarAnimalPorId(int id) const {
  for (Animal *animal : animales) {
    if (animal->getId() == id) {
      return animal;
    }
  }
  return nullptr;
}
