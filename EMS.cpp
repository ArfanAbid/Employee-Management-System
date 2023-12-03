        //  Employee Management System using doubly linked list
#include<iostream>
#include<exception>
#include <string>
using namespace std;

class Node{
public:
    string name;
    string department;
    string designation;
    int id;
    int salary;

    Node* next;
    Node* previous;

    Node(string name, string department, string designation, int id, int salary){
        this->name = name;
        this->department = department;
        this->designation = designation;
        this->id = id;
        this->salary = salary;

        this->next=NULL;
        this->previous = NULL;
    }
};

class EmployeeManagementSystem{
private:
    Node * head;
    Node * tail;
public:
    //Constructor
    EmployeeManagementSystem(){
        this->head = NULL;
        this->tail = NULL;
    }
    //Destructor
    ~EmployeeManagementSystem(){
        Node* current = head;
        while(current != NULL) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
        
    }
    //  Function to Display the Employee Management System Record
    void display(){
        Node* temp=head;
        while(temp != NULL) {
        cout<<"ID: "<<temp->id<<"\t Name: "<<temp->name<<"\t Department: "<<temp->department<<"\t Designation: "<<temp->designation<<"\t Salary: "<<temp->salary<<endl;
            temp=temp->next;
        }
    }
    // Function to add Record
    void insertAtLast(string name, string department, string designation, int id, int salary){
        Node* node = new Node(name, department, designation, id, salary);
        if(head==NULL){  // if LL is empty 
            head = node;
            tail = node;
        }else{

            tail->next=node;
            node->previous=tail;
            tail=node;
            }


    }

    // Function to Delete Record
    void deleteRecord(int idToDelete){
        if(head==NULL){ // if LL is empty
            throw runtime_error("No Record to Delete !!! ");
        }else if(head->id==idToDelete){  // Delete First Record
            Node* toDelete=head;
            head=head->next;
            if (head != NULL) {
                head->previous = NULL;
            } else {
                tail = NULL; // If the list becomes empty
            }
            delete toDelete;

        }else if(tail->previous!=NULL && tail->id==idToDelete){ // Delete Last element
            Node* toDelete=tail;
            tail=tail->previous;
            tail->next=NULL;
            delete toDelete;
        }
        else{                                // Delete at specifix position
            Node* current=head;
            while( current->next != NULL  && current->next->id!=idToDelete ){
                current=current->next;
            }
            if(current->next==NULL){
                cout<<idToDelete<<" Not Found !!!";
                return;
            }
            Node* toDelete=current->next;
            current->next=current->next->next;
            current->next->previous=current;
            delete toDelete;
        }    


    
    }
    // Function to display Particular ID Data
    void displaySpecificRecord(Node* node){
        cout<<"ID: "<<node->id<<"\t Name: "<<node->name<<"\t Department: "<<node->department<<"\t Designation: "<<node->designation<<"\t Salary: "<<node->salary<<endl;
    }

    // Function to Search record by ID
    void searchById(int idToSearch){
        Node* temp =head;
        while(temp!=NULL){
            if(temp->id==idToSearch){
                cout<<"Record for ID: "<<idToSearch<<" is Found. "<<endl;
                displaySpecificRecord(temp);
                return;
            }
            else{
                cout<<"Record for ID: "<<idToSearch<<" is Not Found !!! "<<endl;
                return;
            }
        }
    }

    // Function to search record by Name
    void searchByName(string toFind){
        Node* temp =head;
        while(temp!=NULL){
            if(temp->name==toFind){
                cout<<"Record for ID: "<<toFind<<" is Found. "<<endl;
                displaySpecificRecord(temp);
                return;
            }
            else{
                cout<<"Record for Name: "<<toFind<<" is Not Found !!! "<<endl;
                return;
            }
        }

    }



};
int main(){
    EmployeeManagementSystem EMS;
    EMS.insertAtLast("arfan","CS","programmer",55,50000);
    EMS.insertAtLast("Abisheekh","SE","programmer",66,1000000);
    EMS.insertAtLast("Ahmed","CE","SOk Analyst",77,900000);
    EMS.display();
    cout<<endl;

    EMS.deleteRecord(55);
    EMS.display();
    cout<<"_______________________________"<<endl;

    EMS.searchById(66);
    EMS.searchByName("arfan ");

}
