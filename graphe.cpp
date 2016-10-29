#include "graphe.h"

Graphe::Graphe()
{
    this->sesSommets = new std::vector<Sommet*>();
    this->laPlateforme = new PlateformeDOM();
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
    //création liste des couleurs du graphe.
    std::vector<std::string> *laListeCouleurs = new std::vector<std::string>();
    *laListeCouleurs = {"#33FFFF","#00FF66","#669999","#FF99FF","#9999CC","#000099"};

    //1 : Trie par ordre décroissant de degree
    this->trieParDegree();

    //2 : attribution d'une couleur au premier sommet
    Sommet *lePremierSommet = this->sesSommets->at(0);

    lePremierSommet->setCouleur(laListeCouleurs->at(0));
    this->sesSommets->at(0) = lePremierSommet;
}

void Graphe::constructionFichier()
{
    QDomDocument leDocSVG = this->laPlateforme->faisDocumentVideSVG();
    QDomElement elemSvg = leDocSVG.documentElement();

    for(Sommet *leSommet : *sesSommets)
    {
        QDomElement lePathTemp = leDocSVG.createElement(QString("path"));
        lePathTemp.setAttribute(QString("id"),QString::fromStdString(leSommet->getNom()));
        lePathTemp.setAttribute(QString("d"),QString::fromStdString(leSommet->getCode()));
        lePathTemp.setAttribute(QString("stroke"),"black");
        lePathTemp.setAttribute(QString("fill"),QString::fromStdString(leSommet->getCouleur()));
        elemSvg.appendChild(lePathTemp);
    }
    this->laPlateforme->serialiseArbre(leDocSVG,"France_Colo.svg");
}

void Graphe::determinerSuccesseurs()
{
    //parcour de la liste des sommets
    for (unsigned int leI = 0; leI < this->sesSommets->size(); leI++)
    {
        Sommet *leSommetI = this->sesSommets->at(leI);

        //parcour de la liste des sommets suivants
        for (unsigned int leJ = leI; leJ < this->sesSommets->size(); leJ++)
        {
            Sommet *leSommetJ = this->sesSommets->at(leJ);

            if(this->verifierPoints(leSommetI->getPoints(),leSommetJ->getPoints()) && leSommetI != leSommetJ)
            {
                //pour éviter les doublons
                std::list<Sommet*> *lesSuccesseurs = leSommetI->getSuccesseurs();

                if(std::find(lesSuccesseurs->begin(), lesSuccesseurs->end(), leSommetJ) == lesSuccesseurs->end())
                {
                    //Ajout des successeurs dans les sommets
                    leSommetI->ajouterSuccesseur(leSommetJ);
                    leSommetJ->ajouterSuccesseur(leSommetI);

                    //remplacement dans le vector
                    this->sesSommets->at(leI) = leSommetI;
                    this->sesSommets->at(leJ) = leSommetJ;
                }
            }
        }
    }
}

void Graphe::peuplerGraphe(std::string leFichier)
{
    QDomDocument leFichierDom = this->laPlateforme->faisArbre(leFichier);
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

void Graphe::trieParDegree()
{
    for(unsigned int leI = 0; leI < this->sesSommets->size()-1; leI++)
    {
        int leMaximum = leI;
        for (unsigned int leJ = leI+1; leJ < this->sesSommets->size(); leJ ++)
            if(this->sesSommets->at(leJ)->getNbSuccesseur() > this->sesSommets->at(leMaximum)->getNbSuccesseur())
                leMaximum = leJ;

        if(leMaximum != leI)
        {
            Sommet *leSommetTemp = this->sesSommets->at(leI);
            this->sesSommets->at(leI) = this->sesSommets->at(leMaximum);
            this->sesSommets->at(leMaximum) = leSommetTemp;
        }
    }
}

bool Graphe::verifierPoints(std::vector<std::string> *lesPointsA, std::vector<std::string> *lesPointsB)
{
    for(unsigned int leI = 0; leI < lesPointsA->size(); leI ++)
    {
        std::string lePointA = lesPointsA->at(leI);

        for(unsigned int leJ = 0; leJ < lesPointsB->size(); leJ++)
        {
            std::string lePointB = lesPointsB->at(leJ);

            if(lePointA == lePointB)
                return 1;
        }
    }
    return 0;
}
