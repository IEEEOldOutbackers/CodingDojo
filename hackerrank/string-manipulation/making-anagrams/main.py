'''
Coding Dojo 2020 - Python
Exercise: Making Anagrams
Link: https://www.hackerrank.com/challenges/making-anagrams/problem

Description:

We consider two strings to be anagrams of each other if the first string's letters can be rearranged to form the second string. 
In other words, both strings must contain the same exact letters in the same exact frequency. 
For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.

Given two strings, s1 and s2, that may not be of the same length, 
determine the minimum number of character deletions required to make s1 and s2 anagrams. 
Any characters can be deleted from either of the strings.

For example, s1 = abc and s2=amnop. The only characters that match are a's so we have 
to remove bc from s1 and mnop from s2 for a total of 6 deletions.

Complete the makingAnagrams function in the editor below. 
It should return an integer representing the minimum number of deletions needed to make the strings anagrams. 
'''
import math
import os
import random
import re
import sys
import string # biblioteca para criar uma string com todas as strings do alfabeto

# Complete the makingAnagrams function below.
# Recebo duas strings
# Remover as letras das duas strings para fazer elas virarem anagrama
# Premissa: Anagrama é quando uma string contém os mesmos caracteres que a outra string em mesma quantidade, ou seja,
# quando uma string pode ser rearranjada para formar a segunda string

# Solução:
# Passos
# 1 - Fazer a contagem de caracteres em cada string
# 2 - Comparar o número de caracteres de uma string com a outra
# 3 - Fazer a diferença entre quantidade de mesmo caracter de 1 string com a outra e remover o excesso da string com mais quantidade

def makingAnagrams(s1, s2):

    ref_string = string.ascii_lowercase  # 'abcdefghijklmnopqrstuvwxyz'

    # Passo 1
    s1_dict = dict()
    s2_dict = dict()
    for ch in ref_string:
        s1_dict.update(
            {ch: s1.count(ch)}
        )
        s2_dict.update(
            {ch: s2.count(ch)}
        )
    removes = 0
    for value in ref_string:
        # Passo 2
        if s1_dict[value] != s2_dict[value]:
            # Passo 3
            removes += abs(s1_dict[value] - s2_dict[value])

    return removes
