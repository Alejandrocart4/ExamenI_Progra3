#ifndef MESA_H
#define MESA_H

#include <QDateTime>
#include <QList>

class Mesa {
public:
    Mesa(int id, int capacidad);

    int obtenerId() const;
    int obtenerCapacidad() const;
    bool estaDisponible(const QDateTime &fechaHora) const;

    void reservar(const QDateTime &fechaHora);
    void cancelarReservacion(const QDateTime &fechaHora);

private:
    int id;
    int capacidad;
    QList<QDateTime> reservaciones;
};
#endif // MESA_H
