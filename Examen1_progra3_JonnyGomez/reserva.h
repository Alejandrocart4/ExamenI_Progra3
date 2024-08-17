#ifndef RESERVA_H
#define RESERVA_H

#include <QString>
#include <QDateTime>

class Reserva {
public:
    Reserva(QString referencia, int mesaId, QDateTime fechaHora, QString nombreCliente, QString numeroContacto);
    Reserva(const QString &nombre, const QString &contacto, int numComensales, const QDateTime &fechaHora, int mesaId); // Añadido

    QString getReferencia() const;
    int getMesaId() const;
    QDateTime getFechaHora() const;
    QString getNombreCliente() const;
    QString getNumeroContacto() const;

    void setNombreCliente(const QString &nombreCliente);
    void setNumeroContacto(const QString &numeroContacto);
    void setMesaId(int mesaId);
    void setFechaHora(const QDateTime &fechaHora);

private:
    QString referencia;
    int mesaId;
    QDateTime fechaHora;
    QString nombreCliente;
    QString numeroContacto;
};
#endif // RESERVA_H
