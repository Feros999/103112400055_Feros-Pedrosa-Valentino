#include <iostream>
using namespace std;

int main() {
    int masukan;
    cout << "Inputkan sebuah bilangan: ";
    cin >> masukan;

    for (int i = masukan; i >= 1; i--) {
        for (int s = 0; s < masukan - i; s++) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }

    for (int s = 0; s < masukan; s++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}