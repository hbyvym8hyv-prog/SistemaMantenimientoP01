//
// Created by jimen on 26/4/2026.
//

#ifndef MAINTENANCESTRATEGY_H
#define MAINTENANCESTRATEGY_H

class Equipment;

class MaintenanceStrategy {
public:
    virtual void aplicar(Equipment& eq) = 0;
    virtual ~MaintenanceStrategy() = default;
};

#endif