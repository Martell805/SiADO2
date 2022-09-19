#ifndef SIADO2_FILEUTIL_H
#define SIADO2_FILEUTIL_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void assertFileOpened(const ifstream &file);
void assertFileOpened(const ofstream &file);
void assertFileErrors(const ifstream &file);
void assertFileErrors(const ofstream &file);

void createFile(const string &filename);
void printFile(const string &filename);
void appendToFile(const string &filename, const string &new_line);
int getNumberFromFile(const string &filename, int n);
int getNumberOfNumbersInFile(const string &filename);
void appendToStartOfFile(const string &filename, const string &new_line);

#endif //SIADO2_FILEUTIL_H
