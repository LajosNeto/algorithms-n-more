/** @file lcm.cpp
* 
* @brief Least commom multiple implementations
*
*@author Lajos Onodi Neto
*/

#include <iostream>

using std::cin;
using std::cout;

int eucid_gcd(int a, int b){
    int temp_a = 0;
    if(b == 0) return a;
    temp_a = a % b;
    return (eucid_gcd(b, temp_a));
}

long long lcm(int a, int b){
    long long numerator = (long long) a*b;
    return numerator/eucid_gcd(a,b);
}

int main(){
    int a=0;
    int b=0;
    long long lcm_result = 0;
    cin >> a >> b;
    lcm_result = lcm(a,b);
    cout << lcm_result;
}