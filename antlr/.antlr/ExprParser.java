// Generated from /media/adarsh/DATA/Academic/Sem5/Compilers/project/minic-grammar-StriderJGalt/antlr/Expr.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ExprParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, T__15=16, T__16=17, 
		T__17=18, T__18=19, T__19=20, T__20=21, T__21=22, T__22=23, T__23=24, 
		T__24=25, T__25=26, T__26=27, T__27=28, T__28=29, T__29=30, T__30=31, 
		T__31=32, T__32=33, T__33=34, ID=35, CHAR=36, INT=37, FLOAT=38, STRING=39, 
		COMMENT=40, NS=41, TYPE=42;
	public static final int
		RULE_prog = 0, RULE_global_statements = 1, RULE_global_statement = 2, 
		RULE_func_decl = 3, RULE_func_call = 4, RULE_decl_args = 5, RULE_decl_arg = 6, 
		RULE_args = 7, RULE_block = 8, RULE_rblock = 9, RULE_statements = 10, 
		RULE_statement = 11, RULE_assignment = 12, RULE_ar_elem = 13, RULE_declaration = 14, 
		RULE_id_list = 15, RULE_expr = 16;
	private static String[] makeRuleNames() {
		return new String[] {
			"prog", "global_statements", "global_statement", "func_decl", "func_call", 
			"decl_args", "decl_arg", "args", "block", "rblock", "statements", "statement", 
			"assignment", "ar_elem", "declaration", "id_list", "expr"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "')'", "'MAIN'", "','", "'[]'", "'[][]'", "'{'", "'}'", 
			"'RET'", "';'", "'IF'", "'ELSE'", "'FOR'", "'WHILE'", "'='", "'['", "']['", 
			"']'", "'!'", "'*'", "'/'", "'%'", "'+'", "'-'", "'>'", "'>='", "'<'", 
			"'<='", "'=='", "'!='", "'&'", "'|'", "'?'", "':'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, null, null, null, null, null, null, null, "ID", 
			"CHAR", "INT", "FLOAT", "STRING", "COMMENT", "NS", "TYPE"
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
	public String getGrammarFileName() { return "Expr.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public ExprParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ProgContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(ExprParser.EOF, 0); }
		public List<Global_statementsContext> global_statements() {
			return getRuleContexts(Global_statementsContext.class);
		}
		public Global_statementsContext global_statements(int i) {
			return getRuleContext(Global_statementsContext.class,i);
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
			setState(35); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(34);
				global_statements();
				}
				}
				setState(37); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==ID || _la==TYPE );
			setState(39);
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

	public static class Global_statementsContext extends ParserRuleContext {
		public Global_statementContext global_statement() {
			return getRuleContext(Global_statementContext.class,0);
		}
		public Global_statementsContext global_statements() {
			return getRuleContext(Global_statementsContext.class,0);
		}
		public Global_statementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_global_statements; }
	}

	public final Global_statementsContext global_statements() throws RecognitionException {
		Global_statementsContext _localctx = new Global_statementsContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_global_statements);
		try {
			setState(45);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(41);
				global_statement();
				setState(42);
				global_statements();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(44);
				global_statement();
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

	public static class Global_statementContext extends ParserRuleContext {
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public Func_declContext func_decl() {
			return getRuleContext(Func_declContext.class,0);
		}
		public Global_statementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_global_statement; }
	}

	public final Global_statementContext global_statement() throws RecognitionException {
		Global_statementContext _localctx = new Global_statementContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_global_statement);
		try {
			setState(50);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(47);
				declaration();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(48);
				assignment();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(49);
				func_decl();
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

	public static class Func_declContext extends ParserRuleContext {
		public TerminalNode TYPE() { return getToken(ExprParser.TYPE, 0); }
		public TerminalNode ID() { return getToken(ExprParser.ID, 0); }
		public Decl_argsContext decl_args() {
			return getRuleContext(Decl_argsContext.class,0);
		}
		public RblockContext rblock() {
			return getRuleContext(RblockContext.class,0);
		}
		public Func_declContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_decl; }
	}

	public final Func_declContext func_decl() throws RecognitionException {
		Func_declContext _localctx = new Func_declContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_func_decl);
		try {
			setState(66);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(52);
				match(TYPE);
				setState(53);
				match(ID);
				setState(54);
				match(T__0);
				setState(55);
				decl_args();
				setState(56);
				match(T__1);
				setState(57);
				rblock();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(59);
				match(TYPE);
				setState(60);
				match(T__2);
				setState(61);
				match(T__0);
				setState(62);
				decl_args();
				setState(63);
				match(T__1);
				setState(64);
				rblock();
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

	public static class Func_callContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(ExprParser.ID, 0); }
		public ArgsContext args() {
			return getRuleContext(ArgsContext.class,0);
		}
		public Func_callContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func_call; }
	}

	public final Func_callContext func_call() throws RecognitionException {
		Func_callContext _localctx = new Func_callContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_func_call);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(68);
			match(ID);
			setState(69);
			match(T__0);
			setState(70);
			args();
			setState(71);
			match(T__1);
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

	public static class Decl_argsContext extends ParserRuleContext {
		public Decl_argContext decl_arg() {
			return getRuleContext(Decl_argContext.class,0);
		}
		public Decl_argsContext decl_args() {
			return getRuleContext(Decl_argsContext.class,0);
		}
		public Decl_argsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_decl_args; }
	}

	public final Decl_argsContext decl_args() throws RecognitionException {
		Decl_argsContext _localctx = new Decl_argsContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_decl_args);
		try {
			setState(79);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(73);
				decl_arg();
				setState(74);
				match(T__3);
				setState(75);
				decl_args();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(77);
				decl_arg();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
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

	public static class Decl_argContext extends ParserRuleContext {
		public TerminalNode TYPE() { return getToken(ExprParser.TYPE, 0); }
		public TerminalNode ID() { return getToken(ExprParser.ID, 0); }
		public Decl_argContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_decl_arg; }
	}

	public final Decl_argContext decl_arg() throws RecognitionException {
		Decl_argContext _localctx = new Decl_argContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_decl_arg);
		try {
			setState(89);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(81);
				match(TYPE);
				setState(82);
				match(ID);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(83);
				match(TYPE);
				setState(84);
				match(ID);
				setState(85);
				match(T__4);
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(86);
				match(TYPE);
				setState(87);
				match(ID);
				setState(88);
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

	public static class ArgsContext extends ParserRuleContext {
		public TerminalNode STRING() { return getToken(ExprParser.STRING, 0); }
		public ArgsContext args() {
			return getRuleContext(ArgsContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ArgsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_args; }
	}

	public final ArgsContext args() throws RecognitionException {
		ArgsContext _localctx = new ArgsContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_args);
		try {
			setState(101);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(91);
				match(STRING);
				setState(92);
				match(T__3);
				setState(93);
				args();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(94);
				expr(0);
				setState(95);
				match(T__3);
				setState(96);
				args();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(98);
				match(STRING);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(99);
				expr(0);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
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

	public static class BlockContext extends ParserRuleContext {
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_block);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(103);
			match(T__6);
			setState(104);
			statements();
			setState(105);
			match(T__7);
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

	public static class RblockContext extends ParserRuleContext {
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public RblockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rblock; }
	}

	public final RblockContext rblock() throws RecognitionException {
		RblockContext _localctx = new RblockContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_rblock);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(107);
			match(T__6);
			setState(108);
			statements();
			setState(109);
			match(T__8);
			setState(110);
			expr(0);
			setState(111);
			match(T__9);
			setState(112);
			match(T__7);
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

	public static class StatementsContext extends ParserRuleContext {
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public StatementsContext statements() {
			return getRuleContext(StatementsContext.class,0);
		}
		public StatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statements; }
	}

	public final StatementsContext statements() throws RecognitionException {
		StatementsContext _localctx = new StatementsContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_statements);
		try {
			setState(118);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(114);
				statement();
				setState(115);
				statements();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
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

	public static class StatementContext extends ParserRuleContext {
		public AssignmentContext assignment() {
			return getRuleContext(AssignmentContext.class,0);
		}
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public Func_callContext func_call() {
			return getRuleContext(Func_callContext.class,0);
		}
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<BlockContext> block() {
			return getRuleContexts(BlockContext.class);
		}
		public BlockContext block(int i) {
			return getRuleContext(BlockContext.class,i);
		}
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_statement);
		try {
			setState(158);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(120);
				assignment();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(121);
				declaration();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(122);
				func_call();
				setState(123);
				match(T__9);
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(125);
				match(T__10);
				setState(126);
				match(T__0);
				setState(127);
				expr(0);
				setState(128);
				match(T__1);
				setState(129);
				block();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(131);
				match(T__10);
				setState(132);
				match(T__0);
				setState(133);
				expr(0);
				setState(134);
				match(T__1);
				setState(135);
				block();
				setState(136);
				match(T__11);
				setState(137);
				block();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(139);
				match(T__12);
				setState(140);
				match(T__0);
				setState(141);
				declaration();
				setState(142);
				expr(0);
				setState(143);
				match(T__9);
				setState(144);
				assignment();
				setState(145);
				match(T__1);
				setState(146);
				block();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(148);
				match(T__13);
				setState(149);
				match(T__0);
				setState(150);
				expr(0);
				setState(151);
				match(T__1);
				setState(152);
				block();
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(154);
				match(T__8);
				setState(155);
				expr(0);
				setState(156);
				match(T__9);
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
		public TerminalNode ID() { return getToken(ExprParser.ID, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public Ar_elemContext ar_elem() {
			return getRuleContext(Ar_elemContext.class,0);
		}
		public AssignmentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignment; }
	}

	public final AssignmentContext assignment() throws RecognitionException {
		AssignmentContext _localctx = new AssignmentContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_assignment);
		try {
			setState(170);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(160);
				match(ID);
				setState(161);
				match(T__14);
				setState(162);
				expr(0);
				setState(163);
				match(T__9);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(165);
				ar_elem();
				setState(166);
				match(T__14);
				setState(167);
				expr(0);
				setState(168);
				match(T__9);
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

	public static class Ar_elemContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(ExprParser.ID, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public Ar_elemContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ar_elem; }
	}

	public final Ar_elemContext ar_elem() throws RecognitionException {
		Ar_elemContext _localctx = new Ar_elemContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_ar_elem);
		try {
			setState(184);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
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
				match(T__17);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(179);
				match(ID);
				setState(180);
				match(T__15);
				setState(181);
				expr(0);
				setState(182);
				match(T__17);
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
		public TerminalNode TYPE() { return getToken(ExprParser.TYPE, 0); }
		public Id_listContext id_list() {
			return getRuleContext(Id_listContext.class,0);
		}
		public TerminalNode ID() { return getToken(ExprParser.ID, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public DeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration; }
	}

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_declaration);
		try {
			setState(196);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,11,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(186);
				match(TYPE);
				setState(187);
				id_list();
				setState(188);
				match(T__9);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(190);
				match(TYPE);
				setState(191);
				match(ID);
				setState(192);
				match(T__14);
				setState(193);
				expr(0);
				setState(194);
				match(T__9);
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

	public static class Id_listContext extends ParserRuleContext {
		public TerminalNode ID() { return getToken(ExprParser.ID, 0); }
		public List<TerminalNode> INT() { return getTokens(ExprParser.INT); }
		public TerminalNode INT(int i) {
			return getToken(ExprParser.INT, i);
		}
		public Id_listContext id_list() {
			return getRuleContext(Id_listContext.class,0);
		}
		public Id_listContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_id_list; }
	}

	public final Id_listContext id_list() throws RecognitionException {
		Id_listContext _localctx = new Id_listContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_id_list);
		try {
			setState(226);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,12,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(198);
				match(ID);
				setState(199);
				match(T__15);
				setState(200);
				match(INT);
				setState(201);
				match(T__16);
				setState(202);
				match(INT);
				setState(203);
				match(T__17);
				setState(204);
				match(T__3);
				setState(205);
				id_list();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(206);
				match(ID);
				setState(207);
				match(T__15);
				setState(208);
				match(INT);
				setState(209);
				match(T__17);
				setState(210);
				match(T__3);
				setState(211);
				id_list();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(212);
				match(ID);
				setState(213);
				match(T__3);
				setState(214);
				id_list();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(215);
				match(ID);
				setState(216);
				match(T__15);
				setState(217);
				match(INT);
				setState(218);
				match(T__16);
				setState(219);
				match(INT);
				setState(220);
				match(T__17);
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(221);
				match(ID);
				setState(222);
				match(T__15);
				setState(223);
				match(INT);
				setState(224);
				match(T__17);
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(225);
				match(ID);
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
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode FLOAT() { return getToken(ExprParser.FLOAT, 0); }
		public TerminalNode INT() { return getToken(ExprParser.INT, 0); }
		public Func_callContext func_call() {
			return getRuleContext(Func_callContext.class,0);
		}
		public Ar_elemContext ar_elem() {
			return getRuleContext(Ar_elemContext.class,0);
		}
		public TerminalNode CHAR() { return getToken(ExprParser.CHAR, 0); }
		public TerminalNode ID() { return getToken(ExprParser.ID, 0); }
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 32;
		enterRecursionRule(_localctx, 32, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(241);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				{
				setState(229);
				match(T__18);
				setState(230);
				expr(15);
				}
				break;
			case 2:
				{
				setState(231);
				match(FLOAT);
				}
				break;
			case 3:
				{
				setState(232);
				match(INT);
				}
				break;
			case 4:
				{
				setState(233);
				func_call();
				}
				break;
			case 5:
				{
				setState(234);
				ar_elem();
				}
				break;
			case 6:
				{
				setState(235);
				match(CHAR);
				}
				break;
			case 7:
				{
				setState(236);
				match(ID);
				}
				break;
			case 8:
				{
				setState(237);
				match(T__0);
				setState(238);
				expr(0);
				setState(239);
				match(T__1);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(269);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(267);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
					case 1:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(243);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(244);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__19) | (1L << T__20) | (1L << T__21))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(245);
						expr(15);
						}
						break;
					case 2:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(246);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(247);
						_la = _input.LA(1);
						if ( !(_la==T__22 || _la==T__23) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(248);
						expr(14);
						}
						break;
					case 3:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(249);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(250);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__24) | (1L << T__25) | (1L << T__26) | (1L << T__27))) != 0)) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(251);
						expr(13);
						}
						break;
					case 4:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(252);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(253);
						_la = _input.LA(1);
						if ( !(_la==T__28 || _la==T__29) ) {
						_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(254);
						expr(12);
						}
						break;
					case 5:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(255);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(256);
						match(T__30);
						setState(257);
						expr(11);
						}
						break;
					case 6:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(258);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(259);
						match(T__31);
						setState(260);
						expr(10);
						}
						break;
					case 7:
						{
						_localctx = new ExprContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(261);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(262);
						match(T__32);
						setState(263);
						expr(0);
						setState(264);
						match(T__33);
						setState(265);
						expr(9);
						}
						break;
					}
					} 
				}
				setState(271);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
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
		case 16:
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3,\u0113\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\3\2\6\2&\n\2\r\2\16\2\'\3\2\3\2\3\3\3\3\3\3\3\3\5\3\60\n\3\3\4\3\4\3"+
		"\4\5\4\65\n\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5"+
		"\5\5E\n\5\3\6\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\7\5\7R\n\7\3\b\3\b"+
		"\3\b\3\b\3\b\3\b\3\b\3\b\5\b\\\n\b\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t\3\t"+
		"\3\t\5\th\n\t\3\n\3\n\3\n\3\n\3\13\3\13\3\13\3\13\3\13\3\13\3\13\3\f\3"+
		"\f\3\f\3\f\5\fy\n\f\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3"+
		"\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r"+
		"\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\5\r\u00a1\n\r\3\16\3\16\3\16\3\16\3\16"+
		"\3\16\3\16\3\16\3\16\3\16\5\16\u00ad\n\16\3\17\3\17\3\17\3\17\3\17\3\17"+
		"\3\17\3\17\3\17\3\17\3\17\3\17\5\17\u00bb\n\17\3\20\3\20\3\20\3\20\3\20"+
		"\3\20\3\20\3\20\3\20\3\20\5\20\u00c7\n\20\3\21\3\21\3\21\3\21\3\21\3\21"+
		"\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21"+
		"\3\21\3\21\3\21\3\21\3\21\3\21\3\21\3\21\5\21\u00e5\n\21\3\22\3\22\3\22"+
		"\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\5\22\u00f4\n\22\3\22"+
		"\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22"+
		"\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\7\22\u010e\n\22\f\22\16"+
		"\22\u0111\13\22\3\22\2\3\"\23\2\4\6\b\n\f\16\20\22\24\26\30\32\34\36 "+
		"\"\2\6\3\2\26\30\3\2\31\32\3\2\33\36\3\2\37 \2\u012c\2%\3\2\2\2\4/\3\2"+
		"\2\2\6\64\3\2\2\2\bD\3\2\2\2\nF\3\2\2\2\fQ\3\2\2\2\16[\3\2\2\2\20g\3\2"+
		"\2\2\22i\3\2\2\2\24m\3\2\2\2\26x\3\2\2\2\30\u00a0\3\2\2\2\32\u00ac\3\2"+
		"\2\2\34\u00ba\3\2\2\2\36\u00c6\3\2\2\2 \u00e4\3\2\2\2\"\u00f3\3\2\2\2"+
		"$&\5\4\3\2%$\3\2\2\2&\'\3\2\2\2\'%\3\2\2\2\'(\3\2\2\2()\3\2\2\2)*\7\2"+
		"\2\3*\3\3\2\2\2+,\5\6\4\2,-\5\4\3\2-\60\3\2\2\2.\60\5\6\4\2/+\3\2\2\2"+
		"/.\3\2\2\2\60\5\3\2\2\2\61\65\5\36\20\2\62\65\5\32\16\2\63\65\5\b\5\2"+
		"\64\61\3\2\2\2\64\62\3\2\2\2\64\63\3\2\2\2\65\7\3\2\2\2\66\67\7,\2\2\67"+
		"8\7%\2\289\7\3\2\29:\5\f\7\2:;\7\4\2\2;<\5\24\13\2<E\3\2\2\2=>\7,\2\2"+
		">?\7\5\2\2?@\7\3\2\2@A\5\f\7\2AB\7\4\2\2BC\5\24\13\2CE\3\2\2\2D\66\3\2"+
		"\2\2D=\3\2\2\2E\t\3\2\2\2FG\7%\2\2GH\7\3\2\2HI\5\20\t\2IJ\7\4\2\2J\13"+
		"\3\2\2\2KL\5\16\b\2LM\7\6\2\2MN\5\f\7\2NR\3\2\2\2OR\5\16\b\2PR\3\2\2\2"+
		"QK\3\2\2\2QO\3\2\2\2QP\3\2\2\2R\r\3\2\2\2ST\7,\2\2T\\\7%\2\2UV\7,\2\2"+
		"VW\7%\2\2W\\\7\7\2\2XY\7,\2\2YZ\7%\2\2Z\\\7\b\2\2[S\3\2\2\2[U\3\2\2\2"+
		"[X\3\2\2\2\\\17\3\2\2\2]^\7)\2\2^_\7\6\2\2_h\5\20\t\2`a\5\"\22\2ab\7\6"+
		"\2\2bc\5\20\t\2ch\3\2\2\2dh\7)\2\2eh\5\"\22\2fh\3\2\2\2g]\3\2\2\2g`\3"+
		"\2\2\2gd\3\2\2\2ge\3\2\2\2gf\3\2\2\2h\21\3\2\2\2ij\7\t\2\2jk\5\26\f\2"+
		"kl\7\n\2\2l\23\3\2\2\2mn\7\t\2\2no\5\26\f\2op\7\13\2\2pq\5\"\22\2qr\7"+
		"\f\2\2rs\7\n\2\2s\25\3\2\2\2tu\5\30\r\2uv\5\26\f\2vy\3\2\2\2wy\3\2\2\2"+
		"xt\3\2\2\2xw\3\2\2\2y\27\3\2\2\2z\u00a1\5\32\16\2{\u00a1\5\36\20\2|}\5"+
		"\n\6\2}~\7\f\2\2~\u00a1\3\2\2\2\177\u0080\7\r\2\2\u0080\u0081\7\3\2\2"+
		"\u0081\u0082\5\"\22\2\u0082\u0083\7\4\2\2\u0083\u0084\5\22\n\2\u0084\u00a1"+
		"\3\2\2\2\u0085\u0086\7\r\2\2\u0086\u0087\7\3\2\2\u0087\u0088\5\"\22\2"+
		"\u0088\u0089\7\4\2\2\u0089\u008a\5\22\n\2\u008a\u008b\7\16\2\2\u008b\u008c"+
		"\5\22\n\2\u008c\u00a1\3\2\2\2\u008d\u008e\7\17\2\2\u008e\u008f\7\3\2\2"+
		"\u008f\u0090\5\36\20\2\u0090\u0091\5\"\22\2\u0091\u0092\7\f\2\2\u0092"+
		"\u0093\5\32\16\2\u0093\u0094\7\4\2\2\u0094\u0095\5\22\n\2\u0095\u00a1"+
		"\3\2\2\2\u0096\u0097\7\20\2\2\u0097\u0098\7\3\2\2\u0098\u0099\5\"\22\2"+
		"\u0099\u009a\7\4\2\2\u009a\u009b\5\22\n\2\u009b\u00a1\3\2\2\2\u009c\u009d"+
		"\7\13\2\2\u009d\u009e\5\"\22\2\u009e\u009f\7\f\2\2\u009f\u00a1\3\2\2\2"+
		"\u00a0z\3\2\2\2\u00a0{\3\2\2\2\u00a0|\3\2\2\2\u00a0\177\3\2\2\2\u00a0"+
		"\u0085\3\2\2\2\u00a0\u008d\3\2\2\2\u00a0\u0096\3\2\2\2\u00a0\u009c\3\2"+
		"\2\2\u00a1\31\3\2\2\2\u00a2\u00a3\7%\2\2\u00a3\u00a4\7\21\2\2\u00a4\u00a5"+
		"\5\"\22\2\u00a5\u00a6\7\f\2\2\u00a6\u00ad\3\2\2\2\u00a7\u00a8\5\34\17"+
		"\2\u00a8\u00a9\7\21\2\2\u00a9\u00aa\5\"\22\2\u00aa\u00ab\7\f\2\2\u00ab"+
		"\u00ad\3\2\2\2\u00ac\u00a2\3\2\2\2\u00ac\u00a7\3\2\2\2\u00ad\33\3\2\2"+
		"\2\u00ae\u00af\7%\2\2\u00af\u00b0\7\22\2\2\u00b0\u00b1\5\"\22\2\u00b1"+
		"\u00b2\7\23\2\2\u00b2\u00b3\5\"\22\2\u00b3\u00b4\7\24\2\2\u00b4\u00bb"+
		"\3\2\2\2\u00b5\u00b6\7%\2\2\u00b6\u00b7\7\22\2\2\u00b7\u00b8\5\"\22\2"+
		"\u00b8\u00b9\7\24\2\2\u00b9\u00bb\3\2\2\2\u00ba\u00ae\3\2\2\2\u00ba\u00b5"+
		"\3\2\2\2\u00bb\35\3\2\2\2\u00bc\u00bd\7,\2\2\u00bd\u00be\5 \21\2\u00be"+
		"\u00bf\7\f\2\2\u00bf\u00c7\3\2\2\2\u00c0\u00c1\7,\2\2\u00c1\u00c2\7%\2"+
		"\2\u00c2\u00c3\7\21\2\2\u00c3\u00c4\5\"\22\2\u00c4\u00c5\7\f\2\2\u00c5"+
		"\u00c7\3\2\2\2\u00c6\u00bc\3\2\2\2\u00c6\u00c0\3\2\2\2\u00c7\37\3\2\2"+
		"\2\u00c8\u00c9\7%\2\2\u00c9\u00ca\7\22\2\2\u00ca\u00cb\7\'\2\2\u00cb\u00cc"+
		"\7\23\2\2\u00cc\u00cd\7\'\2\2\u00cd\u00ce\7\24\2\2\u00ce\u00cf\7\6\2\2"+
		"\u00cf\u00e5\5 \21\2\u00d0\u00d1\7%\2\2\u00d1\u00d2\7\22\2\2\u00d2\u00d3"+
		"\7\'\2\2\u00d3\u00d4\7\24\2\2\u00d4\u00d5\7\6\2\2\u00d5\u00e5\5 \21\2"+
		"\u00d6\u00d7\7%\2\2\u00d7\u00d8\7\6\2\2\u00d8\u00e5\5 \21\2\u00d9\u00da"+
		"\7%\2\2\u00da\u00db\7\22\2\2\u00db\u00dc\7\'\2\2\u00dc\u00dd\7\23\2\2"+
		"\u00dd\u00de\7\'\2\2\u00de\u00e5\7\24\2\2\u00df\u00e0\7%\2\2\u00e0\u00e1"+
		"\7\22\2\2\u00e1\u00e2\7\'\2\2\u00e2\u00e5\7\24\2\2\u00e3\u00e5\7%\2\2"+
		"\u00e4\u00c8\3\2\2\2\u00e4\u00d0\3\2\2\2\u00e4\u00d6\3\2\2\2\u00e4\u00d9"+
		"\3\2\2\2\u00e4\u00df\3\2\2\2\u00e4\u00e3\3\2\2\2\u00e5!\3\2\2\2\u00e6"+
		"\u00e7\b\22\1\2\u00e7\u00e8\7\25\2\2\u00e8\u00f4\5\"\22\21\u00e9\u00f4"+
		"\7(\2\2\u00ea\u00f4\7\'\2\2\u00eb\u00f4\5\n\6\2\u00ec\u00f4\5\34\17\2"+
		"\u00ed\u00f4\7&\2\2\u00ee\u00f4\7%\2\2\u00ef\u00f0\7\3\2\2\u00f0\u00f1"+
		"\5\"\22\2\u00f1\u00f2\7\4\2\2\u00f2\u00f4\3\2\2\2\u00f3\u00e6\3\2\2\2"+
		"\u00f3\u00e9\3\2\2\2\u00f3\u00ea\3\2\2\2\u00f3\u00eb\3\2\2\2\u00f3\u00ec"+
		"\3\2\2\2\u00f3\u00ed\3\2\2\2\u00f3\u00ee\3\2\2\2\u00f3\u00ef\3\2\2\2\u00f4"+
		"\u010f\3\2\2\2\u00f5\u00f6\f\20\2\2\u00f6\u00f7\t\2\2\2\u00f7\u010e\5"+
		"\"\22\21\u00f8\u00f9\f\17\2\2\u00f9\u00fa\t\3\2\2\u00fa\u010e\5\"\22\20"+
		"\u00fb\u00fc\f\16\2\2\u00fc\u00fd\t\4\2\2\u00fd\u010e\5\"\22\17\u00fe"+
		"\u00ff\f\r\2\2\u00ff\u0100\t\5\2\2\u0100\u010e\5\"\22\16\u0101\u0102\f"+
		"\f\2\2\u0102\u0103\7!\2\2\u0103\u010e\5\"\22\r\u0104\u0105\f\13\2\2\u0105"+
		"\u0106\7\"\2\2\u0106\u010e\5\"\22\f\u0107\u0108\f\n\2\2\u0108\u0109\7"+
		"#\2\2\u0109\u010a\5\"\22\2\u010a\u010b\7$\2\2\u010b\u010c\5\"\22\13\u010c"+
		"\u010e\3\2\2\2\u010d\u00f5\3\2\2\2\u010d\u00f8\3\2\2\2\u010d\u00fb\3\2"+
		"\2\2\u010d\u00fe\3\2\2\2\u010d\u0101\3\2\2\2\u010d\u0104\3\2\2\2\u010d"+
		"\u0107\3\2\2\2\u010e\u0111\3\2\2\2\u010f\u010d\3\2\2\2\u010f\u0110\3\2"+
		"\2\2\u0110#\3\2\2\2\u0111\u010f\3\2\2\2\22\'/\64DQ[gx\u00a0\u00ac\u00ba"+
		"\u00c6\u00e4\u00f3\u010d\u010f";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}