#include <iostream>

//setting up the node class
template <typename T> class Node
{
    public:
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
        //TODO ADD EXCEPTION
            if(isEmpty()){
                m_front = temp;
                m_rear = temp;
            }
            else{
                m_rear->m_next=temp;
                m_rear=temp;
            }
            m_size++;
    }

    void PopFront() {
            if(isEmpty()){
                throw EmptyQueue();
            }

            else{
                m_size--;
                if(m_front==m_rear){
                    delete (*this->m_front);
                    //will also delete m_rear as they point to the same space
                }
                else{
                    Node<T>* temp=m_front;
                    m_front=m_front->next;
                    delete (temp);
                }
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

    //TODO add the const_iterator to the class

private:

    Node<T>* m_rear, m_front;
    int m_size;

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

template <typename T, typename U>
void transform (Queue<T> CurrentQueue , U (&TransformFunction)(T)) {

    for( const T& element : CurrentQueue){
        TransformFunction(&element->m_value);
        }

};



