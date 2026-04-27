//
// Created by jimen on 26/4/2026.
//
#include "CorrectiveMaintenance.h"
#include "Equipment.h"

void CorrectiveMaintenance::aplicar(Equipment& eq) {
    // mejora fuerte
    eq.setEstado(100);
    eq.resolverIncidencias();
    eq.resetTiempoInactivo();
}