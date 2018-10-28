# From: Python Programming: An Introduction to Computer Science
# Written by: John Zelle

# A caesar cipher is a simple substitution cipher based on the idea of
# shifting each letter of the plaintext message a fixed number 
# (called the key) of positions in the alphabet.

# For example, if the key value is 2, the word "Sourpuss" would be
# Encoded as "Uqwtrwuu". The original message can be recovered
# by "reencoding" it using the negative of the key.

# Write a program to encode and decode Caesar ciphers, being sure
# to deal with long keys in a circular fashion. The input will only be
# letters and spaces.

# ANSWER BELOW:

from string import ascii_lowercase, ascii_uppercase

def ccipher(string, key):
    # Shifts in a circular fashion
    new = ""
    for ch in string:
        if ch in ascii_lowercase:
            add = ascii_lowercase.index(ch)
            if add + key > 25:
                new += ascii_lowercase[add+key-24]
            else:
                new += ascii_lowercase[add+key]
        elif ch in ascii_uppercase:
            add = ascii_uppercase.index(ch)
            if add + key > 25:
                new += ascii_uppercase[add+key-24]
            else:
                new += ascii_uppercase[add+key]
        else:
            new += ch
    return new

def ccipherAnsCirc(string, key):
    chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz"
    new = ""
    for ch in string:
        pos = chars.find(ch)
        # Use remainder division to take care of circular shift
        newpos = (pos + key) % len(chars)
        cipher = cipher + chars[newpos]

def main():
    print("This program will cipher your message.")
    string = input("Please enter a short text to encode: ")
    key = int(input("Please enter the key to shift letters: "))
    print("The cipher of your text is: {0}".format(ccipher(string, key)))

if __name__ == "__main__":
    main()