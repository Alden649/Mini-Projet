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
        std::cout << a->getNom();
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
        std::cout << leFils.nodeName().toStdString() << ' ';
        QDomNamedNodeMap lesAttributs = leFils.attributes();
        QDomNode leAttributRechercher = lesAttributs.namedItem(QString("id"));

        // création du sommet
        Sommet *unSommet = new Sommet(leAttributRechercher.nodeName().toStdString());
        leAttributRechercher = lesAttributs.namedItem(QString("d"));

        // récupération du code
        std::string leCode = leAttributRechercher.nodeValue().toStdString();
        unSommet->setCode(leCode);
        this->sesSommets->push_back(unSommet);
    }
}
