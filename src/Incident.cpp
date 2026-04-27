//
// Created by jimen on 26/4/2026.
//
#include "Incident.h"
#include "Equipment.h"

Incident::Incident(const std::string& severidad, int dia, Equipment* equipo)
        : severidad(severidad), dia(dia), equipo(equipo) {}

std::string Incident::getSeveridad() const {
    return severidad;
}

int Incident::getDia() const {
    return dia;
}

Equipment* Incident::getEquipo() const {
    return equipo;
}