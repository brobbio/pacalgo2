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
	set<Coordenada> chocolatesActuales();
	Jugador jugadorActual() const;
	bool alguienJugando() const;
	Nat cantMov();
	Nat inmunidad();
	Coordenada jugador() const;
private:
	Mapa _mapa;
	bool _alguienJugando;
	Jugador _jugadorActual;
	Partida* _partidaActual;
	string_map<Puntaje> _ranking;
};

#endif // FICHIN_H
