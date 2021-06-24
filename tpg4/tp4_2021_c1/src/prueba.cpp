// #include<stdio.h>
// #include<iostream>


// //#include "Tipos.h"
// #include "aed2_Fichin.h"
// //#include "Dicc_trie.h"
// using namespace std;

// int main(){
//     Coordenada posI, posIA, posIB, posII, posID, posL, posLA, posLB, posLI, posLD;
//     Coordenada pos0, pos1, pos2, pos3, pos4, pos5, pos6, pos7, pos8, pos9;
//     set<Coordenada> posicionesI, posiciones12, posiciones123, posiciones3456, posiciones456, posiciones789, posiciones89, posiciones9;
//     Jugador jugador1, jugador2, jugador3;
//     map<Jugador, Puntaje> ranking1, ranking2, ranking3, ranking4, ranking5, ranking6;
//     pair<Jugador, Puntaje> objetivo1, objetivo2;

//         posI = {2, 7};
//         posIA = {2, 8};
//         posIB = {2, 6};
//         posII = {1, 7};
//         posID = {3, 7};
//         posL = {9, 2};
//         posLA = {9, 3};
//         posLB = {9, 1};
//         posLI = {8, 2};
//         posLD = {10, 2};
//         pos0 = {4, 6};
//         pos1 = {3, 6};
//         pos2 = {8, 3};
//         pos3 = {1, 1};
//         pos4 = {2, 1};
//         pos5 = {1, 2};
//         pos6 = {5, 4};
//         pos7 = {4, 7};
//         pos8 = {1, 6};
//         pos9 = {10, 8};
//         posicionesI = {posI};
//         posiciones12 = {pos1, pos2};
//         posiciones123 = {pos1, pos2, pos3};
//         posiciones3456 = {pos3, pos4, pos5, pos6};
//         posiciones456 = {pos4, pos5, pos6};
//         posiciones789 = {pos7, pos8, pos9};
//         posiciones89 = {pos8, pos9};
//         posiciones9 = {pos9};
//         jugador1 = "jugador1";
//         jugador2 = "jugador2";
//         jugador3 = "jugador3";
//         objetivo1 = {jugador1, 12};
//         objetivo2 = {jugador2, 14};

// 	Mapa m(10, 8, posI, posL, posiciones789,  
//                          posiciones456, posiciones123);
// 	Partida p2(m);
//         aed2_Fichin p(10, 8, posI, posL, posiciones789,  
// 			 posiciones456, posiciones123);
// //	set<Coordenada> x = p.EntornoDistTres(Coordenada {4,4});
// 	//for(Coordenada e: x){
// 		//set<Jugador> C = p.ranking().keys();
// 		cout<<p.ranking().empty()<<endl;
// 		cout<<p.alguienJugando()<<endl;
// 		cout<<p.largo()<<endl;
// 		cout<<p.alto()<<endl;
// 		cout<<"("<<p.inicio().first<<","<<p.inicio().second<<")"<<endl;
// 	//}
// 	p.nuevaPartida("TUTE");
// 	Coordenada hola = p.jugador();
// 	p.mover(ARRIBA);
// 	p2.Mover(ARRIBA);
// //	hola = make_pair(p.jugador().first+1,p.jugador().second);
// //        cout<<"("<<hola.first<<","<<hola.second<<")"<<endl;
//         cout<<"("<<p2.jugador().first<<","<<p2.jugador().second<<")"<<endl;
// 	cout<<m.IdChocolate(make_pair(2,7))<<endl;
// return 0;
// }

