#ifndef FICHIN_H
#define FICHIN_H

#include "Partida.h"
#include <map>
using namespace std;

class Fichin
{
public:
	Fichin(Mapa m);
	bool NuevaPartida(Jugador j);
	bool Mover(Direccion dir);
	map<Jugador, Puntaje> VerRanking();
	pair<Jugador, Puntaje> Objetivo();
private:
	Mapa _mapa;
	bool _alguienJugando;
	Jugador _jugadorActual;
	Partida* _partidaActual;
	map<Jugador, Puntaje> _ranking;
};

#endif // FICHIN_H
