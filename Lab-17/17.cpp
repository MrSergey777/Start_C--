#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
void zad1(int n, int k, int* arr, int sizer) {
    double* arr1 = new double[2 * sizer + 1];
    fill(arr1, arr1 + 2 * sizer + 1, 0);
    for (int i = 0; i < n; i++) {
        arr1[arr[i] + sizer]++;
    }
    sort(arr1, arr1 + 2 * sizer + 1);
    double nn = n;
    for (int i = 2 * sizer; i >= 2 * sizer + 1 - k; i--) {
        cout << (arr1[i] / nn) * 100 << " ";
    }
}
int zad2(int rows, int cols, int** mat) {
    int c = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (mat[i][j] == 0) {
                c++;
                break;
            }
        }
    }
    int* ptr;
    ptr = &c;
    if (c == 0) return 0;
    else return *ptr;
    
}
int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите номер задачи, которую хотите решить\n";
    cout << "1. В массиве из целых чисел найти в процентах частоту появления каждого из k наиболее часто встретившихся чисел (k – натуральное число, не превосходящее числа элементов массива).\n";
    cout << "2 - Дана целочисленная прямоугольная матрица. Если есть в матрице нулевые элементы, то определить количе-ство строк, содержащих их. \n";
    int q;
    cin >> q;
    switch (q) {
    case 1: {
        int* arr;
        cout << "Введите n ";
        int n, k;
        cin >> n;
        arr = new int[n];
        cout << "Введите k ";
        cin >> k;
        int max = INT_MIN;
        int min = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] > max) {
                max = arr[i];
            }
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        int sizer;
        if (abs(min) > abs(max)) {
            sizer = abs(min);
        }
        else {
            sizer = abs(max);
        }
        zad1(n, k, arr, sizer);
        delete[] arr;
        return 0;
    }
    case 2: {
        int rows, cols;
        cout << "Введите количество строк и столбцов: ";
        cin >> rows >> cols;
        int** mat = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            mat[i] = new int[cols];
        }
        cout << "Введите элементы матрицы:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> mat[i][j];
            }
        }
        if (zad2(rows, cols, mat) == 0) cout << "В матрице нет нулевых элеметов";
        else cout << zad2(rows, cols, mat);
        return 0;
    }
   }
}
