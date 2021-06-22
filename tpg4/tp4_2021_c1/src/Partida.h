#ifndef PARTIDA_H
#define PARTIDA_H

//#include "../src/Tipos.h"
#include "../src/Mapa.h"

using namespace std;

class Partida
{
public:
	Partida(Mapa m);
	void Mover(Direccion dir);
	bool Gano();
	bool Perdio();
	Coordenada Jugador();
	Nat CantMov();
	set<Coordenada> chocolatesActuales();
	Nat inmunidad();
	Coordenada jugador() const;
	
private:
	
	Mapa _mapa;
	Coordenada _jugador;
	vector<bool> _chocolates;
	Nat _cantMov;
	Nat _inmunidad;
	bool _gano;
	bool _perdio;
};
#endif // PARTIDA_H
