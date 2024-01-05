        //  Employee Management System using doubly linked list
#include<iostream>
#include<queue>
#include<exception>
#include<windows.h>
#include <string>
#include <algorithm> // For Transform : Uppercase and lowercase
#include<fstream>
#include<sstream>

using namespace std;

class Node{
public:
    string name;
    string department;
    string designation;
    int id;
    int salary;
    double yearsOfService;

    Node* next;
    Node* previous;

    Node(int data){
        this->salary = data;
    }
    Node(string name, string department, string designation, int id, int salary,double years){
        this->name = name;
        this->department = department;
        this->designation = designation;
        this->id = id;
        this->salary = salary;
        this->yearsOfService = years;

        this->next=NULL;
        this->previous = NULL;
    }
};

class EmployeeManagementSystem{
private:
    Node * head;
    Node * tail;
    queue<Node*> bonusQueue;
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
            cout<<"ID: "<<temp->id<<"\t Name: "<<temp->name<<"\t Department: "<<temp->department<<"\t Designation: "<<temp->designation<<"\t Salary: "<<temp->salary<<"\t Years of Service: "<<temp->yearsOfService<<endl;
            temp=temp->next;
        }
    }
    // Function to display Particular ID Data
    void displaySpecificRecord(Node* node){
        cout<<"ID: "<<node->id<<"\t Name: "<<node->name<<"\t Department: "<<node->department<<"\t Designation: "<<node->designation<<"\t Salary: "<<node->salary<<"\t Years of Service: "<<node->yearsOfService<<endl;
    }
    // Function to Check present or Not 
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
    // Function to add Record
    void insert(){
        int ID,salary;double years;string name, department, designation;
        cout<<"Fill the Following Data :: "<<endl;
        cout<<"ID of Employee: ";cin >> ID;
        cout<<"Name of Employee: ";cin.ignore();getline(cin, name);
        cout<<"Department of Employee: ";getline(cin, department);
        cout<<"Designation of Employee: ";getline(cin, designation);
        cout<<"Salary of Employee: ";cin >> salary;
        cout<<"Years of service of Employee: ";cin >>years;
        insertAtLast(name,department,designation,ID,salary,years);

    }
    void insertAtLast(string name, string department, string designation, int id, int salary,double years){
        Node* node = new Node(name, department, designation, id, salary, years);
        if(isPresent(node->id)){
            cout<<"ID NO: "<<node->id<<" Already Exists !!! "<<endl;
            return;
        }else{

            if(head==NULL){  // if LL is empty 
                head = node;
                tail = node;
            }else{

                tail->next=node;
                node->previous=tail;
                tail=node;
                }
            // cout<<"Record Added Successfully."<<endl;
    
        }

    }   
    // Function to Delete Record
    void Delete(){
        int id;
        cout<<"Enter the ID of Employee you want to delete : ";
        cin>>id;
        deleteRecord(id);

        }
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
            }else {
                cout << "Enter Name you want to search: ";
                cin.ignore(); // Ignore previous newline character in input buffer
                getline(cin, searchName); // Read full line with spaces
                searchByName(searchName);           
}
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

    // Function to search record by Name
    void searchByName(string toFind){
        Node* temp = head;
        // Convert the search string to lowercase
        transform(toFind.begin(), toFind.end(), toFind.begin(), ::tolower);
        
        while(temp != NULL){
            string nameToLower = temp->name;
            // Convert the name in the list to lowercase for comparison
            transform(nameToLower.begin(), nameToLower.end(), nameToLower.begin(), ::tolower);
            
            if(nameToLower == toFind){
                cout << "Record for Name: " << temp->name << " is Found." << endl;
                displaySpecificRecord(temp);
                return;
            }
            temp = temp->next;
        }
        cout << "Record for Name: " << toFind << " is Not Found!!!" << endl;
    }


    // Function to update the record
    void update(){
        int idToUpdate,id,salary;double years;string name,department,designation;
        cout<<"Enter the ID of a particular Employee you wants to update Record : ";cin>>idToUpdate;
        cout<<"Please Fill the following fields : "<<endl;
        cout<<"Enter the ID of Employee to update : ";cin>>id;
        cout<<"Enter the Name of the Employee to update : ";cin.ignore();getline(cin,name);
        cout<<"Enter the Department of Employee to update : ";getline(cin,department);
        cout<<"Enter the Designation of the Employee to update : ";getline(cin,designation);
        cout<<"Enter the Salary of the Employee to update : ";cin>>salary;
        cout<<"Enter the Years of service of the Employee to update : ";cin>>years;
        updateRecord(idToUpdate,name,department,designation,id,salary,years);
    }
    void updateRecord(int idToUpdate,string name, string department, string designation, int id, int salary,double years){
        Node* temp=head;
        if(isPresent(idToUpdate)){
            while(temp!=NULL){
                if(temp->id==idToUpdate){
                    temp->name = name;
                    temp->department = department;
                    temp->designation = designation;
                    temp->id = id;
                    temp->salary = salary;
                    temp->yearsOfService=years;
                    cout<<"Record Updated SuccessFully"<<endl;
                    return;
                }
                temp=temp->next;
            }
        }else{
            cout << "Record for ID: " << idToUpdate << " is Not Found !!" << endl;

        }
    }

    // Function to Assign Bonus
    void assignBonus() {
        double years;int bonus;
        cout<<"Enter the Criteria On Years of service for the Employee to assign bonus : ";cin >>years;
        cout<<"Enter the Bonus you want to add in Employee Salary : ";cin>>bonus; 
        Node *temp=head;
        while(temp!=NULL){
            if(isEligibleForBonus(temp,years)){
                bonusQueue.push(temp);
                temp=temp->next;
            }else{
                temp=temp->next;
            }
        }
        distributeBonuses(bonus); 

    }
    bool isEligibleForBonus(Node* node,int criteria) {
        if(node->yearsOfService>=criteria){
            return true;
        }
        return false;
        
    }
    // Function to distribute bonuses
    void distributeBonuses(int bonus) {
        while(!bonusQueue.empty()){
            Node* toAssign=bonusQueue.front();
            toAssign->salary=toAssign->salary+bonus;
            bonusQueue.pop();
        }
        cout<<"Bonuses distributed Successfully!"<<endl;
        
    }
    //Function to sort based on salary 
    void MergeSort(){
        head=mergeSort(head);

    }
    Node* mergeSort(Node* head){
        if(head==NULL || head->next==NULL){
           return head; // sorted
        } 
       Node * mid=findMid(head);

        Node* left=head;
        Node* right=mid->next;
        mid->next=NULL;

        left=mergeSort(left);
        right=mergeSort(right);

       Node * result=merge(left,right);
        return result;
    }

   Node * merge(Node* left,Node* right){
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        Node* ans=new Node(-1); // creating temporary/dummy node
        Node* temp=ans;
        while(left!=NULL && right!=NULL){
            if(left->salary < right->salary){
                temp->next=left;
                temp->previous = left->previous;
                left->previous = temp;
                temp=left;
                left=left->next;
            }
            else{
                temp->next=right;
                temp->previous = right->previous;
                right->previous = temp;
                temp=right;
                right=right->next;
            }
        }

        while(left!=NULL){
            temp->next=left;
            temp->previous = left->previous;
            left->previous = temp;
            temp=left;
            left=left->next;
        }
        while(right!=NULL){
            temp->next=right;
            temp->previous = right->previous;
            right->previous = temp;
            temp=right;
            right=right->next;
        }
        ans=ans->next;
        return ans;
    }

    Node* findMid(Node* head){
        Node* slow=head;
        Node* fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
       return slow; // slow is actually mid Node
    }
    // Function for Displaying Menu
    void menu(){
        cout<<"\t______ MENU ______"<<endl<<endl;
        cout<<"1. Add Employee Record"<<endl;
        cout<<"2. Search Employee Record"<<endl;
        cout<<"3. Update Employee Record"<<endl;
        cout<<"4. Delete Employee Record"<<endl;
        cout<<"5. Display All Employees Record"<<endl;
        cout<<"6. Sort Employees Record "<<endl;
        cout<<"7. Assign Bonus to Employees"<<endl;
        cout<<"8. Exit."<<endl;
        cout<<"Enter Your choice (1-8) : ";
    }
    // Function for Exit
    void EXIT(){
        cout<<"Exiting ";
        for(int k=0;k<6;k++){        
		    cout<<".";
	        Sleep(600);
	    }
    }
    // Functions for file Handling
    void loadFromFile(EmployeeManagementSystem &EMS, const string &filename) {
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                // Parse the line and extract data
                // Format: Name,Department,Designation,ID,Salary,YearsOfService
                stringstream ss(line);
                string name, department, designation;
                int id, salary;
                double yearsOfService;
                char delimiter = ',';

                getline(ss, name, delimiter);
                getline(ss, department, delimiter);
                getline(ss, designation, delimiter);
                ss >> id >> delimiter >> salary >> delimiter >> yearsOfService;

                EMS.insertAtLast(name, department, designation, id, salary, yearsOfService);
            }
            file.close();
            cout << "Data loaded successfully from file: " << filename << endl;
        } else {
            cout << "Unable to open file: " << filename << endl;
        }
    }
    void saveToFile(const string &filename) {
            ofstream file(filename);
            if (file.is_open()) {
                Node *temp = head;
                while (temp != NULL) {
                    file << temp->name << "," << temp->department << "," << temp->designation << ","
                        << temp->id << "," << temp->salary << "," << temp->yearsOfService << endl;
                    temp = temp->next;
                }
                file.close();
                cout << "Data saved successfully to file: " << filename << endl;
            } else {
                cout << "Unable to open file: " << filename << endl;
            }
        }
    



};


int main(){
    EmployeeManagementSystem EMS;
    int ch;
    EMS.loadFromFile(EMS, "employee_data.txt");

    while(true){
        EMS.menu();
        cin >> ch;
        system("cls");
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
            EMS.MergeSort();
            break;
        case 7 :
            EMS.assignBonus();
            break; 
        case 8 :
            EMS.saveToFile("employee_data.txt");
            EMS.EXIT();
            exit(0);
            break;       
        default :
            cout<<"Invalid Choice!!! Please  try again."<<endl;                    

        }

    }

    EMS.saveToFile("employee_data.txt");

}


/*
Add Exceptional handeling
*/