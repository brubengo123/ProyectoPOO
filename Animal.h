
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
  Animal();
  Animal(int id, string nombre, int edad, string estadoSalud);
  Animal(const Animal &otro);
  virtual ~Animal();

  virtual void mostrarInfo() const = 0;
  virtual Animal *clonar() const = 0;

  // Getters y Setters //
  int getId() const;
  string getNombre() const;
  int getEdad() const;
  string getEstadoSalud() const;
  bool isDisponible() const;
  void setDisponible(bool estado);

  bool operator==(const Animal &otro) const;
  bool operator!() const;
};

// 2. Clase Derivada: PERRO (Hereda de Animal) //
class Perro : public Animal {
private:
  string raza;
  string tamano;

public:
  Perro();
  Perro(int id, string nombre, int edad, string estadoSalud, string raza,
        string tamano);
  Perro(const Perro &otro);

  // Métodos propios de Perro
  string getRaza() const;
  string getTamano() const;
  void mostrarInfo() const override;
  Animal *clonar() const override;
};

// 3. Clase Derivada: GATO (Hereda de Animal)
class Gato : public Animal {
private:
  string colorPelaje; // Agrega color de pelaje
  bool esDeInterior;

public:
  Gato();
  Gato(int id, string nombre, int edad, string estadoSalud, string colorPelaje,
       bool esDeInterior);
  Gato(const Gato &otro);

  // Métodos propios de Gato
  string getColorPelaje() const;
  bool getEsDeInterior() const;
  void mostrarInfo() const override;
  Animal *clonar() const override;
};
