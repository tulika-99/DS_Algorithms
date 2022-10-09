def maxSubArray(nums):
        maximumSum = -1e8
        currentSum = 0
        for i in range(0, len(nums)):
            currentSum = currentSum + nums[i]
            if(currentSum > maximumSum):
                maximumSum = currentSum
            if(currentSum < 0):
                currentSum = 0
                         
        return maximumSum

if __name__ == "__main__":
    print(maxSubArray([3, 1, 9, -4, 2, -7, 1]))