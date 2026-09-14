ifndef ANIMAL_H
#define ANIMAL_H

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
  virtual ~Animal(); // Destructor virtual para polimorfismo

  // Método virtual puro para obligar a Perro y Gato a mostrar su info
  virtual void mostrarInfo() const = 0;

  // Getters y Setters
  int getId() const;
  string getNombre() const;
  int getEdad() const;
  string getEstadoSalud() const;
  bool isDisponible() const;
  void setDisponible(bool estado);
};

// 2. Clase Derivada: PERRO (Hereda de Animal)
class Perro : public Animal {
private:
  string raza;   // Agrega raza
  string tamano; // Agrega tamaño ("Grande", "Mediano", "Pequeño")

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
  bool esDeInterior;  // Agrega condición (true: Interior / false: Exterior)

public:
  Gato(int id, string nombre, int edad, string estadoSalud, string colorPelaje,
       bool esDeInterior);

  // Métodos propios de Gato
  string getColorPelaje() const;
  bool getEsDeInterior() const;
  void mostrarInfo() const override;
};

#endif