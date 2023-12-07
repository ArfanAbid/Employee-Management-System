        //  Employee Management System using doubly linked list
#include<iostream>
#include<windows.h>
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
    void insert(){
        int ID,salary;string name, department, designation;
        cout<<"Fill the Following Data :: "<<endl;
        cout<<"ID of Employee: ";cin >> ID;
        cout<<"Name of Employee: ";cin.ignore();getline(cin, name);
        cout<<"Department of Employee: ";getline(cin, department);
        cout<<"Designation of Employee: ";getline(cin, designation);
        cout<<"Salary of Employee: ";cin >> salary;
        insertAtLast(name,department,designation,ID,salary);
        cout<<"Record Added Successfully."<<endl;

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
    void Delete(){
        int id;
        cout<<"Enter the ID of Employee you want to delete : ";
        cin>>id;
        deleteRecord(id);

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
            cout<<"Record Deleted SuccessFully "<<endl;
            delete toDelete;

        }else if(tail->previous!=NULL && tail->id==idToDelete){ // Delete Last element
            Node* toDelete=tail;
            tail=tail->previous;
            tail->next=NULL;
            cout<<"Record Deleted SuccessFully "<<endl;
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
            cout<<"Record Deleted SuccessFully "<<endl;
            delete toDelete;
        }    


    
    }

    void search(){
            int ch;int searchID;string searchName;

            cout<<" 1. Search By ID "<<endl;
            cout<<" 2. Search By Name "<<endl;
            cout<<"Enter your choice "<<endl;
            cin >> ch;
            if(ch == 1){
                cout<<"Enter ID you want to search : ";
                cin>>searchID;
                searchById(searchID);
            }else{
                cout<<"Enter Name you want to search : ";
                cin>>searchName;
                // searchByName(searchName);           
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
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"Record for ID: "<<idToSearch<<" is Not Found !!! "<<endl;
        }
    }

    //Function to search record by Name
    // void searchByName(string toFind){
    //     Node* temp =head;
    //     while(temp!=NULL){
    //         if(temp->name==toFind){
    //             cout<<"Record for Name: "<<toFind<<" is Found. "<<endl;
    //             displaySpecificRecord(temp);
    //             return;
    //         }
    //         temp=temp->next;
    //     }
    //     if(temp==NULL){
    //         cout<<"Record for Name: "<<toFind<<" is Not Found !!! "<<endl;

    //     }
    // }
    void update(){
        int idToUpdate,id,salary;string name,department,designation;
        cout<<"Enter the ID of a particular Employee you wants to update Record : ";cin>>idToUpdate;
        cout<<"Please Fill the following fields : "<<endl;
        cout<<"Enter the ID of Employee to update : ";cin>>id;
        cout<<"Enter the Name of the Employee to update : ";cin.ignore();getline(cin,name);
        cout<<"Enter the Department of Employee to update : ";getline(cin,department);
        cout<<" enter the Designation of the Employee to update : ";getline(cin,designation);
        cout<<"Enter the Salary of the Employee to update : ";cin>>salary;
        updateRecord(idToUpdate,name,department,designation,id,salary);
    }
    bool isPresent(int idToSearch){
        Node* temp =head;
        while(temp!=NULL){
            if(temp->id==idToSearch){
                displaySpecificRecord(temp);
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    // Function to update the record
    void updateRecord(int idToUpdate,string name, string department, string designation, int id, int salary){
        Node* temp=head;
        if(isPresent(idToUpdate)){
            while(temp!=NULL){
                if(temp->id==idToUpdate){
                    temp->name = name;
                    temp->department = department;
                    temp->designation = designation;
                    temp->id = id;
                    temp->salary = salary;
                    cout<<"Record Updated SuccessFully"<<endl;
                    return;
                }
                temp=temp->next;
            }
        }else{
            cout << "Record for ID: " << idToUpdate << " is Not Found !!" << endl;

        }
    }

    void menu(){
        cout<<"\t*** MENU ***"<<endl;
        cout<<"1. Add Employee Record"<<endl;
        cout<<"2. Search Employee Record"<<endl;
        cout<<"3. Update Employee Record"<<endl;
        cout<<"4. Delete Employee Record"<<endl;
        cout<<"5. Display All  Employees Record"<<endl;
        cout<<"6. Sort Record "<<endl;
        cout<<"7. Assign Bonus"<<endl;
        cout<<"8. Exit."<<endl;
        cout<<"Enter Your choice (1-8) : ";
    }
    
    void EXIT(){
        cout<<"Exiting ";
        for(int k=0;k<6;k++){        
		    cout<<".";
	        Sleep(600);
	    }
    }

};





int main(){
    EmployeeManagementSystem EMS;
    int ch;
    while(true){
        // system("cls");
        EMS.menu();
        cin >> ch;

    switch(ch){
        case 1 :
            EMS.insert();
            break;
        case 2 :
            EMS.search();
            break;
        case  3 :
            EMS.update();
            break;
        case 4 :
            EMS.Delete();
            break;
        case 5 :
            EMS.display();
            break;
        case 6 :
            break;
        case 7 :
            break; 
        case 8 :
            EMS.EXIT();
            exit(0);
            break;       
        default :
            cout<<"Invalid Choice!!! Please  try again."<<endl;                    

        }

    }


}
