def selection_Sort(a):
  i = 0
  while i < len(a):
    k = i
    j = i + 1

    while j < len(a):
      if a[j] < a[k]:
          k = j
      j += 1

    temp = a[i]
    a[i] = a[k]
    a[k] = temp    
    i += 1

  return a
