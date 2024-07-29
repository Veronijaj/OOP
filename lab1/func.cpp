#include <iostream>
#include "func.h"
//#include <vld.h>
namespace Matr{
    void input(Matrix& matrix){
        try{
            std::cout <<"Enter number of rows: "<< std::endl;
            matrix.m = getNum<int>(0);
            std::cout <<"Enter number of columns: "<< std::endl;
            matrix.n = getNum<int>(0);
            int capacity=matrix.n;
            matrix.data = new Element[capacity]();//calloc
           //  Element* data = matrix.data;
            for(int i=0; i<matrix.m; i++){
                for(int j=0; j<matrix.n; j++){
                   // std::cout <<"Enter number of number: ";
                    double tmp = getNum<double>(0);
                    if(tmp!=0){
                        if(capacity==matrix.count){
                            capacity+=matrix.n;
                            Element* array=new Element[capacity];
                            std::copy(matrix.data, matrix.data+matrix.count, array);
                            delete[] matrix.data;
                            matrix.data=array;
                        }
                        matrix.data[matrix.count].column=j;
                        matrix.data[matrix.count].row=i;
                        matrix.data[matrix.count].value=tmp;
                        matrix.count++;
                    }
                }
            }
            if(capacity!=matrix.count){
                Element *array = new Element[matrix.count];
                std::copy(matrix.data, matrix.data + matrix.count, array);
                delete[] matrix.data;
                matrix.data = array;
            }
        }
        catch(...){
            Matr::destructor(matrix);
            throw;
        }
    }

    void output(const Matrix m){
        int count=0;
        for(int i=0; i<m.m; i++){
            for(int j=0; j<m.n; j++){
                if(m.data[count].row==i && m.data[count].column==j){
                    std::cout << m.data[count].value << " ";
                    count++;
                }
                else std::cout << "0 ";
            }
            std::cout <<"\n";
        }
    }


    void destructor(Matrix& m){
        if(m.data!=nullptr) delete[] m.data;
        m.count=0;
        m.m=0;
        m.n=0;
        m.data= nullptr;
    }

    void findres(const Matrix m, double*& array){
        int size=m.count;
        if(m.count!=0){
        array = new double[m.m];
            double start;
            start=m.data[0].value;
            double summ;
            int j=0;
            for(int i=0; i<m.m; i++){
                double maxi=start;
                int flag=0;
                summ=0;
                for(;j<size;j++){
                    if(m.data[j].row==i){
                        if(m.data[j].column==0){
                            flag=1;
                            maxi=0;
                        }
                        if(maxi<m.data[j].value && flag==1)maxi=m.data[j].value;
                        summ+=m.data[j].value;
                    }
                    else break;
                }
                array[i]=summ/(m.n*maxi);
            }
        }
        else{
           // std::cout <<"inf\n";
        }
        //return array;
    }
}

namespace Array{

    void output(const double* array, int size){
        if(array==nullptr)std::cout << "inf\n";
        else{
            for(int i=0; i<size; i++){
                std::cout << array[i] << " ";
            }
        }
        std::cout << "\n";
    }

    void destructor(double*& array){
        if(array!=nullptr) delete[] array;
        array=nullptr;
    }
}