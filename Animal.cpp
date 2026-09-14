#include "Animal.h"
#include <iostream>

using namespace std;

// ==========================================
// IMPLEMENTACIÓN DE LA CLASE BASE: Animal
// ==========================================

// Constructor de Animal
Animal::Animal(int id, string nombre, int edad, string estadoSalud)
    : id(id), nombre(nombre), edad(edad), estadoSalud(estadoSalud),
      disponible(true) {}

// Destructor virtual
Animal::~Animal() {}

// Getters y Setters de Animal
int Animal::getId() const { return id; }
string Animal::getNombre() const { return nombre; }
int Animal::getEdad() const { return edad; }
string Animal::getEstadoSalud() const { return estadoSalud; }
bool Animal::isDisponible() const { return disponible; }
void Animal::setDisponible(bool estado) { disponible = estado; }

// ==========================================
// IMPLEMENTACIÓN DE LA CLASE DERIVADA: Perro
// ==========================================

// Constructor de Perro (Llama al constructor de la clase base Animal)
Perro::Perro(int id, string nombre, int edad, string estadoSalud, string raza,
             string tamano)
    : Animal(id, nombre, edad, estadoSalud), raza(raza), tamano(tamano) {}

// Getters de Perro
string Perro::getRaza() const { return raza; }
string Perro::getTamano() const { return tamano; }

// Muestra toda la información del Perro
void Perro::mostrarInfo() const {
  cout << "--- [PERRO] ---" << endl;
  cout << "ID: " << id << endl;
  cout << "Nombre: " << nombre << endl;
  cout << "Edad: " << edad << " años" << endl;
  cout << "Salud: " << estadoSalud << endl;
  cout << "Raza: " << raza << endl;
  cout << "Tamaño: " << tamano << endl;
  cout << "Estado de Adopción: " << (disponible ? "Disponible" : "Adoptado")
       << endl;
  cout << "----------------" << endl;
}

// ==========================================
// IMPLEMENTACIÓN DE LA CLASE DERIVADA: Gato
// ==========================================

// Constructor de Gato (Llama al constructor de la clase base Animal)
Gato::Gato(int id, string nombre, int edad, string estadoSalud,
           string colorPelaje, bool esDeInterior)
    : Animal(id, nombre, edad, estadoSalud), colorPelaje(colorPelaje),
      esDeInterior(esDeInterior) {}

// Getters de Gato
string Gato::getColorPelaje() const { return colorPelaje; }
bool Gato::getEsDeInterior() const { return esDeInterior; }

// Muestra toda la información del Gato
void Gato::mostrarInfo() const {
  cout << "--- [GATO] ---" << endl;
  cout << "ID: " << id << endl;
  cout << "Nombre: " << nombre << endl;
  cout << "Edad: " << edad << " años" << endl;
  cout << "Salud: " << estadoSalud << endl;
  cout << "Pelaje: " << colorPelaje << endl;
  cout << "Condición: "
       << (esDeInterior ? "Gato de Interior" : "Gato de Exterior") << endl;
  cout << "Estado de Adopción: " << (disponible ? "Disponible" : "Adoptado")
       << endl;
  cout << "----------------" << endl;
}