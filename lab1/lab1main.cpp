#include <iostream>
#include "func.h"
using namespace Matr;
int main(){
    Matrix m;
    m.m=0;
    m.count=0;
    double* res=nullptr;
    int a;
    try {
        std::cout << "Make the choice" << std::endl;
        while(true){
            std::cout << "0- Exit\n1- Create matrix\n2- Output matrix\n3- Create array\n" << std::endl;
            a=getNum<int>(0, 3);
            switch (a){
                case 0:
                    destructor(m);
                    Array::destructor(res);
                    return 0;  
                case 1:
                    input(m);
                    break;
                case 2:
                    output(m);
                    break;
                case 3:
                    findres(m, res);
                    Array::output(res, m.m);
                    Array::destructor(res);
                    break;

                default:
                    break;
            }
        }
    }
    catch(const std::bad_alloc& ){
        std::cerr << "Not enough memory" << std::endl;
        destructor(m);
        Array::destructor(res);
    }
    catch(const std::exception& e){
        std::cerr << e.what() <<std::endl;
        destructor(m);
        Array::destructor(res);
    }
    return 0;
}