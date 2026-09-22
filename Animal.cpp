#include "Animal.h"
#include <iostream>
#include <string>
using namespace std;


// Constructor de Animal
Animal::Animal() : Animal(0, "", 0, "") {}

Animal::Animal(int id, string nombre, int edad, string estadoSalud)
    : id(id), nombre(nombre), edad(edad), estadoSalud(estadoSalud),
      disponible(true) {}

Animal::Animal(const Animal &otro)
    : id(otro.id), nombre(otro.nombre), edad(otro.edad),
      estadoSalud(otro.estadoSalud), disponible(otro.disponible) {}

// Destructor virtual
Animal::~Animal() {}

// Getters y Setters de Animal
int Animal::getId() const { return id; }
string Animal::getNombre() const { return nombre; }
int Animal::getEdad() const { return edad; }
string Animal::getEstadoSalud() const { return estadoSalud; }
bool Animal::isDisponible() const { return disponible; }
void Animal::setDisponible(bool estado) { disponible = estado; }
bool Animal::operator==(const Animal &otro) const { return id == otro.id; }
bool Animal::operator!() const { return !disponible; }

// Constructor de Perro //
Perro::Perro() : Perro(0, "", 0, "", "", "") {}

Perro::Perro(int id, string nombre, int edad, string estadoSalud, string raza,
             string tamano)
    : Animal(id, nombre, edad, estadoSalud), raza(raza), tamano(tamano) {}

Perro::Perro(const Perro &otro)
  : Animal(otro), raza(otro.raza), tamano(otro.tamano) {}

// Getters de Perro
string Perro::getRaza() const { return raza; }
string Perro::getTamano() const { return tamano; }

// Muestra toda la información del Perro //
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

Animal *Perro::clonar() const { return new Perro(*this); }


// Constructor de Gato //
Gato::Gato() : Gato(0, "", 0, "", "", false) {}

Gato ::  Gato(int id, string nombre, int edad, string estadoSalud,
      string colorPelaje, bool esDeInterior)
    : Animal(id, nombre, edad, estadoSalud), colorPelaje(colorPelaje),
      esDeInterior(esDeInterior) {}

Gato::Gato(const Gato &otro)
    : Animal(otro), colorPelaje(otro.colorPelaje),
      esDeInterior(otro.esDeInterior) {}

string Gato::getColorPelaje() const { return colorPelaje; }
bool Gato::getEsDeInterior() const { return esDeInterior; }


// Muestra toda la información del Gato //
void Gato::mostrarInfo() const {
  cout << "--- [GATO] ---" << endl;
  cout << "ID: " << id << endl;
  cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << " años" << endl;
  cout << "Salud: " << estadoSalud << endl;
  cout << "Pelaje: " << colorPelaje << endl;
    cout << "Vive en interior: " << (esDeInterior ? "Si" : "No") << endl;
    cout << "Estado de Adopción: " << (disponible ? "Disponible" : "Adoptado")
      << endl;
  cout << "----------------" << endl;
}

Animal *Gato::clonar() const { return new Gato(*this); }