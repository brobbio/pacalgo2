#include<stdio.h>
#include<iostream>


#include "Tipos.h"
#include "Fichin.h"
#include "Dicc_trie.h"
using namespace std;

int main(){
	string_map<int> D;
	D.insert(make_pair("Argentina", 10));
	D.insert(make_pair("Argentina", 20));
	D.insert(make_pair("Argelia", 11));
	D.insert(make_pair("Zambia", 20));
	D.insert(make_pair("Bolivia", 20));
//	set<string> C = D.keys();
	set<string> C;
	C = D.keys();
	for(string e: C){
		cout<<e<<endl;
	}
	cout<<D["Argentina"]<<endl;
return 0;
}
