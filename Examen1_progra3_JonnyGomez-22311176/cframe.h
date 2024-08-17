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
    //void on_btnSalir_clicked();

    void on_btnCerrarprogram_clicked();

    void on_Go_cliente_clicked();

    void on_Go_admin_clicked();

    void on_btnCrearReserva_clicked();

    void on_btnModificarReserva_clicked();

    void on_btnConfirmarAgregarReserva_clicked();

    void on_btnCancelarAgregarReserva_clicked();

    void on_btnConfirmarModificarReserva_clicked();

    void on_btnCancelarReservacion_clicked();

    void on_btnCancelarReserva_clicked();

    void on_btnConsultarDisponibilidad_clicked();

    void on_createReservationButton3_clicked();

    void on_modifyReservationButton3_clicked();

    void on_cancelReservationButton3_clicked();

    void on_viewAvailabilityButton3_clicked();

    void on_btnRESER_clicked();

    void on_btnTABLES_clicked();

    void on_Volver_menuprinci_clicked();


    void on_viewAvailabilityButton4_2_clicked();

    void on_AddTable_2_clicked();

    void on_RemoveTable_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_btnCancelarModificarReserva_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::cframe *ui;
    GestorReservas gestorReservas;
};
#endif // CFRAME_H
