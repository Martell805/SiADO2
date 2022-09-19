#ifndef SIADO2_PHONEBOOKUTIL_H
#define SIADO2_PHONEBOOKUTIL_H

#include "fileUtil.h"
#include <iostream>

using namespace std;

struct PhoneUser{
    string phone;
    string address;
    string name;
};

void convertTextToBinary(const string& textFilename, const string& binFilename);
void convertBinaryToText(const string& binFilename, const string& textFilename);
void printBinaryFile(const string& filename);
PhoneUser getRecord(const string& filename, int n);
void deleteRecord(const string& filename, int n);
void putAllStartsWith(const string& binFilename, const string& textFilename, const &string start);
void deleteAllStartsWith(const string& filename, const string& start);


#endif //SIADO2_PHONEBOOKUTIL_H
