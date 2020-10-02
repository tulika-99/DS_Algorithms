def getSmallestLargest(s, k):
    curr = s[:k]
    lexmin = curr
    lexmax = curr
    for i in range(k, len(s)):
        curr = curr[1:k] + s[i]
        if lexmax < curr:
            lexmax = curr
        if lexmin > curr:
            lexmin = curr

    return lexmin, lexmax
        
s = "shaonakundu"
k = 3
res = getSmallestLargest(s, k)
print(res)