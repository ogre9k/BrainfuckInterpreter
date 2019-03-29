#include <iostream>
#include "Token.hpp"


Token::Token() : _symbol('\0'), _eof(false) {}

void Token::print() const {
	if (eof()) std::cout << "EOF";
	else if (isLeftArrow()) std::cout << "<";
	else if (isRightArrow()) std::cout << ">";
	else if (isLeftBracket()) std::cout << "[";
	else if (isRightBracket()) std::cout << "]";
	else if (isPlus()) std::cout << "+";
	else if (isMinus()) std::cout << "-";
	else if (isPeriod()) std::cout << ".";
	else if (isComma()) std::cout << ",";
	else std::cout << "Uninitialized token.\n";
}