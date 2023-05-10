#include <iostream>
#include <cmath>

struct Point{
    long x;
    long y;
};

long a, b, p = 0;
int modInverse (int n, int m){
    for(int i = 1; i<m; i++)
        if((((n%m+m)%m) * ((i%m+m)%m))%m == 1)
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
        m = ((p2.y - p1.y) * modInverse((p2.x-p1.x), p)) % p;
    }
    result.x = (((m*m) - p1.x - p2.x) % p + p) % p;
    result.y = ((m*(p1.x-result.x) - p1.y) % p + p) % p;

    return result;
}
Point multiply(int n, Point p){
    if(n<=1){
        return p;
    }
    Point result;

    result = add(p, p);

    for(int i = 2; i < n; i++){
        result = add(p, result);
    }

    return result;
}
int main(){
    a = 11;
    b = 19;
    p = 167;

    Point p1, BobSends, AliceSends, AliceShared, BobShared;
    p1.x=2;
    p1.y=7;


    AliceSends = multiply(12, p1);
    BobSends = multiply(31, p1);
    AliceShared = multiply(12, BobSends);
    BobShared = multiply(31, AliceSends);

    /*
  ad8888888888ba
 dP'         `"8b,
 8  ,aaa,       "Y888a     ,aaaa,     ,aaa,  ,aa,
 8  8' `8           "88baadP""""YbaaadP"""YbdP""Yb
 8  8   8              """        """      ""    8b
 8  8, ,8         ,aaaaaaaaaaaaaaaaaaaaaaaaddddd88P
 8  `"""'       ,d8""
 Yb,         ,ad8"    Normand Veilleux
  "Y8888888888P"
    */
   
    std::cout << "  ad8888888888ba" << std::endl;
    std::cout << " dP'         `\"8b," << std::endl;
    std::cout << " 8  ,aaa,       \"Y888a     ,aaaa,     ,aaa,  ,aa," << std::endl;
    std::cout << " 8  8' `8           \"88baadP\"\"\"\"YbaaadP\"\"\"YbdP\"\"Yb" << std::endl;
    std::cout << " 8  8   8              """        """      ""    8b" << std::endl;
    std::cout << " 8  8, ,8         ,aaaaaaaaaaaaaaaaaaaaaaaaddddd88P" << std::endl;
    std::cout << " 8  `\"\"\"'       ,d8\"\"" << std::endl;
    std::cout << " Yb,         ,ad8\"" << std::endl;
    std::cout << "  \"Y8888888888P\"" << std::endl;
    std::cout << "Alice Sends: (" << AliceSends.x << ", " << AliceSends.y << ")" << std::endl;
    std::cout << "  Bob Sends: (" << BobSends.x << ", " << BobSends.y << ")" << std::endl;
    std::cout << "Alice computes shared key: (" << AliceShared.x << ", " << AliceShared.y << ")" << std::endl;
    std::cout << "  Bob computes shared key: (" << BobShared.x << ", " << BobShared.y << ")" << std::endl;
    return 0;
}