#pragma once
#include <string>
#include <iostream>
#include "echiquier.h"
using namespace std;

class Jeu{
public:
  Jeu();
  ~Jeu();
  void affiche();
  void deplace(string orig,string dest);
  void efface();

private:
  Echiquier echiquier;
};
