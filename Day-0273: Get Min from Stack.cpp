// Get Min from Stack (MEDIUM)
// https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1


class Solution {
    stack<int> mainStack;
    stack<int> minStack;

public:
    Solution() {
        while (!mainStack.empty()) mainStack.pop();
        while (!minStack.empty()) minStack.pop();
    }

    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (!mainStack.empty()) {
            if (mainStack.top() == minStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    int peek() {
        if (!mainStack.empty()) {
            return mainStack.top();
        }
        return -1;
    }

    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        return -1;
    }
};
