#include <iostream>
#include <cmath>
#include <time.h>
#include <chrono>
using namespace std;

bool isPrime(int i) {
    if (i <= 1) return false;
    if (i == 2) return true;  // 2 is the only even prime number
    if (i % 2 == 0) return false;  // Even numbers greater than 2 are not prime

    int limit = sqrt(i);
    for (int j = 3; j <= limit; j += 2) {  // Check only odd numbers
        if (i % j == 0) return false;
    }
    return true;
}

int main() {
    chrono::time_point<chrono::system_clock> start;
    chrono::time_point<chrono::system_clock> end;
    chrono::duration<float> elapsed;

	start = chrono::system_clock::now();

    int PrimeNumberRange = 1000000;  
    for (int i = 1; i <= PrimeNumberRange; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }


	cout << endl;
	end = chrono::system_clock::now();
	elapsed = end - start;
	cout << "Elapsed time: " << elapsed.count() << "s" << endl;

    return 0;
}
