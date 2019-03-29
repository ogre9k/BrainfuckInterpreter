#pragma once

#include <vector>

// This class represents the Tape of values in a BF program

class Tape {

public:
	Tape();
	void plus();
	void minus();
	void left();
	void right();
	char output();
	void input(unsigned char c);
	bool isZero();

private:
	std::vector<unsigned char> _tape;
	int _index;
};