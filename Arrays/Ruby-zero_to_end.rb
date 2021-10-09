def move_zeros(array)
  length = array.length
  count = 0
  length.each do |i|
    if array[i] != 0
      array[count] = array[i]
      count += 1
    end
  end
  # Loop from count to len-1 and fill it with zeros
  while count < length
    array[count] = 0
    count += 1
  end
  array
end
