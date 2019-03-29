#pragma once
#include <iostream>
#include <vector>
#include "Tape.hpp"
#include "Token.hpp"
// The Statement (abstract) class serves as a super class for all statements that
// are defined in the language. Ultimately, statements have to be evaluated.
// Therefore, this class defines evaluate, a pure-virtual function to make
// sure that all subclasses of Statement provide an implementation for this
// function.

class Statement {
public:
	Statement(Token op);

	virtual void print() = 0;
	virtual void evaluate(Tape &tape) = 0;

protected:
	Token _op;
};


// Statements is a collection of Statement. For example, all statements in a function
// can be represented by an instance of Statements.

class Statements {
public:
	Statements();

	void addStatement(Statement *statement);
	void evaluate(Tape &tape);
	void print();

private:
	std::vector<Statement *> _statements;
};

class SimpleStatement: public Statement {
public:
	SimpleStatement(Token op);

	virtual void evaluate(Tape &tape);
	virtual void print();

};

class LoopStatement : public Statement {
public:
	LoopStatement(Token op, Statements *statements);

	virtual void evaluate(Tape &tape);
	virtual void print();

private:
	Statements *_statements;
};