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

int MaxPairwiseProduct(const vector<int>& numbers){
    int product = 0;
    int vec_size = numbers.size();
    for(int i=0; i<vec_size; ++i){
        for (int j=i+1; j<vec_size; ++j){
            if(numbers[i] != numbers[j]){
                product = max(product, numbers[i]*numbers[j]);
            }
        }
    }
    return product;
}

int main(){
    int n = 0;
    cin >> n;
    vector<int> numbers(10);
    for(int i=0; i<n; i++){
        cin >> numbers[i];
    }
    int max_product = MaxPairwiseProduct(numbers);
    cout << max_product << "\n";
    return 0;
}