/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/

#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
    stack<int> s1;
    stack<int> s2;

    public:
    void push(int x) {
        s1.push(x);
        
        if (s2.empty()) {
            s2.push(x);
        } else {
            s2.push(min(x, getMin()));
        }
    }

    void pop() {
        s1.pop();
        s2.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }
};


void main()
{
    int data = 0;
    MinStack minStack;// = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    data = minStack.getMin(); // Returns - 3.
    printf("%d\n", data);
    minStack.pop();
    data = minStack.top();    // Returns 0.
    printf("%d\n", data);
    data = minStack.getMin();  // Returns - 2.
    printf("%d\n", data);
}


/*
class MinStack {

public:
// initialize your data structure here.
MinStack() {

}

void push(int x)
{
arr_.emplace_back(x);

for (it_ = list_.begin(); it_ != list_.end(); ++it_)
{
if (x < *it_)
{
list_.insert(it_, x);
return;
}
}

list_.emplace_back(x);  // if list empty or not found min
}

void pop()
{
int last = arr_.size() - 1;
int x = arr_[last];
arr_.erase(arr_.begin() + last);


for (it_ = list_.begin(); it_ != list_.end(); ++it_)
{
if (x == *it_)
{
list_.erase(it_);
return;
}
}
}

int top()
{
return arr_[arr_.size() - 1];
}

int getMin()
{
return *list_.begin();
}

private:
vector<int> arr_;
list<int> list_;
list<int>::const_iterator it_;
};*/