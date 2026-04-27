//
// Created by jimen on 26/4/2026.
//

#ifndef CORRECTIVEMAINTENANCE_H
#define CORRECTIVEMAINTENANCE_H

#include "MaintenanceStrategy.h"

class CorrectiveMaintenance : public MaintenanceStrategy {
public:
    void aplicar(Equipment& eq) override;
};

#endif