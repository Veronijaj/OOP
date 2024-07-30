#pragma once
#ifndef DIALOGB_H
#define DIALOGB_H
#include <iostream>
#include <string>
#include "trixsignal.hpp"
#include "signal.hpp"
using namespace Prog2B;
int dialog(const std::string choice[], int N) {
	int rc;
	int i;
	do {
		for (i = 0; i < N; ++i) std::cout << choice[i] << std::endl;
		std::cout << "Make your choice: --> ";
		rc = getNum<int>(0, N - 1);
		if (std::cin.eof()) {
			//rc = 0;
			throw std::runtime_error("Failed to read number: EOF");
		}
		else if (std::cin.bad()) throw std::runtime_error(std::string("Failed to read number:"));
		else if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "You are wrong, repeat please!" << std::endl;
		}
	} while (rc < 0 || rc >= N);
	return rc;
}

void D_CONST1(Vector& s) {
	Vector oo;
	s = oo;
}

void D_CONST2(Vector& s) {
	std::cout << "State: --> ";
	int res = getNum<int>(0, 2);
	std::cout << "Duration: --> ";
	int res2 = getNum<int>(0);
	Vector oo(res, res2);
	s = oo;
}

void D_CONST3(Vector& s) {
	std::string str;
	while (true) {
		std::cin >> str;
		if (std::cin.eof()) {
			throw std::runtime_error("Failed to read message: EOF");
		}
		try {
			Vector oo(str);
			s = oo;
			break;
		}
		catch (std::runtime_error& msg) {
			std::cin.clear();
			std::cout << msg.what() << std::endl;
		}
		catch (std::logic_error& m) {
			std::cout << m.what() << std::endl;
		}
	}
}

void D_JOIN(Vector& s) {
	Vector obj;
	std::cout << "Enter the string with initialization: ";
	D_CONST3(obj);
	s += obj;
	//s.output(std::cout);
}

void D_REPLACE(Vector& s) {
	Vector obj;
	std::cout << "Enter the string with initialization: ";
	D_CONST3(obj);
	std::cout << "Enter the time of change: ";
	int k = getNum<int>(0);
	s.change(k, obj);
	//s.output(std::cout);
}

void D_DOUBLE(Vector& s) {
	std::cout << "Enter the number of double: ";
	int res = getNum<int>(1);
	s* res;
	//	s.output(std::cout);
}

void D_RIGHT(Vector& s) {
	std::cout << "Enter the time of right shift: " << std::endl;
	int res = getNum<int>(0);
	s >> res;
}

void D_LEFT(Vector& s) {
	std::cout << "Enter the time of left shift: " << std::endl;
	int res = getNum<int>(0);
	s << res;
}

void D_INPUT(Vector& s) {
	int k;
	std::cin >> s;
	//return s;
}

void D_OUTPUT(Vector& s) {
	std::cout << s;
	//s.output(std::cout);
}

#endif

