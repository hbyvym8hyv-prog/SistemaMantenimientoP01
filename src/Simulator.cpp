#include "Simulator.h"
#include "PreventiveMaintenance.h"
#include "CorrectiveMaintenance.h"
#include "Exceptions.h"

#include <iostream>

void Simulator::agregarEquipo(Equipment* eq) {
    equipos.push_back(eq);
}

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

        archivo << "Total equipos: " << equipos.size() << std::endl;
        archivo << "------------------------" << std::endl;

        std::cout << "------------------------" << std::endl;
    }

    archivo.close();
}

void Simulator::degradarEquipos() {
    for (auto& eq : equipos) {
        eq->degradar();
        eq->actualizarTiempoInactivo();
    }
}
void Simulator::calcularPrioridades() {
    for (auto& eq : equipos) {
        eq->calcularPrioridad();
    }
}

void Simulator::ordenarEquipos() {
    if (!equipos.empty()) {
        quickSort(0, equipos.size() - 1);
    }
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
        if (equipos[j]->getPrioridad() > pivot) {
            i++;
            std::swap(equipos[i], equipos[j]);
        }
    }

    std::swap(equipos[i + 1], equipos[high]);
    return i + 1;
}

void Simulator::ordenarPorId() {
    std::sort(equipos.begin(), equipos.end(),
        [](Equipment* a, Equipment* b) {
            return a->getId() < b->getId();
        });
}


void Simulator::aplicarMantenimiento() {

    if (equipos.empty()) {
        throw InvalidOperationException("No hay equipos para procesar");
    }

    for (int i = 0; i < 3 && i < equipos.size(); i++) {

        Equipment* eq = equipos[i];
        MaintenanceStrategy* estrategia;

        if (eq->getIncidencias() > 2) {
            estrategia = new CorrectiveMaintenance();
        } else {
            estrategia = new PreventiveMaintenance();
        }

        estrategia->aplicar(*eq);

        CorrectiveMaintenance* cm = dynamic_cast<CorrectiveMaintenance*>(estrategia);
        if (cm) {
            archivo << "[Correctivo aplicado] ";
        } else {
            archivo << "[Preventivo aplicado] ";
        }

        std::string linea = "Atendido: " + eq->getId() +
                            " | Prioridad: " + std::to_string(eq->getPrioridad());

        std::cout << linea << std::endl;
        archivo << linea << std::endl;

        delete estrategia;
    }
}

Equipment* Simulator::buscarEquipoPorId(const std::string& id) {

    int left = 0;
    int right = equipos.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (equipos[mid]->getId() == id) {
            return equipos[mid];
        }

        if (equipos[mid]->getId() < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return nullptr;
}