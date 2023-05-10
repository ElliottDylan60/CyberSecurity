#include <iostream>
#include <cmath>

struct Point{
    long x;
    long y;
};
long a, b, p = 0;

Point add(Point p1, Point p2){
    Point result;
    if(p1.x == p2.x && p1.y == p2.y){
        long m3x1x1 = (3*p1.x*p1.x);
        long m2y1 = (2*p1.y);
        long m = (((m3x1x1) / (m2y1)) % p + p)  % p;
        result.x = (((m*m) - p1.x - p2.x) % p + p) % p;
        result.y = ((m*(p1.x - result.x) - p1.x) % p + p) % p;
    }else{
        long y2y1 = (p2.y - p1.y);
        long x2x1 = (p2.x - p1.x);
        if(y2y1 == 0 || x2x1 == 0){
            result.x = 0;
            result.y = 0;
            return result;
        }
        long m = ((y2y1)/(x2x1)%p+p)%p;
        result.x = (((m*m) - p1.x - p2.x) % p + p) % p;
        result.y = ((m*(p1.x - result.x) - p1.x) % p + p) % p;
    }
    return result;
}
int main(){
    a = 11;
    b = 19;
    p = 167;
    Point p1, p2, p3;
    p1.x=2;
    p1.y=7;
    p2.x=2;
    p2.y=7;
    std::cout << "(" << p1.x << ", " << p1.y << ")" << " + " << "(" << p2.x << ", " << p2.y << ")" << std::endl;
    p3 = add(p1, p2);
    std::cout << "Result: (" << p3.x << ", " << p3.y << ")" << std::endl;
    std::cout << "(" << p3.x << ", " << p3.y << ")" << " + " << "(" << p2.x << ", " << p2.y << ")" << std::endl;
    p3 = add(p3, p2);
    std::cout << "Result: (" << p3.x << ", " << p3.y << ")" << std::endl;
    std::cout << "(" << p3.x << ", " << p3.y << ")" << " + " << "(" << p2.x << ", " << p2.y << ")" << std::endl;
    p3 = add(p3, p2);
    std::cout << "Result: (" << p3.x << ", " << p3.y << ")" << std::endl;
    std::cout << "(" << p3.x << ", " << p3.y << ")" << " + " << "(" << p2.x << ", " << p2.y << ")" << std::endl;
    p3 = add(p3, p2);
    std::cout << "Result: (" << p3.x << ", " << p3.y << ")" << std::endl;
    std::cout << "(" << p3.x << ", " << p3.y << ")" << " + " << "(" << p2.x << ", " << p2.y << ")" << std::endl;
    p3 = add(p3, p2);
    std::cout << "Result: (" << p3.x << ", " << p3.y << ")" << std::endl;
    std::cout << "(" << p3.x << ", " << p3.y << ")" << " + " << "(" << p2.x << ", " << p2.y << ")" << std::endl;
    p3 = add(p3, p2);
    std::cout << "Result: (" << p3.x << ", " << p3.y << ")" << std::endl;
    std::cout << "(" << p3.x << ", " << p3.y << ")" << " + " << "(" << p2.x << ", " << p2.y << ")" << std::endl;
    p3 = add(p3, p2);
    std::cout << "Result: (" << p3.x << ", " << p3.y << ")" << std::endl;
    std::cout << "(" << p3.x << ", " << p3.y << ")" << " + " << "(" << p2.x << ", " << p2.y << ")" << std::endl;
    p3 = add(p3, p2);
    std::cout << "Result: (" << p3.x << ", " << p3.y << ")" << std::endl;
    std::cout << "(" << p3.x << ", " << p3.y << ")" << " + " << "(" << p2.x << ", " << p2.y << ")" << std::endl;
    p3 = add(p3, p2);
    std::cout << "Result: (" << p3.x << ", " << p3.y << ")" << std::endl;
    std::cout << "(" << p3.x << ", " << p3.y << ")" << " + " << "(" << p2.x << ", " << p2.y << ")" << std::endl;
    p3 = add(p3, p2);
    std::cout << "Result: (" << p3.x << ", " << p3.y << ")" << std::endl;
    std::cout << "(" << p3.x << ", " << p3.y << ")" << " + " << "(" << p2.x << ", " << p2.y << ")" << std::endl;
    p3 = add(p3, p2);
    std::cout << "Result: (" << p3.x << ", " << p3.y << ")" << std::endl;
    std::cout << "(" << p3.x << ", " << p3.y << ")" << " + " << "(" << p2.x << ", " << p2.y << ")" << std::endl;
    p3 = add(p3, p2);
    std::cout << "Result: (" << p3.x << ", " << p3.y << ")" << std::endl;
    std::cout << "(" << p3.x << ", " << p3.y << ")" << " + " << "(" << p2.x << ", " << p2.y << ")" << std::endl;
    p3 = add(p3, p2);
    std::cout << "Result: (" << p3.x << ", " << p3.y << ")" << std::endl;
    std::cout << "(" << p3.x << ", " << p3.y << ")" << " + " << "(" << p2.x << ", " << p2.y << ")" << std::endl;
    p3 = add(p3, p2);
    std::cout << "Result: (" << p3.x << ", " << p3.y << ")" << std::endl;
    std::cout << "(" << p3.x << ", " << p3.y << ")" << " + " << "(" << p2.x << ", " << p2.y << ")" << std::endl;
    p3 = add(p3, p2);
    std::cout << "Result: (" << p3.x << ", " << p3.y << ")" << std::endl;
    
    return 0;
}