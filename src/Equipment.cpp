//
// Created by jimen on 26/4/2026.
//
#include "Equipment.h"

Equipment::Equipment(const std::string& id, int criticidad, double estado)
        : id(id), criticidad(criticidad), estado(estado),
          incidenciasActivas(0), tiempoInactivo(0), prioridad(0) {}

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

double Equipment::getPrioridad() const {
    return prioridad;
}

int Equipment::getIncidencias() const {
    return incidenciasActivas;
}

void Equipment::setEstado(double nuevoEstado) {
    estado = nuevoEstado;
}