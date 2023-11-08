#include<iostream>
#include<vector>

using namespace std;

class MinStack {
    private:
       int min;
       int top;
    public:
        MinStack() {
            vector<int> stack;
            vector<int> minStack;
            top = -1;
            min = -1;
        }
        void push(int x) {
            top++;
            stack.push_back(x);
            if(min == -1 || x < min) {
                min++;
                minStack.push_back(x);
            }
        }
        void pop() {
            if(stack.top() == minStack.top()) {
                minStack.pop_back();
                min--;
            }
            stack.pop_back();
        }
        int top() {
            return stack.top();
        }
        int getMin() {
            return minStack.top();
        }
};