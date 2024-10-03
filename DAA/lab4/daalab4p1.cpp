#include <iostream>
#include <algorithm> // For std::max

int findMaxDigit(int x) {
    if (x < 10) {
        return x;
    }

    int lastDigit = x % 10;
    int remainingDigits = x / 10;

    int maxInRemaining = findMaxDigit(remainingDigits);

    return std::max(lastDigit, maxInRemaining);
}
int main() {int x = 286883;
    std::cout << "The maximum digit in " << x << " is " << findMaxDigit(x) << std::endl;
    return 0;
}