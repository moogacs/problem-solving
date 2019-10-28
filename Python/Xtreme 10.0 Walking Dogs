tC = int(input())
for t in range(tC):
    n,k = [int(i) for i in input().split()]
    dogs = []
    diffs = []
    for j in range(n):
        dogs.append(int(input()))

    dogs = sorted(dogs)
    for j in range(len(dogs)-1):
        diffs.append(dogs[j+1] - dogs[j])

    diffs = sorted(diffs)

    value = dogs[-1] - dogs[0]
    if k!=1:
        value -= sum(diffs[-(k-1):])
        
    print(value)
