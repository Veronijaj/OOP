#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <limits>
#include <string>
#include <cstring>

namespace Matr{
    struct Element{
        double value;
        int column;
        int row;
    };

    struct Matrix{
        int count = 0;
        int m=0;
        int n=0;
        Element* data = nullptr;
    };

    template <class Type>
    Type getNum(Type min = std::numeric_limits<Type>::min(), Type max = std::numeric_limits<Type>::max()){
        Type num;
        while (1){
            std::cin >> num;
            if (std::cin.eof()){
                throw std::runtime_error("Failed to read number: EOF");
            }
            else if(std::cin.bad()) throw std::runtime_error(std::string("Failed to read number:"));
            else if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout <<"You are wrong, repeat please!" << std::endl;
            }
            else if(num >= min && num <= max) return num;
            else
                std::cout << "You are wrong, repeat please!" << std::endl;
        }    
    }
    void input(Matrix& matrix);
    void findres(const Matrix matrix, double*& res);
    void destructor(Matrix& matrix);
    void output(const Matrix matrix);
}

namespace Array{
    void output(const double* array, int k);
    void destructor(double*& array);
}

#endif