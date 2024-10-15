#include <cmath>
#include <iostream>
#include <cstdint> // Za uint64_t

using namespace std;

uint64_t Ro = 1;

uint64_t LCG(uint64_t a, uint64_t b) {
    uint64_t m = 4294967296; // (2^32)
    Ro = (Ro * a + b) % m;

    return Ro;
}
uint64_t RANDOM(uint64_t a, uint64_t b) {
    return a + (LCG(a,b) % (b - a + 1));
}

uint64_t generateRandomNumber(int n) {
    uint64_t min = pow(10, n - 1);
    uint64_t max = pow(10, n) - 1;
    return RANDOM(min, max);
}

uint64_t naivePrimeGeneration(int n) {
    uint64_t p = generateRandomNumber(n);

    if (p % 2 == 0) { // If p is even, increment it by 1 (to make it odd)
        p++;
    }

    while (true) {
        uint64_t j = 3; // Potential divisor of p

        // Check for divisors up to √p
        while (j <= sqrt(p)) {
            if (p % j == 0) { // Check divisibility
                break;  //Found a divisor
            }
            j += 2; // Check the next odd number
        }

        if (j > sqrt(p)) { // No potential divisor found for p
            return p;  // Return the prime number
        }

        p += 2; // Check the next odd number
    }
}

int main() {
    srand(time(0));

    cout << "Prime Numbers" << endl;

    uint64_t a = 69069;      // Množitelj LCG
    uint64_t b = 0;          // Dodatek LCG

    int n = 5; // število mest

    uint64_t randomNumber = RANDOM(a, b);
    cout << randomNumber;

    uint64_t prime = naivePrimeGeneration(n);

    cout << "\nGenerated primer number: " << prime << endl;


    return 0;
}
