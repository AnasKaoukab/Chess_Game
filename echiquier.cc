#include "echiquier.h"
#include "Piece.h"
#include "Couleur.h"
#include "Square.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
#define NBCOL 8

// constructeur

void Echiquier::alloc_mem_echiquier(){
  for(unsigned char i(0); i < NBCOL; i++){
    for (size_t j=0; j< NBCOL; j++){
      echiquier[i][j]=nullptr;
    }
    piecesb.push_back(nullptr);
    piecesn.push_back(nullptr);
    pionsb.push_back(nullptr);
    pionsn.push_back(nullptr);
  }
}

void Echiquier::enlever_piece(Piece * piece, Square position){
    vector <int> a ;
    a=position.get_posi();
    echiquier[a[0]][a[1]]=nullptr;
}

void Echiquier::pose_piece(Piece * piece, Square position){
    vector <int> a ;
    a=position.get_posi();
    echiquier[a[0]][a[1]]=piece;
}


bool Echiquier::petitroque(bool joueur){
  //Cas des blancs
	if(joueur==0){
    		if(!(echiquier[0][5]==nullptr && echiquier[0][6]==nullptr)){
			      cerr << "Des pieces sont présentes entre le roi et la tour:" << endl;
			      cerr << "Petit roque impossible" << endl;
            return false;
		    }
        else {
		        echiquier[0][6]=new Roi(Blanc,"\u2654",  Square(0,6));
		        echiquier[0][5]=new Tour(Blanc,"\u2656",  Square(0,5));
            enlever_piece(echiquier[0][4],echiquier[0][4]->get_pos());
            enlever_piece(echiquier[0][7],echiquier[0][7]->get_pos());
            return true;
       }
	}
  // Cas des noirs
  else{
		  if(!(echiquier[7][5]==nullptr && echiquier[7][6]==nullptr)){
			     cerr << "Des pieces sont présentes entre le roi et la tour:" << endl;
			     cerr << "Petit roque impossible" << endl;
           return false;
		  }
      else{
		      echiquier[7][6]=new Roi(Noir,"\u265A",  Square(7,6));
		      echiquier[7][4]=nullptr;
		      echiquier[7][5]=new Tour(Noir,"\u265C",  Square(7,5));
		      echiquier[7][7]=nullptr;
          return true;
      }
	}
}


bool Echiquier::grandroque(bool joueur){
  //Cas des blancs
	if(joueur==0){
		  if(!(echiquier[0][1]==nullptr && echiquier[0][2]==nullptr && echiquier[0][3]==nullptr)){
			     cerr << "Des pieces sont présentes entre le roi et la tour:" << endl;
           cerr << "Grand roque impossible" << endl;
           return false;
		  }
      else {
		      echiquier[0][2]=new Roi(Blanc,"\u2654",  Square(0,2));
		      echiquier[0][3]=new Tour(Blanc,"\u2656",  Square(0,3));
          enlever_piece(echiquier[0][0],echiquier[0][0]->get_pos());
          enlever_piece(echiquier[0][4],echiquier[0][4]->get_pos());
          return true;
     }
	}
  //Cas des noirs
	else{
		 if(!(echiquier[7][1]==nullptr && echiquier[7][2]==nullptr && echiquier[7][3]==nullptr)){
			    cerr << "Des pieces sont présentes entre le roi et la tour:" << endl;
			    cerr << "Grand roque impossible" << endl;
          return false;
		}
    else{
		      echiquier[7][2]=new Roi(Noir,"\u265A",  Square(7,6));
		      echiquier[7][0]=nullptr;
		      echiquier[7][3]=new Tour(Noir,"\u265C",  Square(7,5));
		      echiquier[7][4]=nullptr;
          return true;
    }
  }
}


bool Echiquier::yaechec(bool joueur,vector<int> orig,vector<int> dest,Piece * echiquier[8][8]){
    vector<int> origine;
    origine.push_back(0);
    origine.push_back(0);
    vector<int> destination;
    destination.push_back(0);
    destination.push_back(0);

    if(joueur==0){
        if (echiquier[orig[0]][orig[1]]->get_nom()=="\u2654") { // Au cas où c'est un roi
            //Parcourir tout l'echiquier
            for (int i = 0; i < NBCOL; i++) {
                for (int j = 0; j < NBCOL; j++) {
                    origine[0]=i;
                    origine[1]=j;
                    // Voir toutes les destinations légales possibles des pieces noires existantes
                    for (int x = 0; x < NBCOL; x++) {
                        for (int y= 0; y < NBCOL; y++) {
                            destination[0]=x;
                            destination[1]=y;
                            if(echiquier[i][j])  {
                                if (echiquier[i][j]->get_couleur()==Noir && echiquier[i][j]->est_mouvement_legal(origine,destination,echiquier)){
                                      //Verifier si l'une des destinations legales des pieces noires existantes
                                      //coincide avec la destination du mouvement du roi blanc
                                      if((dest[0]==destination[0]) && (dest[1]==destination[1])){
                                            return true;
                                      }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    else{
        if (echiquier[orig[0]][orig[1]]->get_nom()=="\u265A") {
            for (int i = 0; i < NBCOL; i++) {
                for (int j = 0; j < NBCOL; j++) {
                    origine[0]=i;
                    origine[1]=j;

                    for (int x = 0; x < NBCOL; x++) {
                        for (int y= 0; y < NBCOL; y++) {
                            destination[0]=x;
                            destination[1]=y;
                            if(echiquier[i][j])  {
                                if (echiquier[i][j]->get_couleur()==Blanc && echiquier[i][j]->est_mouvement_legal(origine,destination,echiquier)){
                                    if((dest[0]==destination[0]) && (dest[1]==destination[1])){
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "pas d'echec pour le roi" <<endl;
    return false;
}


// Initialiser les compteurs de mouvement pour le roi et le tour pour
// bien vérifier la possibilté du roque
int cpt1=0;
int cpt2=0;
int cpt1n=0;
int cpt2n=0;
int joueur=0;

void Echiquier::deplace(string orig,string dest){
    //Cas où on demande le petit Roque:
    if (orig == "o"){
        if (!joueur) {
            if (cpt1 == 0 && cpt2== 0) {
                if(petitroque(joueur)){
                    joueur=!joueur;
                }
            }
            else{
                cerr << "roi ou tour déja deplacé" << endl;
                cerr << "Petit roque impossible" << endl;
            }
        }
        else{
            if (cpt1n == 0 && cpt2n== 0) {
                if(petitroque(joueur)){
                    joueur=!joueur;
                }
            }
            else{
                cerr << "roi ou tour déja deplacé" << endl;
                cerr << "Petit roque impossible" << endl;
            }
        }
    }

    //Cas où on demande le grand Roque:
    else if (orig == "O"){
        if (!joueur){
            if (cpt1 == 0 && cpt2== 0) {
                  if(grandroque(joueur)){
                      joueur=!joueur;
                  }
            }
            else{
                  cerr << "roi ou tour déja deplacé" << endl;
                  cerr << "Grand roque impossible" << endl;
            }
        }
        else{
            if (cpt1n == 0 && cpt2n== 0) {
                  if(grandroque(joueur)){
                      joueur=!joueur;
                  }
            }
            else{
                cerr << "roi ou tour déja deplacé" << endl;
                cerr << "Grand roque impossible" << endl;
            }
       }
   }
  //Cas de demande d'un mouvement normal
   else{
      Square o(orig);
      Square d(dest);
      vector <int> a=o.get_posi();
      vector <int> b=d.get_posi();
      Piece* p;
      Piece* p2;
      p = echiquier[a[0]][a[1]];
      p2 = echiquier[b[0]][b[1]];

      if (! p) {
          cerr << "pas de piece dans la case d'origine" << endl;
      }

      if (!joueur) {
          if (p->get_couleur()==Noir) {
              cerr<< "C'est le tour des blancs" << endl;
          }
          // Effectuer les mouvements en verifiant toujours s'il ya echec
          if ( ! yaechec(joueur,a,b,echiquier)) {
              cout << "pas de menace pour le roi"<< endl;

              if ( p2 && p2->get_couleur()==Blanc) {
                  cerr << "Case de destination occupée" << endl;
              }

              else if (p->get_nom()=="\u2656") {
                  if (p->est_mouvement_legal(a,b,echiquier)==true){
                      enlever_piece(p,p->get_pos());
                      joueur=!joueur;
                      cpt1++;
                      p=new Tour(Blanc,"\u2656",Square(b[0],b[1]));
                  }
                  else {
                      cerr<< "mouvement illegal"<<endl;
                  }
              }
              else if (p->get_nom()=="\u2657") {
                  if (p->est_mouvement_legal(a,b,echiquier)==true){
                      joueur=!joueur;
                      enlever_piece(p,p->get_pos());
                      p=new Fou(Blanc,"\u2657",  Square(b[0],b[1]));
                  }
                  else {
                      cerr<< "mouvement illegal"<<endl;
                  }
              }
              else if(p->get_nom()=="\u2658"){
                  if (p->est_mouvement_legal(a,b,echiquier)==true){
                      joueur=!joueur;
                      enlever_piece(p,p->get_pos());
                      p=new Cavalier(Blanc,"\u2658",Square(b[0],b[1]));
                  }
                  else {
                      cerr<< "mouvement illegal"<<endl;
                  }
              }
              else if (p->get_nom()=="\u2654") {
                  if (p->est_mouvement_legal(a,b,echiquier)==true){
                      enlever_piece(p,p->get_pos());
                      joueur=!joueur;
                      cpt2++;
                      p=new Roi(Blanc,"\u2654",Square(b[0],b[1]));
                  }
                  else {
                      cerr<< "mouvement illegal"<<endl;
                  }
              }
              else if (p->get_nom()=="\u2655") {
                  if (p->est_mouvement_legal(a,b,echiquier)==true){
                      enlever_piece(p,p->get_pos());
                      joueur=!joueur;
                      p=new Dame(Blanc,"\u2655",  Square(b[0],b[1]));
                  }
                  else {
                      cerr<< "mouvement illegal"<<endl;
                  }
              }
              else if (p->get_nom()=="\u2659") {
                  if (p->est_mouvement_legal(a,b,echiquier)==true){
                      enlever_piece(p,p->get_pos());
                      joueur=!joueur;
                      p=new Pion(Blanc,"\u2659",  Square(b[0],b[1]));
                  }
                  else {
                      cerr<< "mouvement illegal"<<endl;
                  }
              }

              pose_piece(p,p->get_pos());
          }
          else{
              cerr << "ATTENTION ECHEC POUR LE ROI " << endl;
              cerr << "REJOUE" << endl;
          }
    }

    else{
          if (p->get_couleur()==Blanc) {
                cerr<< "C'est le tour des noirs" << endl;
          }

          if (! yaechec(joueur,a,b,echiquier)) {
                cout << "pas de menace pour le roi"<< endl;
                if ( p2 && p2->get_couleur()==Noir) {
                    cerr << "Case de destination occupée" << endl;
                }

                else if (p->get_nom()=="\u265C") {
                    if (p->est_mouvement_legal(a,b,echiquier)==true){
                        joueur=!joueur;
                        cpt2n++;
                        enlever_piece(p,p->get_pos());
                        p=new Tour(Noir,"\u265C",Square(b[0],b[1]));
                    }
                    else {
                        cerr<< "mouvement illegal"<<endl;
                    }
                }
                else if (p->get_nom()=="\u265D") {
                    if (p->est_mouvement_legal(a,b,echiquier)==true){
                        joueur=!joueur;
                        enlever_piece(p,p->get_pos());
                        p=new Fou(Noir,"\u265D",  Square(b[0],b[1]));
                    }
                    else {
                        cerr<< "mouvement illegal"<<endl;
                    }
                }
                else if(p->get_nom()=="\u265E"){
                    if (p->est_mouvement_legal(a,b,echiquier)==true){
                        joueur=!joueur;
                        enlever_piece(p,p->get_pos());
                        p=new Cavalier(Noir,"\u265E",  Square(b[0],b[1]));
                    }
                    else {
                        cerr<< "mouvement illegal"<<endl;
                    }
                }
                else if (p->get_nom()=="\u265A") {
                    if (p->est_mouvement_legal(a,b,echiquier)==true){
                        joueur=!joueur;
                        cpt1n++;
                        enlever_piece(p,p->get_pos());
                        p=new Roi(Noir,"\u265A",Square(b[0],b[1]));
                    }
                    else {
                        cerr<< "mouvement illegal"<<endl;
                    }
               }
               else if (p->get_nom()=="\u265B") {
                  if (p->est_mouvement_legal(a,b,echiquier)==true){
                      joueur=!joueur;
                      enlever_piece(p,p->get_pos());
                      p=new Dame(Noir,"\u265B",Square(b[0],b[1]));
                  }
                  else {
                      cerr<< "mouvement illegal"<<endl;
                  }
              }
              else if (p->get_nom()=="\u265F") {
                  if (p->est_mouvement_legal(a,b,echiquier)==true){
                      joueur=!joueur;
                      enlever_piece(p,p->get_pos());
                      p=new Pion(Noir,"\u265F",Square(b[0],b[1]));
                  }
                  else {
                      cerr<< "mouvement illegal"<<endl;
                  }
              }
              pose_piece(p,p->get_pos());
         }
         else{
           cerr << "ATTENTION ECHEC POUR LE ROI " << endl;
           cerr << "REJOUE" << endl;
          }
        }
    if (joueur){
      cout << "C'EST AUX NOIRS" <<endl;
    }
    else{
      cout << "C'EST AUX BLANCS" <<endl;
    }
  }
}

Echiquier::Echiquier ()
{

    alloc_mem_echiquier(); // --> alloue un tableau équivalent à un Piece *[8][8]
                           //     en initialisant les cases à nullptr
                           //     et alloue des vecteurs piecesb, piecesn, pionsb
    // Constructeur (Couleur,nom_affiché,id,case)
    piecesb[0] = new Tour    (Blanc,"\u2656",  Square(0,0));
    piecesb[1] = new Cavalier(Blanc,"\u2658",  Square(0,1));
    piecesb[2] = new Fou     (Blanc,"\u2657",  Square(0,2));
    piecesb[3] = new Dame    (Blanc,"\u2655",  Square(0,3));
    piecesb[4] = new Roi     (Blanc,"\u2654",  Square(0,4));
    piecesb[5] = new Fou     (Blanc,"\u2657",  Square(0,5));
    piecesb[6] = new Cavalier(Blanc,"\u2658",  Square(0,6));
    piecesb[7] = new Tour    (Blanc,"\u2656",  Square(0,7));
    piecesn[0] = new Tour    (Noir, "\u265C",  Square(7,0));
    piecesn[1] = new Cavalier(Noir, "\u265E",  Square(7,1));
    piecesn[2] = new Fou     (Noir, "\u265D",  Square(7,2));
    piecesn[3] = new Dame    (Noir, "\u265B",  Square(7,3));
    piecesn[4] = new Roi     (Noir, "\u265A",  Square(7,4));
    piecesn[5] = new Fou     (Noir, "\u265D",  Square(7,5));
    piecesn[6] = new Cavalier(Noir, "\u265E",  Square(7,6));
    piecesn[7] = new Tour    (Noir, "\u265C",  Square(7,7));

    // allocation des pions
    for (unsigned char i(0);i<NBCOL;i++) {
         pionsb[i] =  new Pion(Blanc, "\u2659", Square(1,i));
         pionsn[i] =  new Pion(Noir,  "\u265F", Square(6,i));
    }


    for (unsigned char i(0);i<NBCOL;i++){
        pose_piece(piecesb[i],piecesb[i]->get_pos());
        pose_piece(piecesn[i],piecesn[i]->get_pos());
        pose_piece(pionsb[i],pionsb[i]->get_pos());
        pose_piece(pionsn[i],pionsn[i]->get_pos());

}
}

Echiquier::  ~Echiquier(){

}


void Echiquier::affiche () const {

        string space5 = string(5,' ');
        cout << endl;
        cout << "     a     b     c     d     e     f     g     h    "<< endl;
        cout << "  +-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
        for (int i(NBCOL-1);i>=0;i--) {
                cout << i+1 << " "; // numérotation ligne dans affichage
                for (int j(0);j<NBCOL;j++) {
                        cout << "|" ;
                        if (echiquier[i][j]) {
                          cout << "\u0020\u0020";  //U+0020 est un esapce utf-8 taille police
                          echiquier[i][j]-> affiche();
                          cout << "\u0020" << " ";
                        }
                        else
                                cout << space5;  // 2 ascii spaces
                }
                cout << "|\n  +-----+-----+-----+-----+-----+-----+-----+-----+";
                cout << endl;
        }
}

void Echiquier::effacer_piece(){

	for(int i(0); i<8; i++){
		for(int j(0); j<8; j++){
			delete echiquier[i][j];
		}
	}
}
