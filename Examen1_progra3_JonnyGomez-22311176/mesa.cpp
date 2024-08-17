#include "Mesa.h"

Mesa::Mesa(int id, int capacidad)
    : id(id), capacidad(capacidad) {}

int Mesa::obtenerId() const {
    return id;
}

int Mesa::obtenerCapacidad() const {
    return capacidad;
}

bool Mesa::estaDisponible(const QDateTime &fechaHora) const {
    return !reservaciones.contains(fechaHora);
}

void Mesa::reservar(const QDateTime &fechaHora) {
    if (!reservaciones.contains(fechaHora)) {
        reservaciones.append(fechaHora);
    }
}

void Mesa::cancelarReservacion(const QDateTime &fechaHora) {
    reservaciones.removeOne(fechaHora);
}
