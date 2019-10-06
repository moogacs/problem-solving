def gcd(a,b):
    x = min(a,b)
    y = max(a,b)
    if y%x == 0:
        return(x)
    else:
        return(gcd(x,y%x))

n = int(input("number 1: "))
m = int(input("number 2: "))

print("gcd: ", gcd(n,m))
