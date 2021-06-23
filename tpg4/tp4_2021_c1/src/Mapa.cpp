

#include "Mapa.h"


Mapa::Mapa(Nat largo,
                   Nat alto,
                   Coordenada inicio,
                   Coordenada llegada,
                   set<Coordenada> fantasmas,
                   set<Coordenada> paredes,
                   set<Coordenada> chocolates): 
			_alto(alto), _largo(largo), _inicio(inicio), _llegada(llegada), _matriz(largo),
			 _cantChocolates(chocolates.size()), _conjuntodeChocolates(chocolates)
{
	int idChocolate = 0;
	int i = 0;
	while(i<largo){
		int j = 0;
		while(j<alto){
			set<Coordenada> C = this->EntornoDistTres(make_pair(i,j));
			bool es_peligrosa = false;
			for(Coordenada e: C){
				if(fantasmas.count(e)){
					es_peligrosa = true;
					break;
				};
			};
			bool f = fantasmas.count(make_pair(i,j));
			bool pared = paredes.count(make_pair(i,j));
			int choco;
			if(chocolates.count(make_pair(i,j))){
				choco = idChocolate;
				idChocolate++;
			}else{
				choco = -1;
			};
                        Casillero c(f, es_peligrosa, pared, choco);
			_matriz[i].push_back(c);
			j++;
		};
		i++;
	};
}

set<Coordenada> Mapa::EntornoDistTres(Coordenada posicion){
	int d = 1;
	set<Coordenada> res = {posicion};
	for(int i=1;i<4;i++){
		for(int j=1;j<4;j++){
			if(i+j<4){
				res.insert(make_pair(posicion.first + i, posicion.second + j));
				res.insert(make_pair(posicion.first -i, posicion.second + j));
				res.insert(make_pair(posicion.first + i, posicion.second - j));
				res.insert(make_pair(posicion.first -i, posicion.second -j));
			}
		}
	}
/*	while(d>0){
		for(Coordenada e: res){
			res.insert(make_pair(e.first,e.second -1));
                	res.insert(make_pair(e.first + 1,e.second));
                	res.insert(make_pair(e.first,e.second +1));
                	res.insert(make_pair(e.first - 1,e.second));
		};
		d = d-1;
	};*/
	return res;
}


bool Mapa::EsCasilleroPeligroso(Coordenada posicion){
	return this->_matriz[posicion.first][posicion.second].peligrosa;
}

bool Mapa::EnRango(Coordenada posicion){
	return (posicion.first < this->_largo) && (posicion.second < this->_alto);
}

Nat Mapa::CantChocolates(){
	return _cantChocolates;
}

bool Mapa::EsPared(Coordenada posicion){
	return this->_matriz[posicion.first][posicion.second].pared;
}

Coordenada Mapa::Inicio() const{
	return this->_inicio;
}

Coordenada Mapa::Llegada() const{
	return this->_llegada;
}

int Mapa::IdChocolate(Coordenada posicion) const{
	return this->_matriz[posicion.first][posicion.second].idChocolate;
}

set<Coordenada> Mapa::conjuntoDeChocolates() const{
	return _conjuntodeChocolates;
}
