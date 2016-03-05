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
    //default values for calling Triangle, basic equilateral
    sideOne = (T) 1;
    sideTwo = (T) 1;
    sideThree = (T) 1;
}

template<class T>
Triangle<T>::Triangle(const T side1, const T side2, const T side3) {
        //check if values are able to create a valid triangle
        if((side1 + side2 > side3) && (side1+side3>side2) && (side2+side3>side1)) {
            sideOne = side1;
            sideTwo = side2;
            sideThree = side3;
        }
        //set valid values to the triangle if input values are invalid for making a triangle
        else{
            setSides((T)1,(T)1,(T)1); //basic equilateral
        }
}

template<class T>
void Triangle<T>::setSides(T newSide1, T newSide2, T newSide3) {
        //check if values are able to create a valid triangle
        if ((newSide1 + newSide2 > newSide3) && (newSide1 + newSide3 > newSide2) && (newSide2 + newSide3 > newSide1)) {
                sideOne = newSide1;
                sideTwo = newSide2;
                sideThree = newSide3;
        }
            else{
                cout<<"Invalid values for a triangle, cannot set new sides"<<endl;
            }
}

template<class T>
std::vector<T> Triangle<T> ::getSides() const {
    std::vector<T> triVector {sideOne, sideTwo, sideThree};
    return triVector;
}
template<class T>
T Triangle<T>::getArea() const {
    T x = (sideOne + sideTwo + sideThree) / 2;
    T area = sqrt(x * (x - sideOne) * (x - sideTwo) * (x - sideThree));
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

    if((temp1==sideThree) || (temp2==sideOne) || (temp3==sideTwo)) {
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
