//TASK2: Very large Prime Number Calculation Using singly Linked List
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//Node creation
struct Node{
    long long data;    //each node stores a part of large number as its value
    Node* next;      //pointer to next node
};

//class Singly linked list: manages large number
class SinglyLL{
public:
    Node* head;      //first node

    //Constructor
    SinglyLL(){
        head=nullptr;       //initially: empty list
    }

    //Add new node to list (representing part of large number)
    void addNode(long long data){
        Node* newNode = new Node();     //dynamically create new node
        newNode->data = data;           //assign newNode data
        newNode->next = nullptr;        //next pointer set to null
        
        //If list is empty newnode=head
        if(head==nullptr){
            head= newNode;
        } else {        //Otherwise, find last node and add new node there
            Node* tempNode= head;
            while(tempNode->next!=nullptr){
                tempNode = tempNode->next;
            }
            tempNode->next = newNode;       
        }
    }

    //Display list (large number)
    void displayList(){
        //start from head and traverse through list 
        Node* tempNode= head;
        while(tempNode != nullptr){
            cout<<tempNode->data<<" ";  //print value of each node
            tempNode = tempNode->next;
        }
        cout<<endl;
    }
    
    //Method to test primality of number
    bool isPrime(){
        Node* tempNode = head;
        long long num = 0;

        //Convert list of values into a single number
        while(tempNode!=nullptr){
            num = (num*1000000000) + tempNode->data;  //Combine each node's value into large number
            tempNode = tempNode->next;
        }
        //Edge cases
        if(num<=1) return false;   //<=1 not prime numbers
        if (num <= 3) return true;
        // If the number is even, it's not prime
        if (num % 2 == 0) return false;

        //USING ALGORITHMS:
        // Miller-Rabin primality test
        bool isPrimeMR = millerRabin(num);
        if (!isPrimeMR) return false;

        // Baillie-PSW primality test
        bool isPrimeBPSW = bailliePSW(num);
        if (!isPrimeBPSW) return false;

        return true;
    }

    // function to calculate (a^n) % p
    long long powerMod(long long a, long long n, long long p) {
        long long res = 1;
        while (n > 0) {
            if (n & 1)
                res = (res * a) % p;
            a = (a * a) % p;
            n >>= 1;
        }
        return res;
    }

    
    // Miller-Rabin primality test
    bool millerRabin(long long n, int k = 5) {
        // If n is less than 2, it's not prime
        if (n < 2)
            return false;
        // If n is 2 or 3, it's prime
        if (n == 2 || n == 3)
            return true;
        // If n is even, it's not prime
        if (n % 2 == 0)
            return false;

        // Find r and d such that n-1 = 2^r * d
        long long d = n - 1;
        int r = 0;
        while ((d & 1) == 0) {
            d >>= 1;
            r++;
        }

        // Run k tests
        for (int i = 0; i < k; i++) {
            // Choose a random number a between 2 and n-2
            long long a = rand() % (n - 3) + 2;
            // Compute x = a^d % n
            long long x = powerMod(a, d, n);
            // If x is 1 or n-1, continue to the next test
            if (x == 1 || x == n - 1)
                continue;
            // Otherwise, check if x^(2^j) % n is n-1 for some j
            for (int j = 1; j < r; j++) {
                x = powerMod(x, 2, n);
                if (x == n - 1)
                    break;
            }
            // If x is not n-1
            if (x != n - 1)
                return false;
        }
        return true;
    }

    // Baillie-PSW primality test
    bool bailliePSW(long long n) {
        // If n is less than 2, it's not prime
        if (n < 2)
            return false;
        // If n is 2 or 3, it's prime
        if (n == 2 || n == 3)
            return true;
        // If n is even, it's not prime
        if (n % 2 == 0)
            return false;

        // Find r and d such that n-1 = 2^r * d
        long long d = n - 1;
        int r = 0;
        while ((d & 1) == 0) {
            d >>= 1;
            r++;
        }

        // Run the Baillie-PSW test
        for (int i = 0; i < 5; i++) {
            // Choose a random number a between 2 and n-2
            long long a = rand() % (n - 3) + 2;
            // Compute x = a^d % n
            long long x = powerMod(a, d, n);
            // If x is 1 or n-1, continue to the next test
            if (x == 1 || x == n - 1)
                continue;
            // Otherwise, check if x^(2^j) % n is n-1 for some j
            for (int j = 1; j < r; j++) {
                x = powerMod(x, 2, n);
                if (x == n - 1)
                    break;
            }
            // If x is not n-1
            if (x != n - 1)
                return false;
        }
        return true;
    }

};

int main(){
    srand(time(0)); // seed the random number generator
    SinglyLL sll;
    //add parts of large prime number in list
    sll.addNode(12345);
    sll.addNode(67890);
    sll.addNode(11111);
    sll.addNode(22222);
    sll.addNode(33333);

    //Display list
    cout<<"Input: ";
    sll.displayList();

    bool isPrime = sll.isPrime();

    cout<<"Output: "<<(isPrime ? "True" : "False")<<endl;

    return 0;
}