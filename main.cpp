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

int main() {
    srand(time(0));

    cout << "Prime Numbers" << endl;

    uint64_t a = 69069;      // Množitelj LCG
    uint64_t b = 0;          // Dodatek LCG

    int n = 5; // število mest

    uint64_t randomNumber = RANDOM(a, b);
    cout << randomNumber;


    return 0;
}
