#pragma once

#include "Adoptante.h"
#include "Animal.h"

enum class EstadoSolicitud { Pendiente, Confirmada, Cancelada };

class SolicitudAdopcion {
private:
  int id;
  Adoptante *adoptante;
  Animal *animal;
  EstadoSolicitud estado;

public:
  SolicitudAdopcion();
  SolicitudAdopcion(int id, Adoptante *adoptante, Animal *animal);
  SolicitudAdopcion(const SolicitudAdopcion &otra);

  int getId() const;
  // Estos punteros son referencias prestadas; no transfieren propiedad.
  Adoptante *getAdoptante();
  const Adoptante *getAdoptante() const;
  Animal *getAnimal();
  const Animal *getAnimal() const;
  EstadoSolicitud getEstado() const;
  void setEstado(EstadoSolicitud nuevoEstado);
  void reasignar(Adoptante *nuevoAdoptante, Animal *nuevoAnimal);
  void mostrarInfo() const;
};