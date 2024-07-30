#include "trixsignal.hpp"
#include "signal.hpp"
#include <iostream>
#include <string>

namespace Prog2B {
	Vector Vector::operator +=(Vector& obj) {
		for (int i = 0; i < n; i++) {
			if (array[i].getC() != obj.array[i].getC()) {
				array[i].setC(Prog2::MyEnum::UNDEF);
			}
			array[i].setD(obj.array[i].get_duration() + array[i].get_duration());
		}
		return *this;
	}

	Vector Vector::operator =(Vector& obj) {
		copasity = obj.copasity;
		for (int i = 0; i < obj.copasity; i++) {
			array[i].setC(obj.array[i].getC());
			array[i].setD(obj.array[i].get_duration());
		}
		return *this;
	}

	Vector Vector::operator >>(int time) {
		for (int i = 0; i < n; i++) array[i].increase(time);
		return *this;
	}

	Vector Vector::operator <<(int time) {
		for (int i = 0; i < n; i++) {
			if (array[i].get_duration() < time)array[i].setD(0);
			else array[i].decrease(time);
		}
		return *this;
	}

	Vector Vector::operator *(int time) {
		if (time * copasity > n) {
			std::cout << "Table overflow" << std::endl;
			return *this;
		}
		for (int i = 1; i < time; i++) {
			for (int j = 0; j < copasity; j++) {
				array[(copasity - 1) * i + j + 1] = array[j];
			}
		}
		copasity *= time;
		return *this;
	}



	void Vector::change(int time, Vector obj) {
		int summ = 0, num = n, i;
		try {
			for (i = 0; i < n; i++) {
				summ += array[i].get_duration();
				if (summ < time)array[i] = obj.array[i];
				else if (summ == time) {
					array[i] = obj.array[i];
					i++;
					break;
				}
				else {
					array[i].setD(summ - time);
					break;
				}
			}
			int k = copasity + obj.copasity - i - 1;
			if (n - copasity + i < obj.copasity) throw std::runtime_error("Not enought place for new diagram");
			for (int j = k; j > i; j--)array[j] = array[j - obj.copasity + i];
			for (; i < obj.copasity; i++) {
				array[i] = obj.array[i];
				copasity++;
			}
		}
		catch (std::runtime_error& e) {
			std::cout << e.what() << std::endl;
		}
		catch (...) {
			if (std::cin.eof()) {
				throw std::runtime_error("Failed to read message: EOF");
			}
		}

	}
}
