#ifndef PARTIDA_H
#define PARTIDA_H

#include "Mapa.h"

using namespace std;

class Partida
{
public:
	Partida(Mapa m);
	void Mover(Direccion dir);
	bool Gano();
	bool Perdio();
	Coordenada Jugador();
	Nat CantMov() const;
	set<Coordenada> chocolatesActuales() const;
	Nat inmunidad() const;
	Coordenada jugador() const;
	Coordenada inicio() const;
	Coordenada llegada() const;
	
private:
	
	Mapa _mapa;
	Coordenada _jugador;
	vector<bool> _chocolates;
	Puntaje _cantMov;
	Nat _inmunidad;
	bool _gano;
	bool _perdio;
};

#endif // PARTIDA_H
