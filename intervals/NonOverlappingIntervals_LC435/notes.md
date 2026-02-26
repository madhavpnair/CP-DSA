- here it is to be noted that we have to **sort the intervals based on the `end_time` and not `start_time`**

`eg : [1,100],
 [2,3],
 [3,4]`
- the key idea is 
```
min number of overlapping intervals to be removed  = total - max number of non-overlapping intervals
```  

- **TODO** <br>the implementation takes linear space and can be optimized to constant space 