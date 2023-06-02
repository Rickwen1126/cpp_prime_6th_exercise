#ifndef QUEUE_TP_H_
#define QUEUE_TP_H_

template <typename T>
class Queue
{
private:
    struct Node
    {
        T item;
        Node *next;
    };
    enum
    {
        Q_SIZE = 10
    };
    Node *front;
    Node *rear;
    int items;
    const int qsize;

    // preemptive defeinitions to prevent public copying
    Queue(const Queue &q) : qsize(0)
    {
    }
    Queue &operator=(const Queue &q) { return *this; }

public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const T &item);
    bool dequeue(T &item);

    // new for exercise 5
    T &operator[](int i) const; // performance is bed, maybe there is better way to do this
    bool deleteNodeByIdx(int i);
};

#endif