#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Creating a file
    ofstream file("ReadMe.txt");

    // Checking if the file was opened successfully
    if (!file.is_open()) {
        cout << "Error creating file." << endl;
        return 1;
    }

    // Writing multiple lines to the file
    file << "Muhammad Bilal (F2022266268)" << endl;
    file << "Faizan Manzar (F2022266260)" << endl;
    file << "Babar Ali (F202226629)" << endl;

    // Closing the file
    file.close();

    // Re-opening the file for reading
    ifstream readfile("ReadMe.txt");

    // Checking if the file was opened successfully
    if (!readfile.is_open()) {
        cout << "Error reading file." << endl;
        return 1;
    }

    // Reading and printing each line in the file
    string line;
    while (getline(readfile, line)) {
        cout << line << endl;
    }

    // Closing the file
    readfile.close();

    return 0;
}

