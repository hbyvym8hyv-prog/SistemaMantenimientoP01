//
// Created by jimen on 27/4/2026.
//

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>
#include "Equipment.h"
#include "MaintenanceStrategy.h"

class Simulator {
private:
    std::vector<Equipment*> equipos;

    void quickSort(int low, int high);
    int partition(int low, int high);

public:
    void agregarEquipo(Equipment* eq);

    void simular();

    void calcularPrioridades();
    void degradarEquipos();
    void ordenarEquipos();

    void aplicarMantenimiento();
};

#endif