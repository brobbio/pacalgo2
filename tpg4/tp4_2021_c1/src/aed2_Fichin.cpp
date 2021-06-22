#include "aed2_Fichin.h"


    aed2_Fichin::aed2_Fichin(Nat largo, Nat alto, Coordenada inicio, Coordenada llegada, set<Coordenada> paredes,
                set<Coordenada> fantasmas, set<Coordenada> chocolates):
				   _fichin(Mapa(largo, alto, inicio, llegada, fantasmas, paredes, chocolates)),
				   _fantasmas(fantasmas), _paredes(paredes), 
				  _chocolatesIniciales(chocolates), _alto(alto), _largo(largo) {}

    void aed2_Fichin::nuevaPartida(Jugador j){
	_fichin.NuevaPartida(j);
    }

    // IMPORTANTE: Debe devolver:
    // - GANO si al mover se gana la partida
    // - PERDIO si al mover se pierde la partida
    // - SIGUE en cualquier otro caso
    ResultadoMovimiento aed2_Fichin::mover(Direccion d){
        return _fichin.Mover2(d);
    }

    bool aed2_Fichin::alguienJugando() const{
    	return _fichin.alguienJugando();
    }

    Jugador aed2_Fichin::jugadorActual() const{
    	return _fichin.jugadorActual();
    }

    map<Jugador, Puntaje> aed2_Fichin::ranking() const{
	map<Jugador, Puntaje> nuevo_dic;
	set<Jugador> C = _fichin.VerRanking().keys();
	for(Jugador e: C){
		nuevo_dic[e] = _fichin.VerRanking()[e];
	}
    	return nuevo_dic;
    }

    pair<Jugador, Puntaje> aed2_Fichin::objetivo() const{
    	return _fichin.Objetivo();
    }

    Coordenada aed2_Fichin::jugador() const{
    	return _fichin.jugador();
    }

    Nat aed2_Fichin::cantidadMovimientos() const{
	return _fichin.cantMov();
    }

    Nat aed2_Fichin::inmunidad() const{
	return _fichin.inmunidad();
    }

    Nat aed2_Fichin::largo() const{
    	return _largo;
    }

    Nat aed2_Fichin::alto() const{
	return _alto;
    }


    Coordenada aed2_Fichin::inicio() const{
    	return _inicio;
    }

    Coordenada aed2_Fichin::llegada() const{
    	return _llegada;
    }

    set<Coordenada> aed2_Fichin::paredes() const{
    	return _paredes;
    }

    set<Coordenada> aed2_Fichin::fantasmas() const{
	return _fantasmas;
    }

    set<Coordenada> aed2_Fichin::chocolatesIniciales() const{
    	return _chocolatesIniciales;
    }

    set<Coordenada> aed2_Fichin::chocolatesActuales() const{
    	return _fichin.chocolatesActuales();
    }
