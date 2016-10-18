#include <iostream>

class TypeNoeudDOM
{
		short sonType;
	public :
        TypeNoeudDOM(const short t);
        short getType() const;
};

std::ostream & operator << (std::ostream & s, const TypeNoeudDOM);
