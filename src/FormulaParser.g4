parser grammar FormulaParser;

options {
  tokenVocab = FormulaLexer;
}

ltlForm           : atomicProposition # ltlBase
                  | OPEN_PARAN formula=ltlForm CLOSE_PARAN # ltlParanthesis
                  | op=GLOBAL formula=ltlForm # ltlUnary
                  | op=FUTURE formula=ltlForm # ltlUnary
                  | op=NEXT formula=ltlForm # ltlUnary
                  | op=NOT formula=ltlForm # ltlUnary
                  | <assoc=right>ltlForm op=UNTIL ltlForm # ltlBinary 
                  | left=ltlForm op=RELEASE right=ltlForm # ltlBinary
                  | left=ltlForm op=AND right=ltlForm # ltlBinary
                  | left=ltlForm op=OR right=ltlForm # ltlBinary
                  | left=ltlForm op=IMPLIES right=ltlForm # ltlBinary
                  | left=ltlForm op=EQUIVALENT right=ltlForm # ltlBinary
                  ;

atomicProposition : relationalForm
                  ;

relationalForm    : value=logicalValue # relationalValue
                  | formula=arithmeticForm # arithmeticFormula
                  | name=id # relationalId
                  | OPEN_PARAN formula=relationalForm CLOSE_PARAN # relationalParanthesis
                  | left=relationalForm op=(LT | GT | LTE | GTE) right=relationalForm # relationalBinary
                  | left=relationalForm op=(EQ | NEQ) right=relationalForm # relationalBinary
                  ;

arithmeticForm    : value=arithValue # arithmeticValue
                  | name=id # arithmeticId
                  | OPEN_PARAN formula=arithmeticForm CLOSE_PARAN # arithmeticParanthesis
                  | left=arithmeticForm op=MOD right=arithmeticForm # arithmeticBinary
                  | left=arithmeticForm op=DIV right=arithmeticForm # arithmeticBinary
                  | left=arithmeticForm op=MUL right=arithmeticForm # arithmeticBinary
                  | left=arithmeticForm op=(PLUS | MINUS) right=arithmeticForm # arithmeticBinary
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

