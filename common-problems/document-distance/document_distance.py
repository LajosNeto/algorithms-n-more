"""
Simple document distance implementation

Reference : MIT 6.006 classes on models of computation and document distance
https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011
"""

# Author: 
# Lajos Neto <lajosneto@gmail.com>


import string
import math
from collections import defaultdict

# Runtime : O(N), N is the number of strings found on document
def get_file_words(file):
    translator = str.maketrans(string.ascii_uppercase, string.ascii_lowercase, string.punctuation)
    raw_file = file.read()
    file_words = raw_file.translate(translator).split()
    return file_words

# Runtime : O(N), N is the number of strings found on document.
# The above runtime does not consider the get_file_words method call complexity, 
# once it is already defined before.
def get_words_frequency(file):
    file_words = get_file_words(file)
    words_freq = defaultdict(int)
    for word in file_words:
        words_freq[word] += 1
    return words_freq

# Runtime : O(N), N is the number of strings on the frequency dictionary
def inner_product(file1_freqs, file2_freqs):
    inner = 0
    for word, count in file1_freqs.items():
        inner += count * file2_freqs.get(word, 0)
    return inner

def get_distance(file1_freqs, file2_freqs):
    num = inner_product(file1_freqs, file2_freqs)
    den = math.sqrt(inner_product(file1_freqs, file1_freqs)*inner_product(file2_freqs, file2_freqs))
    return math.acos(num/den)

if __name__ == '__main__':
    file1 = open('input_test_1.txt', 'r')
    file2 = open('input_test_2.txt', 'r')
    file1_freqs = get_words_frequency(file1)
    file2_freqs = get_words_frequency(file2)
    distance = get_distance(file1_freqs, file2_freqs)
    print(distance)