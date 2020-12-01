grammar Minic;

prog: ( declaration | assignment | func_decl )+ EOF
    ;

func_decl: TYPE ID '(' ( decl_arg',' )* (decl_arg)? ')' statement             
    ;

func_call: ID '(' ( arg',' )* (arg)?   ')'              
    ;

decl_arg: TYPE ID                                       #decl_argSimple
    | TYPE ID'[]'                                       #decl_argArray1D
    | TYPE ID'[]['INT']'                                #decl_argArray2D
    ;

arg: STRING                                             #argString
    | expr                                              #argExpr
    ;


statement: '{' statement+ '}'                           #compoundStatement
    | assignment                                        #statementAssignment
    | declaration                                       #statementDeclaration
    // | func_call ';'                                     #statementFuncCall
    | 'IF' '(' expr ')' statement                       #statementIf
    | 'IF' '(' expr ')' statement 'ELSE' statement      #statementIfElse
    | 'FOR' '(' declaration expr ';'assignment ')' statement   #statementFor
    | 'WHILE' '(' expr ')' statement                   #statementWhile
    | 'RET' expr';'                                     #statementRet
    ;

assignment: ID '=' expr ';'                             #assignmentSimple
    | ID '['expr']' '=' expr ';'                        #assignmentArrayElement1d
    | ID '['expr']['expr']' '=' expr ';'                #assignmentArrayElement2d
    ;


declaration: TYPE ID '=' expr ';'                       #declarationSimple
    | TYPE ID '['INT']'';'                                #declarationArray1D
    | TYPE ID '['INT']['INT']'';'                         #declarationArray2D
    ;

expr: '!' expr                                          #exprNot
    | expr op=('*'|'/'|'%') expr                        #exprMulDivMod                    
    | expr op=('+'|'-') expr                            #exprAddSub                
    | expr op=('>'|'>='|'<'|'<=') expr                  #exprGreaterLesser                        
    | expr op=('=='|'!=') expr                          #exprEqualNotEqual                
    | expr '&' expr                                     #exprAnd        
    | expr '|' expr                                     #exprOr        
    | expr '?' expr ':' expr                            #exprTernary                    
    // | FLOAT                                             #exprFloat
    | INT                                               #exprInt
    | func_call                                         #exprFuncCall    
    | ID '['expr']['expr']'                             #expr2DArrayElement    
    | ID '['expr']'                                     #expr1DArrayElement    
    | CHAR                                              #exprChar
    | ID                                                #exprVar
    | '(' expr ')'                                      #exprParenthesis        
    ;

/*Tokens*/

ID  : [a-z][a-zA-Z0-9]*;
CHAR: ['][a-zA-Z]['];
INT : [0-9]+;
// FLOAT : [0-9]+.[0-9]+;
STRING: '"' (ESC|.)*? '"' ;
fragment
ESC : '\\"' | '\\\\' ;
COMMENT : '//' ~[\r\n]*->skip; 
NS : [ \t\n]+ -> skip; 
TYPE: [BCIU];
