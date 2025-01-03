#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

// Компоненты файла f – целые двухзначные (отличные от нуля) числа,
// причем 10 положительных чисел, 10 отрицательных, и т. д. Получить файл g,
// в котором записаны сначала 5 положительных чисел, затем 5 отрицательных и т. д.

int main()
{
    int pol[100];
    int otr[100];
    int np = 0;
    int notr = 0;
    setlocale(LC_ALL, "RU");
    char s[100];
    FILE* file;
    errno_t err = fopen_s(&file, "C:\\Users\\ASUS\\Desktop\\ЛАБЫ\\Лабараторные работы ОАИП\\19\\isx.txt", "r");
    if (err != 0) {
        cout << "Ошибка открытия файла isx.txt" << endl;
        return 1;
    }
    while (fscanf_s(file, "%s", s, (unsigned)_countof(s)) != EOF) {
        s[strcspn(s, "\n")] = 0;
        int num = stoi(s);
        if (num > 0) {
            pol[np] = num;
            np++;
        }
        else {
            otr[notr] = num;
            notr++;
        }
    }
    fclose(file);

    FILE* file_out;
    errno_t err_out = fopen_s(&file_out, "C:\\Users\\ASUS\\Desktop\\ЛАБЫ\\Лабараторные работы ОАИП\\19\\g.txt", "w");
    if (err_out != 0) {
        cout << "Ошибка открытия файла g.txt" << endl;
        return 1;
    }

    int pos_index = 0, neg_index = 0;
    while (pos_index < np || neg_index < notr) {
        for (int i = 0; i < 5 && pos_index < np; ++i, ++pos_index) {
            fprintf(file_out, "%d ", pol[pos_index]);
        }
        for (int i = 0; i < 5 && neg_index < notr; ++i, ++neg_index) {
            fprintf(file_out, "%d ", otr[neg_index]);
        }
    }
    fclose(file_out);

    cout << "Файл g успешно создан." << endl;
    return 0;
}
