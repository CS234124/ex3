#include <iostream>

//setting up the node class

template<typename T>
class Queue {
private:
    class Node {

    public:
        ///Value of the Node
        T m_value;
        ///Next Node's pointer
        Queue<T>::Node *m_next;

        explicit Node() {
            m_next = nullptr;
        }

        Node(const Queue<T>::Node &other) : m_value(other.m_value), m_next(other.m_next) {}

        Node &operator=(const Queue<T>::Node &other) = default;

        ~Node() = default;

        bool &operator==(const Queue<T>::Node &other) {
            return m_value == other.m_value && m_next == other.m_next;
        }

        ///Gets pointer to the next node.
        /// \return pointer to the next node.
        Node *getNext() const {
            return m_next;
        }

        /// Sets next node.
        /// \param nextNode Pointer to the next node.
        void setNext(Queue<T>::Node *nextNode) {
            m_next = nextNode;
        }

        ///Gets value of the Node.
        T &getValue() {
            return m_value;
        }

        ///Gets const value of the Node.
        const T &getValue() const {
            return m_value;
        }
    };

    ///pointers to first and last nodes of the queue
    Queue<T>::Node *m_rear, *m_front;
    ///size of the queue
    int m_size;

    ///Pops all elements of the Queue until empty.
    void emptyQueue() {
        while (!isEmpty()) {
            popFront();
        }
    }

    ///Checks if the queue is empty.
    /// \return True if empty, False otherwise.
    bool isEmpty() const {
        return (m_front == nullptr) && (m_rear == nullptr);
    }

public:

    Queue() {
        m_front = nullptr;
        m_rear = nullptr;
        m_size = 0;
    }

    /// Copy c'tor of Queue.
    /// \param other Queue to copy.
    Queue(const Queue<T> &other) {
        m_front = nullptr;
        m_rear = nullptr;
        m_size = 0;
        for (T element: other) {
            try {
                pushBack(element);
            }
            catch (std::bad_alloc &e) {
                emptyQueue();
                throw e;
            }
        }
    }

    Queue &operator=(const Queue<T> &other) {
        if (this != &other) {
            emptyQueue();
            for (T element: other) {
                try {
                    pushBack(element);
                }
                catch (std::bad_alloc &e) {
                    emptyQueue();
                    throw e;
                }
            }
        }
        return *this;
    }

    ~Queue() {
        emptyQueue();
    }

    /// Pushes a new Element to the back of the Queue.
    /// \param value Value ot the Element to be pushed.
    void pushBack(const T value) {
        Queue<T>::Node *newNode = new Queue<T>::Node();

        try {
            newNode->m_value=value;
            if (isEmpty()) {
                m_front = newNode;
                m_rear = newNode;
            } else {
                m_rear->setNext(newNode);
                m_rear = newNode;
            }
            m_size++;
        }
        catch (const std::bad_alloc&) {
            delete newNode;
            throw;
        }
    }

    ///Pops out the front Element of the Queue. Does not return its value.
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

    /// Gets the first Element of the Queue
    /// \return
    T &front() const {
        if (isEmpty()) {
            throw EmptyQueue();
        }
        return m_front->getValue();
    }

    /// Gets the size of the Queue.
    /// \return size of the Queue.
    int size() const {
        return m_size;
    }

    ///Empty Queue exception class
    class EmptyQueue {
    };

    ///Iterator class of the Queue
    class Iterator {
        friend class Queue<T>;

    private:
        /// Queue of the iterator
        Queue<T> *m_queue;
        ///Current Element the Iterator is pointing to
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

    ///Const Iterator class of the Queue. Used to handle Queues of Const Elements
    class ConstIterator {
        friend class Queue<T>;

    private:
        /// Queue of the iterator
        Queue<T> const *m_queue;
        ///Current Element the Iterator is pointing to
        Queue<T>::Node const *m_currentNode;

        ConstIterator(const Queue<T> *queue, Queue<T>::Node *currentNode) : m_queue(queue),
                                                                            m_currentNode(currentNode) {}

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

    /// Gets an Iterator pointing to the beginning of the Queue
    Iterator begin() {
        return Iterator(this, m_front);
    }

    /// Gets an Iterator pointing to the end of the Queue (pointing to after the last element of the Queue)
    Iterator end() {
        if (m_rear == nullptr) {
            return Iterator(this, nullptr);
        }
        return Iterator(this, m_rear->getNext());
    }

    /// Gets a Const Iterator pointing to the beginning of the Queue
    ConstIterator begin() const {
        return ConstIterator(this, m_front);
    }

    /// Gets a Const Iterator pointing to the end of the Queue (pointing to after the last element of the Queue)
    ConstIterator end() const {
        if (m_rear == nullptr) {
            return ConstIterator(this, nullptr);
        }
        return ConstIterator(this, m_rear->getNext());
    }
};

/// Filters all the Queue's Elements according to a given condition function.
/// \tparam T Type of the Queue's Elements
/// \param currentQueue Queue to filter
/// \param conditionFunction Boolean Function that gets an Element and returns if it passed the condition.
/// \return New Queue filled only with the Elements that passed the condition function
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

/// Changes the Queue's Elements according to a transform function.
/// \param currentQueue Queue to transform
/// \param transformFunction Void Function that changes a given Element's value.
template<typename T, class TransformFunction>
void transform(Queue<T> &currentQueue, TransformFunction transformFunction) {
    for (T &element: currentQueue) {
        transformFunction(element);
    }
}



