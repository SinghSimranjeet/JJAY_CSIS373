// SIMRANJEET SINGH
//Professor: Ni Lu

// FILE: newnode.cpp
// IMPLEMENTS: The functions of the node class and the
// linked list toolkit (see node1.h for documentation).
// INVARIANT for the node class:
//   The data of a node is stored in data_field, and the link in link_field.

#include "newnode.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;

namespace main_savitch_5
{
    size_t list_length(const node* head_ptr)
    // Library facilities used: cstdlib
    {
	const node *cursor;
	size_t answer;

	answer = 0;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    ++answer;

	return answer;
    }

    void list_head_insert(node*& head_ptr, const node::value_type& entry)
    {
	head_ptr = new node(entry, head_ptr);
    }

    void list_insert(node* previous_ptr, const node::value_type& entry)
    {
	node *insert_ptr;

	insert_ptr = new node(entry, previous_ptr->link( ));
	previous_ptr->set_link(insert_ptr);
    }

    node* list_search(node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
	node *cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    if (target == cursor->data( ))
		return cursor;
	return NULL;
    }

    const node* list_search(const node* head_ptr, const node::value_type& target)
    // Library facilities used: cstdlib
    {
	const node *cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
	    if (target == cursor->data( ))
		return cursor;
	return NULL;
    }

    node* list_locate(node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
	node *cursor;
	size_t i;

	assert (0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
	    cursor = cursor->link( );
	return cursor;
    }

    const node* list_locate(const node* head_ptr, size_t position)
    // Library facilities used: cassert, cstdlib
    {
	const node *cursor;
	size_t i;

	assert (0 < position);
	cursor = head_ptr;
	for (i = 1; (i < position) && (cursor != NULL); i++)
	    cursor = cursor->link( );
	return cursor;
    }

    void list_head_remove(node*& head_ptr)
    {
	node *remove_ptr;

	remove_ptr = head_ptr;
	head_ptr = head_ptr->link( );
	delete remove_ptr;
    }

    void list_remove(node* previous_ptr)
    {
	node *remove_ptr;

	remove_ptr = previous_ptr->link( );
	previous_ptr->set_link( remove_ptr->link( ) );
	delete remove_ptr;
    }

    void list_clear(node*& head_ptr)
    // Library facilities used: cstdlib
    {
	while (head_ptr != NULL)
	    list_head_remove(head_ptr);
    }

    void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
    // Library facilities used: cstdlib
    {
	head_ptr = NULL;
	tail_ptr = NULL;

	// Handle the case of the empty list.
	if (source_ptr == NULL)
	    return;

	// Make the head node for the newly created list, and put data in it.
	list_head_insert(head_ptr, source_ptr->data( ));
	tail_ptr = head_ptr;

	// Copy the rest of the nodes one at a time, adding at the tail of new list.
	source_ptr = source_ptr->link( );
	while (source_ptr != NULL)
	{
	    list_insert(tail_ptr, source_ptr->data( ));
	    tail_ptr = tail_ptr->link( );
	    source_ptr = source_ptr->link( );
	}
    }

    size_t list_occurrences(const node* head_ptr, const node::value_type& target)
    {
        const node* current = head_ptr;
         std::size_t count = 0;

         while(current != NULL)
             if(current->data() == target)
                count++;
            current = current->link();
         
         return count;
    }

    void list_tail_attach(node*& head_ptr, const node::value_type& entry)
    {
          // create node
        node* temp = new node;
        temp->set_data(entry);
        temp->set_link(NULL);

        if(!head_ptr) { // empty list becomes the new node
            head_ptr = temp;
            return;
        } else { // find last and link the new node
            node* last = head_ptr;
            while(last->link()) last=last->link();
            last->set_link(temp);
        }

    }
    

    void list_tail_remove(node*& head_ptr)
    {
        if(head_ptr->link() == NULL)
            delete head_ptr;
        
        node* second_last = head_ptr;
        while (second_last -> link()-> link() != NULL)
        {
            second_last = second_last->link();
        }

        delete(second_last->link());

        second_last -> set_link(NULL);
        
    }

    node* list_copy_front(const node* source_ptr, size_t n)
    {
        if(source_ptr == NULL)  // Takes care of NULL case
        {
        return NULL;
        }
        node *new_head_ptr = NULL;  // Creates new head and ensures NULL
        const node *cursor = source_ptr;  // Sets temp Node = to source

        size_t i = 0;   // Initializes temp variable

        while(cursor!= NULL && i < n)   // Loop that continues while n is bigger than i and it is not NULL
        {
            list_tail_attach(new_head_ptr, cursor->data());
            cursor = cursor->link();  // Attaches to new list
            i++;    // Increases count
        }
        return new_head_ptr;
    }

}

