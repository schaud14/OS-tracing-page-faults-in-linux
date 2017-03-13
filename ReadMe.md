CS550:
Assignment 3:

Submitted by: 
Name: Saurabh Chaudhari
Email: schaud14@binghamton.edu

Description:

Runinng the Code:
To compile: make
To insert module : sudo insmod <module_name.ko> current_proc_id=<process_id of user program>
To view page fault: sudo tail -300f /var/log/kern.log

Description for extra part:
I have defined a structure to store the first 100 page faults
the copy_from_user in write call will copy the this data to proc file created.

