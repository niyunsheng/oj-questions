/**
 * @Date:   2018-07-21
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-07-28
 */



//225. 用队列实现栈
//这个题目太简单了，没有重复的意义
class MyStack {
public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t;
        for(int i=0;i<q.size()-1;i++){
            t=q.front();
            q.pop();
            q.push(t);
        }
        t=q.front();
        q.pop();
        return t;
    }

    /** Get the top element. */
    int top() {
        return q.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
