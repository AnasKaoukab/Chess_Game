#include "echiquier.h"
#include "jeu.h"
#include <string>
#include <iostream>
using namespace std;


Jeu::  Jeu(){
 cout << "DEBUT DU JEU" << endl;
 cout <<"C'EST AU BLANCS"<<endl;
 cout << "COUP 1" << endl;
      }

Jeu::  ~Jeu(){
 cout << "FIN DU JEU" << endl;
}


void Jeu::affiche(){
  echiquier.affiche();
}

void Jeu::deplace(string orig,string dest){
  echiquier.deplace(orig,dest);
}

void Jeu::efface(){
  echiquier.effacer_piece();
}
