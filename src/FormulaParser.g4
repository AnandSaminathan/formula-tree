parser grammar FormulaParser;

options {
  tokenVocab = FormulaLexer;
}

ltl                : (atomicProposition ltlT
                      | GLOBAL ltl ltlT
                      | FUTURE ltl ltlT
                      | NEXT ltl ltlT
                      | NOT ltl ltlT
                      | OPEN_PARAN ltl CLOSE_PARAN ltlT);

ltlT               : (<assoc=right>UNTIL ltl
                      | RELEASE ltl
                      | AND ltl
                      | OR ltl
                      | IMPLIES ltl
                      | EQUIVALENT ltl)?;

atomicProposition  : (relationalExpr);

relationalExpr     : (logicalValue | id 
                      | (arithmeticExpr (LT | GT | LTE | GTE) arithmeticExpr)
                      | (arithmeticExpr (EQ | NEQ) arithmeticExpr));

arithmeticExpr     : (arithValue arithmeticExprT | id arithmeticExprT
                      | OPEN_PARAN arithmeticExpr CLOSE_PARAN arithmeticExprT);

arithmeticExprT    : (MOD arithmeticExpr
                      | DIV arithmeticExpr
                      | MUL arithmeticExpr
                      | PLUS arithmeticExpr
                      | MINUS arithmeticExpr)?;


arithValue         : (integer | decimal);
logicalValue       : (TRUE | FALSE);
id                 : (alpha) alphaNum*;
decimal            : integer DOT wholeNumber;
integer            : (PLUS | MINUS)? wholeNumber;
wholeNumber        : (DIGIT | DIGIT+);
alpha              : (LOWER_CASE | UPPER_CASE);
alphaNum           : (alpha | DIGIT);
newline            : NL;

