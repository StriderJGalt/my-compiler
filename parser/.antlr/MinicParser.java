// Generated from /media/adarsh/DATA/Academic/Sem5/Compilers/project/semantic/parser/Minic.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MinicParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, T__23=24, 
		T__24=25, T__25=26, T__26=27, T__27=28, T__28=29, T__29=30, T__30=31, 
		T__31=32, T__32=33, ID=34, CHAR=35, INT=36, STRING=37, COMMENT=38, NS=39, 
		TYPE=40;
	public static final int
		RULE_prog = 0, RULE_func_decl = 1, RULE_func_call = 2, RULE_decl_arg = 3, 
		RULE_arg = 4, RULE_statement = 5, RULE_assignment = 6, RULE_declaration = 7, 
		RULE_expr = 8;
	private static String[] makeRuleNames() {
		return new String[] {
			"prog", "func_decl", "func_call", "decl_arg", "arg", "statement", "assignment", 
			"declaration", "expr"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "','", "')'", "'[]'", "'[]['", "']'", "'{'", "'}'", "'IF'", 
			"'ELSE'", "'FOR'", "';'", "'WHILE'", "'RET'", "'='", "'['", "']['", "'!'", 
			"'*'", "'/'", "'%'", "'+'", "'-'", "'>'", "'>='", "'<'", "'<='", "'=='", 
			"'!='", "'&'", "'|'", "'?'", "':'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, "ID", "CHAR", 
			"INT", "STRING", "COMMENT", "NS", "TYPE"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Minic.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public MinicParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ProgContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(MinicParser.EOF, 0); }
		public List<DeclarationContext> declaration() {
			return getRuleContexts(DeclarationContext.class);
		}
		public DeclarationContext declaration(int i) {
			return getRuleContext(DeclarationContext.class,i);
		}
		public List<AssignmentContext> assignment() {
			return getRuleContexts(AssignmentContext.class);
		}
		public AssignmentContext assignment(int i) {
			return getRuleContext(AssignmentContext.class,i);
		}
		public List<Func_declContext> func_decl() {
			return getRuleContexts(Func_declContext.class);
		}
		public Func_declContext func_decl(int i) {
			return getRuleContext(Func_declContext.class,i);
		}
		public ProgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_prog; }
	}

	public final ProgContext prog() throws RecognitionException {
		ProgContext _localctx = new ProgContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_prog);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(21); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				setState(21);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
				case 1:
					{
					setState(18);
					declaration();
					}
					break;
				case 2:
					{
					setState(19);
					assignment();
					}
					break;
				case 3:
					{
					setState(20);
					func_decl();
					}
					break;
				}
				}
				setState(23); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==ID || _la==TYPE );
			setState(25);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Func_declContext extends ParserRuleContext {
		public TerminalNode TYPE() { return getToken(MinicParser.TYPE, 0); }
		public TerminalNode ID() { return getToken(MinicParser.ID, 0); }
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public List<Decl_argContext> decl_arg() {
			return getRuleContexts(Decl_argContext.class);
		}
		public Decl_argContext decl_arg(int i) {
			return getRuleContext(Decl_argContext.class,i);
		}
		public Func_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_decl; }
	}

	public final Func_declContext func_decl() throws RecognitionException {
		Func_declContext _localctx = new Func_declContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_func_decl);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(27);
			match(TYPE);
			setState(28);
			match(ID);
			setState(29);
			match(T__0);
			setState(35);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(30);
					decl_arg();
					setState(31);
					match(T__1);
					}
					} 
				}
				setState(37);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			}
			setState(39);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==TYPE) {
				{
				setState(38);
				decl_arg();
				}
			}

			setState(41);
			match(T__2);
			setState(42);
			statement();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Func_callContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(MinicParser.ID, 0); }
		public List<ArgContext> arg() {
			return getRuleContexts(ArgContext.class);
		}
		public ArgContext arg(int i) {
			return getRuleContext(ArgContext.class,i);
		}
		public Func_callContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_call; }
	}

	public final Func_callContext func_call() throws RecognitionException {
		Func_callContext _localctx = new Func_callContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_func_call);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(44);
			match(ID);
			setState(45);
			match(T__0);
			setState(51);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(46);
					arg();
					setState(47);
					match(T__1);
					}
					} 
				}
				setState(53);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,4,_ctx);
			}
			setState(55);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__17) | (1L << ID) | (1L << CHAR) | (1L << INT) | (1L << STRING))) != 0)) {
				{
				setState(54);
				arg();
				}
			}

			setState(57);
			match(T__2);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class Decl_argContext extends ParserRuleContext {
		public Decl_argContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_decl_arg; }
	 
		public Decl_argContext() { }
		public void copyFrom(Decl_argContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class Decl_argArray1DContext extends Decl_argContext {
		public TerminalNode TYPE() { return getToken(MinicParser.TYPE, 0); }
		public TerminalNode ID() { return getToken(MinicParser.ID, 0); }
		public Decl_argArray1DContext(Decl_argContext ctx) { copyFrom(ctx); }
	}
	public static class Decl_argArray2DContext extends Decl_argContext {
		public TerminalNode TYPE() { return getToken(MinicParser.TYPE, 0); }
		public TerminalNode ID() { return getToken(MinicParser.ID, 0); }
		public TerminalNode INT() { return getToken(MinicParser.INT, 0); }
		public Decl_argArray2DContext(Decl_argContext ctx) { copyFrom(ctx); }
	}
	public static class Decl_argSimpleContext extends Decl_argContext {
		public TerminalNode TYPE() { return getToken(MinicParser.TYPE, 0); }
		public TerminalNode ID() { return getToken(MinicParser.ID, 0); }
		public Decl_argSimpleContext(Decl_argContext ctx) { copyFrom(ctx); }
	}

	public final Decl_argContext decl_arg() throws RecognitionException {
		Decl_argContext _localctx = new Decl_argContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_decl_arg);
		try {
			setState(69);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				_localctx = new Decl_argSimpleContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(59);
				match(TYPE);
				setState(60);
				match(ID);
				}
				break;
			case 2:
				_localctx = new Decl_argArray1DContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(61);
				match(TYPE);
				setState(62);
				match(ID);
				setState(63);
				match(T__3);
				}
				break;
			case 3:
				_localctx = new Decl_argArray2DContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(64);
				match(TYPE);
				setState(65);
				match(ID);
				setState(66);
				match(T__4);
				setState(67);
				match(INT);
				setState(68);
				match(T__5);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ArgContext extends ParserRuleContext {
		public ArgContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_arg; }
	 
		public ArgContext() { }
		public void copyFrom(ArgContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class ArgStringContext extends ArgContext {
		public TerminalNode STRING() { return getToken(MinicParser.STRING, 0); }
		public ArgStringContext(ArgContext ctx) { copyFrom(ctx); }
	}
	public static class ArgExprContext extends ArgContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ArgExprContext(ArgContext ctx) { copyFrom(ctx); }
	}

	public final ArgContext arg() throws RecognitionException {
		ArgContext _localctx = new ArgContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_arg);
		try {
			setState(73);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case STRING:
				_localctx = new ArgStringContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(71);
				match(STRING);
				}
				break;
			case T__0:
			case T__17:
			case ID:
			case CHAR:
			case INT:
				_localctx = new ArgExprContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(72);
				expr(0);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	 
		public StatementContext() { }
		public void copyFrom(StatementContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class StatementAssignmentContext extends StatementContext {
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public StatementAssignmentContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class StatementForContext extends StatementContext {
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementForContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class StatementDeclarationContext extends StatementContext {
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public StatementDeclarationContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class CompoundStatementContext extends StatementContext {
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public CompoundStatementContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class StatementIfElseContext extends StatementContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public StatementIfElseContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class StatementWhileContext extends StatementContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementWhileContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class StatementRetContext extends StatementContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public StatementRetContext(StatementContext ctx) { copyFrom(ctx); }
	}
	public static class StatementIfContext extends StatementContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementIfContext(StatementContext ctx) { copyFrom(ctx); }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_statement);
		int _la;
		try {
			setState(118);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				_localctx = new CompoundStatementContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(75);
				match(T__6);
				setState(77); 
				_errHandler.sync(this);
				_la = _input.LA(1);
				do {
					{
					{
					setState(76);
					statement();
					}
					}
					setState(79); 
					_errHandler.sync(this);
					_la = _input.LA(1);
				} while ( (((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__6) | (1L << T__8) | (1L << T__10) | (1L << T__12) | (1L << T__13) | (1L << ID) | (1L << TYPE))) != 0) );
				setState(81);
				match(T__7);
				}
				break;
			case 2:
				_localctx = new StatementAssignmentContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(83);
				assignment();
				}
				break;
			case 3:
				_localctx = new StatementDeclarationContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(84);
				declaration();
				}
				break;
			case 4:
				_localctx = new StatementIfContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(85);
				match(T__8);
				setState(86);
				match(T__0);
				setState(87);
				expr(0);
				setState(88);
				match(T__2);
				setState(89);
				statement();
				}
				break;
			case 5:
				_localctx = new StatementIfElseContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(91);
				match(T__8);
				setState(92);
				match(T__0);
				setState(93);
				expr(0);
				setState(94);
				match(T__2);
				setState(95);
				statement();
				setState(96);
				match(T__9);
				setState(97);
				statement();
				}
				break;
			case 6:
				_localctx = new StatementForContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(99);
				match(T__10);
				setState(100);
				match(T__0);
				setState(101);
				declaration();
				setState(102);
				expr(0);
				setState(103);
				match(T__11);
				setState(104);
				assignment();
				setState(105);
				match(T__2);
				setState(106);
				statement();
				}
				break;
			case 7:
				_localctx = new StatementWhileContext(_localctx);
				enterOuterAlt(_localctx, 7);
				{
				setState(108);
				match(T__12);
				setState(109);
				match(T__0);
				setState(110);
				expr(0);
				setState(111);
				match(T__2);
				setState(112);
				statement();
				}
				break;
			case 8:
				_localctx = new StatementRetContext(_localctx);
				enterOuterAlt(_localctx, 8);
				{
				setState(114);
				match(T__13);
				setState(115);
				expr(0);
				setState(116);
				match(T__11);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AssignmentContext extends ParserRuleContext {
		public AssignmentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignment; }
	 
		public AssignmentContext() { }
		public void copyFrom(AssignmentContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class AssignmentSimpleContext extends AssignmentContext {
		public TerminalNode ID() { return getToken(MinicParser.ID, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public AssignmentSimpleContext(AssignmentContext ctx) { copyFrom(ctx); }
	}
	public static class AssignmentArrayElement1dContext extends AssignmentContext {
		public TerminalNode ID() { return getToken(MinicParser.ID, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public AssignmentArrayElement1dContext(AssignmentContext ctx) { copyFrom(ctx); }
	}
	public static class AssignmentArrayElement2dContext extends AssignmentContext {
		public TerminalNode ID() { return getToken(MinicParser.ID, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public AssignmentArrayElement2dContext(AssignmentContext ctx) { copyFrom(ctx); }
	}

	public final AssignmentContext assignment() throws RecognitionException {
		AssignmentContext _localctx = new AssignmentContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_assignment);
		try {
			setState(143);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				_localctx = new AssignmentSimpleContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(120);
				match(ID);
				setState(121);
				match(T__14);
				setState(122);
				expr(0);
				setState(123);
				match(T__11);
				}
				break;
			case 2:
				_localctx = new AssignmentArrayElement1dContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(125);
				match(ID);
				setState(126);
				match(T__15);
				setState(127);
				expr(0);
				setState(128);
				match(T__5);
				setState(129);
				match(T__14);
				setState(130);
				expr(0);
				setState(131);
				match(T__11);
				}
				break;
			case 3:
				_localctx = new AssignmentArrayElement2dContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(133);
				match(ID);
				setState(134);
				match(T__15);
				setState(135);
				expr(0);
				setState(136);
				match(T__16);
				setState(137);
				expr(0);
				setState(138);
				match(T__5);
				setState(139);
				match(T__14);
				setState(140);
				expr(0);
				setState(141);
				match(T__11);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationContext extends ParserRuleContext {
		public DeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration; }
	 
		public DeclarationContext() { }
		public void copyFrom(DeclarationContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class DeclarationSimpleContext extends DeclarationContext {
		public TerminalNode TYPE() { return getToken(MinicParser.TYPE, 0); }
		public TerminalNode ID() { return getToken(MinicParser.ID, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public DeclarationSimpleContext(DeclarationContext ctx) { copyFrom(ctx); }
	}
	public static class DeclarationArray2DContext extends DeclarationContext {
		public TerminalNode TYPE() { return getToken(MinicParser.TYPE, 0); }
		public TerminalNode ID() { return getToken(MinicParser.ID, 0); }
		public List<TerminalNode> INT() { return getTokens(MinicParser.INT); }
		public TerminalNode INT(int i) {
			return getToken(MinicParser.INT, i);
		}
		public DeclarationArray2DContext(DeclarationContext ctx) { copyFrom(ctx); }
	}
	public static class DeclarationArray1DContext extends DeclarationContext {
		public TerminalNode TYPE() { return getToken(MinicParser.TYPE, 0); }
		public TerminalNode ID() { return getToken(MinicParser.ID, 0); }
		public TerminalNode INT() { return getToken(MinicParser.INT, 0); }
		public DeclarationArray1DContext(DeclarationContext ctx) { copyFrom(ctx); }
	}

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_declaration);
		try {
			setState(165);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				_localctx = new DeclarationSimpleContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(145);
				match(TYPE);
				setState(146);
				match(ID);
				setState(147);
				match(T__14);
				setState(148);
				expr(0);
				setState(149);
				match(T__11);
				}
				break;
			case 2:
				_localctx = new DeclarationArray1DContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(151);
				match(TYPE);
				setState(152);
				match(ID);
				setState(153);
				match(T__15);
				setState(154);
				match(INT);
				setState(155);
				match(T__5);
				setState(156);
				match(T__11);
				}
				break;
			case 3:
				_localctx = new DeclarationArray2DContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(157);
				match(TYPE);
				setState(158);
				match(ID);
				setState(159);
				match(T__15);
				setState(160);
				match(INT);
				setState(161);
				match(T__16);
				setState(162);
				match(INT);
				setState(163);
				match(T__5);
				setState(164);
				match(T__11);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprContext extends ParserRuleContext {
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	 
		public ExprContext() { }
		public void copyFrom(ExprContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class ExprIntContext extends ExprContext {
		public TerminalNode INT() { return getToken(MinicParser.INT, 0); }
		public ExprIntContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprMulDivModContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ExprMulDivModContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprNotContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ExprNotContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprAddSubContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ExprAddSubContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprVarContext extends ExprContext {
		public TerminalNode ID() { return getToken(MinicParser.ID, 0); }
		public ExprVarContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprCharContext extends ExprContext {
		public TerminalNode CHAR() { return getToken(MinicParser.CHAR, 0); }
		public ExprCharContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprFuncCallContext extends ExprContext {
		public Func_callContext func_call() {
			return getRuleContext(Func_callContext.class,0);
		}
		public ExprFuncCallContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprOrContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ExprOrContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprGreaterLesserContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ExprGreaterLesserContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class Expr2DArrayElementContext extends ExprContext {
		public TerminalNode ID() { return getToken(MinicParser.ID, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public Expr2DArrayElementContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprAndContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ExprAndContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprTernaryContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ExprTernaryContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprParenthesisContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ExprParenthesisContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ExprEqualNotEqualContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ExprEqualNotEqualContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class Expr1DArrayElementContext extends ExprContext {
		public TerminalNode ID() { return getToken(MinicParser.ID, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public Expr1DArrayElementContext(ExprContext ctx) { copyFrom(ctx); }
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 16;
		enterRecursionRule(_localctx, 16, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(190);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				{
				_localctx = new ExprNotContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(168);
				match(T__17);
				setState(169);
				expr(15);
				}
				break;
			case 2:
				{
				_localctx = new ExprIntContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(170);
				match(INT);
				}
				break;
			case 3:
				{
				_localctx = new ExprFuncCallContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(171);
				func_call();
				}
				break;
			case 4:
				{
				_localctx = new Expr2DArrayElementContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(172);
				match(ID);
				setState(173);
				match(T__15);
				setState(174);
				expr(0);
				setState(175);
				match(T__16);
				setState(176);
				expr(0);
				setState(177);
				match(T__5);
				}
				break;
			case 5:
				{
				_localctx = new Expr1DArrayElementContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(179);
				match(ID);
				setState(180);
				match(T__15);
				setState(181);
				expr(0);
				setState(182);
				match(T__5);
				}
				break;
			case 6:
				{
				_localctx = new ExprCharContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(184);
				match(CHAR);
				}
				break;
			case 7:
				{
				_localctx = new ExprVarContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(185);
				match(ID);
				}
				break;
			case 8:
				{
				_localctx = new ExprParenthesisContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(186);
				match(T__0);
				setState(187);
				expr(0);
				setState(188);
				match(T__2);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(218);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(216);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
					case 1:
						{
						_localctx = new ExprMulDivModContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(192);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(193);
						((ExprMulDivModContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__18) | (1L << T__19) | (1L << T__20))) != 0)) ) {
							((ExprMulDivModContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(194);
						expr(15);
						}
						break;
					case 2:
						{
						_localctx = new ExprAddSubContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(195);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(196);
						((ExprAddSubContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__21 || _la==T__22) ) {
							((ExprAddSubContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(197);
						expr(14);
						}
						break;
					case 3:
						{
						_localctx = new ExprGreaterLesserContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(198);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(199);
						((ExprGreaterLesserContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__23) | (1L << T__24) | (1L << T__25) | (1L << T__26))) != 0)) ) {
							((ExprGreaterLesserContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(200);
						expr(13);
						}
						break;
					case 4:
						{
						_localctx = new ExprEqualNotEqualContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(201);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(202);
						((ExprEqualNotEqualContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==T__27 || _la==T__28) ) {
							((ExprEqualNotEqualContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(203);
						expr(12);
						}
						break;
					case 5:
						{
						_localctx = new ExprAndContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(204);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(205);
						match(T__29);
						setState(206);
						expr(11);
						}
						break;
					case 6:
						{
						_localctx = new ExprOrContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(207);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(208);
						match(T__30);
						setState(209);
						expr(10);
						}
						break;
					case 7:
						{
						_localctx = new ExprTernaryContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(210);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(211);
						match(T__31);
						setState(212);
						expr(0);
						setState(213);
						match(T__32);
						setState(214);
						expr(9);
						}
						break;
					}
					} 
				}
				setState(220);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,14,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 8:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 14);
		case 1:
			return precpred(_ctx, 13);
		case 2:
			return precpred(_ctx, 12);
		case 3:
			return precpred(_ctx, 11);
		case 4:
			return precpred(_ctx, 10);
		case 5:
			return precpred(_ctx, 9);
		case 6:
			return precpred(_ctx, 8);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3*\u00e0\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\3\2\3\2"+
		"\3\2\6\2\30\n\2\r\2\16\2\31\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\3\7\3$\n\3\f"+
		"\3\16\3\'\13\3\3\3\5\3*\n\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\4\7\4\64\n\4"+
		"\f\4\16\4\67\13\4\3\4\5\4:\n\4\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5"+
		"\3\5\3\5\5\5H\n\5\3\6\3\6\5\6L\n\6\3\7\3\7\6\7P\n\7\r\7\16\7Q\3\7\3\7"+
		"\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3"+
		"\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7"+
		"\5\7y\n\7\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b"+
		"\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\b\5\b\u0092\n\b\3\t\3\t\3\t\3\t\3\t\3\t"+
		"\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\5\t\u00a8\n\t"+
		"\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3"+
		"\n\3\n\3\n\3\n\3\n\3\n\5\n\u00c1\n\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3"+
		"\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\7\n\u00db"+
		"\n\n\f\n\16\n\u00de\13\n\3\n\2\3\22\13\2\4\6\b\n\f\16\20\22\2\6\3\2\25"+
		"\27\3\2\30\31\3\2\32\35\3\2\36\37\2\u00fa\2\27\3\2\2\2\4\35\3\2\2\2\6"+
		".\3\2\2\2\bG\3\2\2\2\nK\3\2\2\2\fx\3\2\2\2\16\u0091\3\2\2\2\20\u00a7\3"+
		"\2\2\2\22\u00c0\3\2\2\2\24\30\5\20\t\2\25\30\5\16\b\2\26\30\5\4\3\2\27"+
		"\24\3\2\2\2\27\25\3\2\2\2\27\26\3\2\2\2\30\31\3\2\2\2\31\27\3\2\2\2\31"+
		"\32\3\2\2\2\32\33\3\2\2\2\33\34\7\2\2\3\34\3\3\2\2\2\35\36\7*\2\2\36\37"+
		"\7$\2\2\37%\7\3\2\2 !\5\b\5\2!\"\7\4\2\2\"$\3\2\2\2# \3\2\2\2$\'\3\2\2"+
		"\2%#\3\2\2\2%&\3\2\2\2&)\3\2\2\2\'%\3\2\2\2(*\5\b\5\2)(\3\2\2\2)*\3\2"+
		"\2\2*+\3\2\2\2+,\7\5\2\2,-\5\f\7\2-\5\3\2\2\2./\7$\2\2/\65\7\3\2\2\60"+
		"\61\5\n\6\2\61\62\7\4\2\2\62\64\3\2\2\2\63\60\3\2\2\2\64\67\3\2\2\2\65"+
		"\63\3\2\2\2\65\66\3\2\2\2\669\3\2\2\2\67\65\3\2\2\28:\5\n\6\298\3\2\2"+
		"\29:\3\2\2\2:;\3\2\2\2;<\7\5\2\2<\7\3\2\2\2=>\7*\2\2>H\7$\2\2?@\7*\2\2"+
		"@A\7$\2\2AH\7\6\2\2BC\7*\2\2CD\7$\2\2DE\7\7\2\2EF\7&\2\2FH\7\b\2\2G=\3"+
		"\2\2\2G?\3\2\2\2GB\3\2\2\2H\t\3\2\2\2IL\7\'\2\2JL\5\22\n\2KI\3\2\2\2K"+
		"J\3\2\2\2L\13\3\2\2\2MO\7\t\2\2NP\5\f\7\2ON\3\2\2\2PQ\3\2\2\2QO\3\2\2"+
		"\2QR\3\2\2\2RS\3\2\2\2ST\7\n\2\2Ty\3\2\2\2Uy\5\16\b\2Vy\5\20\t\2WX\7\13"+
		"\2\2XY\7\3\2\2YZ\5\22\n\2Z[\7\5\2\2[\\\5\f\7\2\\y\3\2\2\2]^\7\13\2\2^"+
		"_\7\3\2\2_`\5\22\n\2`a\7\5\2\2ab\5\f\7\2bc\7\f\2\2cd\5\f\7\2dy\3\2\2\2"+
		"ef\7\r\2\2fg\7\3\2\2gh\5\20\t\2hi\5\22\n\2ij\7\16\2\2jk\5\16\b\2kl\7\5"+
		"\2\2lm\5\f\7\2my\3\2\2\2no\7\17\2\2op\7\3\2\2pq\5\22\n\2qr\7\5\2\2rs\5"+
		"\f\7\2sy\3\2\2\2tu\7\20\2\2uv\5\22\n\2vw\7\16\2\2wy\3\2\2\2xM\3\2\2\2"+
		"xU\3\2\2\2xV\3\2\2\2xW\3\2\2\2x]\3\2\2\2xe\3\2\2\2xn\3\2\2\2xt\3\2\2\2"+
		"y\r\3\2\2\2z{\7$\2\2{|\7\21\2\2|}\5\22\n\2}~\7\16\2\2~\u0092\3\2\2\2\177"+
		"\u0080\7$\2\2\u0080\u0081\7\22\2\2\u0081\u0082\5\22\n\2\u0082\u0083\7"+
		"\b\2\2\u0083\u0084\7\21\2\2\u0084\u0085\5\22\n\2\u0085\u0086\7\16\2\2"+
		"\u0086\u0092\3\2\2\2\u0087\u0088\7$\2\2\u0088\u0089\7\22\2\2\u0089\u008a"+
		"\5\22\n\2\u008a\u008b\7\23\2\2\u008b\u008c\5\22\n\2\u008c\u008d\7\b\2"+
		"\2\u008d\u008e\7\21\2\2\u008e\u008f\5\22\n\2\u008f\u0090\7\16\2\2\u0090"+
		"\u0092\3\2\2\2\u0091z\3\2\2\2\u0091\177\3\2\2\2\u0091\u0087\3\2\2\2\u0092"+
		"\17\3\2\2\2\u0093\u0094\7*\2\2\u0094\u0095\7$\2\2\u0095\u0096\7\21\2\2"+
		"\u0096\u0097\5\22\n\2\u0097\u0098\7\16\2\2\u0098\u00a8\3\2\2\2\u0099\u009a"+
		"\7*\2\2\u009a\u009b\7$\2\2\u009b\u009c\7\22\2\2\u009c\u009d\7&\2\2\u009d"+
		"\u009e\7\b\2\2\u009e\u00a8\7\16\2\2\u009f\u00a0\7*\2\2\u00a0\u00a1\7$"+
		"\2\2\u00a1\u00a2\7\22\2\2\u00a2\u00a3\7&\2\2\u00a3\u00a4\7\23\2\2\u00a4"+
		"\u00a5\7&\2\2\u00a5\u00a6\7\b\2\2\u00a6\u00a8\7\16\2\2\u00a7\u0093\3\2"+
		"\2\2\u00a7\u0099\3\2\2\2\u00a7\u009f\3\2\2\2\u00a8\21\3\2\2\2\u00a9\u00aa"+
		"\b\n\1\2\u00aa\u00ab\7\24\2\2\u00ab\u00c1\5\22\n\21\u00ac\u00c1\7&\2\2"+
		"\u00ad\u00c1\5\6\4\2\u00ae\u00af\7$\2\2\u00af\u00b0\7\22\2\2\u00b0\u00b1"+
		"\5\22\n\2\u00b1\u00b2\7\23\2\2\u00b2\u00b3\5\22\n\2\u00b3\u00b4\7\b\2"+
		"\2\u00b4\u00c1\3\2\2\2\u00b5\u00b6\7$\2\2\u00b6\u00b7\7\22\2\2\u00b7\u00b8"+
		"\5\22\n\2\u00b8\u00b9\7\b\2\2\u00b9\u00c1\3\2\2\2\u00ba\u00c1\7%\2\2\u00bb"+
		"\u00c1\7$\2\2\u00bc\u00bd\7\3\2\2\u00bd\u00be\5\22\n\2\u00be\u00bf\7\5"+
		"\2\2\u00bf\u00c1\3\2\2\2\u00c0\u00a9\3\2\2\2\u00c0\u00ac\3\2\2\2\u00c0"+
		"\u00ad\3\2\2\2\u00c0\u00ae\3\2\2\2\u00c0\u00b5\3\2\2\2\u00c0\u00ba\3\2"+
		"\2\2\u00c0\u00bb\3\2\2\2\u00c0\u00bc\3\2\2\2\u00c1\u00dc\3\2\2\2\u00c2"+
		"\u00c3\f\20\2\2\u00c3\u00c4\t\2\2\2\u00c4\u00db\5\22\n\21\u00c5\u00c6"+
		"\f\17\2\2\u00c6\u00c7\t\3\2\2\u00c7\u00db\5\22\n\20\u00c8\u00c9\f\16\2"+
		"\2\u00c9\u00ca\t\4\2\2\u00ca\u00db\5\22\n\17\u00cb\u00cc\f\r\2\2\u00cc"+
		"\u00cd\t\5\2\2\u00cd\u00db\5\22\n\16\u00ce\u00cf\f\f\2\2\u00cf\u00d0\7"+
		" \2\2\u00d0\u00db\5\22\n\r\u00d1\u00d2\f\13\2\2\u00d2\u00d3\7!\2\2\u00d3"+
		"\u00db\5\22\n\f\u00d4\u00d5\f\n\2\2\u00d5\u00d6\7\"\2\2\u00d6\u00d7\5"+
		"\22\n\2\u00d7\u00d8\7#\2\2\u00d8\u00d9\5\22\n\13\u00d9\u00db\3\2\2\2\u00da"+
		"\u00c2\3\2\2\2\u00da\u00c5\3\2\2\2\u00da\u00c8\3\2\2\2\u00da\u00cb\3\2"+
		"\2\2\u00da\u00ce\3\2\2\2\u00da\u00d1\3\2\2\2\u00da\u00d4\3\2\2\2\u00db"+
		"\u00de\3\2\2\2\u00dc\u00da\3\2\2\2\u00dc\u00dd\3\2\2\2\u00dd\23\3\2\2"+
		"\2\u00de\u00dc\3\2\2\2\21\27\31%)\659GKQx\u0091\u00a7\u00c0\u00da\u00dc";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}