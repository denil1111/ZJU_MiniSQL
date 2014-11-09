/* Companion source code for "flex & bison", published by O'Reilly
 * Media, ISBN 978-0-596-15597-1
 * Copyright (c) 2009, Taughannock Networks. All rights reserved.
 * See the README file for license conditions and contact info.
 * $Header: /home/johnl/flnb/code/sql/RCS/pmysql.l,v 2.1 2009/11/08 02:53:39 johnl Exp $
 */
/*
 * Scanner for mysql subset
 */

%option noyywrap nodefault yylineno case-insensitive
%{
#include "sqltree.hpp"
#include "sql.hpp"
#include <stdarg.h>
#include <string.h>
void yyerror(char *s, ...);
%}

%%

  /* keywords */

AND	{ return ANDOP; }
CREATE	{ return CREATE; }
DATABASE	{ return DATABASE; }
DATABASES	{ return DATABASES; }
DELETE	{ return DELETE; }
DROP	{ return DROP; }
FLOAT4?	{ return FLOAT; }
FROM	{ return FROM; }
INSERT	{ return INSERT; }   
INT	{ return INT; }
INTO	{ return INTO; }
INDEX|KEY	{ return KEY; }
NOT	{ return NOT; }
ON  { return ON; }
OR	{ return OR; }
PRIMARY	{ return PRIMARY; }
SELECT  { return SELECT; }
SHOW  { return SHOW; }
TABLE	{ return TABLE; }
UNIQUE	{ return UNIQUE; }
VALUES? { return VALUES; }
VARCHAR(ACTER)?	{ return VARCHAR; }
WHERE	{ return WHERE; }

   /* numbers */

-?[0-9]+	        { yylval.intval = atoi(yytext); return INTNUM; } 

-?[0-9]+"."[0-9]* |
-?"."[0-9]+	|
-?[0-9]+E[-+]?[0-9]+	|
-?[0-9]+"."[0-9]*E[-+]?[0-9]+ |
-?"."[0-9]*E[-+]?[0-9]+	{ yylval.floatval = atof(yytext) ;
                                  return APPROXNUM; }

   /* strings */

'(\\.|''|[^'\n])*'	|
\"(\\.|\"\"|[^"\n])*\"  { yylval.strval = strdup(yytext); return STRING; }

'(\\.|[^'\n])*$	        { yyerror("Unterminated string %s", yytext); }
\"(\\.|[^"\n])*$	{ yyerror("Unterminated string %s", yytext); }



   /* operators */
[-+&~|^/%*(),.;!]   { return yytext[0]; }

"&&"		{ return ANDOP; }
"||"            { return OR; }

"="	{ yylval.subtok = 4; return COMPARISON; }
"<=>"	{ yylval.subtok = 12; return COMPARISON; }
">="	{ yylval.subtok = 6; return COMPARISON; }
">"	{ yylval.subtok = 2; return COMPARISON; }
"<="	{ yylval.subtok = 5; return COMPARISON; }
"<"	{ yylval.subtok = 1; return COMPARISON; }
"!="	|
"<>"	{ yylval.subtok = 3; return COMPARISON; }

"<<"	{ yylval.subtok = 1; return SHIFT; }
">>"	{ yylval.subtok = 2; return SHIFT; }


[A-Za-z][A-Za-z0-9_]*	{ yylval.strval = strdup(yytext);
                          return NAME; }
`[^`/\\.\n]+`           { yylval.strval = strdup(yytext+1);
                          yylval.strval[yyleng-2] = 0;
                          return NAME; }

`[^`\n]*$               { yyerror("unterminated quoted name %s", yytext); }

	/* everything else */
[ \t\n]         /* white space */
.               { yyerror("mystery character '%c'", *yytext); }

%%

