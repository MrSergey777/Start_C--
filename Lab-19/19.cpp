#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    char s[100];
    char sss[100];
    FILE* file;
    FILE* file1;
    FILE* file2;
    errno_t err = fopen_s(&file, "C:\\Users\\ASUS\\Desktop\\ЛАБЫ\\Лабараторные работы ОАИП\\19\\Fa.txt", "r");
    fgets(s, 100, file);
    int n = atoi(s);
    errno_t err1 = fopen_s(&file1, "C:\\Users\\ASUS\\Desktop\\ЛАБЫ\\Лабараторные работы ОАИП\\19\\Fb.txt", "r");
    fgets(sss, 100, file1);
    errno_t err2 = fopen_s(&file2, "C:\\Users\\ASUS\\Desktop\\ЛАБЫ\\Лабараторные работы ОАИП\\19\\Fc.txt", "w");
    while (fgets(s, 100, file) != NULL && fgets(sss, 100, file1) != NULL) {
        string s1 = "";
        for (int i1 = 0; i1 < n; i1++) {
            int num = s[i1 * 2] - '0';
            int num1 = sss[i1 * 2] - '0'; 
            s1 += to_string(num + num1) + " ";
        }
        fputs((s1 + "\n").c_str(), file2);
    }

    fclose(file1);
    fclose(file);
    fclose(file2);

    return 0;
}
