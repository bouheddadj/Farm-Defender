OBJS_JEU = $(OBJ_DIR)/BatimentDefense.o $(OBJ_DIR)/Vect2.o $(OBJ_DIR)/Jeu.o $(OBJ_DIR)/Ennemi.o $(OBJ_DIR)/JeuModeTexte.o $(OBJ_DIR)/StockageRessources.o $(OBJ_DIR)/Ferme.o $(OBJ_DIR)/BaseCentrale.o $(OBJ_DIR)/winTxt.o
OBJS_GR = $(OBJ_DIR)/JeuModeGraphique.o $(OBJ_DIR)/sdlJeu.o	$(OBJ_DIR)/BatimentDefense.o $(OBJ_DIR)/Vect2.o $(OBJ_DIR)/Jeu.o $(OBJ_DIR)/Ennemi.o $(OBJ_DIR)/StockageRessources.o $(OBJ_DIR)/Ferme.o $(OBJ_DIR)/BaseCentrale.o

SDL1 = -lSDL2 -lSDL2_ttf -lSDL2_image -lX11 -lSDL2_mixer
SDL2 = -ISDL2
FLAGS = -ggdb -Wall
CC = g++
SRC_DIR = ./src
BIN_DIR = ./bin
OBJ_DIR = ./obj
DATA_DIR = ./data

all: $(BIN_DIR)/jeu $(BIN_DIR)/gr

$(BIN_DIR)/jeu: $(OBJS_JEU)
	$(CC) $(FLAGS) $(OBJS_JEU) -o $(BIN_DIR)/jeu

$(BIN_DIR)/gr: $(OBJS_GR)
	$(CC) $(FLAGS) $(OBJS_GR) -o $(BIN_DIR)/gr $(SDL1)

$(OBJ_DIR)/sdlJeu.o: $(SRC_DIR)/sdlJeu.cpp
	$(CC) $(FLAGS) -c $(SRC_DIR)/sdlJeu.cpp -o $(OBJ_DIR)/sdlJeu.o $(SDL2)

$(OBJ_DIR)/JeuModeGraphique.o: $(SRC_DIR)/JeuModeGraphique.cpp $(SRC_DIR)/sdlJeu.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/JeuModeGraphique.cpp -o $(OBJ_DIR)/JeuModeGraphique.o $(SDL2)

$(OBJ_DIR)/Vect2.o: $(SRC_DIR)/Vect2.cpp
	$(CC) $(FLAGS) -c $(SRC_DIR)/Vect2.cpp -o $(OBJ_DIR)/Vect2.o

$(OBJ_DIR)/BatimentDefense.o: $(SRC_DIR)/BatimentDefense.cpp $(SRC_DIR)/Vect2.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/BatimentDefense.cpp -o $(OBJ_DIR)/BatimentDefense.o

$(OBJ_DIR)/Ennemi.o: $(SRC_DIR)/Ennemi.cpp $(SRC_DIR)/Vect2.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/Ennemi.cpp -o $(OBJ_DIR)/Ennemi.o

$(OBJ_DIR)/Jeu.o: $(SRC_DIR)/Jeu.cpp $(SRC_DIR)/BatimentDefense.h $(SRC_DIR)/JeuModeTexte.h $(SRC_DIR)/BaseCentrale.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/Jeu.cpp -o $(OBJ_DIR)/Jeu.o
	
$(OBJ_DIR)/BaseCentrale.o: $(SRC_DIR)/BaseCentrale.cpp $(SRC_DIR)/StockageRessources.h $(SRC_DIR)/Vect2.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/BaseCentrale.cpp  -o $(OBJ_DIR)/BaseCentrale.o
	
$(OBJ_DIR)/StockageRessources.o: $(SRC_DIR)/StockageRessources.cpp
	$(CC) $(FLAGS) -c $(SRC_DIR)/StockageRessources.cpp -o $(OBJ_DIR)/StockageRessources.o

$(OBJ_DIR)/Ferme.o:  $(SRC_DIR)/StockageRessources.h $(SRC_DIR)/Vect2.h $(SRC_DIR)/Ferme.cpp
	$(CC) $(FLAGS) -c $(SRC_DIR)/Ferme.cpp  -o $(OBJ_DIR)/Ferme.o

$(OBJ_DIR)/winTxt.o: $(SRC_DIR)/winTxt.cpp
	$(CC) $(FLAGS) -c $(SRC_DIR)/winTxt.cpp -o $(OBJ_DIR)/winTxt.o

$(OBJ_DIR)/JeuModeTexte.o: $(SRC_DIR)/JeuModeTexte.cpp $(SRC_DIR)/Vect2.h $(SRC_DIR)/winTxt.h $(SRC_DIR)/Jeu.h
	$(CC) $(FLAGS) -c $(SRC_DIR)/JeuModeTexte.cpp -o $(OBJ_DIR)/JeuModeTexte.o

docu:
	cd doc ; doxygen doxyfile

clean:
	rm -f $(OBJS_JEU) $(OBJS_GR) $(BIN_DIR)/jeu $(BIN_DIR)/gr -r doc/html
