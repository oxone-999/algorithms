#include <bits/stdc++.h>

using namespace std;

class Queue{
private:
    struct QNode{
        int data;
        QNode *next;

        QNode(const int &x){
            data = x;
            next = nullptr;
        }
    };

    QNode *start, *end;
    int capacity;

public:
    Queue(){
        capacity = 0;
        start = nullptr;
        end = nullptr;
    }

    int size(){
        return capacity;
    }

    int front(){
        if(start){
            return start->data;
        }
        return -1;
    }

    void push(const int &x){
        QNode *newNode = new QNode(x);
        if(!start){
            start = newNode;
            end = newNode;
        }else{
            end->next = newNode;
            end = end->next;
        }
        capacity++;
    }

    void pop(){
        if(start){
            QNode* front = start;
            start = start->next;
            delete front;

            if(!start){
                end = start;
            }
            capacity--;
        }
    }

    bool isEmpty(){
        return capacity==0;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(4);
    q.push(7);
    while(!q.isEmpty()){
        cout<<q.front()<<endl;
        q.pop();
    }

    return 0;
}