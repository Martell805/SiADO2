#include "fileUtil.h"

void assertFileOpened(const ifstream &file){
    if(file.is_open()) return;
    throw -1;
}

void assertFileOpened(const ofstream &file){
    if(file.is_open()) return;
    throw -1;
}

void assertFileOpened(const fstream &file){
    if(file.is_open()) return;
    throw -1;
}

void assertFileErrors(const ifstream &file){
    if(file.good() or file.eof()) return;
    throw -2;
}

void assertFileErrors(const ofstream &file){
    if(file.good() or file.eof()) return;
    throw -2;
}

void assertFileErrors(const fstream &file){
    if(file.good() or file.eof()) return;
    throw -2;
}

void createFile(const string &filename){
    ofstream file(filename);
    assertFileOpened(file);

    assertFileErrors(file);
    file.close();
}

void printFile(const string &filename){
    ifstream file(filename);
    assertFileOpened(file);

    string line;
    while(getline(file, line)) cout << line << endl;

    assertFileErrors(file);
    file.close();
}

void appendToFile(const string &filename, const string &new_line){
    ofstream file(filename, ios_base::app);
    assertFileOpened(file);

    file << new_line << endl;

    assertFileErrors(file);
    file.close();
}

int getNumberFromFile(const string &filename, int n){
    ifstream file(filename);
    assertFileOpened(file);

    int result;

    for(int q = 0; q < n; q++) file >> result;

    assertFileErrors(file);
    file.close();

    return result;
}

int getNumberOfNumbersInFile(const string &filename){
    ifstream file(filename);
    assertFileOpened(file);

    int result = 0;
    int n;

    while(file >> n) result++;

    assertFileErrors(file);
    file.close();

    return result;
}

void appendToStartOfFile(const string &filename, const string &new_line){
    ifstream infile(filename);
    assertFileOpened(infile);

    vector<string> fileContent;

    fileContent.push_back(new_line);
    string line;
    while(getline(infile, line)) fileContent.push_back(line);

    assertFileErrors(infile);
    infile.close();

    ofstream outfile(filename);
    assertFileOpened(outfile);

    for(const auto& str: fileContent) outfile << str << endl;

    assertFileErrors(outfile);
    outfile.close();
}
