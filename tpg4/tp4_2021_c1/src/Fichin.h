#ifndef FICHIN_H
#define FICHIN_H

#include "Partida.h"
#include "Dicc_trie.h"

using namespace std;

class Fichin
{
public:
	Fichin(Mapa m);
	~Fichin();
	bool NuevaPartida(Jugador j);
	bool Mover(Direccion dir);
	ResultadoMovimiento Mover2(Direccion dir);
	string_map<Puntaje> VerRanking() const;
	pair<Jugador, Puntaje> Objetivo() const;
	set<Coordenada> chocolatesActuales() const;
	Jugador jugadorActual() const;
	bool alguienJugando() const;
	Nat cantMov() const;
	Nat inmunidad() const;
	Coordenada jugador() const;
	Coordenada inicio() const;
	Coordenada llegada() const;
private:
	Mapa _mapa;
	bool _alguienJugando;
	Jugador _jugadorActual;
	Partida* _partidaActual;
	string_map<Puntaje> _ranking;
};

#include "../src/Fichin.cpp"

#endif // FICHIN_H
