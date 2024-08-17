#include "Reserva.h"
#include <QUuid>

Reserva::Reserva(QString referencia, int mesaId, QDateTime fechaHora, QString nombreCliente, QString numeroContacto)
    : referencia(referencia), mesaId(mesaId), fechaHora(fechaHora),
    nombreCliente(nombreCliente), numeroContacto(numeroContacto) {}

Reserva::Reserva(const QString &nombreCliente, const QString &numeroContacto, int numComensales, const QDateTime &fechaHora, int mesaId)
    : nombreCliente(nombreCliente), numeroContacto(numeroContacto), mesaId(mesaId), fechaHora(fechaHora) {
    referencia = QUuid::createUuid().toString(); // Genera un identificador único
}

QString Reserva::getReferencia() const { return referencia; }
int Reserva::getMesaId() const { return mesaId; }
QDateTime Reserva::getFechaHora() const { return fechaHora; }
QString Reserva::getNombreCliente() const { return nombreCliente; }
QString Reserva::getNumeroContacto() const { return numeroContacto; }

void Reserva::setNombreCliente(const QString &nombreCliente) { this->nombreCliente = nombreCliente; }
void Reserva::setNumeroContacto(const QString &numeroContacto) { this->numeroContacto = numeroContacto; }
void Reserva::setMesaId(int mesaId) { this->mesaId = mesaId; }
void Reserva::setFechaHora(const QDateTime &fechaHora) { this->fechaHora = fechaHora; }
