#include "sommet.h"

Sommet::Sommet(std::string sonNom)
{
    this->sesSuccesseurs = new std::list<Sommet*>();
    this->sonNom = sonNom;
    this->saCouleur = "#FFFFFF";
}
Sommet::~Sommet()
{
    delete sesSuccesseurs;
}
void Sommet::ajouterSommet(Sommet *sommet)
{

}
void Sommet::getNbSuccesseur()
{

}
void Sommet::setCouleur(std::string laCouleur)
{

}
void Sommet::setCode(std::string leCode)
{
    this->sonCode = leCode;
}
