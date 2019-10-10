def is_leap(year):
    leap = False
    if (year%400==0):
        leap = True
    elif (year%100==0):
        leap == False
    elif (year%4==0):
        leap = True
    else:
        leap = False
    return leap

year = int(input())

res=is_leap(year)

if res == True:
    print("\nYes it's a Leap Year!")
else:
    print("\nNot a Leap Year!")
