#ifndef RESERVACION_H
#define RESERVACION_H

#include <QString>
#include <QDateTime>

class Reservacion {
public:

    Reservacion(const QString &nombre = "", const QString &contacto = "", int comensales = 0, const QDateTime &fechaHora = QDateTime());

    QString obtenerNombre() const;
    void establecerNombre(const QString &nombre);

    QString obtenerContacto() const;
    void establecerContacto(const QString &contacto);

    int obtenerComensales() const;
    void establecerComensales(int comensales);

    QDateTime obtenerFechaHora() const;
    void establecerFechaHora(const QDateTime &fechaHora);

    QString obtenerReferencia() const;
    void establecerReferencia(const QString &referencia);

private:
    QString nombre;
    QString contacto;
    int comensales;
    QDateTime fechaHora;
    QString referencia;

};
#endif // RESERVACION_H
