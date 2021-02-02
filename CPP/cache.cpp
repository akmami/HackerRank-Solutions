#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};
class LRUCache : public Cache {
public:
    LRUCache(int capacity) {cp=capacity; tail=NULL; head=NULL;}
    void set(int key, int value) {
        bool exists = false;
        Node * node = NULL;
        for(Node* h=head; h!=NULL; h=h->next) {
            if(h->key == key) {
                node = h;
                exists = true;
            }
        }
        if(exists) {
            cout<<"exists"<<endl;
            if(node==head) {
                head->value = value;
                return;
            }
            if(head == node->prev && node == tail) {
                node->prev=NULL;
                node->next=head;
                head->prev=node;
                head->next=NULL;
                tail=head;
                head=node;
                head->value = value;
                return;
            }
            if(node==tail) {
                Node * node = tail;
                tail = node->prev;
                tail->next = NULL;
                node->next = head;
                node->prev = NULL;
                head->prev = node;
                head = node;
                head->value = value;
                return;
            }
            node->prev->next = node->next;
            node->next->prev = node->prev;
            head->prev = node;
            node->prev = NULL;
            node->next = head;
            head = node;
            head->value = value;
        } else {
            Node * newNode = new Node(key, value);
            if(head == NULL) {
                mp.insert(pair<int, Node*>(key, newNode));
                head = newNode;
                tail = newNode;
                return;
            }
            int count=0;
            for(Node* h=head; h!=NULL; h=h->next) {
                count++;
            }
            if(count == cp) {
                Node * node = tail;
                node->prev->next=NULL;
                tail = node->prev;
                mp.erase (node->key);
                mp.insert(pair<int, Node*>(key, newNode));
                head->prev = newNode;
                newNode->next = head;
                head = newNode;
                return;
            }
            mp.insert(pair<int, Node*>(key, newNode));
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    int get(int key) {
        
        for(Node* h=head; h!=NULL; h=h->next) {
            if(h->key == key) return h->value;
        }
        return -1;
    }
};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
