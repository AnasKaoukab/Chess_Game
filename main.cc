#include "echiquier.h"
#include "jeu.h"
using namespace std;
#include <string>
#include <iostream>

int main() {
    Jeu monjeu;  // initialise le jeu
    string mouvement;
    bool stop(false);
    int coup =1;
    monjeu.affiche();
    do
    {
       cout << "Coup (eg. a1a8) ? ";
       cin >> mouvement;
       if (mouvement != "/quit") {
           coup++;
           if (mouvement == "O-O" || mouvement == "0-0"){
             monjeu.deplace("o","rien");
           }
           else if (mouvement == "O-O-O" || mouvement == "0-0-0") {
             monjeu.deplace("O","rien");
           }
           else{
             string orig = mouvement.substr(0, 2);
             string dest = mouvement.substr(2, 2);
             monjeu.deplace(orig, dest);
           }
           monjeu.affiche();

        }
        else stop=true;
        cout << "COUP " << coup << endl;
    } while (!stop);
    monjeu.efface();
}
