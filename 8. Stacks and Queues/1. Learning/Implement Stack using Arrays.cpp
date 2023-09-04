// Stack class.
class Stack {
    
public:
    int *arr;
    int top1;
    int size;

    Stack(int capacity) {
        // Write your code here.
        size=capacity;
        top1=-1;
        arr=new int[capacity];
    }

    void push(int num) {
        // Write your code here.
        if(!isFull())
        arr[++top1]=num;
    }

    int pop() {
        // Write your code here.
        if(isEmpty()) return -1;
        top1--;
        return arr[top1+1];
    }
    
    int top() {
        // Write your code here.
        if(isEmpty()) return -1;
        return arr[top1];
    }
    
    int isEmpty() {
        // Write your code here.
        return (top1==-1)? 1:0;
    }
    
    int isFull() {
        // Write your code here.
        return (top1+1==size)? 1:0;
    }
    
};
