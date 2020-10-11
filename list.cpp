#include "list.h"
#include <iostream>
#include <cstring>
using namespace std;

//implementations for the member functions of LinkedList class
LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList(){
    node *curr = head;
    while (curr)
    {
        head = curr->next;
        delete curr;
        curr = head;
    }
    size = 0;
}

// adding artist only
LinkedList::node *LinkedList::add(artist& anartist){
    cout << "...Calling add method on artist only..." << endl;
    node *newNode = new node(anartist);
    node* current; 
  
    if (!head){
        head = newNode;
    }
    else {
        current = head;
        /* Make the appropriate links */
        newNode->next = current->next; 
  
        // if the new node is not inserted 
        // at the end of the list 
        if (current->next != NULL) 
            newNode->next->prev = newNode; 
  
        current->next = newNode; 
        newNode->prev = current; 
    }
    size++;
    return newNode;
}
/*
LinkedList::node *LinkedList::split(LinkedList::node *head){
    cout << "...Calling split method..." << endl;
    node *fast = head;
    node *slow = tail;
    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    node *temp = slow->next;
    slow->next = NULL;
    return temp;
}

LinkedList::node *LinkedList::merge(node * first, node * second){
    if (!first){
        return second;
    }
    if (!second){
        return first;
    }
    if(first->s.getViews() <= second->s.getViews()){
        first->next = merge(first->next, second);
        first->next->prev = first;  
        first->prev = NULL;  
        return first;  
    }  
    else
    {  
        second->next = merge(first,second->next);  
        second->next->prev = second;  
        second->prev = NULL;  
        return second;  
    } 
}

LinkedList::node *LinkedList::mergeSort(node * newnode){
    cout << "...Calling mergesort method..." << endl;
    if (!newnode || !newnode->next){
        return newnode;
    }
    node *second = split(newnode);

    newnode = mergeSort(newnode);
    second = mergeSort(second);

    return merge(newnode, second);
}


LinkedList::node *LinkedList::get(artist &anartist){
    cout << "Calling get method" << endl;
    node *curr = head;
    while (curr)
    {
        if (curr->a.getName() == anartist.getName()){
            return curr;
        }
        curr = curr->next;
    }
}
*/

void LinkedList::add(song & asong, node *anartist){
    cout << "adding songs" << endl;
    node *newNode = new node(asong, anartist);
    cout << newNode->s.getTitle() << endl;
    cout << newNode->prev->s.getTitle() << endl;
    node *current = anartist->next;
    if (!current){
        cout << "there" << endl;
        
        anartist->next = newNode;
        
        
        cout << anartist->next->s.getTitle() << endl;
    }
    else {
        cout << "here" << endl;
        while (current->s.getViews() < newNode->s.getViews())
        {
            current = current->next;
        }
        anartist->next = newNode;
        newNode->next = current;
        current->prev = newNode;
    }
    

    size++;
}

void LinkedList::del(int m){
    cout << "...Calling delete method on..." << endl;
    node *curr = head;
    node *tmp = curr->next;
    int view = curr->s.getViews();
    if (curr == tail){
        cout << "End of List, delete complete" << endl;
    }
    else {
        if (view == m)
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
        del(m);
    }
}

void LinkedList::displayArtists(){
    cout << "atist " << endl;
    node *curr = head;
    /*
    cout << endl
         << "Displaying the Artists: " << endl;
    if (!curr->next){
        cout << curr->a.getName() << endl;
        cout << curr->a.getStory() << endl;
        cout << curr->a.getInfo() << endl;
    }
    else {
        */
    for (curr = head; curr; curr = curr->next)
    {
        cout << curr->a.getName() << endl;
        cout << curr->a.getStory() << endl;
        cout << curr->a.getInfo() << endl;
    }
    cout << endl;
}

void LinkedList::displaySongs(node *anartist){
    cout << "s" << endl;
    node *curr = anartist;
    cout << endl
         << "Display the Songs of " << anartist->a.getName() << endl;
    for (curr = anartist; curr; curr = curr->next)
    {
       
        cout << curr->s.getTitle() << endl;
        cout << curr->s.getLength() << endl;
        cout << curr->s.getViews() << endl;
        cout << curr->s.getLikes() << endl;
    }
    cout << endl;
}
