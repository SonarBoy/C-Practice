/* LINKED LISTS!!
Why Linked Lists are better than arrays?

- Array sizes are fixed. Linked Lists are not.

- Adding to a linked list is easier and faster while
  adding to an array is expensive because you got to create
  a whole new object.

Why not Linked Lists?

- Random access is not allowed. We only have access to the elemets
  from the first to the last. So we cant do binary searches with 
  linked lists efficiently with its default implementation.

- Extra memory space is required with each element of the list.

- Not cache friendly.


Structure:
1) Data.
2) Pointer (reference to the Next Node).
*/


/*  L Value and R Value notes:

The value to the left of the = assingment operator is known as the
L-value and the value to its right id known as the R-value.

The R value cannot appear on the left hand side of the equals sign 
but the L value can appear on the right hand side.

Also:

Test -> best = x is equal to

(*Test).best = x

Link to Explanation.
http://www.cplusplus.com/forum/beginner/139181/

*/




struct Node{
public:
    int data;
    struct Node* next;
};