#ifndef DICC_TRIE_H_
#define DICC_TRIE_H_

#include <string>

using namespace std;

template<typename T>
class string_map {
public:
    /**
    CONSTRUCTOR
    * Construye un diccionario vacio.
    **/
    string_map();

    /**
    CONSTRUCTOR POR COPIA
    * Construye un diccionario por copia.
    **/
    string_map(const string_map<T>& aCopiar);

    /**
    OPERADOR ASIGNACION
     */

//    string_map& operator=(const string_map& d);

    /**
    DESTRUCTOR
    **/
    ~string_map();

    /**
    INSERT 
    * Inserta un par clave, valor en el diccionario
    **/
    void insert(const pair<string, T>& a);

    /**
    COUNT
    * Devuelve la cantidad de apariciones de la clave (0 o 1).
    * Sirve para identificar si una clave está definida o no.
    **/
   
  //  int count(const string &key) const;

    /**
    AT
    * Dada una clave, devuelve su significado.
    * PRE: La clave está definida.
    --PRODUCE ALIASING--
    -- Versión modificable y no modificable
    **/
  //  const T& at(const string& key) const;
   // T& at(const string& key);

    /**
    ERASE
    * Dada una clave, la borra del diccionario junto a su significado.
    * PRE: La clave está definida.
    --PRODUCE ALIASING--
    **/
    //void erase(const string& key);

    /**
     SIZE
     * Devuelve cantidad de claves definidas */
   // int size() const;

    /**
     EMPTY
     * devuelve true si no hay ningún elemento en el diccionario */
  //  bool empty() const;

    //Devuelve el conjunto de claves del diccionario.
   // set<string> keys() const;

    /** OPTATIVO
    * operator[]
    * Acceso o definición de pares clave/valor
    **/
   // T &operator[](const string &key);
   
private:

    struct Nodo {
        vector<Nodo*> siguientes;
	Nodo() :siguientes(256, NULL), definicion(NULL){}
	Nodo(T* def): siguientes(256, NULL), definicion(def){}
        T* definicion;
    };

    void destruirNodo(Nodo* n);

   // set<string> keysNodo(string s, Nodo* n) const;

    Nodo* _raiz;
    int _size;
};

#include "Dicc_trie.hpp"

#endif // DICC_TRIE_H_
