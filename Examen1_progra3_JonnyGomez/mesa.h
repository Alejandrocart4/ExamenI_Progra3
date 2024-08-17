#ifndef MESA_H
#define MESA_H

class Mesa {
public:
    Mesa(int id, int capacidad, bool habilitada);

    int getId() const;
    int getCapacidad() const;
    bool isHabilitada() const;

    void setCapacidad(int capacidad);
    void setHabilitada(bool habilitada);

private:
    int id;
    int capacidad;
    bool habilitada;
};

#endif // MESA_H

