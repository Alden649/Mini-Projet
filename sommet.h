#ifndef SOMMET_H
#define SOMMET_H
#include <iostream>
#include <list>

class Sommet
{
    std::list<Sommet*> *sesSuccesseurs;
public:
    std::string sonNom;
    std::string saCouleur;
    std::string sonCode;

    Sommet(std::string sonNom);
    ~Sommet();
    void ajouterSommet(Sommet *sommet);
    void getNbSuccesseur();
    void setCouleur(std::string couleur);
    void setCode(std::string code);
};

#endif // SOMMET_H
