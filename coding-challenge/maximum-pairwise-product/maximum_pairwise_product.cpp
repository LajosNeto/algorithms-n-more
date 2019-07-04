/** @file maximum_pairwise_product.cpp
* 
* @brief Maximum Pairwise Product Problem
* Find the maximum product of two distinct numbers in a sequence of non-negative integers.
*
*@author Lajos Onodi Neto
*/

#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::max;

int64_t MaxPairwiseProduct(const vector<int64_t>& numbers){
    int vec_size = numbers.size();
    int64_t biggerA = 0, biggerB = 0;
    int biggerA_position;
    for(int i=0; i<vec_size; ++i) if(numbers[i] > biggerA){
        biggerA = numbers[i];
        biggerA_position = i;
    } 
    for(int j=0; j<vec_size; ++j) if(numbers[j] > biggerB and j != biggerA_position) biggerB = numbers[j];
    return biggerA*biggerB;
}

int main(){
    int n;
    cin >> n;
    vector<int64_t> numbers(n);
    for(int i=0; i<n; ++i){
        cin >> numbers[i];
    }
    int64_t max_product = MaxPairwiseProduct(numbers);
    cout << max_product << "\n";
    return 0;
}