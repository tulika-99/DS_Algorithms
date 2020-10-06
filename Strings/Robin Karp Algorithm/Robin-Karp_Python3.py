"""
Rabin-Karp is a pattern searching algorithm to find the pattern in a efficient
way. It checks the pattern by moving window one by one, but without checking
all characters for all cases, it finds the hash value. When the hash value is
matched, then only it tries to check each character.
It uses hash functions and the rolling hash technique.
A hash function is essentially a function that maps one thing to a value.
A rolling hash allows an algorithm to calculate a hash value without having to
rehash the entire string

Limitations of Rabin-Karp Algorithm
Spurious Hit
When the hash value of the pattern matches with the hash value of a window of
the text but the window is not the actual pattern then it is called a spurious
hit.

Spurious hit increases the time complexity of the algorithm. In order to
minimize spurious hit, we use modulus. It greatly reduces the spurious hit.
"""

## Time complexity : O(m+n)  Worst case: O(mn).

# d is the number of characters in the input alphabet
d = 256

def search(pat, txt, q):
    M = len(pat)
    N = len(txt)
    p = 0    # hash value for pattern
    t = 0    # hash value for txt
    h = 1

    # The value of h would be "pow(d, M-1)%q"
    for i in range(M-1):
        h = (h*d)%q

    # Calculate the hash value of pattern and first window
    # of text
    for i in range(M):
        p = (d*p + ord(pat[i]))%q
        t = (d*t + ord(txt[i]))%q

    # Slide the pattern over text one by one
    for i in range(N-M+1):
        # Check the hash values of current window of text and
        # pattern if the hash values match then only check
        # for characters on by one
        if p==t:
            # Check for characters one by one
            for j in range(M):
                if txt[i+j] != pat[j]:
                    break
                else:
                    j += 1

            # if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if j==M:
                print("Pattern found at index: {}".format(str(i)))

        # Calculate hash value for next window of text: Remove
        # leading digit, add trailing digit
        if i < N-M:
            t = (d*(t-ord(txt[i])*h) + ord(txt[i+M]))%q

            # We might get negative values of t, converting it to
            # positive
            if t < 0:
                t = t+q

# Driver Code
if __name__ == '__main__':
    txt = """Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer
    sit amet risus nibh. Etiam tempus magna mi, ac congue dui gravida ac.
    Aliquam  sit amet lectus elementum, convallis turpis sed, porttitor sapien.
    Sed scelerisque quis nibh at tincidunt. Nunc pretium luctus tincidunt. Cras
    pharetra mollis nulla nec tincidunt. Curabitur vitae eros risus. Cras eget
    augue ipsum. Class aptent taciti sociosqu ad litora torquent per conubia
    nostra, per inceptos himenaeos. Phasellus vehicula nec augue a venenatis."""
    pat = "sit"

    # A prime number
    q = 101

    # Function Call
    search(pat,txt,q)
