template <typename T>
string_map<T>::string_map(): _size(0), _raiz(NULL){}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

//template <typename T>
//string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
//}

template <typename T>
void string_map<T>::destruirNodo(Nodo* n){
	if(n!=NULL){
	     vector<Nodo*> temporal = n->siguientes;
 	     for(Nodo* e: temporal){
			destruirNodo(e);
		}
		delete n;
	}
}

template <typename T>
string_map<T>::~string_map(){
    if(_raiz != NULL){
		this->destruirNodo(_raiz);
    }
}

template <typename T>
void string_map<T>::insert(const pair<string, T>& a){
	Nodo* temp = _raiz;
	for(char e: a.first){
		if(temp->siguientes[int(e)] != NULL){
			temp = temp->siguientes[int(e)];
		}else{
			Nodo* n = new Nodo();
			temp->siguientes[int(e)] = n;
			temp = temp->siguientes[int(e)];
		}
	}
	temp->definicion = new int(a.second);
	_size++;
}


template <typename T>
T& string_map<T>::operator[](const string& clave){
    Nodo* temp = _raiz;
    for(char e : clave){
        temp = temp->siguientes[int(e)];
    }
    return *(temp->definicion);
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    Nodo* temp = _raiz;
    for(char e : clave){
	if(temp->siguientes[int(e)]==NULL){
		return false;
	}else{
        	temp = temp->siguientes[int(e)];
	}
    }
    return temp->definicion == NULL;

}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* temp = _raiz;
    for(char e : clave){
    	temp = temp->siguientes[int(e)];
    }
    return *(temp->definicion);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* temp = _raiz;
    for(char e : clave){
        temp = temp->siguientes[int(e)];
    }
    return *(temp->definicion);
}

//template <typename T>
//void string_map<T>::erase(const string& clave) {
    // COMPLETAR
//}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
set<string> string_map<T>::keysNodo(string s , Nodo* n) const{
	set<string> claves;
	if(n!=NULL){
		vector<Nodo*> sig = n->siguientes;
  		int i = 0;
		while(i<256){
			if(sig[i]!=NULL){
				if(sig[i]->definicion!=NULL){
					claves.insert(s+char(i));
				}
				for(string e: keysNodo(s+char(i), sig[i])){
					claves.insert(e);
				}
			}
			i++;
		}
	}
	return claves;
}

template <typename T>
set<string> string_map<T>::keys() const{
	return this->keysNodo("", _raiz);
}

template <typename T>
bool string_map<T>::empty() const{
    return _size == 0;
}

