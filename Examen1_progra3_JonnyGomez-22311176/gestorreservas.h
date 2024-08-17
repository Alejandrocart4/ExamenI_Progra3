#ifndef GESTORRESERVAS_H
#define GESTORRESERVAS_H

#include <QList>
#include <QString>
#include "Reservacion.h"
#include "Mesa.h"

class GestorReservas {
public:
    GestorReservas();

    QString agregarReservacion(const Reservacion &reservacion);
    bool modificarReservacion(const QString &referencia, const Reservacion &nuevosDetalles);
    bool cancelarReservacion(const QString &referencia);
    QList<Mesa> obtenerMesasDisponibles(const QDateTime &fechaHora) const;

    void agregarMesa(int id, int capacidad);
    bool eliminarMesa(int idMesa);
    QList<Reservacion> obtenerTodasReservaciones() const;

private:
    QString generarReferenciaUnica();
    QList<Reservacion> reservaciones;
    QList<Mesa> mesas;
    QString ultimaReferencia;
    int contadorReferencias = 0;
};
#endif // GESTORRESERVAS_H
