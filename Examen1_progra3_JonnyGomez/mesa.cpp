#include "Mesa.h"

Mesa::Mesa(int id, int capacidad, bool habilitada)
    : id(id), capacidad(capacidad), habilitada(habilitada) {}

int Mesa::getId() const { return id; }
int Mesa::getCapacidad() const { return capacidad; }
bool Mesa::isHabilitada() const { return habilitada; }

void Mesa::setCapacidad(int capacidad) { this->capacidad = capacidad; }
void Mesa::setHabilitada(bool habilitada) { this->habilitada = habilitada; }
