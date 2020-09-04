grammar Expr;

prog: (expr ';') + EOF
    ;


expr: '!' expr
    | expr ('*'|'/') expr
    | expr ('+'|'-') expr
    | expr ('>'|'>='|'<'|'<=') expr
    | expr ('=='|'!=') expr
    | expr '&' expr
    | expr '|' expr
    | FLOAT
    | INT
    | ID
    | '(' expr ')'
    ;

/*Tokens*/

ID  : [a-z][a-zA-Z0-9]*;
INT : [0-9]+;
FLOAT : [0-9]+.[0-9]+;
COMMENT : '//' ~[\r\n]*->skip; 
NS : [ \t\n]+ -> skip; 