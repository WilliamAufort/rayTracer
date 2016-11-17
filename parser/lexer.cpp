#include "lexer.h"

namespace sceneParser {
	Lexer::Lexer(std::istream* in, std::ostream* out) : sceneParserFlexLexer_(in, out) {}

	Lexer::~Lexer() {}

	void Lexer::set_debug(bool b)
	{
    	yy_flex_debug = b;
}	}

#ifdef yylex
#undef yylex
#endif

int sceneParserFlexLexer_::yylex()
{
    std::cerr << "Unexpected call to calcparserFlexLexer::yylex()!" << std::endl;
    return 0;
}

int sceneParserFlexLexer_::yywrap()
{
    return 1;
}
