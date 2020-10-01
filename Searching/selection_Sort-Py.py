#  a is our list
def selection_Sort(a):
  i = 0
  while i < len(a):
    k = i
    j = i + 1  #  we set j to the next element after i so that we can compare them

    while j < len(a):
      if a[j] < a[k]:
          k = j
      j += 1  #  keep comparing j with other elements until it finds one that is lower

    temp = a[i]
    a[i] = a[k]
    a[k] = temp  #  move on to the next element
    i += 1

  return a
