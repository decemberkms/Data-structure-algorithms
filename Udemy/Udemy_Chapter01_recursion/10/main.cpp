#include <iostream>


// Taylor series

double e1(int x, int n){
    static double p = 1.0, f = 1.0;
    double result;

    if (n == 0)
        return 1;
    else {
        result = e1(x, n -1);
        p *= x;
        f *= n;
        return result + p/f;
    }
}
//Horner method 
double e2(double x, double n){
    double s = 1;
    for (n; n > 0; n--){
        s = 1 + (x/n) *s;
    }
    return s;
}

double e3(double x, double n){
    static double s = 1;
    if (n == 0)
        return s;
    else{
        s = 1 + x/n*s;
        return e3(x, n-1);
    }
}

int main(){

    std::cout << e1(2, 3) << std::endl;
    std::cout << e2(2, 3) << std::endl;
    std::cout << e3(2, 3) << std::endl;

    return 0;
}