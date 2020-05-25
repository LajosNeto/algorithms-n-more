"""
Peak finding problem implementation

Reference : MIT 6.006 classes on algorithmic thinking, peak finding.
https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011
"""

# Author: 
# Lajos Neto <lajosneto@gmail.com>


# A little simpler implementation
def __peak_find_v1(values, start, end):
    half = (start+end)//2

    if(start == end): return start
    if(values[half] > values[half+1]): return __peak_find_v1(values, start, half)
    else: return __peak_find_v1(values, half+1, end)

# This implementation follows the idea from MIT 6.006 class idea
def __peak_find_v2(values, start, end):
    half = (start+end)//2

    if(start == end):
        return start
    
    if(values[half] < values[half+1]):
        return __peak_find_v2(values, half+1, end)
    elif(values[half] < values[half-1]):
        return __peak_find_v2(values, start, half)
    else:
        return half

def peak_find(values):
    return __peak_find_v1(values, 0, len(values)-1)