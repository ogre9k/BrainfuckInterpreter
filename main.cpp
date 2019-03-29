#include <iostream>
#include <vector>

#include "Token.hpp"
#include "Tokenizer.hpp"
#include "Tape.hpp"
#include "Parser.hpp"
#include "Statements.hpp"

bool debug = true;

int main(int argc, char *argv[]) {

	/*
	if (argc != 2) {
		std::cout << "usage: " << argv[0] << " nameOfAnInputFile\n";
		exit(1);
	}
	*/

	std::ifstream inputStream;

	inputStream.open("test.txt", std::ios::in);
	if (!inputStream.is_open()) {
		std::cout << "Unable to open " << argv[1] << ". Terminating...";
		perror("Error when attempting to open the input file.");
		exit(2);
	}


	Tokenizer tokenizer(inputStream);
	Parser parser(tokenizer);
	Statements *statements = parser.statements();
	Tape tape;
	//tokenizer.printProcessedTokens();
	statements->evaluate(tape);
	std::cout << "\n---MEMORY MAP---\n";
	tape.print();

	return 0;
}