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
