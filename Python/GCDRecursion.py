#GCD implemented using recursion
#
#This program implements calculation of GCD using the Euclidean recursive algorithm.
#Given two positive integers a and b such that a<b, gcd is calculated as follows:
# If a=0 or b=0, gcd(a,b) = 0
# Otherwise, gcd(a,b) = gcd(a,b%a)
#
#Example:
#   Input: 15 21
#   Output: 3


def gcd(a,b):
    x = min(a,b)
    y = max(a,b)
    if x==0 or y==0:
        return(0)
    else:
        if y%x == 0:
            return(x)
        else:
            return(gcd(x,y%x))

n = int(input("number 1: "))
m = int(input("number 2: "))

print("gcd: ", gcd(n,m))
