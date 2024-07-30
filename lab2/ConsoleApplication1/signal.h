#pragma once
#ifndef FUNC_H
#define FUNC_H
#include <iostream>
#include <string>

template <class T>
T getNum(T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max()) {
	T num;
	while (1) {
		std::cin >> num;
		if (std::cin.eof()) {
			throw std::runtime_error("Failed to read number: EOF");
		}
		else if (std::cin.bad()) throw std::runtime_error(std::string("Failed to read number:"));
		else if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "You are wrong, repeat please!" << std::endl;
		}
		else if (num >= min && num <= max) return num;
		else
			std::cout << "Invalid value" << std::endl;
	}
}
namespace Prog2 {
	enum MyEnum {
		OFF,
		ON,
		UNDEF
	};

	class Signal {
	private:
		int duration;
		MyEnum condition;
	public:
		explicit Signal() : condition(UNDEF), duration(0) {};
		Signal(MyEnum c, int d) : condition(c), duration(d) {};
		Signal(std::string& str) { findres(str); };
		Signal& setC(MyEnum c) { condition = c; return*this; }
		Signal& setD(int);

		int increase(int d) {
			duration += d;
			return duration;
		}
		int decrease(int d) {
			duration -= d;
			return duration;
		}

		Signal& input() {
			int k = getNum<int>();
			condition = (MyEnum)k;
			duration = getNum<int>();
		}

		bool operator==(const Signal& obj1) const;
		Signal& devide(int time);
		const MyEnum getC() const { return condition; }
		int get_duration() const { return duration; }
		void findres(std::string& res);
		void const format();
		friend std::ostream& operator << (std::ostream& os, const Signal& s) {
			//У<<Ф дл€ вывода экземпл€ра простого класса в выходной поток;
			return os << "State: " << s.getC() << " Duration: " << s.get_duration() << std::endl;
		}
		friend std::istream& operator>> (std::istream& os, Signal& s) {
			//У>>Ф дл€ ввода экземпл€ра простого класса из входного потока;
			int str, k;
			str = getNum<int>(0, 2);
			k = getNum<int>(0);
			s.setD(k);
			if (os.good()) {
				if (s.get_duration() >= 0) {
					if (str == 0) s.setC(OFF);
					else if (str == 1)s.setC(ON);
					else if (str == 2)s.setC(UNDEF);
					else os.setstate(std::ios::failbit);
				}
				else os.setstate(std::ios::failbit);
			}
			return os;
		}
	};
}

#endif

