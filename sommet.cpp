#include "sommet.h"

Sommet::Sommet(std::string sonNom)
{
    this->sesSuccesseurs = new std::list<Sommet*>();
    this->sonNom = sonNom;
    this->saCouleur = "#FFFFFF";
    this->sonCode = "";
}
Sommet::~Sommet()
{
    delete sesSuccesseurs;
}
void Sommet::ajouterSuccesseur(Sommet *leSuccesseur)
{
    this->sesSuccesseurs->push_back(leSuccesseur);
}
void Sommet::setCouleur(std::string laCouleur)
{
    this->saCouleur = laCouleur;
}
void Sommet::setCode(std::string leCode)
{
    this->sonCode = leCode;
}
int Sommet::getNbSuccesseur()
{
    return this->sesSuccesseurs->size();
}
bool Sommet::estSuccesseur(Sommet *unSommet)
{
    for(Sommet *unSuccesseur : *sesSuccesseurs)
        if (unSuccesseur = unSommet)
            return 1;

    return 0;
}
std::string Sommet::getNom()
{
    return this->sonNom;
}
std::string Sommet::getCode()
{
    return this->sonCode;
}
std::string Sommet::getCouleur()
{
    return this->saCouleur;
}
std::list<Sommet*> *Sommet::getSuccesseurs()
{
    return this->sesSuccesseurs;
}
std::vector<std::string> *Sommet::getPoints()
{
    std::vector<std::string> *vecPoints = new std::vector<std::string>();
    std::string cpCode = this->sonCode;
    std::size_t pos;

    while ((pos = cpCode.find(" ")) != std::string::npos)
    {
        vecPoints->push_back(cpCode.substr(0, pos));    //stockage du points dans le vector.
        cpCode = cpCode.substr(pos+1);                  //on se positione après l'espace découvert pour recommencer.
    }

    vecPoints->pop_back();                              //on supprime le 'z'.

    return vecPoints;
}

