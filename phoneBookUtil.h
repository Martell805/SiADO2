#ifndef SIADO2_PHONEBOOKUTIL_H
#define SIADO2_PHONEBOOKUTIL_H

#include "fileUtil.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct PhoneUser{
    char phone[10];
    char address[50];
    char name[50];
};

void convertTextToBinary(const string& textFilename, const string& binFilename);
void convertBinaryToText(const string& binFilename, const string& textFilename);
void printBinaryFile(const string& filename);
PhoneUser getRecord(const string& filename, int n);
void deleteRecord(const string& filename, const char phone[10]);
void putAllStartsWith(const string& binFilename, const string& textFilename, const char start[3]);
void deleteAllStartsWith(const string& filename, char start);


#endif //SIADO2_PHONEBOOKUTIL_H
