/** @file fibonacci.cpp
* 
* @brief Fibonnaci functions
*
*@author Lajos Onodi Neto
*/

#include <iostream>
#include <vector>
#include <cassert>

using std::vector;
using std::cin;
using std::cout;

// Resursive function to calculate N element from Fibonacci sequence
int fib_recursive(int n){
    if (n<=1) return n;
    return fib_recursive(n-1) + fib_recursive(n-2);
}

// Calculated the N element form the Fibonacci sequence.
// Fast way without recursion
int fib_fast(int n){
    vector<int> fib_seq(n+2);
    fib_seq[0] = 1;
    fib_seq[1] = 1;
    for(int i = 2; i<=n; ++i){
        fib_seq[i] = (fib_seq[i-1] + fib_seq[i-2]);
    }
    return fib_seq[n-1];

}

// Get last digit from the last element N from the fibonacci sequence
int last_digit_fibn(int n){
    vector<int> fib_seq(n+2);
    fib_seq[0] = 1;
    fib_seq[1] = 1;
    for(int i = 2; i<=n; ++i){
        fib_seq[i] = (fib_seq[i-1] + fib_seq[i-2])%10;
    }
    return fib_seq[n-1];
}


void test_solution(){
    assert(fib_fast(3) == 2);
    assert(fib_fast(10) == 55);
    for(int i = 0; i<20; ++i) {
        assert(fib_fast(i) == fib_recursive(i));
    }
}

int main(){
    int n = 0;
    cin >> n;
    cout << fib_fast(n);
    //cout << fib_recursive(n);
    //test_solution();
    return 0;
}