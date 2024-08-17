#include "Reserva.h"
#include <QUuid>
#include "GestorReservas.h"

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

bool GestorReservas::modificarReserva(const QString &referencia, const Reserva &reservaModificada) {
    // Buscar la reserva existente por referencia
    for (int i = 0; i < reservas.size(); ++i) {
        if (reservas[i].getReferencia() == referencia) {
            // Modificar la reserva encontrada
            reservas[i] = reservaModificada;
            return true; // Modificación exitosa
        }
    }
    return false; // No se encontró la reserva con la referencia dada
}

Reserva* GestorReservas::obtenerReserva(const QString &referencia) {
    for (int i = 0; i < reservas.size(); ++i) {
        if (reservas[i].getReferencia() == referencia) {
            return &reservas[i];
        }
    }
    return nullptr; // No se encontró la reserva con la referencia dada
}
