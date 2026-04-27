#include "PreventiveMaintenance.h"
#include "Equipment.h"

void PreventiveMaintenance::aplicar(Equipment& eq) {
    // mejora ligera
    eq.setEstado( eq.getPrioridad() + 5 ); // puedes ajustar luego
    eq.resetTiempoInactivo();
}