#include "Equipment.h"

Equipment::Equipment(const std::string& id, int criticidad, double estado)
        : id(id),
          criticidad(criticidad),
          estado(estado),
          incidenciasActivas(0),
          tiempoInactivo(0),
          prioridad(0) {}

void Equipment::degradar() {
    estado -= 2;
    if (estado < 0) estado = 0;
}
void Equipment::agregarIncidencia() {
    incidenciasActivas++;
}

void Equipment::resolverIncidencias() {
    incidenciasActivas = 0;
}

void Equipment::actualizarTiempoInactivo() {
    tiempoInactivo++;
}

void Equipment::resetTiempoInactivo() {
    tiempoInactivo = 0;
}

void Equipment::calcularPrioridad() {
    prioridad = (criticidad * 0.5) +
                (incidenciasActivas * 0.3) +
                (tiempoInactivo * 0.2);
}


std::string Equipment::getId() const {
    return id;
}

int Equipment::getCriticidad() const {
    return criticidad;
}

double Equipment::getEstado() const {
    return estado;
}

int Equipment::getIncidencias() const {
    return incidenciasActivas;
}

int Equipment::getTiempoInactivo() const {
    return tiempoInactivo;
}

double Equipment::getPrioridad() const {
    return prioridad;
}

void Equipment::setEstado(double nuevoEstado) {
    estado = nuevoEstado;

    if (estado > 100) estado = 100;
    if (estado < 0) estado = 0;
}