
#pragma once

#include <string>

using namespace std;

// 1. Clase Base: Contiene lo que tienen TODOS los animales
class Animal {
protected:
  int id;             // ID
  string nombre;      // Nombre
  int edad;           // Edad
  string estadoSalud; // Estado de salud
  bool disponible;    // Estado de adopción (true: Disponible / false: Adoptado)

public:
  // Constructor por defecto y parametrizado
  Animal(int id, string nombre, int edad, string estadoSalud);
  virtual ~Animal();

  virtual void mostrarInfo() const = 0;

  // Getters y Setters //
  int getId() const;
  string getNombre() const;
  int getEdad() const;
  string getEstadoSalud() const;
  bool isDisponible() const;
  void setDisponible(bool estado);
};

// 2. Clase Derivada: PERRO (Hereda de Animal) //
class Perro : public Animal {
private:
  string raza;
  string tamano;

public:
  Perro(int id, string nombre, int edad, string estadoSalud, string raza,
        string tamano);

  // Métodos propios de Perro
  string getRaza() const;
  string getTamano() const;
  void mostrarInfo() const override;
};

// 3. Clase Derivada: GATO (Hereda de Animal)
class Gato : public Animal {
private:
  string colorPelaje; // Agrega color de pelaje

public:
  Gato(int id, string nombre, int edad, string estadoSalud, string colorPelaje);

  // Métodos propios de Gato
  string getColorPelaje() const;
  void mostrarInfo() const override;
};
