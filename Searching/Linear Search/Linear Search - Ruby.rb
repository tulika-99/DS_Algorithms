# frozen_string_literal: true

def linear_search(data, item)
  data.each_with_index do |element, index|
    return index if element == item
  end

  -1 # Element Not Found
end

data = [10, 2, 5, 16, 9, 13, 25, 30, 45, 100]

puts "Data = #{data}"
puts
puts "Index for Item 2 = #{linear_search(data, 2)}"
puts "Index for Item 9 = #{linear_search(data, 9)}"
puts "Index for Item 30 = #{linear_search(data, 30)}"
puts "Index for Item 100 = #{linear_search(data, 100)}"
puts "Index for Item 99999 = #{linear_search(data, 99_999)}"
puts "Index for Item 1 in empty data = #{linear_search([], 1)}"
