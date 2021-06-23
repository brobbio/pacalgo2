#include "Partida.h"

Partida::Partida(Mapa m): _mapa(m), _chocolates(),_jugador(), _cantMov(0), _inmunidad(), _gano(0), _perdio(0) {
	_jugador = m.Inicio();
	int i = 0;
	while(i<m.CantChocolates()){
		_chocolates.push_back(true);
		i++;
	};
	int idChoco = m.IdChocolate(_jugador);
	bool hayUnChoco = (0<= idChoco) && (idChoco < m.CantChocolates());
	if(hayUnChoco){
		_chocolates[idChoco] = false;
		_inmunidad = 10;
	}else{
		_inmunidad = 0;
	};
	_perdio = (m.EsCasilleroPeligroso(_jugador)) && (_inmunidad == 0);
}

void Partida::Mover(Direccion dir){
	Coordenada nuevaPosicion = _jugador;
	if(dir == ARRIBA){
		nuevaPosicion = make_pair(_jugador.first,1+_jugador.second);
	};
	if(dir == ABAJO){
		nuevaPosicion = make_pair(_jugador.first,_jugador.second-1);
	};
	if(dir == DERECHA){
		nuevaPosicion = make_pair(1+_jugador.first,_jugador.second);
	};
	if(dir == IZQUIERDA){
		nuevaPosicion = make_pair(_jugador.first-1,_jugador.second);
	};
	if(_mapa.EnRango(nuevaPosicion)){
		if(!(_mapa.EsPared(nuevaPosicion))){
			_jugador = nuevaPosicion;
			_cantMov++;
			int idChoco = _mapa.IdChocolate(_jugador);
			bool hayUnChoco = (0<= idChoco) && (idChoco < _mapa.CantChocolates());
			if(hayUnChoco && _chocolates[idChoco]){
				_chocolates[idChoco] = false;
				_inmunidad = 10;
			}else{
				if(_inmunidad  < 1){
					_inmunidad = 0;
				}else{
					_inmunidad--;
				}
			}
			_perdio = (_mapa.EsCasilleroPeligroso(_jugador)) && (_inmunidad == 0);
			_gano = _mapa.Llegada() == _jugador;
		}
	}
}


bool Partida::Gano(){
	return _gano;
}

bool Partida::Perdio(){
	return _perdio;
}

Coordenada Partida::Jugador(){
	return _jugador;
}

Puntaje Partida::CantMov() const{
	return _cantMov;
}


set<Coordenada> Partida::chocolatesActuales() const{
	set<Coordenada> res;
	for(Coordenada e: _mapa.conjuntoDeChocolates()){
		if(_chocolates[_mapa.IdChocolate(e)]){
			res.insert(e);
		}
	}
	return res;
}

Nat Partida::inmunidad() const{
	return _inmunidad;
}

Coordenada Partida::jugador() const{
	return _jugador;
}

Coordenada Partida::inicio() const{
	return _mapa.Inicio();
}

Coordenada Partida::llegada() const{
        return _mapa.Llegada();
}
