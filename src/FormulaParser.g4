parser grammar FormulaParser;

options {
  tokenVocab = FormulaLexer;
}

form              : ltlForm
                  ;

ltlForm           : relationalForm                                    #ltlBase
                  | OPEN_PARAN formula=ltlForm CLOSE_PARAN            #ltlParentheses
                  | op=GLOBAL formula=ltlForm                         #ltlUnary
                  | op=FUTURE formula=ltlForm                         #ltlUnary
                  | op=NEXT formula=ltlForm                           #ltlUnary
                  | op=NOT formula=ltlForm                            #ltlUnary
                  | <assoc=right>left=ltlForm op=UNTIL right=ltlForm  #ltlBinary 
                  | left=ltlForm op=RELEASE right=ltlForm             #ltlBinary
                  | left=ltlForm op=AND right=ltlForm                 #ltlBinary
                  | left=ltlForm op=OR right=ltlForm                  #ltlBinary
                  | left=ltlForm op=IMPLIES right=ltlForm             #ltlBinary
                  | left=ltlForm op=EQUIVALENT right=ltlForm          #ltlBinary
                  ;

relationalForm    : content=logicalValue                                              #relationalValue
                  | arithmeticForm                                                    #arithmeticFormula
                  | content=id                                                        #relationalId
                  | OPEN_PARAN formula=relationalForm CLOSE_PARAN                     #relationalParentheses
                  | left=relationalForm op=(LT | GT | LTE | GTE) right=relationalForm #relationalBinary
                  | left=relationalForm op=(EQ | NEQ) right=relationalForm            #relationalBinary
                  ;

arithmeticForm    : content=arithValue                                          #arithmeticValue
                  | content=id                                                  #arithmeticId
                  | OPEN_PARAN formula=arithmeticForm CLOSE_PARAN               #arithmeticParentheses
                  | left=arithmeticForm op=MOD right=arithmeticForm             #arithmeticBinary
                  | left=arithmeticForm op=DIV right=arithmeticForm             #arithmeticBinary
                  | left=arithmeticForm op=MUL right=arithmeticForm             #arithmeticBinary
                  | left=arithmeticForm op=(PLUS | MINUS) right=arithmeticForm  #arithmeticBinary
                  ;


logicalValue       : (TRUE | FALSE);
arithValue         : (integer | decimal);
id                 : (LOWER_CASE | UPPER_CASE | UNDERSCORE) (LOWER_CASE | UPPER_CASE | DIGIT | UNDERSCORE)*;
decimal            : integer DOT wholeNumber;
integer            : (PLUS | MINUS)? wholeNumber;
wholeNumber        : (DIGIT | DIGIT+);

