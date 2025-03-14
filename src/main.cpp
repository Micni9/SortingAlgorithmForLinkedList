#include "list_node.h"
#include "sortings.h"
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {4, 2, 1, 3,23,12313,4858,-23,235,19,15,58};
    cout<<"Original list: ";
    for(int i = 0; i < vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    
    while(1){
        ListNode *head = create_list(vec);
        cout<<"\nPlease choose the sorting method or end the program: "<<endl;
        cout<<"0. End the program"<<endl;

        
        vector<string> sortings = {"selection", "insertion", "bubble", "merge", "quick"};
        for(int i = 0; i < sortings.size(); i++){
            cout<<i+1<<". "<<sortings[i]<<" sort"<<endl;
        }
        cout<<"Your choice: ";
        char choice;
        cin>>choice;

        switch(choice){
            case '0':
                return 0;
            case '1':
                selection_sort(head);
                break;
            case '2':
                insertion_sort(head);
                break;
            case '3':
                bubble_sort(head);
                break;
            case '4':
                merge_sort(head);
                break;
            case '5':
                quick_sort(head);
                break;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
                char c = cin.get();
                while(!isdigit(c)){
                    c = cin.get();
                }
                cin.putback(c);
                continue;
        }

        cout<<"After "<<sortings[choice-'1']<<" sort: ";
        print_list(head);
        if(is_sorted(head)){
            cout<<"The list is sorted correctly"<<endl;
        }
        else{
            cout<<"The list is not sorted correctly."<<endl;
        }
    }

    return 0;
}