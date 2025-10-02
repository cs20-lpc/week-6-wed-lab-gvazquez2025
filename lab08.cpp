#include <iostream> 
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

unsigned fact(unsigned);
unsigned fib(unsigned);
unsigned mult(unsigned, unsigned);
unsigned power(unsigned, unsigned);
unsigned product(unsigned, unsigned);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls various recursive functions that can be
 * optimized using tail recursion.
*******************************************************************************/

int main() {
    // try a ridiculous case that won't work without tail recursion
    cout << "6 * 123000 = " << mult(6, 123000) << endl;
    
    // these functions can't demonstrate the usefulness of tail recursion
    // due to data type overflow, but still, good practice
    cout << "3 ^ 10 = " << power(3, 10) << endl;
    cout << "8 * 9 * ... * 15 = " << product(8, 15) << endl;
    cout << "10! = " << fact(10) << endl;

    // without tail recursion, this next call is going to take a while
    cout << "50th Fibonacci number is " << fib(50) << endl;

    // terminate
    return 0;
}

/*******************************************************************************
 * Tail recursive function definitions
*******************************************************************************/

// helper for factorial
unsigned factHelper(unsigned n, unsigned acc) {
    if (n <= 1) return acc;
    return factHelper(n - 1, n * acc);
}
unsigned fact(unsigned n) {
    return factHelper(n, 1);
}

// helper for Fibonacci
unsigned fibHelper(unsigned n, unsigned a, unsigned b) {
    if (n == 0) return a;
    if (n == 1) return b;
    return fibHelper(n - 1, b, a + b);
}
unsigned fib(unsigned n) {
    return fibHelper(n, 0, 1);
}

// helper for multiplication
unsigned multHelper(unsigned x, unsigned y, unsigned acc) {
    if (y == 0) return acc;
    return multHelper(x, y - 1, acc + x);
}
unsigned mult(unsigned x, unsigned y) {
    return multHelper(x, y, 0);
}

// helper for power
unsigned powerHelper(unsigned x, unsigned y, unsigned acc) {
    if (y == 0) return acc;
    return powerHelper(x, y - 1, acc * x);
}
unsigned power(unsigned x, unsigned y) {
    return powerHelper(x, y, 1);
}

// helper for product
unsigned productHelper(unsigned x, unsigned y, unsigned acc) {
    if (x > y) return acc;
    return productHelper(x + 1, y, acc * x);
}
unsigned product(unsigned x, unsigned y) {
    return productHelper(x, y, 1);
}
