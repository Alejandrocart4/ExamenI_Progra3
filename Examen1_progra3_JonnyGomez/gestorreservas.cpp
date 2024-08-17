#include "GestorReservas.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

GestorReservas::GestorReservas() {

    mesas.append(Mesa(1, 4, true));
    mesas.append(Mesa(2, 2, true));
    mesas.append(Mesa(3, 6, true));
    cargarMesasDesdeArchivo("mesas.txt");
}

QList<Mesa> GestorReservas::getMesas() const {
    return mesas;
}

void GestorReservas::cargarMesasDesdeArchivo(const QString &nombreArchivo) {
    QFile archivo(nombreArchivo);

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo de mesas";
        return;
    }

    QTextStream in(&archivo);
    while (!in.atEnd()) {
        QString linea = in.readLine();
        QStringList datosMesa = linea.split(',');

        if (datosMesa.size() == 3) {
            int id = datosMesa[0].toInt();
            int capacidad = datosMesa[1].toInt();
            bool habilitada = (datosMesa[2] == "true");

            Mesa mesa(id, capacidad, habilitada);
            mesas.append(mesa);
        }
    }

    archivo.close();
}

void GestorReservas::guardarMesasEnArchivo(const QString &nombreArchivo) {
    QFile archivo(nombreArchivo);

    if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "No se pudo abrir el archivo para escribir.";
        return;
    }

    QTextStream out(&archivo);

    for (const Mesa &mesa : mesas) {
        out << mesa.getId() << ","
            << mesa.getCapacidad() << ","
            << (mesa.isHabilitada() ? "true" : "false")
            << "\n";
    }

    archivo.close();
}

bool GestorReservas::agregarReserva(const Reserva &reserva) {
    reservas.append(reserva);
    return true;
}

bool GestorReservas::modificarReserva(const QString &referencia, const Reserva &nuevaReserva) {
    for (int i = 0; i < reservas.size(); ++i) {
        if (reservas[i].getReferencia() == referencia) {
            reservas[i] = nuevaReserva;
            return true;
        }
    }
    return false;
}

bool GestorReservas::cancelarReserva(const QString &referencia) {
    for (int i = 0; i < reservas.size(); ++i) {
        if (reservas[i].getReferencia() == referencia) {
            reservas.removeAt(i);
            return true;
        }
    }
    return false;
}

QList<Reserva> GestorReservas::consultarDisponibilidad(const QDateTime &fechaHora) const {
    QList<Reserva> disponibles;
    for (const Reserva &reserva : reservas) {
        if (reserva.getFechaHora() == fechaHora) {
            disponibles.append(reserva);
        }
    }
    return disponibles;
}

QList<Mesa> GestorReservas::getMesasDisponibles(const QDateTime &fechaHora) const {
    QList<Mesa> disponibles;
    for (const Mesa &mesa : mesas) {
        bool ocupada = false;
        for (const Reserva &reserva : reservas) {
            if (reserva.getMesaId() == mesa.getId() && reserva.getFechaHora() == fechaHora) {
                ocupada = true;
                break;
            }
        }
        if (!ocupada && mesa.isHabilitada()) {
            disponibles.append(mesa);
        }
    }
    return disponibles;
}

bool GestorReservas::agregarMesa(const Mesa &mesa) {
    mesas.append(mesa);
    guardarMesasEnArchivo("mesas.txt"); // Actualiza el archivo con la nueva mesa
    return true;
}

bool GestorReservas::eliminarMesa(int mesaId) {
    for (int i = 0; i < mesas.size(); ++i) {
        if (mesas[i].getId() == mesaId) {
            mesas.removeAt(i);
            guardarMesasEnArchivo("mesas.txt"); // Actualiza el archivo después de eliminar la mesa
            return true;
        }
    }
    return false;
}

QList<Reserva> GestorReservas::obtenerTodasReservas() const {
    return reservas;
}


