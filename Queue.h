#include <iostream>

//setting up the node class
template <typename T> class Node
{
    public:
    // bunch of types

    Node( T member) {
        this->m_value = member;
        this->m_next = NULL;
    }

    private:
    T m_value;
    T* m_next;
};

template <typename T>
class Queue {

    public:

    Queue(){
        m_front=NULL;
        m_rear=NULL;
        m_size=0;
            }

    class Iterator{
    public:
        const T& operator*() const{
            return m_current->m_value;
        }

        Iterator& operator++(){
            m_current=m_current->m_next;
            return *this;
        }
        Iterator& operator++(int){
            return ++*this;
        }

        //TODO need a checkup
        bool operator!=(const Iterator& it) const{
            if(queue==it.queue){
                return m_current == it.m_current;
            }
            else{
                return false;
            }
        }

    private:
        const Queue<T>* queue;
        Node<T>* m_current;
        Iterator(const Queue<T>* queue , Node<T>* m_current){
            this->queue = queue;
            this->m_current = m_current;
        }
        friend class Queue<T>;

    };
    Iterator begin() const{
        return Iterator(this, m_front);
    }
    Iterator end() const{
        return Iterator(this, m_rear);
    }


    //declaring and writing the functions
    bool isEmpty() {
        return (m_front==NULL) && (m_rear==NULL);
    }

    void Pushback(Node<T>* n){
            if(isEmpty()){
                m_front = n;
                m_rear = n;
            }
            else{
                m_rear->m_next=n;
                m_rear=n;
            }
            m_size++;

    }
    Node<T>* Front() {
            if (isEmpty()){
                return NULL;
            }

            return m_front;

    }
    Node<T>* PopFront() {
            Node<T>* temp=NULL;
            if(isEmpty()){
                return NULL;
            }

            else{
                m_size--;
                if(m_front==m_rear){
                    temp=m_front;
                    m_front=NULL;
                    m_rear=NULL;
                    return temp;
                }
                else{
                    temp=m_front;
                    m_front=m_front->next;
                    return temp;
                }

            }
    }

    int Size() {
            return m_size;
    }

    private:

    Node<T>* m_rear, m_front;
    int m_size;

};


template <typename T>
Queue<T> Filter (Queue<T> CurrentQueue , bool(&conditionFunction)(T)) {


    //TODO not sure if i need const or not.
    for( T& element : CurrentQueue){
        if{

        }


    }
};

template <typename T>
Queue<T> transform (Queue<T> queue1 , bool(&conditionFunction)(T)) {};



