#include "phoneBookUtil.h"

void convertTextToBinary(const string& textFilename, const string& binFilename){
    ifstream infile(textFilename);
    assertFileOpened(infile);

    ofstream outfile(binFilename, ios::binary);
    assertFileOpened(outfile);

    PhoneUser phoneUser{};

    while(infile >> phoneUser.phone){
        infile >> phoneUser.address;
        infile >> phoneUser.name;

        outfile.write((char*)&phoneUser, sizeof(char) * 110);
    }

    assertFileErrors(infile);
    infile.close();

    assertFileErrors(outfile);
    outfile.close();
}

void convertBinaryToText(const string& binFilename, const string& textFilename){
    ifstream infile(binFilename, ios::binary);
    assertFileOpened(infile);

    ofstream outfile(textFilename);
    assertFileOpened(outfile);

    PhoneUser phoneUser{};

    while(infile.read((char*)&phoneUser, sizeof(char) * 110)){
        outfile << phoneUser.phone << " " << phoneUser.address << " " << phoneUser.name << endl;
    }

    assertFileErrors(infile);
    infile.close();

    assertFileErrors(outfile);
    outfile.close();
}

void printBinaryFile(const string& filename){
    ifstream infile(filename, ios::binary);
    assertFileOpened(infile);

    PhoneUser phoneUser{};

    while(infile.read((char*)&phoneUser, sizeof(char) * 110)){
        cout << phoneUser.phone << " " << phoneUser.address << " " << phoneUser.name << endl;
    }

    assertFileErrors(infile);
    infile.close();
}

PhoneUser getRecord(const string& filename, int n){
    ifstream infile(filename, ios::binary);
    assertFileOpened(infile);

    PhoneUser phoneUser{};

    infile.seekg(n * sizeof(char) * 110);

    infile.read((char*)&phoneUser, sizeof(char) * 110);

    assertFileErrors(infile);
    infile.close();

    return phoneUser;
}

void deleteRecord(const string& filename, const char phone[10]){
    fstream file(filename, ios::binary | ios::in);
    assertFileOpened(file);

    vector<PhoneUser> users;

    PhoneUser record{};
    int recordsQuantity = 0;
    int n = 0;

    while(file.read((char*)&record, sizeof(char) * 110)) {
        if(strcmp(record.phone, phone) == 0) n = recordsQuantity;
        recordsQuantity++;
        users.push_back(record);
    }

    users[n] = record;

    assertFileErrors(file);
    file.close();

    file.open(filename, ios::binary | ios::out);
    assertFileOpened(file);

    for(int q = 0; q < users.size() - 1; q++)
        file.write((char*)&users[q], sizeof(char) * 110);

    assertFileErrors(file);
    file.close();
}

void putAllStartsWith(const string& binFilename, const string& textFilename, const char start[3]){
    ifstream infile(binFilename, ios::binary);
    assertFileOpened(infile);

    ofstream outfile(textFilename);
    assertFileOpened(outfile);

    PhoneUser phoneUser{};

    while(infile.read((char*)&phoneUser, sizeof(char) * 110)){
        if(phoneUser.phone[0] == start[0] and phoneUser.phone[1] == start[1] and phoneUser.phone[2] == start[2])
            outfile << phoneUser.phone << " " << phoneUser.address << " " << phoneUser.name << endl;
    }

    assertFileErrors(infile);
    infile.close();

    assertFileErrors(outfile);
    outfile.close();
}

void deleteAllStartsWith(const string& filename, char start){
    fstream file(filename, ios::binary | ios::in);
    assertFileOpened(file);

    vector<PhoneUser> users;

    PhoneUser record{};

    while(file.read((char*)&record, sizeof(char) * 110)) {
        if(record.phone[0] != start)
            users.push_back(record);
    }

    assertFileErrors(file);
    file.close();

    file.open(filename, ios::binary | ios::out);
    assertFileOpened(file);

    for(int q = 0; q < users.size(); q++)
        file.write((char*)&users[q], sizeof(char) * 110);

    assertFileErrors(file);
    file.close();
}