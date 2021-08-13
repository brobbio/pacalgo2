#ifndef MAPA_H
#define MAPA_H

#include "Tipos.h"

using namespace std;

class Mapa
{
public:
    Mapa(Nat largo,
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
    Coordenada Inicio() const;
    Coordenada Llegada() const;
    int IdChocolate(Coordenada posicion) const;
    set<Coordenada> conjuntoDeChocolates() const;
    set<Coordenada> EntornoDistTres(Coordenada posicion);

private:

    struct Casillero
    {
        
	Casillero(bool f, bool pel, bool par, int idChoco):
		fantasma(f), peligrosa(pel), pared(par), idChocolate(idChoco){
			}
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
    set<Coordenada> _conjuntodeChocolates;
};

#endif // MAPA_H
