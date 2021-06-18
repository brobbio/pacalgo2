#include<stdio.h>
#include<iostream>


#include "Tipos.h"
#include "Fichin.h"
#include "Dicc_trie.h"
using namespace std;

int main(){
	string_map<int> D;
	D.insert(make_pair("Argentina", 10));
	//D.insert(make_pair("Argelia", 11));
	//D.insert(make_pair("Bolivia", 20));
//	set<string> C = D.keys();
	set<int> C;
	C.insert(10);
	for(int e: C){
		cout<<e<<endl;
	}
//	cout<<D.empty()<<endl;
return 0;
}
