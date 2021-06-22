#include "Fichin.h"

Fichin::Fichin(Mapa m): _mapa(m), _alguienJugando(false), _jugadorActual(""), _partidaActual(NULL), _ranking(){}

Fichin::~Fichin(){
	if(_partidaActual != NULL){
		delete _partidaActual;
	}
}

bool Fichin::NuevaPartida(Jugador a){
	bool res = false;
	if(!(_alguienJugando)){
		_jugadorActual = a;
		_alguienJugando = true;
		_partidaActual = new Partida(_mapa);
		res = true;
	}
	return res;
}

bool Fichin::Mover(Direccion dir){
	bool res = false;
	if(_alguienJugando){
		(*_partidaActual).Mover(dir);
		res = true;
		if((*_partidaActual).Gano()){
			if(_ranking.count(_jugadorActual)){
				if(_ranking[_jugadorActual]>(*_partidaActual).CantMov()){
					_ranking[_jugadorActual] = (*_partidaActual).CantMov();
				}
			}else{
				_ranking[_jugadorActual] = (*_partidaActual).CantMov();
			}
		delete _partidaActual;
		_alguienJugando = false;
		_jugadorActual = "";
		}
		if((*_partidaActual).Perdio()){
			delete _partidaActual;
			_alguienJugando = false;
			_jugadorActual = "";
		}
	}
	return res;
}

ResultadoMovimiento Fichin::Mover2(Direccion dir){
        ResultadoMovimiento res = SIGUE;
        if(_alguienJugando){
                (*_partidaActual).Mover(dir);
                if((*_partidaActual).Gano()){
                        if(_ranking.count(_jugadorActual)){
                                if(_ranking[_jugadorActual]>(*_partidaActual).CantMov()){
                                        _ranking[_jugadorActual] = (*_partidaActual).CantMov();
                                }
                        }else{
                                _ranking[_jugadorActual] = (*_partidaActual).CantMov();
                        }
                	delete _partidaActual;
                	_alguienJugando = false;
	                _jugadorActual = "";
			res = GANO;
                }
                if((*_partidaActual).Perdio()){
                        delete _partidaActual;
                        _alguienJugando = false;
                        _jugadorActual = "";
			res = PERDIO;
                }
        }
        return res;

}

string_map<Puntaje> Fichin::VerRanking() const{
	return _ranking;
}


pair<Jugador, Puntaje> Fichin::Objetivo() const{
	int i = 0;
	set<Jugador> C = _ranking.keys();
	set<Jugador> S;
	Puntaje p = _ranking.at(_jugadorActual);
	pair<Jugador, Puntaje> res;
	for(Jugador e: C){
		if(_ranking.at(e) < p){
			S.insert(e);
		}
	}
	if(S.size()==0){
		res = make_pair(_jugadorActual, p);
	}else{
		Puntaje min = 0;
		Jugador min_jugador;
		for(Jugador e: S){
			if(_ranking.at(e)>=min){
				min = _ranking.at(e);
				min_jugador = e;
			}
		}
		res = make_pair(min_jugador, min);
	}
	return res;
}

set<Coordenada> Fichin::chocolatesActuales(){
	return (*_partidaActual).chocolatesActuales();
}

Jugador Fichin::jugadorActual() const{
	return _jugadorActual;
}

bool Fichin::alguienJugando() const{
	return _alguienJugando;
}

Nat Fichin::cantMov(){
	return (*_partidaActual).CantMov();
}

Nat Fichin::inmunidad(){
	return (*_partidaActual).inmunidad();
}

Coordenada Fichin::jugador() const{
	return (*_partidaActual).jugador();
}
