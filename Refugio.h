#include "Animal.h"
#include <string>
#include <vector>

class Refugio {
private:
  std::vector<Animal *> animales;

public:
  Refugio();
  ~Refugio();

  // Gestion de Animales
  void registrarPerro(std::string nombre, int edad, std::string salud,
                      std::string raza, std::string tamano);
  void registrarGato(std::string nombre, int edad, std::string salud,
                     std::string colorPelaje, bool esDeInterior);
  void listarAnimales() const;
  void listarAnimalesDisponibles() const;
  Animal *buscarAnimalPorId(int id) const;
};