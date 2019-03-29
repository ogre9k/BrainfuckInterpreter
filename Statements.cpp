#include "Statements.hpp"
void die(std::string where, std::string message, Token &token) {
	std::cout << where << " " << message << std::endl;
	token.print();
	std::cout << std::endl;
	exit(1);
}

// Statement
Statement::Statement(Token op): _op(op) {}

// Statements

Statements::Statements() {}
void Statements::addStatement(Statement *statement) { _statements.push_back(statement); }

void Statements::print() {
	for (auto s : _statements)
		s->print();
}

void Statements::evaluate(Tape &tape) {
	for (auto s : _statements)
		s->evaluate(tape);
}

// Simple Statements

SimpleStatement::SimpleStatement(Token op) : Statement(op) {}

void SimpleStatement::evaluate(Tape &tape) {
	if (_op.isPlus())
		tape.plus();
	else if (_op.isMinus())
		tape.minus();
	else if (_op.isLeftArrow())
		tape.left();
	else if (_op.isRightArrow())
		tape.right();
	else if (_op.isPeriod())
		std::cout << tape.output();
	else if (_op.isComma()) {
		unsigned char x;
		std::cin >> x;
		tape.input(x);
	}
	else
		die("SimpleStatement::evaluate", "Token is not a valid simple statement operator: ", _op);
}

void SimpleStatement::print() {
	_op.print();
}

// LoopStatement

LoopStatement::LoopStatement(Token op, Statements* statements) : Statement(op) { _statements = statements; }

void LoopStatement::evaluate(Tape &tape) {
	while (!tape.isZero()) {
		_statements->evaluate(tape);
	}
}

void LoopStatement::print() {
	_op.print();
	_statements->print();
}