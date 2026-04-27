//
// Created by jimen on 26/4/2026.
//

#ifndef PREVENTIVEMAINTENANCE_H
#define PREVENTIVEMAINTENANCE_H

#include "MaintenanceStrategy.h"

class PreventiveMaintenance : public MaintenanceStrategy {
public:
    void aplicar(Equipment& eq) override;
};

#endif