#include "cframe.h"
#include "ui_cframe.h"
#include "QMessageBox"
#include "Reserva.h"
#include "gestorreservas.h"

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)


{
    ui->setupUi(this);
    gestorReservas = new GestorReservas();

    ui->comboBoxMesa->clear();
    for (const Mesa &mesa : gestorReservas->getMesas()) {
        ui->comboBoxMesa->addItem(QString("Mesa %1 - Capacidad %2").arg(mesa.getId()).arg(mesa.getCapacidad()), mesa.getId());
    }
}

cframe::~cframe()
{
    delete ui;
    delete gestorReservas;
}

void cframe::on_Go_cliente_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void cframe::on_Go_admin_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void cframe::on_btnCrearReserva_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void cframe::on_btnModificarReserva_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void cframe::on_btnCancelarReserva_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void cframe::on_btnConsultarDisponibilidad_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void cframe::on_btnCancelarAgregarReserva_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void cframe::on_btnConfirmarAgregarReserva_clicked()
{
    QString nombre = ui->txtNombreCliente->text();
    QString contacto = ui->txtNumeroContacto->text();
    int numComensales = ui->spnNumeroComensales->value();
    QDateTime fechaHora = ui->dtpFechaHoraReserva->dateTime();
    int mesaId = ui->comboBoxMesa->currentData().toInt();


    if (nombre.isEmpty() || contacto.isEmpty() || mesaId == -1) {
        QMessageBox::warning(this, "Error", "Por favor, complete todos los campos.");
        return;
    }


    Reserva nuevaReserva(nombre, contacto, numComensales, fechaHora, mesaId);


    if (gestorReservas->agregarReserva(nuevaReserva)) {
        QMessageBox::information(this, "Éxito", "Reserva agregada con éxito.");
        ui->txtNombreCliente->clear();
        ui->txtNumeroContacto->clear();
        ui->spnNumeroComensales->setValue(1);
        ui->dtpFechaHoraReserva->setDateTime(QDateTime::currentDateTime());
        ui->comboBoxMesa->setCurrentIndex(0);
    } else {
        QMessageBox::warning(this, "Error", "No se pudo agregar la reserva. Es posible que la mesa ya esté reservada para la hora seleccionada.");
    }
}


void cframe::on_btnConfirmarModificarReserva_clicked()
{
    QString referencia = ui->txtReferenciaReserva_2->text();  // Asumimos que tienes un campo para la referencia
    QString nombre = ui->txtNombreCliente_2->text();
    QString contacto = ui->txtNumeroContacto_2->text();
    int numComensales = ui->spnNumeroComensales_2->value();
    QDateTime fechaHora = ui->dtpFechaHoraReserva_2->dateTime();
    int mesaId = ui->comboBoxMesa_2->currentData().toInt();

    if (referencia.isEmpty() || nombre.isEmpty() || contacto.isEmpty() || mesaId == -1) {
        QMessageBox::warning(this, "Error", "Por favor, complete todos los campos.");
        return;
    }

    Mesa mesaSeleccionada;
    bool mesaEncontrada = false;
    for (const Mesa &mesa : gestorReservas->getMesas()) {
        if (mesa.getId() == mesaId) {
            mesaSeleccionada = mesa;
            mesaEncontrada = true;
            break;
        }
    }




}

