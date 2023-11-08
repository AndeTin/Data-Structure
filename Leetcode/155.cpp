#include<iostream>
#include<vector>

using namespace std;

class MinStack {
    private:
        vector<int> stack;
        vector <int> min;
        int topn;
        int minn;
    public:
        MinStack() {
            topn = -1;
            minn = -1;
            vector <int> stack;
            vector <int> min;
        }
        void push(int x) {
            if (topn == -1) {
                topn++;
                minn++;
                stack.push_back(x);
                min.push_back(x);
                }
            else if (x < min[topn]) {
                stack.push_back(x);
                min.push_back(x);
                topn++;
                minn++;
                }
            else {
                stack.push_back(x);
                topn++;
                }
            }
        void pop() {
            if (topn == -1) {
                return;
            }
            else if (min[minn] == stack[topn]) {
                stack.pop_back();
                min.pop_back();
                topn--;
                minn--;
            }
            else {
                stack.pop_back();
                topn--;
            }
        }
        int top() {
            if (topn == -1) {
                return -1;
            }
            else {
                return stack[topn];
            }
        }
        int getMin() {
            if (topn == -1) {
                return -1;
            }
            else {
                return min[minn];
            }
        }
        
};