#ifndef GESTORRESERVAS_H
#define GESTORRESERVAS_H

#include <QString>
#include <QList>
#include <QDateTime>
#include "Reserva.h"
#include "Mesa.h"

class GestorReservas {
public:
    GestorReservas();

    bool agregarReserva(const Reserva &reserva);
    bool modificarReserva(const QString &referencia, const Reserva &nuevaReserva);
    bool cancelarReserva(const QString &referencia);
    QList<Reserva> consultarDisponibilidad(const QDateTime &fechaHora) const;
    QList<Mesa> getMesasDisponibles(const QDateTime &fechaHora) const;
    bool agregarMesa(const Mesa &mesa);
    bool eliminarMesa(int mesaId);
    QList<Reserva> obtenerTodasReservas() const;

    QList<Mesa> getMesas() const;


private:
    QList<Reserva> reservas;
    QList<Mesa> mesas;

    void cargarMesasDesdeArchivo(const QString &nombreArchivo); // Método para cargar mesas desde un archivo
    void guardarMesasEnArchivo(const QString &nombreArchivo);  // Método para guardar mesas en un archivo
};

#endif // GESTORRESERVAS_H


