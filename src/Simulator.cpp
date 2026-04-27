//
// Created by jimen on 27/4/2026.
//
#include "Simulator.h"
#include "PreventiveMaintenance.h"
#include "CorrectiveMaintenance.h"
#include <iostream>

// agregar equipos
void Simulator::agregarEquipo(Equipment* eq) {
    equipos.push_back(eq);
}

// simular 30 días
void Simulator::simular() {
    for (int dia = 1; dia <= 30; dia++) {
        std::cout << "Dia " << dia << std::endl;

        degradarEquipos();
        calcularPrioridades();
        ordenarEquipos();
        aplicarMantenimiento();

        std::cout << "------------------------" << std::endl;
    }
}

// degradación diaria
void Simulator::degradarEquipos() {
    for (auto& eq : equipos) {
        eq->degradar();
        eq->actualizarTiempoInactivo();
    }
}

// cálculo de prioridad
void Simulator::calcularPrioridades() {
    for (auto& eq : equipos) {
        eq->calcularPrioridad();
    }
}

// quicksort
void Simulator::ordenarEquipos() {
    if (!equipos.empty())
        quickSort(0, equipos.size() - 1);
}

void Simulator::quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int Simulator::partition(int low, int high) {
    double pivot = equipos[high]->getPrioridad();
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (equipos[j]->getPrioridad() > pivot) { // mayor a menor
            i++;
            std::swap(equipos[i], equipos[j]);
        }
    }

    std::swap(equipos[i + 1], equipos[high]);
    return i + 1;
}

// aplicar mantenimiento a top 3
void Simulator::aplicarMantenimiento() {

    for (int i = 0; i < 3 && i < equipos.size(); i++) {
        Equipment* eq = equipos[i];

        MaintenanceStrategy* estrategia;

        if (eq->getIncidencias() > 2) {
            estrategia = new CorrectiveMaintenance();
        } else {
            estrategia = new PreventiveMaintenance();
        }

        estrategia->aplicar(*eq);

        std::cout << "Atendido: " << eq->getId()
                  << " Prioridad: " << eq->getPrioridad()
                  << std::endl;

        delete estrategia;
    }
}