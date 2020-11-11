#include "laboratorio.h"
#include <fstream>
#include <algorithm>

Laboratorio::Laboratorio()
{
}

void Laboratorio::agregarFinal(const Computadora &c)
{
    computadoras.push_back(c);
}

void Laboratorio::mostrar()
{
    cout << endl;
    cout << left;
    cout << setw(10) << "Sistema";
    cout << setw(10) << "Nombre";
    cout << setw(17) << "Almacenamiento";
    cout << setw(6) << "Ram";
    cout << endl;
    for (size_t i = 0; i < computadoras.size(); i++)
    {
        Computadora &c = computadoras[i];
        cout << c;
    }
}

void Laboratorio::respaldar()
{
    ofstream archivo("respaldo.txt");
    if (archivo.is_open())
    {
        for (size_t i = 0; i < computadoras.size(); i++)
        {
            Computadora &c = computadoras[i];
            archivo << c.getSistema() << endl;
            archivo << c.getNombre() << endl;
            archivo << c.getAlmac() << endl;
            archivo << c.getRam() << endl;
        }
    }
    archivo.close();
}

void Laboratorio::recuperar()
{
    ifstream archivo("respaldo.txt");
    if (archivo.is_open())
    {
        string temp;
        int almac;
        int ram;
        Computadora c;

        while (true)
        {
            getline(archivo, temp); //Sistema
            if (archivo.eof())
            {
                break;
            }
            c.setSistema(temp);

            getline(archivo, temp); //Nombre
            c.setNombre(temp);

            getline(archivo, temp); //Almacenamiento
            almac = stoi(temp);     //String-to-int
            c.setAlmac(almac);

            getline(archivo, temp); //Ram
            ram = stoi(temp);
            c.setRam(ram);

            agregarFinal(c);
        }
    }
    archivo.close();
}

void Laboratorio::insertar(const Computadora &c, size_t pos)
{
    computadoras.insert(computadoras.begin() + pos, c);
}

size_t Laboratorio::size()
{
    return computadoras.size();
}

size_t Laboratorio::empty()
{
    return computadoras.empty();
}

void Laboratorio::inicializar(const Computadora &c, size_t n)
{
    computadoras = vector<Computadora>(n, c);
}

void Laboratorio::eliminar(size_t pos)
{
    computadoras.erase(computadoras.begin() + pos);
}

void Laboratorio::ordenar()
{
    sort(computadoras.begin(), computadoras.end());
}

void Laboratorio::eliminarUltimo()
{
    computadoras.pop_back();
}

Computadora *Laboratorio::buscar(const Computadora &c)
{
    // vector<Personaje>::iterator
    auto it = find(computadoras.begin(), computadoras.end(), c);

    if (it == computadoras.end())
    {
        return nullptr;
    }
    else
    {
        return &(*it);
    }
}