# include <cmath>
# include <iomanip>
# include "2DMotion.h"

Point::Point(): x{0}, y{0} {}
Point::Point(float x , float y): x{x}, y{y} {}

int Point:: quadrant(){
    if (x >= 0 && y >= 0) return 1;
    else if ( x < 0 && y >=0 ) return 2;
    else if (x<0 && y<0) return 3;
    else if ( x>=0 && y <=0) return 4;
    else return 0;
}
Force::Force(): angle{0}, magnitude{0} {}
Force::Force(float x, float b): angle{x}, magnitude{b} {}
Force Force::operator*(float n){
    float mag = n*magnitude;
    return Force{mag,angle};
}
Force operator*(int n , const Force &f){
    float mag = n*(f.magnitude);
    return Force{mag,f.angle};
}

Point operator+(const Point &p, const Force& f){
    float radian = ((f.angle)*PI)/180.00;
    float x = (f.magnitude)*cos(radian);
    float y = (f.magnitude)*sin(radian);
    return Point{(p.x)+x, (p.y)+y};
    
}
std::istream & operator >>(std::istream& in, Point &p){
     return in >> p.x >> p.y;
}

std::istream & operator >>(std::istream& in, Force & f ){
    return in >> f.angle >> f.magnitude;
}

std::ostream & operator <<(std::ostream& out, const Point & p){
    return out << std::fixed << std::setprecision(2) << "(" << p.x << ", " << p.y << ")" << std::defaultfloat ;
}

std::ostream & operator<<(std::ostream& out, const Force & f){
    return out << std::fixed << std::setprecision(2) << f.angle << " degrees with magnitude of " << f.magnitude << std::defaultfloat;
} 




