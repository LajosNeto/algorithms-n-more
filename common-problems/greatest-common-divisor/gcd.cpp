/** @file gcd.cpp
* 
* @brief Greatest Common Divisor implementations
*
*@author Lajos Onodi Neto
*/

#include <iostream>
#include <vector>
#include <cassert>

using std::vector;
using std::cin;
using std::cout;

int gcd_naive(int a, int b){
    int best = 0;
    for(int i = 1; i<=a+b; ++i){
        if(a%i == 0 and b%i ==0) best = i;
    }
    return best;
}

int eucid_gcd(int a, int b){
    int temp_a = 0;
    if(b == 0) return a;
    
    temp_a = a % b;
    return (eucid_gcd(b, temp_a));
}

int main(){
    int a=0;
    int b=0;
    int best = 0;
    cin >> a >> b;

    //best = gcd_naive(a,b);
    best = eucid_gcd(a,b);
    cout << best;
    return 0;
}