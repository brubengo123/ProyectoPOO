#include "Refugio.h"
#include "Excepciones.h"
#include <iostream>
#include <stdexcept>

using namespace std;

static int contadorIdAnimal = 100;
static int contadorIdAdoptante = 0;
static int contadorIdSolicitud = 0;

namespace {
const char *textoEstado(EstadoSolicitud estado) {
  switch (estado) {
  case EstadoSolicitud::Pendiente:
    return "Pendiente";
  case EstadoSolicitud::Confirmada:
    return "Confirmada";
  case EstadoSolicitud::Cancelada:
    return "Cancelada";
  }
  return "Desconocida";
}
}

Adoptante::Adoptante() : Adoptante(0, "", "", "", "") {}

Adoptante::Adoptante(int id, string nombre, string telefono, string correo,
                     string tipoVivienda)
    : id(id), nombre(nombre), telefono(telefono), correo(correo),
      tipoVivienda(tipoVivienda) {}

Adoptante::Adoptante(const Adoptante &otro)
    : id(otro.id), nombre(otro.nombre), telefono(otro.telefono),
      correo(otro.correo), tipoVivienda(otro.tipoVivienda) {}

int Adoptante::getId() const { return id; }
string Adoptante::getNombre() const { return nombre; }
string Adoptante::getTelefono() const { return telefono; }
string Adoptante::getCorreo() const { return correo; }
string Adoptante::getTipoVivienda() const { return tipoVivienda; }

void Adoptante::mostrarInfo() const {
  cout << "--- ADOPTANTE ---\n"
       << "ID: " << id << "\n"
       << "Nombre: " << nombre << "\n"
       << "Telefono: " << telefono << "\n"
       << "Correo: " << correo << "\n"
       << "Tipo de vivienda: " << tipoVivienda << "\n"
       << "-----------------\n";
}

SolicitudAdopcion::SolicitudAdopcion()
    : SolicitudAdopcion(0, nullptr, nullptr) {}

SolicitudAdopcion::SolicitudAdopcion(int id, Adoptante *adoptante,
                                     Animal *animal)
    : id(id), adoptante(adoptante), animal(animal),
      estado(EstadoSolicitud::Pendiente) {}

SolicitudAdopcion::SolicitudAdopcion(const SolicitudAdopcion &otra)
    : id(otra.id), adoptante(otra.adoptante), animal(otra.animal),
      estado(otra.estado) {}

int SolicitudAdopcion::getId() const { return id; }
Adoptante *SolicitudAdopcion::getAdoptante() { return adoptante; }
const Adoptante *SolicitudAdopcion::getAdoptante() const { return adoptante; }
Animal *SolicitudAdopcion::getAnimal() { return animal; }
const Animal *SolicitudAdopcion::getAnimal() const { return animal; }
EstadoSolicitud SolicitudAdopcion::getEstado() const { return estado; }
void SolicitudAdopcion::setEstado(EstadoSolicitud nuevoEstado) {
  estado = nuevoEstado;
}
void SolicitudAdopcion::reasignar(Adoptante *nuevoAdoptante,
                                  Animal *nuevoAnimal) {
  adoptante = nuevoAdoptante;
  animal = nuevoAnimal;
}

void SolicitudAdopcion::mostrarInfo() const {
  cout << "Solicitud " << id << " | Adoptante: "
       << (adoptante ? adoptante->getNombre() : "N/A")
       << " | Animal: " << (animal ? animal->getNombre() : "N/A")
       << " | Estado: " << textoEstado(estado) << '\n';
}

Refugio::Refugio() = default;

Refugio::Refugio(const Refugio &otro) {
  for (const Animal *animal : otro.animales) {
    animales.push_back(animal->clonar());
  }
  for (const Adoptante *adoptante : otro.adoptantes) {
    adoptantes.push_back(new Adoptante(*adoptante));
  }
  for (const SolicitudAdopcion *solicitud : otro.solicitudes) {
    Animal *animal = buscarAnimalPorId(solicitud->getAnimal()->getId());
    Adoptante *adoptante =
        buscarAdoptantePorId(solicitud->getAdoptante()->getId());
    SolicitudAdopcion *copia =
        new SolicitudAdopcion(solicitud->getId(), adoptante, animal);
    copia->setEstado(solicitud->getEstado());
    solicitudes.push_back(copia);
  }
}

Refugio &Refugio::operator=(const Refugio &otro) {
  if (this == &otro) {
    return *this;
  }

  for (Animal *animal : animales) {
    delete animal;
  }
  for (Adoptante *adoptante : adoptantes) {
    delete adoptante;
  }
  for (SolicitudAdopcion *solicitud : solicitudes) {
    delete solicitud;
  }
  animales.clear();
  adoptantes.clear();
  solicitudes.clear();

  for (const Animal *animal : otro.animales) {
    animales.push_back(animal->clonar());
  }
  for (const Adoptante *adoptante : otro.adoptantes) {
    adoptantes.push_back(new Adoptante(*adoptante));
  }
  for (const SolicitudAdopcion *solicitud : otro.solicitudes) {
    Animal *animal = buscarAnimalPorId(solicitud->getAnimal()->getId());
    Adoptante *adoptante =
        buscarAdoptantePorId(solicitud->getAdoptante()->getId());
    SolicitudAdopcion *copia =
        new SolicitudAdopcion(solicitud->getId(), adoptante, animal);
    copia->setEstado(solicitud->getEstado());
    solicitudes.push_back(copia);
  }
  return *this;
}

Refugio::~Refugio() {
  for (Animal **it = animales.data(); it != animales.data() + animales.size();
       ++it) {
    delete *it;
  }
  for (Adoptante **it = adoptantes.data();
       it != adoptantes.data() + adoptantes.size(); ++it) {
    delete *it;
  }
  for (SolicitudAdopcion **it = solicitudes.data();
       it != solicitudes.data() + solicitudes.size(); ++it) {
    delete *it;
  }
}

void Refugio::registrarPerro(string nombre, int edad, string salud,
                             string raza, string tamano) {
  int nuevoId = ++contadorIdAnimal;
  if (buscarAnimalPorId(nuevoId) != nullptr) {
    throw IdDuplicadoException(nuevoId);
  }
  animales.push_back(new Perro(nuevoId, nombre, edad, salud, raza, tamano));
  cout << "Perro registrado exitosamente con ID: " << nuevoId << endl;
}

void Refugio::registrarGato(string nombre, int edad, string salud,
                            string colorPelaje, bool esDeInterior) {
  int nuevoId = ++contadorIdAnimal;
  if (buscarAnimalPorId(nuevoId) != nullptr) {
    throw IdDuplicadoException(nuevoId);
  }
  animales.push_back(
      new Gato(nuevoId, nombre, edad, salud, colorPelaje, esDeInterior));
  cout << "Gato registrado exitosamente con ID: " << nuevoId << endl;
}

void Refugio::listarAnimales() const {
  if (animales.empty()) {
    cout << "No hay animales registrados en el refugio." << endl;
    return;
  }
  for (Animal *const *it = animales.data();
       it != animales.data() + animales.size(); ++it) {
    (*it)->mostrarInfo();
  }
}

void Refugio::listarAnimalesDisponibles() const {
  bool hayDisponibles = false;
  for (Animal *const *it = animales.data();
       it != animales.data() + animales.size(); ++it) {
    if ((*it)->isDisponible()) {
      (*it)->mostrarInfo();
      hayDisponibles = true;
    }
  }
  if (!hayDisponibles) {
    cout << "No hay animales disponibles en este momento." << endl;
  }
}

Animal *Refugio::buscarAnimalPorId(int id) {
  for (Animal *const *it = animales.data();
       it != animales.data() + animales.size(); ++it) {
    if ((*it)->getId() == id) {
      return *it;
    }
  }
  return nullptr;
}

const Animal *Refugio::buscarAnimalPorId(int id) const {
  for (Animal *const *it = animales.data();
       it != animales.data() + animales.size(); ++it) {
    if ((*it)->getId() == id) {
      return *it;
    }
  }
  return nullptr;
}

Animal *Refugio::operator()(int id) { return buscarAnimalPorId(id); }

const Animal *Refugio::operator()(int id) const {
  return buscarAnimalPorId(id);
}

int Refugio::registrarAdoptante(string nombre, string telefono, string correo,
                                string tipoVivienda) {
  int nuevoId = ++contadorIdAdoptante;
  if (buscarAdoptantePorId(nuevoId) != nullptr) {
    throw IdDuplicadoException(nuevoId);
  }
  adoptantes.push_back(
      new Adoptante(nuevoId, nombre, telefono, correo, tipoVivienda));
  cout << "Adoptante registrado exitosamente con ID: " << nuevoId << endl;
  return nuevoId;
}

void Refugio::listarAdoptantes() const {
  if (adoptantes.empty()) {
    cout << "No hay adoptantes registrados." << endl;
    return;
  }
  for (Adoptante *const *it = adoptantes.data();
       it != adoptantes.data() + adoptantes.size(); ++it) {
    (*it)->mostrarInfo();
  }
}

Adoptante *Refugio::buscarAdoptantePorId(int id) {
  for (Adoptante *const *it = adoptantes.data();
       it != adoptantes.data() + adoptantes.size(); ++it) {
    if ((*it)->getId() == id) {
      return *it;
    }
  }
  return nullptr;
}

const Adoptante *Refugio::buscarAdoptantePorId(int id) const {
  for (Adoptante *const *it = adoptantes.data();
       it != adoptantes.data() + adoptantes.size(); ++it) {
    if ((*it)->getId() == id) {
      return *it;
    }
  }
  return nullptr;
}

int Refugio::crearSolicitud(int idAdoptante, int idAnimal) {
  Adoptante *adoptante = buscarAdoptantePorId(idAdoptante);
  Animal *animal = buscarAnimalPorId(idAnimal);
  if (adoptante == nullptr || animal == nullptr) {
    return 0;
  }
  if (!animal->isDisponible()) {
    throw AnimalNoDisponibleException(idAnimal);
  }
  int nuevoId = ++contadorIdSolicitud;
  for (const SolicitudAdopcion *solicitud : solicitudes) {
    if (solicitud->getId() == nuevoId) {
      throw IdDuplicadoException(nuevoId);
    }
  }
  solicitudes.push_back(new SolicitudAdopcion(nuevoId, adoptante, animal));
  return nuevoId;
}

bool Refugio::confirmarSolicitud(int idSolicitud) {
  for (SolicitudAdopcion *solicitud : solicitudes) {
    if (solicitud->getId() == idSolicitud &&
        solicitud->getEstado() == EstadoSolicitud::Pendiente &&
        solicitud->getAnimal()->isDisponible()) {
      solicitud->setEstado(EstadoSolicitud::Confirmada);
      solicitud->getAnimal()->setDisponible(false);
      return true;
    }
  }
  return false;
}

bool Refugio::cancelarSolicitud(int idSolicitud) {
  for (SolicitudAdopcion *solicitud : solicitudes) {
    if (solicitud->getId() == idSolicitud &&
        solicitud->getEstado() == EstadoSolicitud::Pendiente) {
      solicitud->setEstado(EstadoSolicitud::Cancelada);
      return true;
    }
  }
  return false;
}

bool Refugio::devolverAnimal(int idAnimal) {
  Animal *animal = buscarAnimalPorId(idAnimal);
  if (animal == nullptr || animal->isDisponible()) {
    return false;
  }
  animal->setDisponible(true);
  return true;
}

void Refugio::listarSolicitudes() const {
  if (solicitudes.empty()) {
    cout << "No hay solicitudes registradas." << endl;
    return;
  }
  for (const SolicitudAdopcion *solicitud : solicitudes) {
    solicitud->mostrarInfo();
  }
}
