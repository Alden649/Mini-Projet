#include "graphe.h"

Graphe::Graphe()
{
    this->sesSommets = new std::vector<Sommet*>();
}
Graphe::~Graphe()
{
    delete sesSommets;
}
void Graphe::affiche()
{
    for(auto *a: *sesSommets)
        std::cout << "Sommet :" << a->getNom()<< "\nCode: " << a->getCode() << "\nCouleur :" << a-> getCouleur() << "\n ======== \n";
}
void Graphe::colorer()
{

}
void Graphe::peuplerGraphe(std::string leFichier)
{
    PlateformeDOM *laPlateforme = new PlateformeDOM();
    QDomDocument leFichierDom = laPlateforme->faisArbre(leFichier);
    QDomElement leSvg = leFichierDom.documentElement();

    for(QDomNode leFils = leSvg.firstChild();!leFils.isNull();leFils = leFils.nextSibling())
    {
        //parcour du document SVG
        QDomNamedNodeMap lesAttributs = leFils.attributes();

        // création du sommet
        QDomNode leAttributRechercher = lesAttributs.namedItem(QString("id"));
        Sommet *unSommet = new Sommet(leAttributRechercher.nodeValue().toStdString());

        // récupération du code
        leAttributRechercher = lesAttributs.namedItem(QString("d"));
        std::string leCode = leAttributRechercher.nodeValue().toStdString();
        unSommet->setCode(leCode);

        //ajout du sommet dans le graphe
        this->sesSommets->push_back(unSommet);
    }
}
void Graphe::determinerSuccesseurs()
{
    for(auto *a : *sesSommets)
    {

    }
}
