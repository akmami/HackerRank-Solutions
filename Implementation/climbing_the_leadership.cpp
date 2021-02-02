#include <stdio.h>
#include <iostream>

using namespace std;
// 1st Solution
class List {
public:
    List(): size(0), head(NULL) {}
    ~List(){
        while (size!=0)
            remove();
    }  // end Distructor
    void show() {
        ListNode* cur=head;
        while(cur!=NULL) {
            cout << cur->item << " ";
            cur=cur->next;
        }
        cout << endl;
    }
    int insert(int newItem, bool sorted) {


        ListNode *newPtr = new ListNode;
        size++;
        newPtr->item = newItem;
        
        if( sorted ) {
            ListNode* cur=head;
            int place=0;
            while(cur->item > newItem) {
                cur=cur->next;
                if(cur==head) {
                    place=1;
                } else {
                    if(cur->prev->item!=cur->item)
                        place++;
                }
                if(cur->next == NULL)
                    break;
            }
            if(cur==head) {
                newPtr->next = head;
                newPtr->prev = NULL;
                head = newPtr;
            } else if(cur->item > newItem && cur->next==NULL) {
                cur->next=newPtr;
                newPtr->next=NULL;
                newPtr->prev=cur;
                place++;
            } else {
                cur->prev->next=newPtr;
                newPtr->prev=cur->prev;
                cur->prev=newPtr;
                newPtr->next=cur;
            }
            return place;
        }
        if (head==NULL) {
            newPtr->next = NULL;
            newPtr->prev = NULL;
            head = newPtr;
        }
        else {
            ListNode* cur = head;
            while(cur->next != NULL)
                cur=cur->next;
            
            cur->next=newPtr;
            newPtr->prev=cur;
            newPtr->next=NULL;
        }
        return 0;
    } // end insert

    bool remove() {
        size--;
        ListNode* temp=head;
        if(size==0) {
            delete head;
            head=NULL;
            return true;
        }
        temp->next->prev=NULL;
        head=temp->next;
        
        temp->next=NULL;
        delete temp;
        temp = NULL;
        return true;
    }  // end remove
private:
    struct ListNode{
        int item;
        ListNode *next, *prev;
    };
    int       size;
    ListNode *head;
};

int main()
{
    int scores_count;
    cin >> scores_count;

    List scores;
    for (int i = 0; i < scores_count; i++) {
        int scores_item;
        cin>> scores_item;
        scores.insert(scores_item, false);
    }

    int alice_count;
    cin >> alice_count;

    for (int i = 0; i < alice_count; i++) {
        int alice_item;
        cin >> alice_item;
        cout << scores.insert(alice_item, true) + 1<< endl;
    }
    
    scores.show();
    return 0;
}

// 2nd Solution
//#include <stdio.h>
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    
//    stack<int> s;
//    int temp;
//    cin >> temp;
//    s.push(temp);
//    for(int i = 1; i < n; i++) {
//        cin >> temp;
//        if(s.top() != temp)
//            s.push(temp);
//    }
//    
//    int m;
//    cin >> m;
//    for(int i = 0; i < m; i++){
//        cin >> temp;
//        while(!s.empty() && temp >= s.top())
//            s.pop();
//        cout << s.size()+1 << endl;
//    }
//    
//    return 0;
//}
