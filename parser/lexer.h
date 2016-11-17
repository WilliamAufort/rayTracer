#ifndef DEF_LEXER
#define DEF_LEXER

#ifndef YY_DECL
#define YY_DECL sceneParser::Parser::token_type \
    sceneParser::Lexer::yylex(sceneParser::Parser::semantic_type* yylval, sceneParser::Parser::location_type* yylloc)
#endif

#undef yyFlexLexer
#define yyFlexLexer sceneParserFlexLexer_

#include <FlexLexer.h>

namespace sceneParser {
	class Driver;
}

#include "sceneParser.hpp"

namespace sceneParser {
	class Lexer : public sceneParserFlexLexer_
	{
		public:
		Lexer(std::istream* arg_yyin = 0, std::ostream* arg_yyout = 0);
		virtual ~Lexer();
		virtual Parser::token_type yylex(Parser::semantic_type *yylval, sceneParser::Parser::location_type* yylloc);
		void set_debug(bool b);
};	}

#endif
