# Goal: Write a program that prints the numbers from 1 to 50 but:
#   - For multiples of three print “Fizz” instead of the number.
#   - For the multiples of five print “Buzz” intead of the number.
#   - For numbers which are multiples of both three and five print “FizzBuzz” intead of the number.
#
# There are many ways to solve this but here is two alternatives:


# Using string concatenation:
for i in range(1, 51):
    string = ""
    if i % 3 == 0:
        string = string + "Fizz"
    if i % 5 == 0:
        string = string + "Buzz"
    if i % 5 != 0 and i % 3 != 0:
        string = string + str(i)
    print(string)

# Using if, elif and else
for i in range(1, 51):
    if i % 3 == 0 and i % 5 == 0:
        print("FizzBuzz")
    elif i % 3 == 0:
        print("Fizz")
    elif i % 5 == 0:
        print("Buzz")
    else:
        print(i)
