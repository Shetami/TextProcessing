#ifndef KURSACH_H_INCLUDED
#define KURSACH_H_INCLUDED


#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <cstdio>
#include <windows.h>
#include <ConIO.h>
#include <wincon.h>

using namespace std;

void GoToXY(short x, short y);
void ConsoleCursorVisible(bool show, short size);

string inputString(string prompt);
string inputWord(string prompt);
int inputInt(string prompt);
string inputFilename(string prompt);
string checkOpenFile();
string checkOutputFile();
void parserArray(string arr[], int& size, int& num_str);
void addAfter(string arr[], int& size, int num_str);
void addBefore(string arr[], int& size, int num_str);
void deleteString(string arr[], int& size, int num_str);
void replaceString(string arr[], int size, int num_str);
int move(int num_str, int size);
void outputString(string arr[], int size, int num_str);
void outputDir(string arr[], int size);


#endif // LAB3_H_INCLUDED

