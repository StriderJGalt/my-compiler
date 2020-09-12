grammar Minic;

prog: global_statements + EOF
    ;

global_statements: global_statement global_statements
    | global_statement
    ;

global_statement: declaration
    | assignment
    | func_decl
    ;

func_decl: TYPE ID '(' decl_args ')' rblock
    | TYPE 'MAIN' '(' decl_args ')' rblock
    ;

func_call: ID '(' args ')'
    ;

decl_args : decl_arg ',' decl_args
    | decl_arg
    |
    ;

decl_arg: TYPE ID
    | TYPE ID'[]'
    | TYPE ID'[][]'
    ;

args: STRING',' args
    | expr',' args
    | STRING
    | expr
    |
    ;

block: '{' statements '}'
    ;

rblock:  '{' statements 'RET' expr ';' '}'
    ;

statements: statement statements
    | 
    ;

statement: assignment
    | declaration
    | func_call ';'
    | 'IF' '(' expr ')' block
    | 'IF' '(' expr ')' block 'ELSE' block
    | 'FOR' '(' declaration expr ';'assignment ')' block
    | 'WHILE' '(' expr ')' block
    | 'RET' expr';'
    ;

assignment: ID '=' expr ';'
    | ar_elem '=' expr ';'
    ;

ar_elem: ID '['expr']['expr']'
    | ID '['expr']'
    ;

declaration: TYPE id_list';'
    | TYPE ID '=' expr ';'
    ;

id_list: ID'['INT']['INT']'',' id_list
    |ID'['INT']'',' id_list
    | ID',' id_list
    | ID'['INT']['INT']'
    | ID'['INT']'
    | ID
    ;

expr: '!' expr
    | expr ('*'|'/'|'%') expr
    | expr ('+'|'-') expr
    | expr ('>'|'>='|'<'|'<=') expr
    | expr ('=='|'!=') expr
    | expr '&' expr
    | expr '|' expr
    | expr '?' expr ':' expr
    | FLOAT
    | INT
    | func_call
    | ar_elem
    | CHAR
    | ID
    | '(' expr ')'
    ;

/*Tokens*/

ID  : [a-z][a-zA-Z0-9]*;
CHAR: ['][a-zA-Z]['];
INT : [0-9]+;
FLOAT : [0-9]+.[0-9]+;
STRING: '"' (ESC|.)*? '"' ;
fragment
ESC : '\\"' | '\\\\' ;
COMMENT : '//' ~[\r\n]*->skip; 
NS : [ \t\n]+ -> skip; 
TYPE: [BCIU];
