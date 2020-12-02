#include <iostream>
#include "antlr4-runtime.h"
#include "MinicLexer.cpp"
#include "MinicParser.cpp"
#include "ast.h"
#include "MinicBuildASTVisitor.h"
#include "CodegenVisitor.h"

bool DEBUG_PRINT = true;

using namespace std;
using namespace antlr4;

int main(int argc, const char* argv[]) {
    std::ifstream stream;

    if(DEBUG_PRINT)
    cout << "Processing input file " << argv[1] << endl;
    stream.open(argv[1]);
    
    ANTLRInputStream input(stream);

    MinicLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    MinicParser parser(&tokens);    

    MinicParser::ProgContext *ctx = parser.prog();

    MinicVisitor *visitor = new MinicBuildASTVisitor();


    ASTProg *program_root = visitor->visitProg(ctx);
    
    // ASTvisitor* generator = new CodegenVisitor();
    // program_root->accept(*generator);

    if(DEBUG_PRINT)
    cout << endl;

    // dynamic_cast<CodegenVisitor*>(generator)->generateCode();

    return 0;
}
