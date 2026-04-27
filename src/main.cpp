#include <iostream>
#include <vector>
#include <cstdlib>

#include "Simulator.h"
#include "Equipment.h"

int main() {

    Simulator sim;
    std::vector<Equipment*> equipos;

    for (int i = 1; i <= 100; i++) {

        int criticidad = rand() % 10 + 1;
        double estado = rand() % 100 + 1;

        Equipment* eq = new Equipment("EQ-" + std::to_string(i), criticidad, estado);

        equipos.push_back(eq);
        sim.agregarEquipo(eq);
    }
    for (int i = 0; i < 300; i++) {
        int index = rand() % 100;
        equipos[index]->agregarIncidencia();
    }
    sim.simular();

    Equipment* encontrado = sim.buscarEquipoPorId("EQ-10");

    if (encontrado != nullptr) {
        std::cout << "Encontrado: " << encontrado->getId() << std::endl;
    } else {
        std::cout << "Equipo no encontrado" << std::endl;
    }

    for (auto& eq : equipos) {
        delete eq;
    }

    return 0;
}