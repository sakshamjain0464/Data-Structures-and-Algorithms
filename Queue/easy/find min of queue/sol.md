# Find Minimum of QUEUE
## Approach 
1. Use a recursive function with the reference of queue and a min variable.
2. if queue is empty return min.
3. else take out the front of the queue, and check, 
    - if the front is less than the previous min, assign front to min.
    - go to the next call and assign its return value to min.
    - check if the min is not equal to front push front to queue.(This will not push the minimum to the queue)
    - return min.

(If we need to take out the minimum element from queue we can take it out or else we can skip the check if the min is not equal to front push front to queue part)

## Code
```cpp
    long long findMin(queue<long long> &q, long long min){
        if(q.empty()){
            return min;
        }
        else{
            long long front = q.front();
            q.pop();
            if(front < min){
                min = front;
            }
                
            min = findMin(q, min);
            
            if(min != front){
                q.push(front)
            }
            
            return min;
        }
    }
```