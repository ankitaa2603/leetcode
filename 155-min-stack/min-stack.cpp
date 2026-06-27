#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    MinStack() {
    }

    void push(int x) {
        mainStack.push(x);

        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop(); 
        }
        mainStack.pop(); 
    }

    int top() {
        return mainStack.top();
    }

    int getMin() {
        return minStack.top(); 
    }
};
