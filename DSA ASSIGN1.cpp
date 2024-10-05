#include <iostream>
using namespace std;

//Node structure for circular linked list 
//Each node represents a process
struct Node{
    int process_id;
    int execution_time;
    int remaining_time;

    Node* next;
};

//Circular linked list class: manages processes
class CircularLL{
public:
   Node *head;      //pointer to head of cll

   //Constructor
   CircularLL(){
      head = nullptr;      //initially list is empty
   }

   //Function to add new process to list
   void addProcess (int process_id, int execution_time){
        Node* newNode = new Node();        //new process node (dynamically created)
        newNode->process_id = process_id;  //assign process id to node
        newNode->execution_time = execution_time;  //assign total execution time
        newNode->remaining_time = execution_time;  //Initially remaining time = execution time
        newNode->next = nullptr;     //set next pointer to null

        //if list is empty make newNode the head 
        if (head == nullptr){
            head = newNode;
            newNode->next = head;  //next pointer points to head, forming a circular link
        } else {
            Node* tempNode = head;    //temp pointer to traverse the list
            while (tempNode->next != head) {   //Traverse until the last node is found
                tempNode = tempNode->next;
            }
            //Add newNode at end of the list
            tempNode->next = newNode;
            newNode->next = head;  //newNode points to head to maintain circular structure
        }
   }

   //Method to remove process from CLL
   void removeProcess(Node* process) {
       if (head == nullptr) return;  // If list is empty, do nothing

       // If the process to be removed is the head
       if (process == head) {
           if (head->next == head) {  // If there's only one process
               delete head;
               head = nullptr;  // List is now empty
           } else {
               Node* tempNode = head;
               // Find the last node that points to the head
               while (tempNode->next != head) {
                   tempNode = tempNode->next;
               }
               tempNode->next = head->next;  // Update last node to point to the new head
               Node* toDelete = head;        // Old head to be deleted
               head = head->next;            // Move head to the next process
               delete toDelete;
           }
       } else {  // Process to be removed is not the head
           Node* tempNode = head;
           // Traverse to find the node before the process to be removed
           while (tempNode->next != process) {
               tempNode = tempNode->next;
           }
           tempNode->next = process->next;  // Bypass the process to be removed
           delete process;  // Deallocate memory for the removed process
       }
   }
   
   //Function to schedule and execute processes
   void scheduleProcess (int cpu_time) {
       if (head == nullptr) return;  // No processes to schedule if the list is empty

       Node* tempNode = head;
       do {
           tempNode->remaining_time -= cpu_time;  // Deduct CPU time
           if (tempNode->remaining_time <= 0) {  // If the process has finished
               cout << "Process " << tempNode->process_id << " has completed its execution." << endl;
               Node* nextNode = tempNode->next;  // Store the next node
               removeProcess(tempNode);          // Remove the current process
               tempNode = nextNode;              // Move to the next process
               if (head == nullptr) break;       // If the list becomes empty, stop
           } else {
               cout << "Process " << tempNode->process_id << " remaining time: " << tempNode->remaining_time << endl;
               tempNode = tempNode->next;        // Move to the next process
           }
       } while (tempNode != head && head != nullptr);  // Continue until all processes are executed
   }

   //Method to display the current state of all processes
   void displayProcess() {
       if (head == nullptr) {
           cout << "No processes in the list." << endl;
           return;
       }

       Node* tempNode = head;
       do {
           cout << "Process " << tempNode->process_id << " remaining time: " << tempNode->remaining_time << endl;
           tempNode = tempNode->next;  // Move to the next process
       } while (tempNode != head);  // Stop when we loop back to the head
   }
};

int main(){
    CircularLL cll;     // Instance of class 
    int cpu_time = 4;

    // Add processes to list
    cll.addProcess(1, 10);
    cll.addProcess(2, 5);
    cll.addProcess(3, 9);

    // Display initial state of processes
    cout << "Initial Processes: " << endl;
    cll.displayProcess();

    cout << "CPU time: " << cpu_time << endl;

    // Schedule processes for 3 cycles
    for (int i = 1; i <= 3; i++) {
        cout << "Cycle " << i << " : " << endl;
        cll.scheduleProcess(cpu_time);
    }

    // Add a new process
    cll.addProcess(4, 9);
    cout << "New process arrives: Process 4 remaining time: 9" << endl;

    // Schedule further cycles with the new process included
    for (int i = 4; i <= 5; i++) {
        cout << "Cycle " << i << ": " << endl;
        cll.scheduleProcess(cpu_time);
    }

    return 0;
}
