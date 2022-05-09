Hello world. 
This project was my first use of enums, lists, vectors, maps, const and smart pointers. 
A lot of the time was thus allocated to understanding and implementing these ideas.
Previously I was using ints for enums, raw pointer and dynamic arrays to gain a better understanding of memory storage for both the stack and the heap. 

Features of the code:
I found getting truly random integers was a struggle using a time based domain as my objects were all being created at the same time at the start of the program. 
Therefore the following was used: 
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist2(0, 1);

I have stored the information of each bunny as ints which can then be translated via a map when it is called in thePen.cpp. 
Therefore, there is no need to store this string but just the integer of the object, this meant the use of getters in the bunny class to get these.

Within thePen, the bunnies are stored in a list of smart pointers as this will easily allow me to delete a bunny compared with arrays or vectors which are contiguous containers. 
const promises were made in thePen.h for constant integers in the code, for the speed of the program. 

A vector was used to store the information about the mothers fur so that this could be used for baby rabbits in overloaded instantiation,
where instead of a random number being used for the fur colour, an int is passed in to identify the colour. 

To cull the bunnies, it was necessary to traverse the list using an iterator coupled with a random number. 
This pointer would then be deleted from the list after the rabbits obituary was printed to the screen. 

There are two branches, (ExtraTask1) and (ExtraTask2) which include the code for the two extra tasks. 
