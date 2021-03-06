lexer grammar FormulaLexer;

TRUE        : 'true';
FALSE       : 'false';
PLUS        : '+';
MINUS       : '-';
DIV         : '/';
MUL         : '*';
MOD         : '%';
NOT         : '!';
AND         : '&&';
OR          : '||';
IMPLIES     : '->';
EQUIVALENT  : '<->';
EQ          : '==';
NEQ         : '!=';
GT          : '>';
LT          : '<';
GTE         : '>=';
LTE         : '<=';
NEXT        : 'X';
UNTIL       : 'U';
RELEASE     : 'R';
GLOBAL      : 'G';
FUTURE      : 'F';
LOWER_CASE  : 'a'..'z';
UPPER_CASE  : 'A'..'Z';
DIGIT       : '0'..'9';
WS          : [ \r\n\t]+ -> skip;
NL          : ('\n')+;
UNDERSCORE  : '_';
DOT         : '.';
COMMA       : ',';
COLON       : ':';
SC          : ';';
OPEN_CURLY  : '{';
CLOSE_CURLY : '}';
OPEN_PARAN  : '(';
CLOSE_PARAN : ')';
