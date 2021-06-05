#!/bin/python3

import math
import os
import random
import re
import sys

def check(s):
    for i in range(int(len(s)/2)):
        par = (s[i],s[len(s)-1-i])
        if par[0] != par[1]:
            return False
    return True

# Complete the palindromeIndex function below.
def palindromeIndex(s):
    if check(s):
        return -1
    else:
        for i in range(int(len(s)/2)):
            par = (s[i],s[len(s)-1-i])
            if par[0] != par[1]:
                aux = [letra for letra in s]
                aux.pop(i)
                if check(aux):
                    return i
                else:
                    return len(s)-1-i


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        s = input()

        result = palindromeIndex(s)

        fptr.write(str(result) + '\n')

    fptr.close()
