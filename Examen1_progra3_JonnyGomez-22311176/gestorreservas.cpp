#include "GestorReservas.h"

GestorReservas::GestorReservas() {
    // Inicializar las mesas
    mesas.append(Mesa(1, 4));
    mesas.append(Mesa(2, 2));
    mesas.append(Mesa(3, 6));
}

QString GestorReservas::generarReferenciaUnica() {
    return QString::number(++contadorReferencias);
}

QString GestorReservas::agregarReservacion(const Reservacion &reservacion) {
    Reservacion nuevaReservacion = reservacion;
    QString referencia = generarReferenciaUnica();
    nuevaReservacion.establecerReferencia(referencia);

    for (int i = 0; i < mesas.size(); ++i) {
        Mesa &mesa = mesas[i];
        if (mesa.estaDisponible(nuevaReservacion.obtenerFechaHora())) {
            mesa.reservar(nuevaReservacion.obtenerFechaHora());
            reservaciones.append(nuevaReservacion);
            ultimaReferencia = referencia;
            return referencia;
        }
    }
    return QString();
}

bool GestorReservas::modificarReservacion(const QString &referencia, const Reservacion &nuevosDetalles) {
    for (int i = 0; i < reservaciones.size(); ++i) {
        if (reservaciones[i].obtenerReferencia() == referencia) {
            bool reservacionCancelada = false;
            for (int j = 0; j < mesas.size(); ++j) {
                Mesa &mesa = mesas[j];
                if (!mesa.estaDisponible(reservaciones[i].obtenerFechaHora())) {
                    mesa.cancelarReservacion(reservaciones[i].obtenerFechaHora());
                    reservacionCancelada = true;
                    break;
                }
            }

            if (!reservacionCancelada) {
                return false;
            }

            // Actualizar la reservación
            reservaciones[i] = nuevosDetalles;
            reservaciones[i].establecerReferencia(referencia);

            for (int j = 0; j < mesas.size(); ++j) {
                Mesa &mesa = mesas[j];
                if (mesa.estaDisponible(nuevosDetalles.obtenerFechaHora())) {
                    mesa.reservar(nuevosDetalles.obtenerFechaHora());
                    return true;
                }
            }
            return false;
        }
    }
    return false; // No se encontró la reservación
}

bool GestorReservas::cancelarReservacion(const QString &referencia) {
    for (int i = 0; i < reservaciones.size(); ++i) {
        if (reservaciones[i].obtenerReferencia() == referencia) {
            // Cancelar la reservación
            for (int j = 0; j < mesas.size(); ++j) {
                Mesa &mesa = mesas[j];
                if (!mesa.estaDisponible(reservaciones[i].obtenerFechaHora())) {
                    mesa.cancelarReservacion(reservaciones[i].obtenerFechaHora());
                    reservaciones.removeAt(i);
                    return true;
                }
            }

            reservaciones.removeAt(i);
            return false;  // La reservación no pudo ser cancelada
        }
    }
    return false;  // No se encontró la reservación
}

QList<Mesa> GestorReservas::obtenerMesasDisponibles(const QDateTime &fechaHora) const {
    QList<Mesa> mesasDisponibles;
    foreach (const Mesa &mesa, mesas) {
        if (mesa.estaDisponible(fechaHora)) {
            mesasDisponibles.append(mesa);
        }
    }
    return mesasDisponibles;
}

void GestorReservas::agregarMesa(int id, int capacidad) {
    Mesa nuevaMesa(id, capacidad);
    mesas.append(nuevaMesa);
}

bool GestorReservas::eliminarMesa(int idMesa) {
    for (int i = 0; i < mesas.size(); ++i) {
        if (mesas[i].obtenerId() == idMesa) {
            mesas.removeAt(i);
            return true;
        }
    }
    return false;
}

QList<Reservacion> GestorReservas::obtenerTodasReservaciones() const {
    return reservaciones;
}
