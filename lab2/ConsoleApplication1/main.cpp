#include <iostream>
#include <string>
#include "signal.h"
#include "trixsignal.h"
#include "dialog.h"

using namespace Prog2B;
int main() {
	int rc;
	const std::string choice[] = { "0- Exit", "1- Constructor", "2- Constructor of state and duration","3- Constructor with string initialization",
	"4- Join diagram with random diagram", "5- Replace the time interval with another diagram", "6- Shift the diagram to the right",
	"7- Shift the diagram to the left","8- Multiply the diagram",
	"9- Output to the stream",
	"10- Input to the stream" };
	const int N = sizeof(choice) / sizeof(choice[0]);
	void(*fptr[])(Vector&) = { nullptr, D_CONST1, D_CONST2, D_CONST3, D_JOIN, D_REPLACE, D_RIGHT, D_LEFT, D_DOUBLE, D_OUTPUT, D_INPUT };
	Vector obj;
	try {
		while (rc = dialog(choice, N)) {
			fptr[rc](obj);
		}
	}
	catch (...) {
		std::cout << "Thanks! Goodbye!";
		return 0;
	}
	std::cout << "Thanks! Goodbye!";
	return 0;
}