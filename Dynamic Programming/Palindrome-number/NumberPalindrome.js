function numPalindrome(x) {
  // make a copy of param
  let tmpNum = x;
  let reversedNum = 0;
  while (tmpNum > 0) {
    // multiply reversedNum with base position of tmpNum % 10
    reversedNum = reversedNum * 10 + (tmpNum % 10);
    tmpNum = Math.trunc(tmpNum / 10);
  }

  return x == reversedNum;
}
