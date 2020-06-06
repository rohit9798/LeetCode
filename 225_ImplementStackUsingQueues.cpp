Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Example:

MyStack stack = new MyStack();

stack.push(1);
stack.push(2);  
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false



class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1, q2;
    MyStack() {
    
    }
    
    
    /** Push element x onto stack. */
    void push(int x) {
        
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        
        if(q1.size() == 0)
            return -1;
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        
        if(q1.size() == 0)
            return -1;
        int x = q1.front();
        return x;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        
        if(q1.size() == 0 && q2.size() == 0)
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
