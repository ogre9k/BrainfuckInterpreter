#include<vector>
#include<iostream>

#include "Token.hpp"
#include "Parser.hpp"
#include "Statements.hpp"

// Parser functions
void Parser::die(std::string where, std::string message, Token &token) {
	std::cout << where << " " << message << std::endl;
	token.print();
	std::cout << std::endl;
	std::cout << "\nThe following is a list of tokens that have been identified up to this point.\n";
	tokenizer.printProcessedTokens();
	int test;
	std::cin >> test;
	exit(1);
}

Statements *Parser::statements() {
	// This function is called when we KNOW that we are about to parse
	// a series of assignment statements.


	Statements *stmts = new Statements();
	Token tok = tokenizer.getToken();

	if (tok.isRightBracket()) 
		die("Parser::statements", "] without a matching [ detected", tok);

	while (!tok.eof() && !tok.isRightBracket()) {
		tokenizer.ungetToken();
		if (tok.isLeftBracket()) {
			LoopStatement *loopStmt = loopStatement();
			stmts->addStatement(loopStmt);
		}
		else {
			SimpleStatement *simpleStmt = simpleStatement();
			stmts->addStatement(simpleStmt);
		}
		tok = tokenizer.getToken();
	}

	tokenizer.ungetToken();
	return stmts;
}

SimpleStatement *Parser::simpleStatement() {
	return new SimpleStatement(tokenizer.getToken());
}

LoopStatement *Parser::loopStatement() {
	Token tok = tokenizer.getToken();
	if (!tok.isLeftBracket())
		die("Parser::loopStatement", "Expected a [, got a ", tok);
	
	Parser parser(tokenizer);
	Statements *statements = parser.statements();

	tok = tokenizer.getToken();
	if (!tok.isRightBracket())
		die("Parser::loopStatement", "Expected a ], got a ", tok);

	return new LoopStatement(tok, statements);
}