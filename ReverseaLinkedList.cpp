/*
 * File: ReverseaLinkedList.cpp
 * This program allows the user to create a linked list data structure and to reverse the contents of the list.
 */

#include <iostream>
#include <cmath>

using namespace std;

// node object to create the linked list
struct node {
    int data;
    node *next;
};

// first node function that takes in the root of your linked list as an argument
void firstnode(node *root) {
    cout << "Enter the list: " << endl;
    cin >> root->data;
    root->next = NULL;
}

// function that creates the rest of the list; appends the incoming objects to the list
void l(node *root, node *current, int n) {
    current = root;
    for (int i = 0; i < n - 1 ; i++) {
        current->next = new node;
        current = current->next; 
        cin >> current->data;
    }
    current->next=NULL;
}

// function to reverse the linked list, provided the head of the previous list
void reversel(node **head_ref)
{
    node *prev = NULL;
    node *current = *head_ref;
    node *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

// function to print the list, provided the head and the current pointer from where one would like to begin printing
void print(node *root, node *current) {
    current = root;
    while ( current->next != NULL) {
        cout << current->data << "  ";
        current = current->next;
    }
    cout << current->data << endl;
}

int main() {
    node *root;
    root = new node;
    node *current;
    cout << "Please enter the number of nodes in your linked list: " << endl;
    int n;
    cin >> n;
    while (n <= 0) { // sanity checks
        cout << "The number of nodes in a linked list should be greater than zero. Please enter the number again: " << endl;
        cin >> n;
    }
    cout << endl;
    firstnode(root);
    l(root, current, n);
    cout << endl << "This is the current list: " << endl;
    print(root, current);
    reversel(&root);
    cout << endl << "This is the reversed list: " << endl;
    print(root, current);
}
