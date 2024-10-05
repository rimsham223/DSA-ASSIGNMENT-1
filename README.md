**Problem 1: CPU Process Scheduling Using Circular Linked List**

**Approach:**
This solution implements a CPU scheduling system using a Circular Linked List. Each process is represented as a node in the linked list, with attributes like process_id, execution_time, and remaining_time. The scheduler assigns a fixed time slice (cpu_time) to each process in each cycle. After processing each node, its remaining_time is reduced, and if a process finishes (i.e., remaining_time <= 0), it is removed from the list. The scheduling continues until all processes complete execution.

**Steps:**
   -Add Processes: Processes are added to the circular linked list. The head node 
    represents the first process, and the last node links back to the head to create 
    the circular structure.

  -Process Scheduling: The scheduleProcess() function cycles through the processes in 
   the list, reducing the remaining_time of each process by the assigned CPU time. If a 
   process completes, it is removed.

  -Dynamic Insertion: The system supports adding new processes during runtime, 
   demonstrating the flexibility to handle real-time dynamic process arrival.

  -Display State: After each cycle, the remaining time of each process is displayed, 
   showing the state of the system.

**Assumptions:**
  -Each process has a unique process_id.
  -The circular linked list ensures fair round-robin scheduling, where each process 
   gets an equal chance to execute.
  -The CPU time slice is consistent across all processes.
  -New processes can be dynamically added during execution, simulating a real-world CPU 
   environment.
  -Once a process's remaining_time reaches zero or below, it is considered complete and 
   is removed from the list.
  -The program stops once all processes have finished execution.
  
**Challenges Faced:**
  -Circular Linked List Management: Ensuring that the list remains circular when adding 
   and removing processes was challenging, especially during head removal and when the 
   list becomes empty.

  -Memory Management: Deleting processes after completion while ensuring that pointers 
   remain valid required careful attention to avoid segmentation faults.

  -Dynamic Process Addition: Allowing the scheduler to handle new processes that are 
   added while the CPU is already cycling through existing processes was complex and 
   required careful pointer management.

  -Output Duplication: The initial implementation displayed processes multiple times 
   per cycle. This was resolved by restructuring the output logic within the scheduling 
   loop.
![Screenshot 2024-10-05 011905](https://github.com/user-attachments/assets/a1e024af-5b4d-4239-9cf6-f1bbcaea4a9a)
________________________________________________________________________________________

**Problem 2: Very Large Prime Number Calculation Using Singly Linked List**

**Approach:**
This solution simulates storing and testing a very large number for primality using a Singly Linked List. Since primitive data types cannot handle extremely large numbers, we store parts of the number in separate nodes of a linked list. We then use the Miller-Rabin Primality Test to probabilistically check whether the number is prime.

Steps:
  -Singly Linked List Structure:The large number is split into smaller parts, and each 
   part is stored in a node of the singly linked list.
  -The linked list is traversed to combine these parts into the full number.

  -Miller-Rabin Primality Test: The primality of the large number is tested using the 
   probabilistic Miller-Rabin test. This method efficiently checks if a number is prime 
   by choosing random bases and performing modular exponentiation.

  -Power Function:
   A helper function efficiently computes large powers modulo a number to support the 
   Miller-Rabin test.

**Assumptions:**
  -The large number is split into parts, with each part stored in a node.
  -The maximum number of iterations for the Miller-Rabin test is set to 5 to balance 
   accuracy and performance.
  -The number is assumed to fit into a 64-bit long long integer for each part stored in 
   the nodes.
  -The solution assumes no overflows while converting from the linked list to a single 
   large number.

**Challenges Faced:**
  -Handling Large Numbers: Since the number is split across multiple nodes, careful 
   management of data types and combining the nodes into a large number was critical to 
   avoid overflow or incorrect representation.

  -Efficient Primality Testing: The Miller-Rabin test involves multiple iterations and 
   modular exponentiations, which had to be implemented efficiently to avoid 
   performance issues for large numbers
   ![Screenshot 2024-10-05 053756](https://github.com/user-attachments/assets/b73b00d4-3663-4b26-98cc-456d378b4daa)
.

  -Memory Management: Ensuring the list structure is correctly maintained while testing 
   and handling large numbers in a time-efficient manner was crucial.
 
  -Randomness in Primality Test: Miller-Rabin is a probabilistic test, so randomness 
   had to be controlled carefully to get reliable results.

