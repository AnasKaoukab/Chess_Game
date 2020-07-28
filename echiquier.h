#pragma once
#include "Piece.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Echiquier {
public:
  Echiquier();
  ~Echiquier();
  void alloc_mem_echiquier();
  void affiche() const;
  void deplace(string orig,string dest);
  void pose_piece(Piece * piece, Square pos);
  void enlever_piece(Piece * piece, Square position);
  bool petitroque(bool joueur);
  bool yaechec(bool joueur,vector<int> orig,vector<int> dest,Piece * echiquier[8][8]);
  bool grandroque(bool joueur);
  bool enpassant(bool joueur, string coupprecedant, bool direction);
  void effacer_piece();



protected:
  vector <Piece * > piecesb;
  vector <Piece * > piecesn;
  vector <Piece * > pionsb;
  vector <Piece * > pionsn;
  Piece * echiquier[8][8];


};
