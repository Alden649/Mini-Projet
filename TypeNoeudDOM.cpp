#include <cassert>
#include "TypeNoeudDOM.h"
#include <QDomNode>

TypeNoeudDOM::TypeNoeudDOM(const short t)
: sonType(t)
{}

short TypeNoeudDOM::getType() const
{
    return sonType;
}

std::ostream & operator << (std::ostream & s, const TypeNoeudDOM unType)
{
    switch (unType.getType())
	{
        case QDomNode::ElementNode :
			s << "ELEMENT_NODE"; break;
        case QDomNode::AttributeNode :
			s << "ATTRIBUTE_NODE"; break;
        case QDomNode::TextNode :
			s << "TEXT_NODE"; break;
        case QDomNode::CDATASectionNode :
			s << "CDATA_SECTION_NODE"; break;
        case QDomNode::EntityReferenceNode :
			s << "ENTITY_REFERENCE_NODE"; break;
        case QDomNode::EntityNode :
			s << "ENTITY_NODE"; break;
        case QDomNode::ProcessingInstructionNode :
			s << "PROCESSING_INSTRUCTION_NODE"; break;
        case QDomNode::CommentNode :
			s << "COMMENT_NODE"; break;
        case QDomNode::DocumentNode :
			s << "DOCUMENT_NODE"; break;
        case QDomNode::DocumentTypeNode :
			s << "DOCUMENT_TYPE_NODE"; break;
        case QDomNode::DocumentFragmentNode :
            s << "DOCUMENT_FRAGMENT_NODE"; break;
        case QDomNode::NotationNode :
			s << "NOTATION_NODE"; break;
        case QDomNode::BaseNode :
            s << "BASE_NODE"; break;
        case QDomNode::CharacterDataNode :
            s << "CHARACTER_DATA__NODE"; break;
		default : assert(false);
	}
	return s;
}
