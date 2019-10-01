"""
Roman numeral conversion:
 * Given a Roman number (I, II, III, IV, ...) in input, convert and print it into arabic numeral system (1, 2, 3, ...)
 * Example:
 *  Input: MMXIX
 *  Output: 2019
"""

import sys

# In this sample code the input is received from terminal (argv[1])
value1 = sys.argv[1]

M = 1000
D = 500
C = 100
L = 50
X = 10
V = 5
I = 1

supp = []
out = 0

for char in value1:
    if char == 'M':
        supp.append(M)
    if char == 'D':
        supp.append(D)
    if char == 'C':
        supp.append(C)
    if char == 'L':
        supp.append(L)
    if char == 'X':
        supp.append(X)
    if char == 'I':
        supp.append(I)
    if char == 'V':
        supp.append(V)

supp.append(0)

# calculate the number in arabic numeral
for i in range(len(supp) - 1):
    if supp[i] < supp[i+1]:
        out -= supp[i]
    else:
        out += supp[i]

print(out)