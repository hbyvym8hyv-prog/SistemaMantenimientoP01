//
// Created by jimen on 27/4/2026.
//
#include "Simulator.h"
#include "PreventiveMaintenance.h"
#include "CorrectiveMaintenance.h"
#include "Exceptions.h"

#include <iostream>
#include <algorithm>

// Agregar equipo
void Simulator::agregarEquipo(Equipment* eq) {
    equipos.push_back(eq);
}

// Simulación principal (30 días)
void Simulator::simular() {

    archivo.open("reporte.txt");

    if (!archivo.is_open()) {
        throw FileException("No se pudo abrir el archivo de reporte");
    }

    for (int dia = 1; dia <= 30; dia++) {

        std::cout << "Dia " << dia << std::endl;
        archivo << "Dia " << dia << std::endl;

        degradarEquipos();
        calcularPrioridades();
        ordenarEquipos();
        aplicarMantenimiento();

        std::cout << "------------------------" << std::endl;
        archivo << "------------------------" << std::endl;
    }

    archivo.close();
}

// Degradación diaria
void Simulator::degradarEquipos() {
    for (auto& eq : equipos) {
        eq->degradar();
        eq->actualizarTiempoInactivo();
    }
}

// Calcular prioridad
void Simulator::calcularPrioridades() {
    for (auto& eq : equipos) {
        eq->calcularPrioridad();
    }
}

// Ordenar equipos por prioridad (mayor a menor)
void Simulator::ordenarEquipos() {
    if (!equipos.empty()) {
        quickSort(0, equipos.size() - 1);
    }
}

// QuickSort
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

        if (equipos[j]->getPrioridad() > pivot) { // descendente
            i++;
            std::swap(equipos[i], equipos[j]);
        }
    }

    std::swap(equipos[i + 1], equipos[high]);
    return i + 1;
}

// Aplicar mantenimiento (top 3)
void Simulator::aplicarMantenimiento() {

    if (equipos.empty()) {
        throw InvalidOperationException("No hay equipos para procesar");
    }

    for (int i = 0; i < 3 && i < equipos.size(); i++) {

        Equipment* eq = equipos[i];
        MaintenanceStrategy* estrategia;

        // decisión automática
        if (eq->getIncidencias() > 2) {
            estrategia = new CorrectiveMaintenance();
        } else {
            estrategia = new PreventiveMaintenance();
        }

        estrategia->aplicar(*eq);

        std::string linea = "Atendido: " + eq->getId() +
                            " | Prioridad: " + std::to_string(eq->getPrioridad());

        std::cout << linea << std::endl;
        archivo << linea << std::endl;

        delete estrategia;
    }
}