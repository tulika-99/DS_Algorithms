def fib(n):

	fib_numbers = [0,1] # initial two fib numbers
    
	for i in range(2,n+1): # start at 2nd number, go up to nth
		fib_numbers.append(fib_numbers[-1] + fib_numbers[-2]) # next fibonnaci number is a sum of the last two
	return fib_numbers[n] # return nth fib number

n=4
print(fib(n))