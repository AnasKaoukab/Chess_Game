#include <string>
#include <iostream>
#include "Couleur.h"
#include "Piece.h"

using namespace std;
#define NBCOL 8

Piece:: Piece(Couleur couleur, string nom, Square idcase): couleur(couleur),
  		nom(nom), idcase(idcase) {

      }

Piece:: ~Piece(){
}

Couleur Piece::get_couleur() const {
	return couleur;
}

string Piece::get_nom() const {
	return nom;
}

Square Piece::get_pos() const {
	return idcase;
}

Tour::  Tour(Couleur couleur, string nom, Square idcase): Piece(couleur, nom,idcase){}
Tour:: ~Tour(){
}
void Tour::affiche() const {
	    cout << get_nom();
		}

bool Tour::est_mouvement_legal(vector<int> orig, vector<int> dest,Piece* echiquier[8][8]) const {

      if (dest[0]<0 || dest[0]>7 ||dest[1]<0 ||dest[1]>7){
        cerr << "coordonnées hors echiquier" << endl;
        return false;
      }


      for (int i =1 ; i < NBCOL; i++) {
          if ( ((orig[0])==dest[0]) && ((orig[1]+i) == dest[1])){
            for (int j = 1; j < i; j++) {
              if ( echiquier[orig[0]][orig[1]+j]) {
                return false;
              }
            }
            return true;
          }

          if ( ((orig[0])==dest[0]) && ((orig[1]-i) == dest[1])){
            for (int j = 1; j < i; j++) {
              if ( echiquier[orig[0]][orig[1]-j]) {
                return false;
              }
            }
            return true;
          }

          if ( ((orig[0]-i)==dest[0]) && ((orig[1]) == dest[1])){
            for (int j = 1; j < i; j++) {
              if ( echiquier[orig[0]-j][orig[1]]) {
                return false;
              }
            }
            return true;
          }

          if ( ((orig[0]+i)==dest[0]) && ((orig[1]) == dest[1])){
            for (int j = 1; j < i; j++) {
              if ( echiquier[orig[0]+j][orig[1]]) {
                return false;
              }
            }
            return true;
          }
      }
      return false;
}


Cavalier::Cavalier(Couleur couleur, string nom, Square idcase): Piece(couleur, nom,idcase){}
Cavalier:: ~Cavalier(){
}
void Cavalier::affiche() const {
			     cout << get_nom();
				}

bool Cavalier::est_mouvement_legal(vector<int> orig, vector<int> dest,Piece* echiquier[8][8]) const {

    if (dest[0]<0 || dest[0]>7 ||dest[1]<0 ||dest[1]>7){
      cerr << "coordonnées hors echiquier" << endl;
      return false;
    }

    if( ( ((dest[0] ==(orig[0]+2)) || (dest[0] ==(orig[0]-2)))  && ((dest[1]==((orig[1])+1))
      ||(dest[1]==(orig[1]-1))) ) || ( ((dest[0] ==(orig[0]+1)) || (dest[0] ==(orig[0]-1)))
      && ((dest[1]==((orig[1])+2))  ||(dest[1]==(orig[1]-2))) )){
              return true;
    }
    else{
            return false;
    }
}


Fou::Fou(Couleur couleur, string nom, Square idcase): Piece(couleur, nom,idcase){}
Fou:: ~Fou(){
}
void Fou::affiche() const {
		 cout << get_nom();
}

bool Fou::est_mouvement_legal(vector<int> orig, vector<int> dest,Piece* echiquier[8][8]) const {

      if (dest[0]<0 || dest[0]>7 ||dest[1]<0 ||dest[1]>7){
        cerr << "coordonnées hors echiquier" << endl;
        return false;
      }

      for (int i = 0; i < NBCOL; i++) {
        if ( ((orig[0]+i)==dest[0]) && ((orig[1]+i) == dest[1])){
          for (int j = 1; j < i; j++) {
            if ( echiquier[orig[0]+j][orig[1]+j]) {
              return false;
            }
          }
          return true;
        }

        if ( ((orig[0]+i)==dest[0]) && ((orig[1]-i) == dest[1])){
          for (int j = 1; j < i; j++) {
            if ( echiquier[orig[0]+j][orig[1]-j]) {
              return false;
            }
          }
          return true;
        }

        if ( ((orig[0]-i)==dest[0]) && ((orig[1]-i) == dest[1])){
          for (int j = 1; j < i; j++) {
            if ( echiquier[orig[0]-j][orig[1]-j]) {
              return false;
            }
          }
          return true;
        }

        if ( ((orig[0]-i)==dest[0]) && ((orig[1]+i) == dest[1])){
          for (int j = 1; j < i; j++) {
            if ( echiquier[orig[0]-j][orig[1]+j]) {
              return false;
            }
          }
          return true;
        }
      }
      return false;
}


Dame::Dame(Couleur couleur, string nom, Square idcase): Piece(couleur, nom,idcase){}
Dame:: ~Dame(){
}
void Dame::affiche() const {
					     cout << get_nom();
}

bool  Dame::est_mouvement_legal(vector<int> orig, vector<int> dest,Piece* echiquier[8][8]) const {
      if (dest[0]<0 || dest[0]>7 ||dest[1]<0 ||dest[1]>7){
        cerr << "coordonnées hors echiquier" << endl;
        return false;
      }

      for (int i = 0; i < NBCOL; i++){
        if ( ((orig[0]+i)==dest[0]) && ((orig[1]+i) == dest[1])){
          for (int j = 1; j < i; j++) {
            if ( echiquier[orig[0]+j][orig[1]+j]) {
              return false;
            }
          }
          return true;
        }

        if ( ((orig[0]+i)==dest[0]) && ((orig[1]-i) == dest[1])){
            for (int j = 1; j < i; j++) {
            if ( echiquier[orig[0]+j][orig[1]-j]) {
              return false;
            }
          }
          return true;
        }

        if ( ((orig[0]-i)==dest[0]) && ((orig[1]-i) == dest[1])){
          for (int j = 1; j < i; j++) {
            if ( echiquier[orig[0]-j][orig[1]-j]) {
              return false;
            }
          }
          return true;
        }

        if ( ((orig[0]-i)==dest[0]) && ((orig[1]+i) == dest[1])){
          for (int j = 1; j < i; j++) {
            if ( echiquier[orig[0]-j][orig[1]+j]) {
              return false;
            }
          }
          return true;
        }

        if ( ((orig[0])==dest[0]) && ((orig[1]+i) == dest[1])){
          for (int j = 1; j < i; j++) {
            if ( echiquier[orig[0]][orig[1]+j]) {
              return false;
            }
          }
          return true;
        }

        if ( ((orig[0])==dest[0]) && ((orig[1]-i) == dest[1])){
          for (int j = 1; j < i; j++) {
            if ( echiquier[orig[0]][orig[1]-j]) {
              return false;
            }
          }
          return true;
        }

        if ( ((orig[0]-i)==dest[0]) && ((orig[1]) == dest[1])){
          for (int j = 1; j < i; j++) {
            if ( echiquier[orig[0]-j][orig[1]]) {
              return false;
            }
          }
          return true;
        }

        if ( ((orig[0]+i)==dest[0]) && ((orig[1]) == dest[1])){
          for (int j = 1; j < i; j++) {
            if ( echiquier[orig[0]+j][orig[1]]) {
              return false;
            }
          }
          return true;
        }
      }
      return false;
}


Roi::Roi(Couleur couleur, string nom, Square idcase): Piece(couleur, nom,idcase){}
Roi:: ~Roi(){
}
void Roi::affiche() const {
					 cout << get_nom();
}
bool Roi::est_mouvement_legal (vector<int> orig,vector<int> dest,Piece* echiquier[8][8]) const{
      if (dest[0]<0 || dest[0]>7 ||dest[1]<0 ||dest[1]>7){
        cerr << "coordonnées hors echiquier" << endl;
        return false;
      }

      if (dest[0]==orig[0]){
        if (dest[1]==orig[1]+1 || dest[1]==orig[1]-1){
          return true;
        }
      }

      if (dest[0]==orig[0]+1){
        if ( dest[1]==orig[1]-1 || dest[1]==orig[1] || dest[1]==orig[1]+1){
          return true;
        }
      }

      if (dest[0]+1==orig[0]){
        if (dest[1]==orig[1]+1 || dest[1]==orig[1]-1 || dest[1]==orig[1]){
          return true;
        }
      }
      return false;
}


Pion::Pion(Couleur couleur, string nom, Square idcase): Piece(couleur, nom,idcase){}
Pion:: ~Pion(){
}
void Pion::affiche() const {
					 cout << get_nom();
}

bool Pion::est_mouvement_legal (vector<int> orig,vector<int> dest,Piece* echiquier[8][8]) const{

      if (dest[0]<0 || dest[0]>7 ||dest[1]<0 ||dest[1]>7){
        cerr << "coordonnées hors echiquier" << endl;
        return false;
      }

      if(echiquier[orig[0]][orig[1]]->get_couleur()==Blanc){
        if (orig[0]==1){
          if ((orig[1]==dest[1]) && ( dest[0]==(orig[0]+1))) {
            if (echiquier[dest[0]][dest[1]]){
              return false;
            }
            else{
              return true;
            }
          }

          if ((orig[1]==dest[1]) && ( dest[0]==(orig[0]+2))) {
              if (echiquier[dest[0]][dest[1]] || echiquier[dest[0]-1][dest[1]]){
                return false;
              }
              else{
                return true;
              }
          }
        }

        if((orig[1]==dest[1]) && ( dest[0]==(orig[0]+1))) {
          if(echiquier[dest[0]][dest[1]]){
            return false;
          }
          else{
            return true;
          }
        }

        if((((orig[1]+1)==dest[1]) && (echiquier[orig[0]+1][orig[1]+1]) && ((orig[0]+1)==dest[0]))){
         return true;
        }

        if  ((((orig[1]-1)==dest[1]) && (echiquier[orig[0]+1][orig[1]-1]) && ((orig[0]+1)==dest[0]))){
         return true;
        }
      }

      else{
        if (orig[0]==6){
          if ((orig[1]==dest[1]) && ( dest[0]==(orig[0]-1))) {
            if (echiquier[dest[0]][dest[1]]){
              return false;
            }
            else{
              return true;
            }
          }

          if ((orig[1]==dest[1]) && ( dest[0]==(orig[0]-2))) {
            if (echiquier[dest[0]][dest[1]] || echiquier[dest[0]+1][dest[1]]){
              return false;
            }
            else{
              return true;
            }
          }

      }

      if((orig[1]==dest[1]) && ( dest[0]==(orig[0]-1))) {
         if(echiquier[dest[0]][dest[1]]){
           return false;
         }
         else{
           return true;
         }
       }

       if((((orig[1]+1)==dest[1]) && (echiquier[orig[0]-1][orig[1]+1]) && ((orig[0]-1)==dest[0]))){
            return true;
          }

       if  ((((orig[1]-1)==dest[1]) && (echiquier[orig[0]-1][orig[1]-1]) && ((orig[0]-1)==dest[0]))){
           return true;
       }
     }
     return false;
}
