//
// Created by jimen on 26/4/2026.
//

#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>

class Equipment; // forward declaration

class Incident {
private:
    std::string severidad;
    int dia;
    Equipment* equipo; // relación con Equipment

public:
    Incident(const std::string& severidad, int dia, Equipment* equipo);

    std::string getSeveridad() const;
    int getDia() const;

    Equipment* getEquipo() const;
};

#endif