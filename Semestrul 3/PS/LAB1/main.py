import itertools
import math
import random
from random import sample
from math import factorial, perm, comb
from itertools import permutations, combinations, combinations_with_replacement

help(itertools.combinations_with_replacement)

def aranjamente(word, k, numar_total = False, aleator = False):
    if numar_total is True:
        print("Aranjamente: ",perm(k) * comb(len(word), k))
    elif aleator is True:
        print(sample(word, k))
    else:
        print(list(permutations(word, k)))


def combinari(word, k, numar_total = False, aleator = False):
    if numar_total is True:
        print("Combinari: ", comb(len(word),k))
    elif aleator is True:
        return [sample(word,)]
    else:
        print(list(combinations(word, k)))


def combinariRepetitii(word, k):
    for s in combinations_with_replacement(word, k):
        print(''.join(s))




if __name__ == '__main__':
    word = "word"

    #1 a
    print(list(permutations(word)), "\n")

    #1 b
    print("Permutari: ",factorial(len(word)), "\n")

    #1 c
    print(sample(word, 4))

    #2
    print("\n2.")
    aranjamente(word, 2, aleator=True)

    #3
    print("\n3.")
    combinari(word, 2, numar_total=True)

    #4
    print("\n4.")
    combinariRepetitii(word, 4)

    #5
    print("\n5.")
    aranjamente("00000000", 5, numar_total=True)