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
void LinkedList::add(artist& anartist){
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

*/
int LinkedList::find(int aviews){
    cout << "...Calling find method on..." << aviews << endl;
    node *curr = head->next;
    int count = 0;
    if (curr->s.getViews() < aviews && curr != NULL){ 
        ++count;
        cout << count << endl;
        return count;
    }
    else{
        if (curr->next != NULL){
            head = head->next;
            return find(aviews);
        }
        else{
            return false;
        }
    }
}


void LinkedList::add(song &asong){
    cout << "adding songs" << endl;
    node *newNode = new node(asong);
    node* current; 
    if (!head->next){
        head->next = newNode;
    }
    else {
        current = head->next;
        /* Make the appropriate links */
        while (current->next && current->s.getViews()> newNode->s.getViews()){
            current = current->next;
        }
        newNode->next = current->next; 
  
        // if the new node is not inserted 
        // at the end of the list 
        if (current->next != NULL) 
            newNode->next->prev = newNode; 
  
        current->next = newNode; 
        newNode->prev = current; 
    }
    size++;
}

void LinkedList::del(int m){
    cout << "...Calling delete method on..." << m << endl;
    node *ptr = head->next;
    //change the next and prev only if they are not null
    while(ptr){
        if (ptr->s.getViews() < m){
            if(ptr->next != NULL)
                ptr->next->prev = ptr->prev;
            
 
            if(ptr->prev != NULL)
                ptr->prev->next = ptr->next;
               
            delete(ptr); //delete the node
        }
        ptr = ptr->next;
    }
}

    /*
    node *tmp = tail;
    int count = find(m);
    if (count >= 1)
    {
        for (int i = 0; i <= count; i++)
        {
            cout << "count" << endl;
            if (tmp == NULL)
            {
                cout << "Nodata" << endl;
            }
            else{
                node *curr = tmp;
                curr->next->prev = tmp->prev->prev;
                curr->prev->next = 
                delete tmp;
                cout << "count" << endl;
                return true;
            }
            cout << "s" << endl;
        }
    }
    else{
        cout << "nothing to delete" << endl;
        return false;
    }
}*/
    /*
    if (LinkedList::find(m))
    {
        if (tmp->s.getViews() < m){
            head->next = tmp->next;
            delete tmp;
            cout << m << " deleted" << endl;
            return true;
        }
        else {
            while (tmp!= NULL){ 
                if (tmp->s.getViews() < m){
                    node *curr = tmp;
                    curr->prev->next = tmp->next;
                    curr->next->prev = tmp->prev;
                    delete tmp;
                    cout << m << " 2deleted" << endl;
                    return true;
                }
                tmp = tmp->next;
            }
            cout << "Unable to delete character" << endl;
            return false;
        }
    }
    else{
    if (head->next){
        head = head->next;
        return del(m);
    }
    cout << "No character found" << endl;
    }
    return false;
}
*/
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
        cout << "Name: " << curr->a.getName() << endl;
        cout << "Story: " << curr->a.getStory() << endl;
        cout << "Info: " << curr->a.getInfo() << endl;
    }
    cout << endl;
}

void LinkedList::displaySongs(){
    cout << "s" << endl;
    node *curr;
    cout << "Display the Songs of " << head->a.getName() << endl;
    
    for (curr = head->next; curr; curr = curr->next)
    {
        cout << "===========" << endl;
        cout << curr->s.getTitle() << endl;
        cout << curr->s.getLength() << endl;
        cout << "Views: " << curr->s.getViews() << endl;
        cout << curr->s.getLikes() << endl;
    }
    
}
