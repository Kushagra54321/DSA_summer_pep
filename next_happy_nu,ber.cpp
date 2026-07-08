#include <iostream>
using namespace std;

int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    while (n != 1 && n != 4) {
        n = sumOfSquares(n);
    }
    return n == 1;
}

int nextHappyNumber(int n) {
    n++;
    while (!isHappy(n)) {
        n++;
    }
    return n;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Next happy number: " << nextHappyNumber(num) << endl;
    return 0;
}