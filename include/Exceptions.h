//
// Created by jimen on 27/4/2026.
//

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

// Excepción para errores de archivo
class FileException : public std::exception {
private:
    std::string mensaje;

public:
    explicit FileException(const std::string& msg) : mensaje(msg) {}

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

// Excepción para formato inválido
class InvalidFormatException : public std::exception {
private:
    std::string mensaje;

public:
    explicit InvalidFormatException(const std::string& msg) : mensaje(msg) {}

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

// Excepción para operaciones inválidas
class InvalidOperationException : public std::exception {
private:
    std::string mensaje;

public:
    explicit InvalidOperationException(const std::string& msg) : mensaje(msg) {}

    const char* what() const noexcept override {
        return mensaje.c_str();
    }
};

#endif
