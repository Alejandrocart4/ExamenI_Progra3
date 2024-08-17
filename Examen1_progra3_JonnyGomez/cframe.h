#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>
#include "gestorreservas.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class cframe;
}
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    cframe(QWidget *parent = nullptr);
    ~cframe();

private slots:
    void on_Go_cliente_clicked();

    void on_Go_admin_clicked();

    void on_btnCrearReserva_clicked();

    void on_btnModificarReserva_clicked();

    void on_btnCancelarReserva_clicked();

    void on_btnConsultarDisponibilidad_clicked();

    void on_btnCancelarAgregarReserva_clicked();

    void on_btnConfirmarAgregarReserva_clicked();


    void on_btnConfirmarModificarReserva_clicked();

private:
    Ui::cframe *ui;
    GestorReservas *gestorReservas;

};
#endif // CFRAME_H
