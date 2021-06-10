#ifndef MAPA_H
#define MAPA_H

#include <set>
#include <vector>
#include "../src/Tipos.h"

using namespace std;

class Mapa
{
public:
    Mapa NuevoMapa(Nat largo,
                   Nat alto,
                   Coordenada inicio,
                   Coordenada llegada,
                   set<Coordenada> fantasmas,
                   set<Coordenada> paredes,
                   set<Coordenada> chocolates);
    bool EsCasilleroPeligroso(Coordenada posicion);
    bool EnRango(Coordenada posicion);
    Nat CantChocolates();
    bool EsPared(Coordenada posicion);
    Coordenada Inicio();
    Coordenada Llegada();
    int IdChocolate(Coordenada posicion);

private:

    struct Casillero
    {
        bool fantasma;
        bool peligrosa;
        bool pared;
        int idChocolate;
    };

    vector<vector<Casillero>> _matriz;

    Nat _cantChocolates;
    Nat _alto;
    Nat _largo;
    Coordenada _inicio;
    Coordenada _llegada;
};

#endif // MAPA_H
