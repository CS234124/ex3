#include <iostream>

//setting up the node class

template<typename T>
class Queue {
    class Node {
    private:
        T m_value;
        Queue<T>::Node *m_next;

    public:
        Node(T value) {
            m_value = value;
            m_next = nullptr;
        }

        Node(const Queue<T>::Node &other) : m_value(other.m_value), m_next(other.m_next) {}

        Node &operator=(const Queue<T>::Node &other) = default;

        ~Node() = default;

        bool &operator==(const Queue<T>::Node &other) {
            return m_value == other.m_value && m_next == other.m_next;
        }

        Node *getNext() const {
            return m_next;
        }

        void setNext(Queue<T>::Node *nextNode) {
            m_next = nextNode;
        }

        T &getValue() {
            return m_value;
        }

        const T &getValue() const {
            return m_value;
        }
    };
private:
    Queue<T>::Node *m_rear, *m_front;
    int m_size;

    void emptyQueue() {
        while (!isEmpty()) {
            popFront();
        }
    }

    bool isEmpty() const {
        return (m_front == nullptr) && (m_rear == nullptr);
    }

public:

    Queue() {
        m_front = nullptr;
        m_rear = nullptr;
        m_size = 0;
    }

    Queue(const Queue<T> &other) {
        m_front = nullptr;
        m_rear = nullptr;
        m_size = 0;
        for (T element: other) {
            pushBack(element);
        }
    }

    Queue &operator=(const Queue<T> &other) {
        if (this != &other) {
            emptyQueue();
            for (T element: other) {
                pushBack(element);
            }
        }
        return *this;
    }

    ~Queue() {
        emptyQueue();
    }

    void pushBack(const T value) {
        Queue<T>::Node *temp = new Queue<T>::Node(value);

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
        if (m_front == m_rear) {
            delete (m_front);
            m_front = nullptr;
            m_rear = nullptr;
        } else {
            Queue<T>::Node *temp = m_front;
            m_front = m_front->getNext();
            delete (temp);
        }
        m_size--;
    }

    T &front() const {
        if (isEmpty()) {
            throw EmptyQueue();
        }
        return m_front->getValue();
    }

    int size() const {
        return m_size;
    }

    //exception
    class EmptyQueue {
    };

    class Iterator {
        friend class Queue<T>;

    private:
        Queue<T> *m_queue;
        Queue<T>::Node *m_currentNode;

        Iterator(Queue<T> *queue, Queue<T>::Node *currentNode) : m_queue(queue), m_currentNode(currentNode) {}

        bool operator==(const Iterator &it) const {
            return m_queue == it.m_queue && m_currentNode == it.m_currentNode;
        }

    public:
        Iterator(const Iterator &other) : m_queue(other.m_queue), m_currentNode(other.m_currentNode) {}

        Iterator &operator=(const Iterator &other) = default;

        ~Iterator() = default;

        //operators
        T &operator*() const {
            if (*this == m_queue->end()) {
                throw InvalidOperation{};
            }
            return m_currentNode->getValue();
        }

        Iterator &operator++() {
            if (*this == m_queue->end()) {
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
        Queue<T>::Node const *m_currentNode;

        ConstIterator(const Queue<T> *queue, Queue<T>::Node *currentNode) : m_queue(queue), m_currentNode(currentNode) {}

        bool operator==(const ConstIterator &it) const {
            return m_queue == it.m_queue && m_currentNode == it.m_currentNode;
        }

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
            if (*this == m_queue->end()) {
                throw InvalidOperation{};
            }
            return m_currentNode->getValue();
        }

        ConstIterator &operator++() {
            if (*this == m_queue->end()) {
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
        if (m_rear == nullptr) {
            return Iterator(this, nullptr);
        }
        return Iterator(this, m_rear->getNext());
    }

    ConstIterator begin() const {
        return ConstIterator(this, m_front);
    }

    ConstIterator end() const {
        if (m_rear == nullptr) {
            return ConstIterator(this, nullptr);
        }
        return ConstIterator(this, m_rear->getNext());
    }
};

template<typename T, class ConditionFunction>
Queue<T> filter(const Queue<T> &currentQueue, ConditionFunction conditionFunction) {
    Queue<T> filteredQueue;
    for (const T element: currentQueue) {
        if (conditionFunction(element)) {
            filteredQueue.pushBack(element);
        }
    }
    return filteredQueue;
}

template<typename T, class TransformFunction>
void transform(Queue<T> &currentQueue, TransformFunction transformFunction) {
    for (T &element: currentQueue) {
        transformFunction(element);
    }
}



