//
// Created by Omar Shaikh on 2/23/16.
//

#ifndef HW3_TRIANGLE_H
#define HW3_TRIANGLE_H
/** Header file for the class Triangle. */

#include <vector>
#include <cmath>
#include <iostream>
#include "triangle_interface.h"


using namespace std;

template<class T>
class Triangle : public triangleInterface<T> {
private:
    //data fields --> 3 sides of the triangle
    T sideOne, sideTwo, sideThree;

public:
    //default constructor
    Triangle();

    //parameterized constructor
    Triangle(const T side1, const T side2, const T side3);

/** Sets or modifies the sides of this triangle. Ensures that the new sides form a triangle. */
    void setSides(T newSide1, T newSide2, T newSide3);

    /** Gets the three sides of this triangle.
     * @return A vector containing the values of the sides. */
     std::vector<T> getSides() const;

    /** Computes the area of this triangle. @return This triangle's area. */
     T getArea() const;

    /** Computes the perimeter of this triangle. @return This triangle's perimeter. */
     T getPerimeter() const;

    /** @return True if this triangle is a right triangle. */
     bool isRightTriangle() const;

    /** @return True if this triangle is an equilateral triangle. */
     bool isEquilateral() const;

    /** @return True if this triangle is an isosceles triangle. */
     bool isIsosceles() const;


};// end Triangle

template<class T>
Triangle<T>::Triangle() {
    //default values for calling Triangle
    sideOne = (T) 1;
    sideTwo = (T) 1;
    sideThree = (T) 1;
}

template<class T>
Triangle<T>::Triangle(const T side1, const T side2, const T side3) {
    if(abs(side1)>0 && abs(side2)>0 && abs(side3)>0 ) { //cannot have vector triangle if a magnitude == 0
        sideOne = side1;
        sideTwo = side2;
        sideThree = side3;
    }
    else{
        cout<<"Please check your values, all lengths of your triangle sides must all be more than 0 \n";
    }
}

template<class T>
void Triangle<T>::setSides(T newSide1, T newSide2, T newSide3) {
    if (abs(newSide1) > 0 && abs(newSide2) > 0 && abs(newSide3) > 0) { //cannot have vector triangle if a magnitude == 0
        if ((sideOne + sideTwo > sideThree) && (sideOne + sideThree > sideTwo) && (sideTwo + sideThree > sideOne)) {
            sideOne = newSide1;
            sideTwo = newSide2;
            sideThree = newSide3;
        }
    }
    else{
        Triangle();
    }

}

template<class T>
std::vector<T> Triangle<T> ::getSides() const {
    std::vector<T> triVector {sideOne, sideTwo, sideThree};
    return triVector;
}
template<class T>
T Triangle<T>::getArea() const {
    T x= (sideOne+sideTwo+sideThree)/2;
    T area = sqrt(x*(x-sideOne)*(x-sideTwo)*(x-sideThree));
    return area;
}

template<class T>
T Triangle<T>::getPerimeter() const {
    return (sideOne+sideTwo+sideThree);
}

template<class T>
bool Triangle<T>::isRightTriangle() const {
    float temp1 = sqrt((sideOne*sideOne) + (sideTwo*sideTwo));
    float temp2 = sqrt((sideTwo*sideTwo) + (sideThree*sideThree));
    float temp3 = sqrt((sideOne*sideOne) + (sideThree*sideThree));

    if(temp1==sideThree) {
        return true;
    }
    else if(temp2==sideOne){
        return true;
    }
    else if(temp3==sideTwo){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
bool Triangle<T>::isEquilateral() const {
    if(sideOne==sideTwo&& sideOne == sideThree){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
bool Triangle<T>::isIsosceles() const {
    if(sideOne==sideTwo&& sideOne!=sideThree){
        return true;
    }
    else if(sideOne==sideThree&& sideOne!=sideTwo){
        return true;
    }
    else if(sideTwo==sideThree&& sideTwo!=sideOne){
        return true;
    }
    else{
        return false;
    }
}

#endif //HW3_TRIANGLE_H
