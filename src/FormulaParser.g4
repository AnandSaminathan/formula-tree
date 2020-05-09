parser grammar FormulaParser;

options {
  tokenVocab = FormulaLexer;
}

form              : propForm
                  | pseudoBoolForm
                  | ltlForm
                  ;

propForm          : relationalForm                              #propBase
                  | OPEN_PARAN formula=propForm CLOSE_PARAN     #propParenthesis
                  | op=NOT formula=propForm                     #propUnary
                  | left=propForm op=AND right=propForm         #propBinary
                  | left=propForm op=OR right=propForm          #propBinary
                  | left=propForm op=IMPLIES right=propForm     #propBinary
                  | left=propForm op=EQ right=propForm          #propBinary
                  ;

pseudoBoolForm    : relationalForm                                                 #pseudoBoolBase 
                  | OPEN_PARAN formula=pseudoBoolForm CLOSE_PARAN                  #pseudoBoolParenthesis
                  | op=NOT formula=pseudoBoolForm                                  #pseudoBoolLogicalUnary
                  | left=pseudoBoolForm op=AND right=pseudoBoolForm                #pseudoBoolLogicalBinary
                  | left=pseudoBoolForm op=OR right=pseudoBoolForm                 #pseudoBoolLogicalBinary
                  | left=pseudoBoolForm op=IMPLIES right=pseudoBoolForm            #pseudoBoolLogicalBinary
                  | left=wholeNumber op=MUL right=pseudoBoolForm                   #pseudoBoolCoeff
                  | left=pseudoBoolForm op=(PLUS | MINUS) right=pseudoBoolForm     #pseudoBoolArithBinary
                  | left=pseudoBoolForm op=(LT | GT | LTE | GTE) right=wholeNumber #pseudoBoolIneqBinary
                  | left=pseudoBoolForm op=(EQ | NEQ) right=pseudoBoolForm         #pseudoBoolLogicalBinary
                  ;

ltlForm           : relationalForm                                    #ltlBase
                  | OPEN_PARAN formula=ltlForm CLOSE_PARAN            #ltlParenthesis
                  | op=GLOBAL formula=ltlForm                         #ltlUnary
                  | op=FUTURE formula=ltlForm                         #ltlUnary
                  | op=NEXT formula=ltlForm                           #ltlUnary
                  | op=NOT formula=ltlForm                            #ltlUnary
                  | <assoc=right>left=ltlForm op=UNTIL right=ltlForm  #ltlBinary 
                  | left=ltlForm op=RELEASE right=ltlForm             #ltlBinary
                  | left=ltlForm op=AND right=ltlForm                 #ltlBinary
                  | left=ltlForm op=OR right=ltlForm                  #ltlBinary
                  | left=ltlForm op=IMPLIES right=ltlForm             #ltlBinary
                  | left=ltlForm op=EQ right=ltlForm                  #ltlBinary
                  ;

relationalForm    : content=logicalValue                                              #relationalValue
                  | arithmeticForm                                                    #arithmeticFormula
                  | content=id                                                        #relationalId
                  | OPEN_PARAN formula=relationalForm CLOSE_PARAN                     #relationalParenthesis
                  | left=relationalForm op=(LT | GT | LTE | GTE) right=relationalForm #relationalBinary
                  | left=relationalForm op=(EQ | NEQ) right=relationalForm            #relationalBinary
                  ;

arithmeticForm    : content=arithValue                                          #arithmeticValue
                  | content=id                                                  #arithmeticId
                  | OPEN_PARAN formula=arithmeticForm CLOSE_PARAN               #arithmeticParenthesis
                  | left=arithmeticForm op=MOD right=arithmeticForm             #arithmeticBinary
                  | left=arithmeticForm op=DIV right=arithmeticForm             #arithmeticBinary
                  | left=arithmeticForm op=MUL right=arithmeticForm             #arithmeticBinary
                  | left=arithmeticForm op=(PLUS | MINUS) right=arithmeticForm  #arithmeticBinary
                  ;


logicalValue       : (TRUE | FALSE);
arithValue         : (integer | decimal);
id                 : (LOWER_CASE | UPPER_CASE | UNDERSCORE | DOT) (LOWER_CASE | UPPER_CASE | DIGIT | UNDERSCORE | DOT)*;
decimal            : integer DOT wholeNumber;
integer            : (PLUS | MINUS)? wholeNumber;
wholeNumber        : (DIGIT | DIGIT+);

