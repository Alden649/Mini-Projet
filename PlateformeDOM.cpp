#include <cassert>
#include <iostream>
#include <QFile>
#include <QString>
#include <QXmlParseException>
#include <QDomElement>
#include <QDomDocumentType>
#include <QFile>
#include <QDomNode>
#include "PlateformeDOM.h"
		
QDomDocument PlateformeDOM::faisDocumentVideDTD
        (const std::string & unNomRacine, const std::string & uneURL_dtd)
{
        QDomDocumentType leNoeudDTD =
            sonImplementationDOM.createDocumentType(QString(unNomRacine.c_str()),0,
                                                    QString(uneURL_dtd.c_str()));
        QDomDocument leDocument =
            sonImplementationDOM.createDocument(0,QString(unNomRacine.c_str()),leNoeudDTD);
        return leDocument;
}

QDomDocument PlateformeDOM::faisDocumentVideSVG()
{
        std::string leURL_dtd("-//W3C//DTD SVG 1.1//EN\"\n\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd");
        QDomDocumentType leNoeudDTDSVG =
            sonImplementationDOM.createDocumentType(QString("svg"), QString(leURL_dtd.c_str()), 0);
        QDomDocument leDocumentSVG =
            sonImplementationDOM.createDocument(0,QString("svg"),leNoeudDTDSVG);

        QDomElement leElemSVG=leDocumentSVG.documentElement();
        leElemSVG.setAttribute(QString("xmlns"),QString("http://www.w3.org/2000/svg"));
        leElemSVG.setAttribute(QString("version"),QString("1.1"));
	
        return leDocumentSVG;
}

QDomDocument PlateformeDOM::faisArbre(const std::string & uneEntiteXML)
{
    QFile leDocumentXML(uneEntiteXML.c_str());
    QString leMsgErreur; int laLigneErreur; int laColonneErreur;
    // Ouverture du fichier en lecture seule et en mode texte
    leDocumentXML.open(QFile::ReadOnly | QFile::Text);
    QDomDocument leArbreDOM;
    if(!(leArbreDOM.setContent(&leDocumentXML,false,&leMsgErreur, &laLigneErreur, &laColonneErreur)))
    {
        std::cerr
                << "Erreur XML pendant l'analyse de l'entite : \"" << uneEntiteXML << "\"" << std::endl
                << "Message : " << leMsgErreur.toStdString() << std::endl
                << "Ligne : " << laLigneErreur << std::endl
                << "Colonne : " << laColonneErreur << std::endl
		;
    }
    return leArbreDOM;
}

void PlateformeDOM::serialiseArbre
(QDomDocument unDocXML, const std::string & unCheminFichier)
{
    QString unChemin(unCheminFichier.c_str());
    QFile leFichierSortie(unChemin);
    leFichierSortie.open(QIODevice::WriteOnly);
    QTextStream leFlotTexte(&leFichierSortie);
    unDocXML.save(leFlotTexte,3);
}
