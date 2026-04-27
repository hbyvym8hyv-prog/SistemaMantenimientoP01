#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>
#include <fstream>
#include "Equipment.h"
#include "MaintenanceStrategy.h"

class Simulator {
private:
    std::vector<Equipment*> equipos;

    std::ofstream archivo; // para reporte txt

    // algoritmo propio (QuickSort)
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