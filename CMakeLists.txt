
cmake_minimum_required(VERSION 3.20)
project(ProyectoMantenimiento)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(include)
set(SOURCES
        src/main.cpp
        src/Equipment.cpp
        src/Incident.cpp
        src/PreventiveMaintenance.cpp
        src/Simulator.cpp
        include/Incident.h
        src/Incident.cpp
        include/MaintenanceStrategy.h
        include/PreventiveMaintenance.h
        src/PreventiveMaintenance.cpp
        include/CorrectiveMaintenance.h
        src/CorrectiveMaintenance.cpp
        include/Simulator.h
        src/Simulator.cpp
        src/main.cpp
)
add_executable(ProyectoMantenimiento ${SOURCES})