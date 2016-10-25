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
void Sommet::ajouterSommet(Sommet *leSuccesseur)
{
    this->sesSuccesseurs->push_back(leSuccesseur);
}
void Sommet::getNbSuccesseur()
{

}
void Sommet::setCouleur(std::string laCouleur)
{
    this->saCouleur = laCouleur;
}
void Sommet::setCode(std::string leCode)
{
    this->sonCode = leCode;
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
std::set<std::string> *Sommet::getPoints()
{
    std::set<std::string> *setPoints = new std::set<std::string>();
    std::string cpCode = this->sonCode;
    std::size_t pos;

    while ((pos = cpCode.find(" ")) != std::string::npos)
    {
       setPoints->insert(cpCode.substr(0, pos));    //stockage du points dans le vector.
       cpCode = cpCode.substr(pos+1);               //on se positione après l'espace découvert pour recommencer.
    }

    setPoints->erase(std::prev(setPoints->end()));  //on supprime le 'z'.

    return setPoints;
}
