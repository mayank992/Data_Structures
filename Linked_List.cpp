#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node *next;
    node(int data = 0, node* next = NULL) {
        this -> data = data;
        this -> next = next;
    }
};

class linkedList {
    public:
        node *Head, *Tail;
    linkedList() {
        Head = NULL;
        Tail = NULL;
    }
    void Builder();
    void insert_at_Head(int data);
    void insert_at_Tail(int data);
    void insert_at_position_k(int data, int k);
    void reverse_Iterative();
    void reverse_Recursive(node *prev, node *nextNode);
    void print();
    int delete_at_Head();
    int delete_at_Tail();
    int delete_kth_node(int k);
    int search_Iterative(int key);
    int search_Recursive(node *ptr, int pos, int key);
    int get_kth_from_Front(int k);
    int get_kth_from_Last(int k);
    int get_mid();
};

void linkedList::Builder() {
    int n, data;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> data;
        insert_at_Tail(data);
    }
    cout << "Linked List after Build: ";
    print();
}

void linkedList::insert_at_Head(int data) {
    if(Head == NULL) {
        Head = Tail = new node(data);
        return ;
    }
    node* temp = new node(data, Head);
    Head = temp;
}

void linkedList::insert_at_Tail(int data) {
    if(Head == NULL) {
        Head = Tail = new node(data);
        return ;
    }
    Tail -> next = new node(data);
    Tail = Tail -> next;
}

void linkedList::insert_at_position_k(int data, int k) {
    if(Head == NULL) {
        insert_at_Head(data);
        return ;
    }
    node *it = Head;
    while(k != 2) {
        it = it -> next;
        k--;
    }
    node *temp = new node(data, it -> next);
    it -> next = temp;
}

void linkedList::reverse_Iterative() {
    cout << "Linked List after Reversal(Iterative): ";
    if(Head == NULL || Head -> next == NULL) {
        print();
        return ;
    }
    node *prev = NULL, *current = Head, *nextNode;
    while(current != NULL) {
        nextNode = current -> next;
        current -> next = prev;
        prev = current;
        current = nextNode;
    }
    Head = prev;
    print();
}

void linkedList::reverse_Recursive(node *prev = NULL, node *nextNode = NULL) {
    if(Head == NULL || Head -> next == NULL) {
        if(Head != NULL)
            Head -> next = prev;
        cout << "Linked List after Reversal(Recursive): ";
        print();
        return ;
    }
    nextNode = Head -> next;
    Head -> next = prev;
    prev = Head;
    Head = nextNode;
    reverse_Recursive(prev, nextNode);
}

int linkedList::delete_at_Head() {
    if(Head == NULL) 
        return -1;
    node *temp = Head;
    Head = Head -> next;
    int ret = temp -> data;
    delete temp;
    return ret;
}

int linkedList::delete_at_Tail() {
    if(Head == NULL || Head -> next == NULL) {
        return delete_at_Head();
    }
    node *temp = Head;
    while(temp -> next != Tail) {
        temp = temp -> next;
    }
    Tail = temp;
    temp = temp -> next;
    Tail -> next = NULL; 
    int ret = temp -> data;
    delete temp;
    return ret;
}

int linkedList::delete_kth_node(int k) {
    if(k == 1) 
        return delete_at_Head();
    node *temp = Head, *p;
    while(k != 2) {
        temp = temp -> next;
        k--;
    }
    p = temp -> next;
    temp -> next = p -> next;
    int ret = p -> data;
    delete p;
    return ret;
}

int linkedList::search_Iterative(int key) {
    node *temp = Head;
    int pos = 1;
    while(temp -> data != key && temp != NULL) {
        pos++;
        temp = temp -> next;
    }
    if(temp == NULL)
        return -1;
    else
        return pos;
}

int linkedList::search_Recursive(node *ptr, int pos, int key) {
    if(ptr == NULL) {
        return -1;
    }
    if(ptr -> data == key)
        return pos;
    return search_Recursive(ptr -> next, pos + 1, key);
}

int linkedList::get_kth_from_Front(int k) {
    node *temp = Head;
    k--;
    while(k--) 
        temp = temp -> next;
    return temp -> data;
}

int linkedList::get_kth_from_Last(int k) {
    node *temp1 = Head, *temp2 = Head;
    k--;
    while(k--)
        temp2 = temp2 -> next;
    while(temp2 -> next != NULL) {
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
    return temp1 -> data;
}

int linkedList::get_mid() {
    node *temp1 = Head, *temp2 = Head -> next;
    while(temp2 != NULL && temp2 -> next != NULL) {
        temp1 = temp1 -> next;
        temp2 = temp2 -> next -> next;
    }
    return temp1 -> data;
}

void linkedList::print() {
    if(Head == NULL) {
        cout << "Empty\n";
        return ;
    }
    node *it = Head;
    while(it != NULL) {
        cout << it -> data << ((it -> next == NULL)? ("\n"): (" --> "));
        it = it -> next;
    }
}

int main() {
    linkedList obj;
    obj.Builder();
    obj.insert_at_position_k(3, 3);// insert(data, position)
    cout << "Linked List after insertion at position Kth: ";  obj.print();
    obj.reverse_Iterative();
    obj.reverse_Recursive();
    cout << "Deleted element at Head: " << obj.delete_at_Head() << "\n";
    cout << "Deleted element at Tail: " << obj.delete_at_Tail() << "\n";
    cout << "Deleted element at Kth posiiton: " << obj.delete_kth_node(2) << "\n";//delete(position)
    cout << "Linked List after Deletion: "; obj.print();
    int pos = obj.search_Iterative(4);//search(position)
    if(pos == -1)
        cout << "Search Key(Iterative): Key not Found\n";
    else 
        cout << "Search Key(Iterative): Key Found at position " << pos << "\n";
    pos = obj.search_Recursive(obj.Head, 1, 4);//search(position)
    if(pos == -1)
        cout << "Search Key(Recursive): Key not Found\n";
    else 
        cout << "Search Key(Recursive): Key Found at position " << pos << "\n";
    cout << "Kth element from Front: " << obj.get_kth_from_Front(3) << "\n";
    cout << "Kth element from Last: " << obj.get_kth_from_Last(3) << "\n";
    cout << "Midlle Element: " << obj.get_mid() << "\n";
    return 0;
}


