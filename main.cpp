#include "fileUtil.h"
#include "phoneBookUtil.h"

using namespace std;

void task1(){
    string filename, line;
    int command, n;

    while(true){
        cout << "Choose operation:" << endl;
        cout << "0 - exit" << endl;
        cout << "1 - create file" << endl;
        cout << "2 - print file" << endl;
        cout << "3 - append line to file" << endl;
        cout << "4 - get n-th number from file" << endl;
        cout << "5 - get quantity of numbers in file" << endl;
        cout << "6 - append line to start of file" << endl;
        cin >> command;

        cout << "Enter file name:" << endl;
        cin >> filename;
        filename = "../" + filename;

        try {
            switch (command) {
                case 0:
                    return;
                case 1:
                    createFile(filename);
                    break;
                case 2:
                    printFile(filename);
                    break;
                case 3:
                    getchar();
                    cout << "Enter line to append:" << endl;
                    getline(cin, line);
                    appendToFile(filename, line);
                    break;
                case 4:
                    cout << "Enter n:" << endl;
                    cin >> n;
                    cout << "n-th number is " << getNumberFromFile(filename, n) << endl;
                    break;
                case 5:
                    cout << "There is " << getNumberOfNumbersInFile(filename) << " numbers in file" << endl;
                    break;
                case 6:
                    getchar();
                    cout << "Enter line to append:" << endl;
                    getline(cin, line);
                    appendToStartOfFile(filename, line);
                    break;
                default:
                    cout << "There is no such a command" << endl;
                    break;
            }
        } catch (int errCode) {
            switch (errCode) {
                case -1:
                    cout << "Error in file opening" << endl;
                    break;
                case -2:
                    cout << "Error occurred while working with file" << endl;
                    break;
                default:
                    return;
            }
        }
        cout << endl;
    }
}

void task2(){
    string textFilename, binFilename;
    char number[10];
    char substring[3];
    char character;
    int command, n;
    PhoneUser user{};

    while(true){
        cout << "Choose operation:" << endl;
        cout << "0 - exit" << endl;
        cout << "1 - convert text file to binary file" << endl;
        cout << "2 - convert binary file to text file" << endl;
        cout << "3 - print binary file" << endl;
        cout << "4 - get n-th record from binary file" << endl;
        cout << "5 - delete record from binary file by number" << endl;
        cout << "6 - put all users with numbers starts with substring from binary file to text file" << endl;
        cout << "7 - delete all users with numbers starts with character from binary file" << endl;
        cin >> command;

        try {
            switch (command) {
                case 0:
                    return;
                case 1:
                    cout << "Enter text file name:" << endl;
                    cin >> textFilename;
                    cout << "Enter binary file name:" << endl;
                    cin >> binFilename;
                    convertTextToBinary("../" + textFilename, "../" + binFilename);
                    break;
                case 2:
                    cout << "Enter binary file name:" << endl;
                    cin >> binFilename;
                    cout << "Enter text file name:" << endl;
                    cin >> textFilename;
                    convertTextToBinary("../" + binFilename, "../" + textFilename);
                    break;
                case 3:
                    cout << "Enter binary file name:" << endl;
                    cin >> binFilename;
                    printBinaryFile("../" + binFilename);
                    break;
                case 4:
                    cout << "Enter binary file name:" << endl;
                    cin >> binFilename;
                    cout << "Enter n:" << endl;
                    cin >> n;
                    user = getRecord("../" + binFilename, n);
                    cout << "n-th record is {" << user.phone << ", " << user.address << ", " << user.name << "}" << endl;
                    break;
                case 5:
                    cout << "Enter binary file name:" << endl;
                    cin >> binFilename;
                    cout << "Enter number:" << endl;
                    cin >> number;
                    deleteRecord("../" + binFilename, number);
                    break;
                case 6:
                    cout << "Enter binary file name:" << endl;
                    cin >> binFilename;
                    cout << "Enter text file name:" << endl;
                    cin >> textFilename;
                    cout << "Enter substring" << endl;
                    cin >> substring;
                    putAllStartsWith("../" + binFilename, "../" + textFilename, substring);
                    break;
                case 7:
                    cout << "Enter binary file name:" << endl;
                    cin >> binFilename;
                    cout << "Enter character" << endl;
                    cin >> character;
                    deleteAllStartsWith("../" + binFilename, character);
                    break;
                default:
                    cout << "There is no such a command" << endl;
                    break;
            }
        } catch (int errCode) {
            switch (errCode) {
                case -1:
                    cout << "Error in file opening" << endl;
                    break;
                case -2:
                    cout << "Error occurred while working with file" << endl;
                    break;
                default:
                    return;
            }
        }
        cout << endl;
    }
}

void test(){
    cout << "Task 1:" << endl;
    createFile("../file.txt");
    appendToFile("../file.txt", "5 6 7 8");
    appendToStartOfFile("../file.txt", "1 2 3");
    cout << "Content of file:" << endl;
    printFile("../file.txt");
    cout << "Forth number in file: (should be 5)" << endl;
    cout << getNumberFromFile("../file.txt", 4) << endl;
    cout << "Forth number of numbers in file: (should be 7)" << endl;
    cout << getNumberOfNumbersInFile("../file.txt") << endl;

    cout << "Task 2:" << endl;

    cout << "Test 1: ordinary file" << endl;
    createFile("../file1.txt");
    appendToFile("../file1.txt", "22350 addr1 name1");
    appendToFile("../file1.txt", "22360 addr2 name2");
    appendToFile("../file1.txt", "25360 addr3 name3");
    appendToFile("../file1.txt", "42360 addr4 name4");

    cout << "Initial text file:" << endl;
    printFile("../file1.txt");
    convertTextToBinary("../file1.txt", "../binary1.dat");
    cout << "Binary file:" << endl;
    printBinaryFile("../binary1.dat");
    convertBinaryToText("../binary1.dat", "../new_file1.txt");
    cout << "New text file:" << endl;
    printFile("../new_file1.txt");
    cout << "Second record`s phone is:" << endl;
    PhoneUser user{};
    user = getRecord("../binary1.dat", 1);
    cout << user.phone << endl;
    putAllStartsWith("../binary1.dat", "../str_text1.txt", "223");
    cout << "Text file with records starts with 223:" << endl;
    printFile("../str_text1.txt");
    deleteAllStartsWith("../binary1.dat", '2');
    cout << "Binary file all records started with 2 deleted:" << endl;
    printBinaryFile("../binary1.dat");

    cout << "Test 2: blank file" << endl;
    cout << "Initial text file:" << endl;
    createFile("../file2.txt");
    printFile("../file2.txt");
    convertTextToBinary("../file2.txt", "../binary2.dat");
    cout << "Binary file:" << endl;
    printBinaryFile("../binary2.dat");
    convertBinaryToText("../binary2.dat", "../new_file2.txt");
    cout << "New text file:" << endl;
    printFile("../new_file2.txt");
    putAllStartsWith("../binary2.dat", "../str_text2.txt", "223");
    cout << "Text file with records starts with 223:" << endl;
    printFile("../str_text2.txt");
    deleteAllStartsWith("../binary2.dat", '2');
    cout << "Binary file all records started with 2 deleted:" << endl;
    printBinaryFile("../binary2.dat");
}

int main() {
    int n;
    cout << "Choose task 1 or 2:" << endl;
    cin >> n;

    switch(n){
        case 0:
            test();
            break;
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        default:
            cout << "There is no such a task" << endl;
            break;
    }
}
