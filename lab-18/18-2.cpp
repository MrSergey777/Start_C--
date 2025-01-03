#include <iostream>
using namespace std;

double sum(int n, ...) {
    double* p = (double*)&n + 1;
    double ym = 0;
    double prev = *p; 
    for (int i = 1; i < n; i++) {
        double neew = *(++p); 
        ym += prev * neew; 
        prev = neew; 
    }
    return ym;
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Сумма для (1.5, 2.5, 3.5, 4.5): " << sum(4, 1.5, 2.5, 3.5, 4.5) << endl;
    cout << "Сумма для (5.5, 6.5, 7.5): " << sum(3, 5.5, 6.5, 7.5) << endl;
    cout << "Сумма для (8.5, 9.5): " << sum(2, 8.5, 9.5) << endl;
    return 0;
}
