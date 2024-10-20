#ifndef MOTION2D
#define MOTION2D
#include <iostream>

// Predefined constant for pi, to be used if/when converting degrees
// to radians.
#define PI 3.14159265

// Forward declation of Force. Needed in case any of Point references
// the existence of type Force.
class Force;

class Point {
    // Private fields and helpers here.
    float x;
    float y;

  public:
    // Required public interface here.
    Point();
    Point(float x, float y);

    int quadrant();
    friend Point operator+(const Point& p,const Force& f);

    friend std::istream & operator>>(std::istream& in, Point & p);
    friend std::ostream & operator<<(std::ostream& out, const Point & p); 
};
std::istream & operator>>(std::istream& in, Point & p );
std::ostream & operator<<(std::ostream& out, const Point & p); 

class Force {
    // Private fields and helpers here.
    float angle;
    float magnitude;

  public:
    // Required public interface here.
    Force();
    Force(float angle, float magnitude);

    Force operator*(float n);

    friend std::istream& operator>>(std::istream& in, Force & f);
    friend std::ostream& operator<<(std::ostream& out, const Force & p); 
    friend Force operator*(int n , const Force &f);
    friend Point operator+(const Point& p, const Force& f);
};
// we didnot declare it as the method because that would change the order in which the cout is called
std::istream& operator>>(std::istream& in, Force & f );
std::ostream& operator<<(std::ostream& out, const Force & p); 
Force operator*(int n , const Force &f);
Point operator+(const Point& p,const Force& f);

#endif
