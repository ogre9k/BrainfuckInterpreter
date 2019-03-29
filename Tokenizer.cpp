#include <iostream>
#include "Tokenizer.hpp"

bool isComment(char c);

Tokenizer::Tokenizer(std::ifstream &stream) : ungottenToken{ false }, inStream{ stream }, lastToken{} {}

Token Tokenizer::getToken() {

	if (ungottenToken) {
		ungottenToken = false;
		return lastToken;
	}

	char c;
	Token token;
	while (inStream.get(c) && isComment(c))
		;

	if (inStream.eof())
		token.eof() = true;
	else if (c == '<')
		token.symbol('<');
	else if (c == '>')
		token.symbol('>');
	else if (c == '[')
		token.symbol('[');
	else if (c == ']')
		token.symbol(']');
	else if (c == '+')
		token.symbol('+');
	else if (c == '-')
		token.symbol('-');
	else if (c == '.')
		token.symbol('.');
	else if (c == ',')
		token.symbol(',');
	else {
		std::cout << "Unknown character in input";
		exit(1);
	}
	_tokens.push_back(token);
	return lastToken = token;
}

bool isComment(char c) {
	return (c != '<' && c != '>' && c != '[' && c != ']' && c != '+' && c != '-' && c != '.' && c != ',');
}

void Tokenizer::ungetToken() {
	ungottenToken = true;
}

void Tokenizer::printProcessedTokens() {
	for (auto iter = _tokens.begin(); iter != _tokens.end(); ++iter) {
		iter->print();
		std::cout << std::endl;
	}
}