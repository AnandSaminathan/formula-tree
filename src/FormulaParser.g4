parser grammar FormulaParser;

options {
  tokenVocab = FormulaLexer;
}

ltl                : atomicProposition # ltlBase
                      | OPEN_PARAN ltl CLOSE_PARAN # ltlParanthesis
                      | GLOBAL ltl # ltlUnary
                      | FUTURE ltl # ltlUnary
                      | NEXT ltl # ltlUnary
                      | NOT ltl # ltlUnary
                      | <assoc=right>ltl UNTIL ltl # ltlBinary 
                      | ltl RELEASE ltl # ltlBinary
                      | ltl AND ltl # ltlBinary
                      | ltl OR ltl # ltlBinary
                      | ltl IMPLIES ltl # ltlBinary
                      | ltl EQUIVALENT ltl # ltlBinary
                      ;

atomicProposition  : (relationalExpr);

relationalExpr     : logicalValue # relationalValue
                      | id # relationalId
                      | arithmeticExpr (LT | GT | LTE | GTE) arithmeticExpr # relationalBinary
                      | arithmeticExpr (EQ | NEQ) arithmeticExpr # relationalBinarys
                      ;

arithmeticExpr     : arithValue # arithmeticValue
                      | id # arithmeticId
                      | OPEN_PARAN arithmeticExpr CLOSE_PARAN # arithmeticParanthesis
                      | arithmeticExpr MOD arithmeticExpr # arithmeticBinary
                      | arithmeticExpr DIV arithmeticExpr # arithmeticBinary
                      | arithmeticExpr MUL arithmeticExpr # arithmeticBinary
                      | arithmeticExpr (PLUS | MINUS) arithmeticExpr # arithmeticBinary
                      ;

arithValue         : (integer | decimal);
logicalValue       : (TRUE | FALSE);
id                 : (alpha) alphaNum*;
decimal            : integer DOT wholeNumber;
integer            : (PLUS | MINUS)? wholeNumber;
wholeNumber        : (DIGIT | DIGIT+);
alpha              : (LOWER_CASE | UPPER_CASE);
alphaNum           : (alpha | DIGIT);
newline            : NL;

