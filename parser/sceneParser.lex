%option yylineno
%option c++
%option prefix="sceneParser"

%{

namespace  sceneParser {
    class Driver;
}

#include <iostream>
#include "sceneParser.hpp"
#include "lexer.h"

typedef sceneParser::Parser::token token;
typedef sceneParser::Parser::token_type token_type;
#define yyterminate() return token::TEOF

extern int line_number;	/* defined in parser.ypp */

using namespace std;

#ifndef DEBUG
    bool verbose = true;
#endif
#ifdef DEBUG
    bool verbose = true;
#endif

%}

whitespace  [ \t]+
float       -?([0-9]+|[0-9]*\.[0-9]+)
%x comment

%%

{whitespace}			{/* We ignore */}

"#"						BEGIN(comment);		//
<comment>[^\n]			break;				//
<comment>\n				{					// Comments handling
							BEGIN(INITIAL);	//
							line_number++;	//
						}					//

\n+						{ cout<<"EOL "; line_number++; return(token::EOL); }
"("						{ cout<<"LPAR "; return(token::LPAR); }
")"						{ cout<<"RPAR "; return(token::RPAR); }
","						{ cout<<"SEP "; return(token::SEP); }

"Lookat"				{ cout<<"LOOKAT "; return(token::LOOK_AT); }
"CameraFov"				{ cout<<"CAMERA_FOV "; return(token::CAMERA_FOV); }
"OutputImage"			{ cout<<"OUTPUT_SIZE "; return(token::OUTPUT_SIZE); }
"LightSource"			{ cout<<"LIGHT_SOURCE "; return(token::LIGHT_SOURCE); }

"BeginSphere"			{ cout<<"BEGIN_SPHERE "; return(token::BEGIN_SPHERE); }
"EndSphere"				{ cout<<"END_SPHERE "; return(token::END_SPHERE); }
"Center"				{ cout<<"CENTER "; return(token::CENTER); }
"Radius"				{ cout<<"RADIUS "; return(token::RADIUS); }
"Color"					{ cout<<"COLOR "; return(token::COLOR); }

"BeginMaterial"			{ cout<<"BEGIN_MATERIAL "; return(token::BEGIN_MATERIAL); }
"EndMaterial"			{ cout<<"END_MATERIAL "; return(token::END_MATERIAL); }
"Specular"				{ cout<<"SPECULAR "; return(token::SPECULAR); }
"Transparent"			{ cout<<"TRANSPARENT "; return(token::TRANSPARENT); }
"Diffuse"				{ cout<<"DIFFUSE "; return(token::DIFFUSE); }
"Emissive"				{ cout<<"EMISSIVE "; return(token::EMISSIVE); }


{float}  {
  yylval->dbl = atof(yytext);
  cout<<"FLOAT ";
  return(token::FLOAT);
}


. { std::cerr << "line " << line_number << ": error: illegal character" << std::endl; exit(1); }
