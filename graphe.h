#ifndef GRAPHE_H
#define GRAPHE_H

#include <vector>
#include <iostream>
#include <algorithm>
#include "Sommet.h"
#include "PlateformeDOM.h"
#include "RapporteurErreur.h"
#include "TypeNoeudDOM.h"

class Graphe
{
private:
    std::vector<Sommet*> *sesSommets;
    PlateformeDOM *laPlateforme;
public:
    Graphe();
    ~Graphe();
    void affiche();
    void colorer();
    void constructionFichier();
    void determinerSuccesseurs();
    void peuplerGraphe(std::string leFichier);
    void trieParDegree();
    bool verifierPoints(std::vector<std::string> *lesPointsA, std::vector<std::string> *lesPointsB);

};

#endif // GRAPHE_H
