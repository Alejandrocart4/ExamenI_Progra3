#include "cframe.h"
#include "ui_cframe.h"
#include <QMessageBox>
#include <QCoreApplication>
#include <QApplication>
#include "gestorreservas.h"

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{
    ui->setupUi(this);
}

cframe::~cframe()
{
    delete ui;
}

/*
void cframe::on_btnRegresar_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void cframe::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

    ui->btnRegresar2->setVisible(false);
    ui->btnRegresar->setVisible(true);
}*/


void cframe::on_createReservationButton3_clicked()
{
    QString nombre = ui->nameLineEdit3->text();
    QString contacto = ui->contactLineEdit3->text();
    int comensales = ui->guestsSpinBox3->value();
    QDateTime fechaHora = ui->dateTimeEdit3->dateTime();

    Reservacion reservacion(nombre, contacto, comensales, fechaHora);
    QString referencia = gestorReservas.agregarReservacion(reservacion);

    if (!referencia.isEmpty()) {
        // Mostrar el número de referencia en un mensaje emergente
        QMessageBox::information(this, "Reserva Confirmada", "Tu número de referencia es: " + referencia);
    } else {
        QMessageBox::warning(this, "Error", "No se pudo realizar la reserva. Por favor, intente nuevamente.");
    }

    ui->nameLineEdit3->clear();
    ui->contactLineEdit3->clear();
    ui->referenceLineEdit3->clear();
}


void cframe::on_viewAvailabilityButton3_clicked()
{
    QDateTime fechaHora = ui->dateTimeEdit3->dateTime();
    QList<Mesa> mesasDisponibles = gestorReservas.obtenerMesasDisponibles(fechaHora);

    if (mesasDisponibles.isEmpty()) {
        QMessageBox::information(this, "Disponibilidad", "No hay mesas disponibles para la fecha y hora seleccionadas.");
    } else {
        QString mensaje = "Mesas disponibles:\n";
        foreach (const Mesa &mesa, mesasDisponibles) {
            mensaje += QString("Mesa %1 (Capacidad: %2)\n").arg(mesa.obtenerId()).arg(mesa.obtenerCapacidad());
        }
        QMessageBox::information(this, "Disponibilidad", mensaje);
    }
}


void cframe::on_modifyReservationButton3_clicked()
{
    QString ref = ui->referenceLineEdit3->text();
    QString nuevoNombre = ui->nameLineEdit3->text();
    QString nuevoContacto = ui->contactLineEdit3->text();
    int nuevosComensales = ui->guestsSpinBox3->value();
    QDateTime nuevaFechaHora = ui->dateTimeEdit3->dateTime();

    Reservacion nuevosDetalles(nuevoNombre, nuevoContacto, nuevosComensales, nuevaFechaHora);
    if (gestorReservas.modificarReservacion(ref, nuevosDetalles)) {
        QMessageBox::information(this, "Reserva Modificada", "La reserva ha sido modificada con éxito.");
    } else {
        QMessageBox::warning(this, "Error", "No se pudo modificar la reserva. Verifique el número de referencia.");
    }

    ui->nameLineEdit3->clear();
    ui->contactLineEdit3->clear();
    ui->referenceLineEdit3->clear();
}


void cframe::on_cancelReservationButton3_clicked()
{
    QString ref = ui->referenceLineEdit3->text();

    if (gestorReservas.cancelarReservacion(ref)) {
        QMessageBox::information(this, "Reserva Cancelada", "La reserva ha sido cancelada con éxito.");
    } else {
        QMessageBox::warning(this, "Error", "No se pudo cancelar la reserva. Verifique el número de referencia.");
    }
}

void cframe::on_btnTABLES_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void cframe::on_btnRESER_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void cframe::on_btnCerrarprogram_clicked()
{
    QCoreApplication::quit();
}


void cframe::on_Go_cliente_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void cframe::on_Go_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void cframe::on_btnCrearReserva_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void cframe::on_btnModificarReserva_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void cframe::on_btnConfirmarAgregarReserva_clicked()
{
    QString nombre = ui->txtNombreCliente->text();
    QString contacto = ui->txtNumeroContacto->text();
    int comensales = ui->spnNumeroComensales->value();
    QDateTime fechaHora = ui->dtpFechaHoraReserva->dateTime();

    Reservacion reservacion(nombre, contacto, comensales, fechaHora);
    QString referencia = gestorReservas.agregarReservacion(reservacion);

    if (!referencia.isEmpty()) {
        // Mostrar el número de referencia en un mensaje emergente
        QMessageBox::information(this, "Reserva Confirmada", "Tu número de referencia es: " + referencia);
    } else {
        QMessageBox::warning(this, "Error", "No se pudo realizar la reserva. Por favor, intente nuevamente.");
    }

    ui->txtNombreCliente->clear();
    ui->txtNumeroContacto->clear();
    ui->txtReferenciaReserva_2->clear();
}


void cframe::on_btnCancelarAgregarReserva_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void cframe::on_btnConfirmarModificarReserva_clicked()
{
    QString ref = ui->txtReferenciaReserva_2->text();
    QString nuevoNombre = ui->txtNombreCliente_2->text();
    QString nuevoContacto = ui->txtNumeroContacto_2->text();
    int nuevosComensales = ui->spnNumeroComensales_2->value();
    QDateTime nuevaFechaHora = ui->dtpFechaHoraReserva_2->dateTime();

    Reservacion nuevosDetalles(nuevoNombre, nuevoContacto, nuevosComensales, nuevaFechaHora);
    if (gestorReservas.modificarReservacion(ref, nuevosDetalles)) {
        QMessageBox::information(this, "Reserva Modificada", "La reserva ha sido modificada con éxito.");
    } else {
        QMessageBox::warning(this, "Error", "No se pudo modificar la reserva. Verifique el número de referencia.");
    }
}


void cframe::on_btnCancelarReservacion_clicked()
{
    QString ref = ui->txtReferenciaReserva_3->text();

    if (gestorReservas.cancelarReservacion(ref)) {
        QMessageBox::information(this, "Reserva Cancelada", "La reserva ha sido cancelada con éxito.");
    } else {
        QMessageBox::warning(this, "Error", "No se pudo cancelar la reserva. Verifique el número de referencia.");
    }
}


void cframe::on_btnCancelarReserva_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void cframe::on_btnConsultarDisponibilidad_clicked()
{
    QDateTime fechaHora = ui->dateTimeEdit3->dateTime();
    QList<Mesa> mesasDisponibles = gestorReservas.obtenerMesasDisponibles(fechaHora);

    if (mesasDisponibles.isEmpty()) {
        QMessageBox::information(this, "Disponibilidad", "No hay mesas disponibles para la fecha y hora seleccionadas.");
    } else {
        QString mensaje = "Mesas disponibles:\n";
        foreach (const Mesa &mesa, mesasDisponibles) {
            mensaje += QString("Mesa %1 (Capacidad: %2)\n").arg(mesa.obtenerId()).arg(mesa.obtenerCapacidad());
        }
        QMessageBox::information(this, "Disponibilidad", mensaje);
    }
}


void cframe::on_Volver_menuprinci_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void cframe::on_AddTable_2_clicked()
{
    int id = ui->NumberTablespinBox_2->value();
    int capacidad = ui->CapacityspinBox_2->value();

    if (id > 0 && capacidad > 0) {
        gestorReservas.agregarMesa(id, capacidad);
        QMessageBox::information(this, "Completado", "Mesa añadida correctamente!");
    } else {
        QMessageBox::warning(this, "Error", "Ingrese datos correctamente.");
    }
}


void cframe::on_RemoveTable_2_clicked()
{
    int id = ui->NumberTablespinBox_2->value();

    if (id > 0) {
        gestorReservas.eliminarMesa(id);
        QMessageBox::information(this, "Completado", "Mesa removida exitosamente!");
    } else {
        QMessageBox::warning(this, "Error", "Por favor, ingrese un ID de Mesa válido.");
    }
}


void cframe::on_viewAvailabilityButton4_2_clicked()
{
    QDateTime fechaHora = ui->dateTimeEdit3->dateTime();
    QList<Mesa> mesasDisponibles = gestorReservas.obtenerMesasDisponibles(fechaHora);

    if (mesasDisponibles.isEmpty()) {
        QMessageBox::information(this, "Disponibilidad", "No hay mesas disponibles para la fecha y hora seleccionadas.");
    } else {
        QString mensaje = "Mesas disponibles:\n";
        foreach (const Mesa &mesa, mesasDisponibles) {
            mensaje += QString("Mesa %1 (Capacidad: %2)\n").arg(mesa.obtenerId()).arg(mesa.obtenerCapacidad());
        }
        QMessageBox::information(this, "Disponibilidad", mensaje);
    }
}


void cframe::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void cframe::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void cframe::on_btnCancelarModificarReserva_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void cframe::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void cframe::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void cframe::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

