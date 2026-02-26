## Approach 1 : XOR trick
use 

``` 
a ^ a = 0 
a ^ 0 = a
```

`(0 ^ 1 ^ 2 ^ ... ^ i ... ^ n ) (0 ^ 1 ^ 2 ^ ... ^ i-1 ^ i+1 ^ ... ^ n) = i`

## Approach 2 : Sum formula

`sum of first n natural numbers = n(n+1)/2`<br>
deduct the sum of the numbers in the given array from this sum to get the missing number<br>
`missing number = sum[0..n] - sum[nums]`