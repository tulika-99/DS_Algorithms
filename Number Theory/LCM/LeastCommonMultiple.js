// Let's find the smallest number that could be divided with both numbers.
// Here's the easy way.

function findLCM (num1, num2) {
	let lcm = 1;
  
  while(true){
    if((lcm % num1 == 0) && (lcm % num2 == 0)){
        break;
    } // The first number we find at the end of this process would be the least number.
      lcm++;
    }
  	return lcm
}