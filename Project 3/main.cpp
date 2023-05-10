#include <iostream>
#include <cmath>

struct Point{
    long x;
    long y;
};
long a, b, p = 0;
int modInverse (int n, int m){
    for(int i = 1; i<m; i++)
        if(((n%m) * (i%m))%m ==1)
            return i;
    return -1;
}
Point add(Point p1, Point p2){
    Point result;
    if(p1.x == 0 && p2.x == 0){
        return p2;
    }else if(p2.x == 0 && p2.x == 0){
        return p1;
    }

    if(p1.x == p2.x && (p1.y == (-1*p2.y) % p)){
        result.x = 0;
        result.y = 0;
        return result;
    }
    int m = 0;
    
    if(p1.x == p2.x && p1.y == p2.y){
        m = (((3*p1.x*p1.x) + a) * modInverse((2*p1.y), p))%p;
    }else{
        
        m = ((p2.y = p1.y) * modInverse((p2.x-p1.x), p)) % p;
    }
    result.x = (((m*m) - p1.x - p2.x) % p + p) % p;
    result.y = ((m*(p1.x-result.x) - p1.y) % p + p) % p;

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
    //std::cout << modInverse(14, 167) << std::endl;
    
    std::cout << "(" << p1.x << ", " << p1.y << ")" << " + " << "(" << p2.x << ", " << p2.y << ")" << std::endl;
    p3 = add(p1, p2);
    std::cout << "Result: (" << p3.x << ", " << p3.y << ")" << std::endl;
    /*
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
    */
    return 0;
}