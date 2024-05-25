CC = gcc
CFLAGS = -Wall
SOURCES = main.c verif.c placement.c affiche_niveau.c alloc_lib.c joueur_jeu_mouv.c nbr_ale.c banniere.c
HEADERS = structure_bibli.h
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)