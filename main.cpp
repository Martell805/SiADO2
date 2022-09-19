#include "fileUtil.h"

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

}

int main() {
    int n;
    cout << "Choose task 1 or 2: ";
    cin >> n;

    switch(n){
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
