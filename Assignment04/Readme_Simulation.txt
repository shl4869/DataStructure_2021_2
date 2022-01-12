Readme_Simulation.txt

//Program Purpose
This program is written for simulating the queue when there is two bankers providing service. The program gives simulation results by the number of customers served, total wait time, average wait time per person, and number of customers still wating after the simulation ends. 

0. define

(1) MAX_QUEUE_SIZE 100:
This definition is for setting the max size of the queue. 

1. typedef and global variables

(1) element: 
This structure is made to represent a customer's infomation (id, arrival time, service time)

(2) QueueType:
This structure is made to set a circular array queue that has front and rear.

(3) QueueType queue: The queue that is going to be used for the simulation. 

<State variables needed for simulation>
(4) int duration: simulation time
(5) double arrival_prob: average number of customers arriving in one time unit
(6) int max_serv_time: maximum service time for one customer
(7) int clock: the clock count for unit time that has passed 

<Results of the simulation>
(8) int customers: total number of customers
(9) int served_customers: number of customers served
(10) int waited_time: time the customers waited


2. Functions

(1) void random():
This function was made to generate real random number from 0 to 1.
There is no return for this function. 

(2) int is_empty(QueueType *q):
This function is for determining if the queue is empty. 
The function returns 1 when the queue is empty and 0 when the queue is not empty. 

(3) int is_full(QueueType *q):
This function is for determining if the queue is full. 
The function returns 1 when the queue is full and 0 when the queue is not full. 

(4) void enqueue(QueueType *q, element item):
This function is made to perform the enqueue operation. If the queue is full, the function prints the error message "Queue is full". If the queue is not full, it adds an item to the rear of the queue and moves the rear to the next place of the circular queue. 
The function has no return. 

(5) element dequeue(QueueType *q):
This function is made to perform the dequeue operation. If the queue is empty, the function prints the error message "Queue is empty". If the queue is not empty, it removes an item from the front of the queue and moves the front to the next place of the circular queue.  
The function returns the element saved at the front of the queue before it removes it from the queue. 

(6) int is_customer_arrived():
This function decides wether a new customer arrived when called, by the probablity of 'int arrival_prob'.
It returns 1 if a new customer arrived, and 0 if there is no new customer. 

(7) void insert_customer(int arrival_time):
This function saves the information(id, arrival time, service time) of a new customer and adds the customer to the queue using 'enqueue()' function. Then, it prints the information of new customer added to the queue. 
There is no return for this function. 

(8) int remove_customer(int banker):
This function retrieves the customer wating in the queue and return the customer's service time. When the banker is given, it fetches the customer at the front of the queue and increases 'int suerved_customers' and 'int waited_time' by 1 and 'clock-customer.arrival_time' each. Then it prints the time customer starting the service, the banker that is in charge of the customer, and the time the customer has been wated. 
The function returns 0 when the queue is empty, and 'int service_time' when queue is not empty. 

(9) void print_stat():
This function prints out the number of customers served, total wait time, average wait time per person, and number of customers still wating in the queue at the time when this function is called. 
There is no return for this function. 

(10) void main():
In main function, the service time of two banker and the clock time is initialized as 0. 
The while loops until 'int clock' meets 'int duration'. In the loop, it prints current time and determine wether the customer has arrived. If there is a new customer, it adds customer to the queue. Then, the function starts a customer's service at the banker with no customer currently. Banker with a customer decreses the service time left. When 'clock' meets 'duration', while loop ends and current statistics are printed through 'print_stat()'function. 