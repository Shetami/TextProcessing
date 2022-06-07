#include "API.h"
#define UP 72
#define DOWN 80
#define ENTER 13

int main()
{
    system("CLS");
    SetConsoleTitle(L"Kursach");
    setlocale(LC_ALL, "Russian");
    ConsoleCursorVisible(false, 100);
    int num_str = 0;
    int active_menu = 0;
    system("CLS");
    string arr[SIZEARR];
    int arr_size = 0;
    string Menu[] = {
        "Выход",
        "Считать строки из файла",
        "Добавить строки перед текущей строкой",
        "Добавить строки после текущей строки",
        "Удалить строки",
        "Заменить строку",
        "Передвинуть указатель строк",
        "Вывести заданое число строк в консоль",
        "Сохранить строки в файл"
    };
    char ch;
    while (true)
    {
        int x = 0, y = 0;
        GoToXY(x, y);
        for (int i = 0; i < size(Menu); i++)
        {
            if (i == active_menu)SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            else SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN);
            GoToXY(x, y++);
            cout << Menu[i] << endl;
        }
        ch = _getch();
        if (ch == -32) ch = _getch();
        switch (ch) {
        case UP:
            if (active_menu > 0)
                --active_menu;
            break;
        case DOWN:
            if (active_menu < size(Menu) - 1)
                ++active_menu;
            break;
        case ENTER:
            switch (active_menu)
            {
            case 0:
                exit(0);
            case 1:
                system("CLS");
                parserArray(arr, arr_size, num_str);
                system("CLS");
                break;
            case 2:
                system("CLS");
                addBefore(arr, arr_size, num_str);
                system("CLS");
                break;
            case 3:
                system("CLS");
                addAfter(arr, arr_size, num_str);
                system("CLS");
                break;
            case 4:
                system("CLS");
                deleteString(arr, arr_size, num_str);
                system("CLS");
                break;
            case 5:
                system("CLS");
                replaceString(arr, arr_size, num_str);
                system("CLS");
                break;
            case 6:
                system("CLS");
                num_str = move(num_str, arr_size);
                system("CLS");
                break;
            case 7:
                system("CLS");
                outputString(arr, arr_size, num_str);
                _getch();
                system("CLS");
                break;
            case 8:
                system("CLS");
                outputDir(arr, arr_size);
                system("CLS");
                break;
            }

            break;
        }
    }

}