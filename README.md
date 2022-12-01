# LinkedListImp
This program provides the implementation of the linked list for storing information of addresses. In addition, it continues to store data for records with missing parameters, avoiding error.

dict1.c contains a main program running functions that insert into the linked list and searches for records with a particular desired query, in this case, all records on a particular street.

dict2.c contains another main program that traverses through the linked list, inserting the records in the linked list into a dynamic array and finds the lowest difference of records.

Both above programs makes use of listops.c and data.c, providing helper functions used in the main function to carr out those particular tasks. 

Listops.c includes all linked list related operators as well as linked list connetions with the dynamic array functions. This file also makes use of the data.c functions in order to interlink the data and the link list.

Data.c provides several function totake in records, assorting them to their various datatypes, checking for and missing records.

array.c contains array operators, manipulating the dynamic arrays.
