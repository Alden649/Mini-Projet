#include <iostream>
#include "graphe.h"

int main()
{
    std::string leFichier("France.svg");
    Graphe * leGraphe = new Graphe();
    leGraphe->peuplerGraphe(leFichier);
    leGraphe->determinerSuccesseurs();
    std::cout << "\n\n";

    Sommet *leS = new Sommet("A");
    leS->setCode("M443.4375,182.03125 L441.625,182.96875 L440.09375,184.09375 L440.09375,186.59375 L440.9375,189.5625 L440.9375,191.5 L440.46875,194.625 L439.40625,195.71875 L451.4375,201.15625 L452.1875,200.28125 L454.78125,199.875 L453.8125,195.71875 L453.21875,193.5625 L450.46875,193.96875 L450.09375,191.625 L451.0625,189.84375 L451.25,187.5 L450.6875,186.15625 L447.15625,183.40625 L444.03125,183.21875 L443.4375,182.03125 L443.4375,182.03125 L443.4375,182.03125 L443.4375,182.03125 Z M443.4375,182.03125");
    std::set<std::string> *leV = leS->getPoints();

    for(auto a: * leV)
        std::cout << a << '\n';
}
