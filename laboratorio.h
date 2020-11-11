#ifndef LABORATORIO_H
#define LABORATORIO_H

#include "computadora.h"
#include <vector>

class Laboratorio
{
    vector<Computadora> computadoras;

public:
    Laboratorio();
    void agregarFinal(const Computadora &c);
    void mostrar();
    void respaldar();
    void recuperar();

    void insertar(const Computadora &c, size_t pos);
    size_t size();
    size_t empty();
    void inicializar(const Computadora &c, size_t n);
    void eliminar(size_t pos);
    void ordenar();
    void eliminarUltimo();
    Computadora *buscar(const Computadora &c);

    friend Laboratorio &operator<<(Laboratorio &l, const Computadora &c)
    {
        l.agregarFinal(c);

        return l;
    }
};

#endif