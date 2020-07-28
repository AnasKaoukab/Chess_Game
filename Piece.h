#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Couleur.h"
#include "Square.h"
using namespace std;

class Piece {
public:
  Piece(Couleur couleur, string nom, Square idcase);
  ~Piece();
  string get_nom() const;
  Couleur get_couleur() const;
  Square get_pos() const;
  virtual void affiche() const = 0;
  virtual bool est_mouvement_legal (vector<int> orig,vector<int> dest,Piece* echiquier[8][8]) const = 0;
protected:
  Couleur couleur;
  string nom;
  Square idcase;

};

class Tour : public Piece{
public:
  Tour(Couleur couleur, string nom, Square idcase);
  ~Tour();
  virtual bool est_mouvement_legal (vector<int> orig,vector<int> dest,Piece* echiquier[8][8]) const;
  virtual void affiche() const;
};

class Cavalier : public Piece{
public:
  Cavalier(Couleur couleur, string nom, Square idcase) ;
  ~Cavalier();
  virtual void affiche() const;
  virtual bool est_mouvement_legal (vector<int> orig,vector<int> dest,Piece* echiquier[8][8]) const;
};

class Fou : public Piece{
public:
  virtual void affiche() const;
  Fou(Couleur couleur, string nom, Square idcase) ;
  ~Fou();
  virtual bool est_mouvement_legal (vector<int> orig,vector<int> dest,Piece* echiquier[8][8]) const;
};

class Dame : public Piece{
public:
  virtual void affiche() const;
  Dame(Couleur couleur, string nom, Square idcase) ;
  ~Dame();
  virtual bool est_mouvement_legal (vector<int> orig,vector<int> dest,Piece* echiquier[8][8]) const;
};

class Roi : public Piece{
public:
  virtual void affiche() const;
  Roi(Couleur couleur, string nom, Square idcase);
  ~Roi();
  virtual bool est_mouvement_legal (vector<int> orig,vector<int> dest,Piece* echiquier[8][8]) const;
};

class Pion : public Piece{
public:
  Pion(Couleur couleur, string nom, Square idcase);
  ~Pion();
  virtual bool est_mouvement_legal (vector<int> orig,vector<int> dest,Piece* echiquier[8][8]) const;
  virtual void affiche() const;

};
