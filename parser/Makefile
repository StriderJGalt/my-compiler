ANTLR4=java -Xmx500M -cp "/usr/local/lib/antlr-4.8-complete.jar:$CLASSPATH" org.antlr.v4.Tool

antlr:	Minic.g4
		$(ANTLR4) -Dlanguage=Cpp -no-listener -visitor Minic.g4
		clang++ -g main.cpp `llvm-config --cppflags --ldflags --libs core  --system-libs` -o Minic -I/usr/local/include/antlr4-runtime -lantlr4-runtime

clean:	
		rm -f MinicLexer.h MinicParser.h Minic *.tokens *.interp MinicBaseVisitor.cpp \
		rm -f MinicBaseVisitor.h MinicParser.cpp MinicLexer.cpp MinicBaseVisitor.cpp  \ 
		rm -f MinicVisitor.cpp  MinicVisitor.h

