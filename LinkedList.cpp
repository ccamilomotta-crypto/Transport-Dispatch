#include <stdexcept>
#include "LinkedList.h"

// TODO(student): implement a linked list
LinkedList::LinkedList():head{nullptr}{}
LinkedList::LinkedList(const LinkedList& other):head{nullptr}{
    Node* current =other.head;
    Node* tail =nullptr;
    while(current!=nullptr){
        Node* new_node =new Node(current->value);
        if(head ==nullptr){
            head =new_node;
        }else{
            tail->next =new_node;
        }
        tail =new_node;
        current =current->next;
    }
}
LinkedList::~LinkedList(){
    clear();
}
LinkedList& LinkedList::operator=(const LinkedList& other){
    if(this ==&other){
        return *this;
    }
    LinkedList copy(other);
    Node* temp =head;
    head =copy.head;
    copy.head =temp;
    return *this;
}
bool LinkedList::empty()const{
    return head ==nullptr;
}
unsigned LinkedList::size()const{
    unsigned count =0;
    Node* current =head;
    while(current!=nullptr){
        ++count;
        current =current->next;
    }
    return count;
}
int LinkedList::at(unsigned index)const{
    Node* current =head;
    unsigned current_index =0;
    while(current !=nullptr&&current_index<index){
        current =current->next;
        ++current_index;
    }
    if(current ==nullptr){
        throw std::out_of_range("index out of bounds");
    }
    return current->value;
}
int LinkedList::front()const{
    if(empty()){
        throw std::out_of_range("list is empty");
    }
    return head->value;
}
void LinkedList::add(int value,unsigned index){
    if(index>size()){
        throw std::out_of_range("index out of bounds");
    }
    if(index==0){
        head =new Node(value, head);
        return;
    }
    Node* previous =head;
    for(unsigned i =0;i<index -1;++i){
        previous =previous->next;
    }
    previous->next =new Node(value,previous->next);
}
void LinkedList::remove(unsigned index){
    if(index>=size()){
        throw std::out_of_range("index out of bounds");
    }
    if(index ==0){
        Node* old_head =head;
        head =head->next;
        delete old_head;
        return;
    }
    Node* previous =head;
    for(unsigned i=0;i <index-1;++i){
        previous =previous->next;
    }
    Node* node_to_delete =previous->next;
    previous->next =node_to_delete->next;
    delete node_to_delete;
}
void LinkedList::clear(){
    while(head !=nullptr){
        Node* node_to_delete =head;
        head =head->next;
        delete node_to_delete;
    }
}
