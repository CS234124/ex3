#include <iostream>

//setting up the node class
template <typename T> class Node
{
private:
    T m_value;
    Node<T>* m_next;

public:
    Node( T member) {
        m_value = member;
        m_next = NULL;
    }

    Node<T>* getNext(){
        return m_next;
    }
};

template <typename T>
class Queue {

private:
    Node<T>* m_rear, *m_front;
    int m_size;


public:

    Queue(){
        m_front=NULL;
        m_rear=NULL;
        m_size=0;
    }

    ~Queue(){
        while (!isEmpty())
        {
            PopFront();
        }
    }

    //declaring and writing the functions
    bool isEmpty() {
        return (m_front==NULL) && (m_rear==NULL);
    }

    void Pushback(T* n){

        Node<T>* temp=new Node<T>*(n);
//TODO how to assign the exception of bad_alloc

        if(isEmpty()){
            m_front = temp;
            m_rear = temp;
        }
        else{
            m_rear->getNext()=temp;
            m_rear=temp;
        }
        m_size++;
    }

    void PopFront() {
        if(isEmpty()){
            throw EmptyQueue();
        }
        m_size--;
        if(m_front==m_rear){
            delete (m_front);
        }
        else{
            Node<T>* temp=m_front;
            m_front= m_front->getNext();
            delete (temp);
        }
    }


    Node<T>* Front() {
        if (isEmpty()){
            throw EmptyQueue();
        }
        return m_front;
    }

    int Size() {
        return m_size;
    }

    //exception
    class EmptyQueue{};

    //iterator definition
    class Iterator{
    public:
        //exception
        class InvalidOperation{};

        //constructor and defining
        const T& operator*() const{

            if(*this==NULL){
                throw InvalidOperation{};
            }
            return m_current->m_value;
        }

        Iterator& operator++(){

            if(*this==NULL){
                throw InvalidOperation{};
            }

            m_current=m_current->m_next;
            return *this;
        }
        Iterator& operator++(int){
            return ++*this;
        }

        //TODO need a checkup - in the end
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


    //TODO add the const_iterator to the class

};

template <typename T>
Queue<T> Filter (Queue<T> CurrentQueue , bool(&conditionFunction)(T)) {

    Queue<T> queue;
    for( const T& element : CurrentQueue){
        if(conditionFunction(element.m_value)){
            queue.pushBack(element);
        }
    }
    return queue;
};

//TODO make sure its the same tyoe and shit
template <typename T, typename U>
void transform (Queue<T> CurrentQueue , U (&TransformFunction)(T)) {

    for( const T& element : CurrentQueue){
        TransformFunction(&element->m_value);
    }

};



