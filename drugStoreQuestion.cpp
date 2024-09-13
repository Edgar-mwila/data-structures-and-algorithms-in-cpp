/*
    
*/
#include <iostream>
using namespace std;

struct drug {
    string name;
    int quantity;
    double price;  
};

struct Node {
    drug drugData;
    Node* next;
    Node* prev;
};

class LinkedList {
    Node* head;
    public:
    LinkedList() { head = nullptr; }
    void Add(drug drug);
    drug Search(string name);
    void Display();
    void Delete(string name);
};

void App(){
    LinkedList DrugList;
    int option;
    while(true){
        cout<<"menu \n"<<"======================\n"<<"choices\n"<<"1 Add \n"<<"2 search \n"<<"3 Display \n"<<"4 Delete \n" << "5 exit \n";
        cout<<"Enter your choice: ";
        cin>>option;
        if(option == 1){
            string name;
            double price;
            int quantity;
            cout<<"Enter Drugs name: ";
            cin>>name;
            cout<<"Enter drug quantity: ";
            cin>>quantity;
            cout<<"Enater drug Price: ";
            cin>>price;

            DrugList.Add({name, quantity, price});
        }
        if(option == 2){
            string name;
            cout<<"enter drug to be searched: ";
            cin>>name;
            drug drug = DrugList.Search(name);
            cout<<"Name: "<<drug.name<<"\nQuantity: "<<drug.quantity<<"\nPrice: "<<drug.price<<endl;
        }
        if(option == 3){
            DrugList.Display();
            cout<<endl;
        }
        if(option == 4){
            string name;
            cout<<"enter drug to be Deleted: ";
            cin>>name;
            DrugList.Delete(name);
        }
        if(option == 5) return;
    }
}
int main()
{
    App();
    return 0;
}

void LinkedList::Add(drug drug)
{
    Node* newDrug = new Node();
    newDrug->drugData = drug;
    newDrug->next = head;
    newDrug->prev = nullptr;
    if(head != nullptr){
        head->prev = newDrug;
    }
    head = newDrug;
}

drug LinkedList::Search(string name)
{
    Node* temp = head;
    while(temp != nullptr){
        if(temp->drugData.name == name){
            return temp->drugData;
        }
        temp = temp->next;
    }
    return drug();
}

void LinkedList::Display()
{
    Node* temp = head;
    int count = 1;
    cout<<"NO \t"<<"Name \t"<<"Quantity \t"<<"Price"<<endl;
    while(temp != nullptr){
        cout<<count<<"\t"<<temp->drugData.name<<"\t"<<temp->drugData.quantity<<"\t"<<temp->drugData.price<<endl;
        temp = temp->next;
        count ++;
    }
}

void LinkedList::Delete(string name) {
    Node* temp = head;
    Node* prev = nullptr; // Keep track of the previous node

    while (temp != nullptr) {
        if (temp->drugData.name == name) {
            // Found the node to delete
            if (prev == nullptr) {
                // Node to delete is the head node
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            cout << "Deleted " << name << " from the list." << endl;
            delete temp; // Free the memory
            return; // Exit the function
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Error" << name << " not found in the list." << endl;
}
