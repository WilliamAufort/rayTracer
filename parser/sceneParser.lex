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

bool verbose = false; /* for stupid parser debug */
%}

whitespace  [ \t]+
float       -?([0-9]+|[0-9]*\.[0-9]+)
%x comment

%%

{whitespace}            {/* We ignore */}

"#"                     BEGIN(comment);     //
<comment>[^\n]          break;              //
<comment>\n             {                   // Comments handling
                            BEGIN(INITIAL); //
                            line_number++;  //
                        }                   //

\n+                     { if (verbose) {cout<<"EOL ";} line_number++; return(token::EOL); }
"("                     { if (verbose) {cout<<"LPAR ";} return(token::LPAR); }
")"                     { if (verbose) {cout<<"RPAR ";} return(token::RPAR); }
","                     { if (verbose) {cout<<"SEP ";} return(token::SEP); }

"Lookat"                { if (verbose) {cout<<"LOOKAT ";} return(token::LOOK_AT); }
"CameraFov"             { if (verbose) {cout<<"CAMERA_FOV ";} return(token::CAMERA_FOV); }
"OutputImage"           { if (verbose) {cout<<"OUTPUT_SIZE ";} return(token::OUTPUT_SIZE); }
"LightSource"           { if (verbose) {cout<<"LIGHT_SOURCE ";} return(token::LIGHT_SOURCE); }

"BeginSphere"           { if (verbose) {cout<<"BEGIN_SPHERE ";} return(token::BEGIN_SPHERE); }
"EndSphere"             { if (verbose) {cout<<"END_SPHERE ";} return(token::END_SPHERE); }
"Center"                { if (verbose) {cout<<"CENTER ";} return(token::CENTER); }
"Radius"                { if (verbose) {cout<<"RADIUS ";} return(token::RADIUS); }
"Color"                 { if (verbose) {cout<<"COLOR ";} return(token::COLOR); }

"BeginMaterial"         { if (verbose) {cout<<"BEGIN_MATERIAL ";} return(token::BEGIN_MATERIAL); }
"EndMaterial"           { if (verbose) {cout<<"END_MATERIAL ";} return(token::END_MATERIAL); }
"Specular"              { if (verbose) {cout<<"SPECULAR ";} return(token::SPECULAR); }
"Transparent"           { if (verbose) {cout<<"TRANSPARENT ";} return(token::TRANSPARENT); }
"Diffuse"               { if (verbose) {cout<<"DIFFUSE ";} return(token::DIFFUSE); }
"Emissive"              { if (verbose) {cout<<"EMISSIVE ";} return(token::EMISSIVE); }


{float}  {
  yylval->dbl = atof(yytext);
  if (verbose) {cout<<"FLOAT ";}
  return(token::FLOAT);
}


. { std::cerr << "line " << line_number << ": error: illegal character" << std::endl; exit(1); }
