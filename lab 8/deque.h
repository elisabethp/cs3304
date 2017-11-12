#ifndef _DEQUE_H_
#define  _DEQUE_H_

#include <iostream>
#include <cstdlib>

template <typename T>
class deque
{
public:
    typedef std::size_t size_type;
    static const size_type CAPACITY = 10;
    
    //postcondition: empty deque has been created
    deque();
    
    //precondition: deque is not empty
    // postcondition: reference to element at front of deque
    //                            has been returned
    T& front();
    
    // precondition: deque is not empty
    // postcondition: copy of element at front of deque
    //                            has been returned
    T front() const;
    
    // precondition: deque is not empty
    // postcondition: reference to element at front of deque
    //                            has been returned
    T& back();
    
    // precondition: deque is not empty
    // postcondition: copy of element at back of deque
    //                            has been returned
    T back() const;
    
    // precondition: deque is not full
    // postcondition: entry has been inserted at the front
    //                            of the deque
    void push_front (const T& entry);
    
    // precondition: deque is not full
    // postcondition: entry has been inserted at the back
    //                            of the deque
    void push_back (const T& entry);
    
    // precondition: deque is not empty
    // postcondition: element at front of deque has been removed
    void pop_front();
    
    // precondition: deque is not empty
    // postcondition: element at back of deque has been removed
    void pop_back();
    
    // postcondition: number of elements in deque has been returned
    size_type size() const;
    
    // postcondition: whether deque is empty has been returned
    bool empty() const;
    
    // postcondition: whether deque is full has been returned
    bool full() const;
    
    // postcondition: returned whether 2 deques are equal - equal is defined
    //                            as the deques have the same number of elements &
    //                            corresponding elements are equal
    template <typename U>
    friend bool operator == (const deque<U>& dq1, const deque<U>& dq2);

    // postcondition: dq has been display from front to rear on out
    template <typename U>
    friend std::ostream& operator<< (std::ostream& out, const deque<U>& dq);

private:
    T data[CAPACITY];     // Circular array
    size_type first;         // Index of item at front of the queue
    size_type last;          // Index of item at rear of the queue
    size_type count;         // Total number of items in the queue

    // postcondition: returned next index in array
    size_type next_index(size_type i) const;
    
    // postcondition: returned previous index in array
    size_type prev_index (size_type i) const;
};



#include "deque.template"

#endif