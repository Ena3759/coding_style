/*!
    @file
    @brief A file with a description of the methods of the Complex class
*/

#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/*!
    @brief class constructor
    @param a_re Real  component
    @param a_im Imaginary component
*/
Complex::Complex( double aRe, double aIm )
{
    Re = aRe;
    Im = aIm;
}

/*!
    @brief class constructor
    @param complex_num Complex number
*/
Complex::Complex( const Complex& aRval )
{
    Re = aRval.Re;
    Im = aRval.Im;
}

/*!
    @brief Class Destructor
*/
Complex::~Complex()
{
    Re = 0.0;
    Im = 0.0;
}

/*!
    @brief Sets the real and imaginary part of a complex number
*/
void Complex::Set(  double aRe, double aIm )
{
    Re = aRe;
    Im = aIm;
}

/*!
    @brief Returns the module of a complex number
    @return Module of a complex number
*/
Complex::operator double()
{
    return abs();
}

/*!
    @brief Returns the formula for finding the modulus of a complex number
    @return The formula for finding the module
*/
double Complex::abs()
{
    return sqrt( Re*Re + Im*Im );
}

/*!
    @brief The sum of two complex numbers
*/
Complex Complex::operator+( const Complex& aRval )
{
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im;
    return Result;
}

/*!
    @brief The difference of two complex numbers
*/
Complex Complex::operator-( const Complex& aRval )
{
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}

/*!
    @brief The sum of a complex number and a real
*/
Complex Complex::operator+( const double& aval )
{
    Complex result;
    result.Re = Re + aval;
    result.Im = Im;
    return result;
}

/*!
    @brief The difference between a complex number and a real one
*/
Complex Complex::operator-( const double& aRval )
{
    Complex Result( *this );
    Result.Re = Re - aRval;
    return Result;
}

/*!
    @brief The product of two complex numbers
*/
Complex Complex::operator*( const Complex& aRval )
{
    Complex Result;
    Result.Re = Re*aRval.Re - Im*aRval.Im;
    Result.Im = Re*aRval.Im + Im*aRval.Re;
    return Result;
}

/*!
    @brief The product of a complex number and a real
*/
Complex Complex::operator*( const double& aRval )
{
    Complex Result;
    Result.Re = Re*aRval;
    Result.Im = Im*aRval;
    return Result;
}

/*!
    @brief Quotient of a complex number and a real
*/
Complex Complex::operator/( const double& aRval )
{   Complex Result;
    Result.Re = Re/aRval;
    Result.Im = Im/aRval;
    return Result;
}

/*!
    @brief Overloading the sum operator of complex numbers
*/
Complex& Complex::operator+=( const Complex& arval )
{
    Re += arval.Re;
    Im += arval.Im;
    return *this;
}

/*!
    @brief Overloading the difference operator of complex numbers
*/
Complex& Complex::operator-=( const Complex& aRval )
{
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}

/*!
    @brief Overloading the product operator of complex numbers
*/
Complex& Complex::operator*=( const Complex& aRval )
{
    double tmpRe = Re;
    Re = Re*aRval.Re - Im*aRval.Im;
    Im = Im*aRval.Re + tmpRe*aRval.Im;
    return *this;
}

/*!
    @brief Overload of the sum operator of a complex number and a real
*/
Complex& Complex::operator+=( const double& aRval )
{
    Re += aRval;
    return *this;
}

/*!
    @brief Overload of the difference operator of a complex number and a real one
*/
Complex& Complex::operator-=( const double& aRval )
{
    Re -= aRval;
    return *this;
}

/*!
    @brief Overloading the operator of the product of a complex number and a real
*/
Complex& Complex::operator*=( const double& aRval )
{
    Re *= aRval;
    Im *= aRval;
    return *this;
}

/*!
    @brief Overloading the operator of a particular complex number and indeed
*/
Complex& Complex::operator/=( const double& aRval )
{
    Re /= aRval;
    Im /= aRval;
    return *this;
}

/*!
    @brief Class Constructor
*/
Complex& Complex::operator=( const Complex& aRval )
{
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}

/*!
    @brief Class Constructor
*/
Complex& Complex::operator=( const double& aRval )
{
    Re = aRval;
    Im = 0.0;
    return *this;
}

/*!
    @brief Overloading the operator function >> to enter the Complex class
*/
istream& operator >> ( istream& stream, Complex& a )
{
    char tmp[256];
    stream >> a.Re >> a.Im >> tmp;
    return stream;
}

/*!
    @brief Overloading the << operator function to output the Complex class
*/
ostream& operator << ( ostream& stream, Complex& a )
{
    stream << a.Re;
    if( !(a.Im < 0) )
        stream << '+';
    stream << a.Im << 'i';
    return stream;
}

/*!
    @brief Overload +
*/
Complex operator+( const double& aLval, const Complex& aRval)
{
    Complex Result;
    Result.Re = aLval + aRval.Re;
    Result.Im = aRval.Im;
    return Result;
}

/*!
    @brief  Overload -
*/
Complex operator-( const double& aLval, const Complex& aRval )
{
    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im = - aRval.Im;
    return Result;
}

/*!
    @brief Overload *
*/
Complex operator*(const double& aLval, const Complex& a )
{
    Complex r;
    r.Re = aLval * a.Re;
    r.Im = aLval * a.Im;
    return r;
}
