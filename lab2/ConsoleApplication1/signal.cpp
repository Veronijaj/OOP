#include "signal.hpp"
#include <iostream>
#include <string>

namespace Prog2 {
	void Signal::findres(std::string& str) {
		int size = (int)str.size(), res(1);
		if (str[0] == '1') Signal::condition = ON;
		if (str[0] == '0') Signal::condition = OFF;
		else Signal::condition = UNDEF;
		for (int i = 1; i < size && str[i] == str[i - 1]; i++) {
			if (str[i] == '1') Signal::condition = ON;
			else if (str[i] == '0') Signal::condition = OFF;
			else Signal::condition = UNDEF;
			res++;
		}
		Signal::duration = res;
	}

	void const Signal::format() {
		char c;
		if (Signal::condition == ON) c = '~';
		if (Signal::condition == OFF)c = '_';
		else c = '-';
		for (int i = 0; i < Signal::duration; i++)std::cout << c << ' ';
		std::cout << std::endl;
	}

	Signal& Signal::devide(int time) {
		if (Signal::duration < time) throw std::out_of_range("Exceeding the time limit");
		Signal obj1(Signal::condition, Signal::duration - time);
		this->setD(time);
		return obj1;
	}

	Signal& Signal::setD(int d) {
		this->duration = d;
		return*this;
	}
}
