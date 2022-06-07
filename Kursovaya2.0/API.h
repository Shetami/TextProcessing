#ifndef API_H_INCLUDED
#define API_H_INCLUDED
#define NOMINMAX
#define SIZEARR 100
#include "Kursovaya.h"

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

string inputString(string prompt) {
    string text;
    cout << prompt;
    getline(cin, text);
    return text;
}

string inputWord(string prompt) {
    string word;
    cout << prompt;
    if (!(cin >> word)) {
        cout << "Incorrect word!\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        inputWord(prompt);
    }
    else {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return word;
    }
}

int inputInt(string prompt) {
    int value = 0;
    cout << prompt;
    if (!(cin >> value)) {
        cout << "Incorrect number!\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        inputInt(prompt);
    }
    else {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}

string inputFilename(string prompt) {
    string name = "";
    cout << prompt;
    getline(cin, name);
    if (name == "") {
        cout << "Incorrect file name!";
        inputFilename(prompt);
    }
    else {
        return name;
    }
}

string checkOpenFile() {
    string path = inputFilename("Введите имя файла: ");
    ifstream fin;
    fin.exceptions(ifstream::badbit | ifstream::failbit);
    try
    {
        fin.open(path);
        fin.close();
        return path;
    }
    catch (const std::exception& ex)
    {
        cout << ex.what() << endl;
        cout << "Не удалось открыть файл для чтения!" << endl;
        checkOpenFile();
    }
}

string checkOutputFile() {
    string path = inputFilename("Введите имя файла: ");
    ofstream fout;
    fout.exceptions(ofstream::badbit | ofstream::failbit);
    try
    {
        fout.open(path);
        fout.close();
        return path;
    }
    catch (const std::exception& ex)
    {
        cout << ex.what() << endl;
        cout << "Не удалось открыть файл для чтения для записи!" << endl;
        checkOutputFile();
    }
}

void GoToXY(short x, short y)
{
    SetConsoleCursorPosition(hStdOut, { x, y });
}
void ConsoleCursorVisible(bool show, short size)
{

    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hStdOut, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(hStdOut, &structCursorInfo);

}

void parserArray(string arr[], int& size, int& num_str) {
    string path = checkOpenFile();
    ifstream fin;
    fin.open(path);
    size = 0;
    string str;
    while (!fin.eof())
    {
        str = "";
        getline(fin, str);
        arr[size] = str;
        size++;
    }
    fin.close();
    num_str = 0;

    system("CLS");
}

void addAfter(string arr[], int& size, int num_str) {
    int count = 0;
    count = inputInt("Колличество добавляемых строк: ");
    if (size + count > SIZEARR) {
        cout << "Out of range";
        _getch();
    }
    else {
        cout << "Введите строки: \n";
        for (int i = 0; i < count; i++) {
            for (int j = size - 1; j > num_str + i; j--) {
                arr[j + 1] = arr[j];
            }
            arr[num_str + 1 + i] = inputString("");
            size++;
        }
    }
}

void addBefore(string arr[], int& size, int num_str) {
    int count = 0;
    count = inputInt("Колличество добавляемых строк: ");
    if (size + count > SIZEARR) {
        cout << "Out of range";
        _getch();
    }
    else {
        cout << "Введите строки: \n";
        for (int i = 0; i < count; i++) {
            for (int j = size - 1; j >= num_str; j--) {
                arr[j + 1] = arr[j];
            }
            arr[num_str] = inputString("");
            num_str++;
            size++;
        }
    }
}


void deleteString(string arr[], int& size, int num_str) {
    int count = 0;
    string change = "";
    string before = "<-";
    string after = "->";
    count = inputInt("Колличество удаляемых строк: ");
    change = inputWord("Ввдите <- или ->: ");
    if (change == after) {
        if (num_str + count > size) {
            cout << "Превышен лимит";
            _getch();
        }
        else {
            for (int i = 0; i < count; i++) {
                for (int j = num_str; j < size - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                size--;
            }
        }
    }
    else if (change == before) {
        if (num_str - count < 0) {
            cout << "Превышен лимит";
            _getch();
        }
        else {
            for (int i = 0; i < count; i++) {
                for (int j = num_str; j < size - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                num_str--;
                size--;
            }
        }
    }
    else {
        cout << "Некоректный ввод";
        _getch();
    }
}

void replaceString(string arr[], int size, int num_str) {
    arr[num_str] = inputString("Введите новую строку: \n");
}


int move(int num_str, int size) {
    int step = 0;
    string direction = "";
    step = inputInt("Введите шаг перемещения: ");
    direction = inputWord("Введите <- или ->: ");
    if (direction == "<-") {
        if ((num_str - step) < 0) {
            num_str = 0;
        }
        else {
            num_str = num_str - step;
        }
    }
    else if (direction == "->") {
        if ((num_str + step) > size) {
            num_str = size;
        }
        else {
            num_str = num_str + step;
        }
    }
    else {
        cout << "input error\n";
        _getch();
    }
    return num_str;
}

void outputString(string arr[], int size, int num_str) {
    int count = 0;
    count = inputInt("Введите число выводимых строк: ");
    for (int i = num_str; i <= num_str + count; i++) {
        cout << arr[i] << endl;
    }
}

void outputDir(string arr[], int size) {
    ofstream fout;
    string name = checkOutputFile();

    fout.open(name);
    for (int i = 0; i < size; i++) {
        fout << arr[i] << endl;
    }
    fout.close();
}


#endif