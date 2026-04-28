#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

#include "Equipment.h"
#include "MaintenanceStrategy.h"

class Simulator {
private:
    std::vector<Equipment*> equipos;
    std::ofstream archivo;

    void quickSort(int low, int high);
    int partition(int low, int high);

public:
    void agregarEquipo(Equipment* eq);

    void simular();

    void degradarEquipos();
    void calcularPrioridades();
    void ordenarEquipos();
    void ordenarPorId();

    void aplicarMantenimiento();

    Equipment* buscarEquipoPorId(const std::string& id);
};

#endif