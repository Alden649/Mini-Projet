#include <iostream>
#include "graphe.h"

int main()
{
    std::string leFichier("France.svg");
    Graphe * leGraphe = new Graphe();
    leGraphe->peuplerGraphe(leFichier);
}
