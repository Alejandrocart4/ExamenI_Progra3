#include "Reservacion.h"

Reservacion::Reservacion(const QString &nombre, const QString &contacto, int comensales, const QDateTime &fechaHora)
    : nombre(nombre), contacto(contacto), comensales(comensales), fechaHora(fechaHora) {}

QString Reservacion::obtenerNombre() const { return nombre; }
void Reservacion::establecerNombre(const QString &nombre) { this->nombre = nombre; }

QString Reservacion::obtenerContacto() const { return contacto; }
void Reservacion::establecerContacto(const QString &contacto) { this->contacto = contacto; }

int Reservacion::obtenerComensales() const { return comensales; }
void Reservacion::establecerComensales(int comensales) { this->comensales = comensales; }

QDateTime Reservacion::obtenerFechaHora() const { return fechaHora; }
void Reservacion::establecerFechaHora(const QDateTime &fechaHora) { this->fechaHora = fechaHora; }

QString Reservacion::obtenerReferencia() const { return referencia; }
void Reservacion::establecerReferencia(const QString &referencia) { this->referencia = referencia; }
