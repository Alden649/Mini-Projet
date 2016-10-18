#include <QDomImplementation>
#include <QDomDocument>

class PlateformeDOM
{
                QDomImplementation sonImplementationDOM;
	public :		
                QDomDocument faisDocumentVideDTD
                        (const std::string & unNomRacine, const std::string & uneURL_dtd);

                QDomDocument faisDocumentVideSVG();
			
                QDomDocument faisArbre(const std::string & uneEntiteXML);
                void serialiseArbre(QDomDocument unArbreDOM, const std::string & uneEntiteXML);
};
