
#include "Tape.hpp"
#include <vector>
#include <iostream>

Tape::Tape() : _tape(std::vector<unsigned char>(1, 0)), _index(0) {}

void Tape::plus() {
	if (_tape[_index] != 255)
		_tape[_index]++;
	else
		_tape[_index] = 0;
}

void Tape::minus() {
	if (_tape[_index] != 0)
		_tape[_index]--;
	else
		_tape[_index] = 255;
}

void Tape::left() {
	if(_index != 0)
		_index--;
}

void Tape::right() {
	if (_index == _tape.size() - 1)
		_tape.push_back(0);
	_index++;
}

char Tape::output() {
	return _tape[_index];
}

void Tape::input(unsigned char in) {
	_tape[_index] = in;
}

bool Tape::isZero() {
	return _tape[_index] == 0;
}