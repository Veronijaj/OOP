#pragma once
#ifndef FUNCB_H
#define FUNCB_H
#include <iostream>
#include <string>
#include "signal.hpp"

namespace Prog2B {
	class Vector {
	private:
		static const int n = 20;
		Prog2::Signal array[n];
		int copasity;
	public:
		Vector() { copasity = 0; }

		Vector(int arr1, int arr2) {
			copasity = n;
			for (int i = 0; i < n; i++) {
				array[i].setC((Prog2::MyEnum)arr1);
				array[i].setD(arr2);
			}
		}

		Vector(std::string str) {
			int c, count = 1, num = 0;
			size_t size = str.size();
			if (str[0] == '~')c = 1;
			else if (str[0] == '_')c = 0;
			else if (str[0] == '-')c = 2;
			else throw std::runtime_error(std::string("Failed to read message:"));
			array[num].setC((Prog2::MyEnum)c);
			array[num].setD(count);
			for (int i = 1; i < size + 1; i++) {
				if (i == size || str[i] != str[i - 1]) {
					array[num].setC((Prog2::MyEnum)c);
					array[num].setD(count);
					num++;
					count = 0;
					if (i == size) break;
					if (n == num)throw std::logic_error("Vector overflow!");
					if (str[i] == '~')c = 1;
					else if (str[i] == '_')c = 0;
					else if (str[i] == '-')c = 2;
					else throw std::runtime_error(std::string("Failed to read message:"));
				}
				count++;
			}
			copasity = num;
		}
		Vector(int size) {
			for (int i = 0; i < size; i++) {
				array[i].setC((Prog2::MyEnum)(rand() % 3));
				array[i].setD(rand() % 50);
			}
			copasity = size;
		}
		int getTop() const { return copasity; }
		Vector operator +=(Vector&);
		Vector operator =(Vector&);
		Vector operator >>(int);
		Vector operator <<(int);
		friend std::ostream& operator <<(std::ostream& os, Vector& v) {
			for (int i = 0; i < v.copasity; i++) {
				os << v.array[i];
			}
			return os;
		}
		Vector operator *(int time);
		void change(int, Vector);
		friend std::istream& operator >>(std::istream& os, Vector& v) {
			v.copasity = 0;
			int k;
			std::cout << "Enter number of signals: ";
			k = getNum<int>(0, v.n);
			for (int i = 0; i < k; i++) {
				std::cout << "Enter the state and then duration: ";
				while (1) {
					os >> v.array[i];
					if (std::cin.eof()) {
						throw std::runtime_error("Failed to read number: EOF");
					}
					else if (std::cin.bad()) throw std::runtime_error(std::string("Failed to read number:"));
					else if (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cout << "You are wrong, repeat please!" << std::endl;
					}
					else if (v.array[i].getC() >= 0 && v.array[i].getC() <= 2) {
						v.copasity++;
						break;
					}
					else
						std::cout << "Invalid value" << std::endl;
				}
			}
			return os;
		}
	};
}


#endif
