#include <iostream>
#include <fstream>

using namespace std;

void assertFileOpened(const ifstream &file){
    if(file) return;
    raise(-1);
}

void assertFileOpened(const ofstream &file){
    if(file) return;
    raise(-1);
}

void assertFileErrors(const ifstream &file){
    if(file.good()) return;
    raise(-2);
}

void assertFileErrors(const ofstream &file){
    if(file.good()) return;
    raise(-2);
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
    while(getline(file, line)) cout << line;

    assertFileErrors(file);
    file.close();
}

void appendToFile(const string &filename, const string &new_line){
    ofstream file(filename, ios::app);
    assertFileOpened(file);

    file << new_line;

    assertFileErrors(file);
    file.close();
}

int getNumberFromFile(const string &filename, int n){
    ifstream file(filename);
    assertFileOpened(file);

    int result;

    for(int q = 0; q < n; q++) cin >> result;

    assertFileErrors(file);
    file.close();

    return result;
}

int getNumberOfNumbersInFile(const string &filename){
    ifstream file(filename);
    assertFileOpened(file);

    int result = 0;
    int n;

    while(cin >> n) result++;

    assertFileErrors(file);
    file.close();

    return result;
}

int main() {
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
        cin >> command;

        cout << "Enter file name: ";
        cin >> filename;

        try {
            switch (command) {
                case 0:
                    return 0;
                case 1:
                    createFile(filename);
                    break;
                case 2:
                    printFile(filename);
                    break;
                case 3:
                    cout << "Enter line to append: ";
                    cin >> line;
                    appendToFile(filename, line);
                    break;
                case 4:
                    cout << "Enter n: ";
                    cin >> n;
                    cout << "n-th number is " << getNumberFromFile(filename, n) << endl;
                    break;
                case 5:
                    cout << "There is " << getNumberOfNumbersInFile(filename) << " numbers in file" << endl;
                    break;
                default:
                    cout << "There is no such a command" << endl;
                    break;
            }
        } catch (int errCode) {
            switch (errCode) {
                case -1:
                    cout << "Error in file opening" << endl;
                case -2:
                    cout << "Error occurred while working with file" << endl;
                default:
                    return errCode;
            }
        }
    }
}
