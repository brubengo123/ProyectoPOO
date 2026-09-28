#include "Animal.h"
#include "Adoptante.h"
#include "SolicitudAdopcion.h"
#include <string>
#include <vector>

class Refugio {
private:
  std::vector<Animal *> animales;
  std::vector<Adoptante *> adoptantes;
  std::vector<SolicitudAdopcion *> solicitudes;

public:
  Refugio();
  Refugio(const Refugio &otro);
  Refugio &operator=(const Refugio &otro);
  ~Refugio();

  // Gestion de Animales
  void registrarPerro(std::string nombre, int edad, std::string salud,
                      std::string raza, std::string tamano);
  void registrarGato(std::string nombre, int edad, std::string salud,
                     std::string colorPelaje, bool esDeInterior);
  void listarAnimales() const;
  void listarAnimalesDisponibles() const;
  // Los punteros devueltos son prestados; Refugio conserva su propiedad.
  Animal *buscarAnimalPorId(int id);
  const Animal *buscarAnimalPorId(int id) const;
  Animal *operator[](size_t posicion);
  const Animal *operator[](size_t posicion) const;
  Animal *operator()(int id);
  const Animal *operator()(int id) const;

  // Gestion de Adoptantes
  int registrarAdoptante(std::string nombre, std::string telefono,
                         std::string correo);
  void listarAdoptantes() const;
  Adoptante *buscarAdoptantePorId(int id);
  const Adoptante *buscarAdoptantePorId(int id) const;

  // Gestion de SolicitudesAdopcion
  int crearSolicitud(int idAdoptante, int idAnimal);
  bool confirmarSolicitud(int idSolicitud);
  bool cancelarSolicitud(int idSolicitud);
  bool devolverAnimal(int idAnimal);
  void listarSolicitudes() const;
};