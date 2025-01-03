#include <iostream>
#include <cmath>
using namespace std;
double dixotomia(double (*func)(double), double a, double b, double e = 0.001) {
    double x = (a + b) / 2;
    while (abs(a - b) > 2 * e) {
        x = (a + b) / 2;
        double fx = func(x);
        double fa = func(a);
        if (fx * fa <= 0) {
            b = x;
        }
        else {
            a = x;
        }
    }
    return x;
}
double func1(double x) {
    return pow(x, 3) + x - 3;
}
double func2(double x) {
    return cos(x) + x - 7;
}
int main() {
    setlocale(LC_ALL, "Ru");
    double a1 = 0.5, b1 = 1.5;
    double a2 = 1.0, b2 = 1.5;
    double root1 = dixotomia(func1, a1, b1);
    double root2 = dixotomia(func2, a2, b2);
    cout << "Корень первого уравнения: " << root1 << endl;
    cout << "Корень второго уравнения: " << root2 << endl;
    return 0;
}
