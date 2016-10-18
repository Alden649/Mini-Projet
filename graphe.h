#ifndef GRAPHE_H
#define GRAPHE_H

#include <vector>
#include <iostream>
#include "Sommet.h"
#include "PlateformeDOM.h"
#include "RapporteurErreur.h"
#include "TypeNoeudDOM.h"

class Graphe
{
private:
    std::vector<Sommet*> *sesSommets;
public:
    Graphe();
    ~Graphe();
    void affiche();
    void colorer();
    void peuplerGraphe(std::string leFichier);
};

#endif // GRAPHE_H
