Charles Bell, text based RPG
Created: May 4th, 2017

This program is based on the creature class provided by Mrs. Moschardelli in CIS 230 Winter 2017 semester Henry Ford College.

The class was expanded on to create an inheritance structure to eliminate the need for a type variable.
Virtual methods were created to allow for polymorphism in the main function of the program.
I added a dark elf class which has a completely unique attack compared to the rest of the creatures. Instead of calling the parent
getDamage() function and then adding to it, it rolls a special attack chance, and on fail calls the parent getDamage() function.

The game itself involves a lot of rand() number generation. The game functions on random damage number rolls and random chance on 
what is behind each door. Some of the doors will have items in them. As oppose to creating a unique class for the items they 
affect the users strength and hitpoints immediately.

Creature pointer arrays are used to allow any random creature to be confronted at any point instead of pre-determined enemy.

These pointers are passed to a non-member function that can run a battle simulation with any two creatures passed to it.