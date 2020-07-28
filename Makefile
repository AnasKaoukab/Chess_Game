CC=g++
CFLAGS=--std=c++11 -Wall -g
DFLAGS=DEBUG

target : echec

echec : main.cc jeu.o echiquier.o Piece.o Square.o Couleur.h
	$(CC) $(CFLAGS) main.cc jeu.o echiquier.o Piece.o Square.o -o $@

echiquier.o : echiquier.h echiquier.cc Piece.h Couleur.h
	$(CC) $(CFLAGS) -c echiquier.cc

Piece.o : Piece.h Piece.cc Couleur.h
	$(CC) $(CFLAGS) -c Piece.cc

Square.o : Square.h Square.cc Couleur.h
	$(CC) $(CFLAGS) -D$(DFLAGS) -c Square.cc

jeu.o : jeu.h jeu.cc Couleur.h echiquier.h
	$(CC) $(CFLAGS) -c jeu.cc

clean:
	rm -rf *.dSYM *.o echec
