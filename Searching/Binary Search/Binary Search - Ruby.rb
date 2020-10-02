# frozen_string_literal: true

def binary_search(data, item)
  return -1 if data.empty?

  left = 0
  right = data.length - 1
  mid = 0

  index = -1

  while left <= right
    mid = (left + right) / 2

    if data[mid] < item
      left = mid + 1
    elsif data[mid] > item
      right = mid - 1
    elsif data[mid] == item
      index = mid
      break
    end
  end

  index
end

sorted_data = [1, 2, 5, 6, 9, 13, 25, 30, 45, 100]

puts "Data = #{sorted_data}"
puts
puts "Index for Item 1 = #{binary_search(sorted_data, 1)}"
puts "Index for Item 5 = #{binary_search(sorted_data, 5)}"
puts "Index for Item 30 = #{binary_search(sorted_data, 30)}"
puts "Index for Item 100 = #{binary_search(sorted_data, 100)}"
puts "Index for Item 99999 = #{binary_search(sorted_data, 99_999)}"
