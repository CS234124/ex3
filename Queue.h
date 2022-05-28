#include <iostream>

//setting up the node class
template<typename T>
class Node {
private:
    T m_value;
    Node<T> *m_next;

public:
    Node(T value) {
        m_value = value;
        m_next = NULL;
    }

    Node(const Node<T> &other) : m_value(other.m_value), m_next(other.m_next) {}

    Node &operator=(const Node<T> &other) = default;

    ~Node() = default;

    Node *getNext() const {
        return m_next;
    }

    void setNext(Node<T> *nextNode) {
        m_next = nextNode;
    }

    T &getValue() {
        return m_value;
    }

    const T &getValue() const {
        return m_value;
    }
};

template<typename T>
class Queue {

private:
    Node<T> *m_rear, *m_front;
    int m_size;


public:

    Queue() {
        m_front = NULL;
        m_rear = NULL;
        m_size = 0;
    }

    ~Queue() {
        while (!isEmpty()) {
            popFront();
        }
    }

    //declaring and writing the functions
    bool isEmpty() {
        return (m_front == NULL) && (m_rear == NULL);
    }

    void pushBack(T value) {
        Node<T> *temp = new Node<T>(value);
//TODO how to assign the exception of bad_alloc

        if (isEmpty()) {
            m_front = temp;
            m_rear = temp;
        } else {
            m_rear->setNext(temp);
            m_rear = temp;
        }
        m_size++;
    }

    void popFront() {
        if (isEmpty()) {
            throw EmptyQueue();
        }
        m_size--;
        if (m_front == m_rear) {
            delete (m_front);
        } else {
            Node<T> *temp = m_front;
            m_front = m_front->getNext();
            delete (temp);
        }
    }

    T &front() {
        if (isEmpty()) {
            throw EmptyQueue();
        }
        return m_front->getValue();
    }

    int size() {
        return m_size;
    }

    //exception
    class EmptyQueue {
    };

    class Iterator {
        friend class Queue<T>;

    private:
        Queue<T> *m_queue;
        Node<T> *m_currentNode;

        Iterator(Queue<T> *queue, Node<T> *currentNode) : m_queue(queue), m_currentNode(currentNode) {
        }

    public:
        Iterator(const Iterator &other) : m_queue(other.m_queue), m_currentNode(other.m_currentNode) {}

        Iterator &operator=(const Iterator &other) = default;

        ~Iterator() = default;

        //operators
        T &operator*() const {
            if (this == NULL) {
                throw InvalidOperation{};
            }
            return m_currentNode->getValue();
        }

        Iterator &operator++() {
            if (this == NULL) {
                throw InvalidOperation{};
            }
            m_currentNode = m_currentNode->getNext();
            return *this;
        }

        Iterator &operator++(int) {
            return ++*this;
        }

        bool operator!=(const Iterator &it) const {
            return m_queue != it.m_queue || m_currentNode != it.m_currentNode;
        }

        //exception
        class InvalidOperation {
        };
    };

    class ConstIterator {
        friend class Queue<T>;

    private:
        Queue<T> const *m_queue;
        Node<T> const *m_currentNode;

        ConstIterator(const Queue<T> *queue, Node<T> *currentNode) : m_queue(queue), m_currentNode(currentNode) {}

    public:
        ConstIterator(const ConstIterator &other) = default;

        ConstIterator(const Iterator &other) : m_queue(other.m_queue), m_currentNode(other.m_currentNode) {}

        ConstIterator &operator=(const ConstIterator &other) = default;

        ConstIterator &operator=(const Iterator &other) {
            m_queue = other.m_queue;
            m_currentNode = other.m_currentNode;
        }

        ~ConstIterator() = default;

        const T &operator*() const {
            if (this == NULL) {
                throw InvalidOperation{};
            }
            return m_currentNode->getValue();
        }

        ConstIterator &operator++() {
            if (this == NULL) {
                throw InvalidOperation{};
            }

            m_currentNode = m_currentNode->getNext();
            return *this;
        }

        ConstIterator &operator++(int) {
            return ++*this;
        }

        bool operator!=(const ConstIterator &it) const {
            return m_queue != it.m_queue || m_currentNode != it.m_currentNode;
        }

        //exception
        class InvalidOperation {
        };
    };

    Iterator begin() {
        return Iterator(this, m_front);
    }

    Iterator end() {
        return Iterator(this, m_rear->getNext());
    }

    ConstIterator begin() const {
        return ConstIterator(this, m_front);
    }

    ConstIterator end() const {
        return ConstIterator(this, m_rear->getNext());
    }
};

template<typename T>
Queue<T> filter(Queue<T> currentQueue, bool(&conditionFunction)(T)) {
    Queue<T> filteredQueue;
    for (const T &element: currentQueue) {
        if (conditionFunction(element)) {
            filteredQueue.pushBack(element);
        }
    }
    return filteredQueue;
};

//TODO make sure its the same tyoe and shit
template<typename T>
void transform(Queue<T> currentQueue, void (&transformFunction)(T &)) {

    for (T element: currentQueue) {
        transformFunction(element);
    }
};



