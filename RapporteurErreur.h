#include <QXmlErrorHandler>
#include <QXmlParseException>
#include <QString>

class RapporteurErreur : public QXmlErrorHandler
{
	public:
    RapporteurErreur() : sesErreursVues(false) {}
    ~RapporteurErreur() {}

    // -----------------------------------------------------------------------
    //  Implementation de l'interface ErrorHandler
    // -----------------------------------------------------------------------
    bool warning(const QXmlParseException & );
    bool error(const QXmlParseException & );
    bool fatalError(const QXmlParseException & );
    QString errorString () const;
    void resetErrors();

    // -----------------------------------------------------------------------
    bool lesErreursVues() const;

	private :
    bool    sesErreursVues;
};

inline bool RapporteurErreur::lesErreursVues() const
{return sesErreursVues;}
