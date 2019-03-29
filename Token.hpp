#pragma once

#include <string>

class Token {

public:
	Token();

	// Set symbol
	void symbol(char c) { _symbol = c; }
	// Get symbol
	char symbol() { return _symbol; }

	// Symbol checkers
	bool &eof() { return _eof; }
	bool eof() const { return _eof; }
	bool isLeftArrow() const { return _symbol == '<'; }
	bool isRightArrow() const { return _symbol == '>'; }
	bool isLeftBracket() const { return _symbol == '['; }
	bool isRightBracket() const { return _symbol == ']'; }
	bool isPlus() const { return _symbol == '+'; }
	bool isMinus() const { return _symbol == '-'; }
	bool isPeriod() const { return _symbol == '.'; }
	bool isComma() const { return _symbol == ','; }

	void print() const;
private:
	char _symbol;
	bool _eof;
};