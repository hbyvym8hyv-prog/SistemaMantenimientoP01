//
// Created by jimen on 26/4/2026.
//
#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>

class Incident; // forward declaration

class Equipment {
private:
    std::string id;
    int criticidad;
    double estado;

    int incidenciasActivas;
    int tiempoInactivo;
    double prioridad;

public:
    Equipment(const std::string& id, int criticidad, double estado);

    void degradar();
    void agregarIncidencia();
    void resolverIncidencias();
    void actualizarTiempoInactivo();
    void resetTiempoInactivo();

    void calcularPrioridad();

    std::string getId() const;
    int getCriticidad() const;
    double getEstado() const;
    int getIncidencias() const;
    int getTiempoInactivo() const;
    double getPrioridad() const;

    void setEstado(double nuevoEstado);
};

#endif