Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false



class MyQueue {
public:
    stack<int> s1, s2;
    /** Initialize your data structure here. */
    MyQueue() {
        
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        
        s1.push(x);
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        int x;
        if(s2.empty())
        {
            while(!s1.empty())
            {
                int x = s1.top();
                s2.push(x);
                s1.pop();
            }
        }
        x = s2.top();
        s2.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        
        if(s2.empty())
        {
            while(!s1.empty())
            {
                int x = s1.top();
                s2.push(x);
                s1.pop();
            }
        }
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        
        if(s1.empty() && s2.empty())
            return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
