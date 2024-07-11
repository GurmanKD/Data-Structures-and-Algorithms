#include <iostream>
using namespace std;

void printSteps(int s, int d, int h, int n) {
    if (n == 1) {
        cout << "Moving plate " << n << " from " << s << " to " << d << "..." << endl;
        return;
    }

    // Move n-1 plates from source to helper via destination
    printSteps(s, h, d, n-1);

    // Move the nth plate from source to destination
    cout << "Moving plate " << n << " from " << s << " to " << d << "..." << endl;

    // Move n-1 plates from helper to destination via source
    printSteps(h, d, s, n-1);

    return;
}

int main() {
    int source = 1;
    int helper = 2;
    int destination = 3;

    int n;
    cout << "Enter the number of plates: ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of plates must be a positive integer." << endl;
        return 1;
    }

    printSteps(source, destination, helper, n);

    return 0;
}
