//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------


// Write the assignment code here
class Real {
  protected:
    float number;
  public:
    Real(float n) {
      number=n;
    } 
    float GetReal(){  
         return number;
    }
   Real operator+(float Other){
    return Real(number+Other);
  }
};

class Complex:public Real {
  protected:
   float number2;
  public:
    Complex(float n,float i):Real(n){
      number2=i;
    }
    float GetImaginary(){
      return number2;
    }
    Complex operator+(float Other){
    return Complex(number+Other,number2+Other);
    }
};

class Surreal:public Complex {
  protected:
    float number3;
  public:
    Surreal(float n, float i, float c):Complex(n,i){
      number3=c;
    }
    float GetSurreal(){
      return number3;
    }
    Surreal operator+(float Other){
    return Surreal(number+Other,number2+Other,number3+Other);
    }
};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
        REQUIRE( r.GetImaginary() == 22.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
        REQUIRE( r.GetImaginary() == 22.0 );
        REQUIRE( r.GetSurreal() == 32.0 );
    }
}
//------------------------------
