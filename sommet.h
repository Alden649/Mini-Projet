#ifndef SOMMET_H
#define SOMMET_H
#include <iostream>
#include <list>
#include <Vector>
#include <algorithm>

class Sommet
{
    std::list<Sommet*> *sesSuccesseurs;
public:
    std::string sonNom;
    std::string saCouleur;
    std::string sonCode;

    Sommet(std::string sonNom);
    ~Sommet();
    void ajouterSuccesseur(Sommet *sommet);
    void setCouleur(std::string couleur);
    void setCode(std::string code);
    int getNbSuccesseur();
    bool estSuccesseur(Sommet *unSommet);
    std::string getNom();
    std::string getCode();
    std::string getCouleur();
    std::vector<std::string> *getPoints();
    std::list<Sommet*> *getSuccesseurs();
};

#endif // SOMMET_H
