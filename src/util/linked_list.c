#include <stdlib.h>
#include "linked_list.h"
#include "util.h"
struct _ll_node
{
	struct _ll_node * next;
	struct _ll_node * prev;
	void* data;
};

struct _ll_list
{
	linked_list_node* first;
	linked_list_node* last;
	unsigned int sz;
};


linked_list* make_linked_list()
{
	linked_list* ll = NEW(linked_list);
	if(ll != NULL)
	{
		ll->first = NULL;
		ll->last = NULL;
		ll->sz = 0;
	}
	return ll;
}

void linked_list_destroy(linked_list* ll)
{
	while(ll->first != NULL)
		linked_list_remove_first(ll);
	rfree(ll);
}

void* linked_list_remove_first(linked_list* ll)
{
	if(ll->first == NULL) return NULL;
	linked_list_node *n = ll->first;
	void* v = n->data;
	if(n->next == NULL)
	{
		ll->first = NULL;
		ll->last = NULL;
	}
	else
	{
		ll->first = n->next;
		ll->first->prev = NULL;
	}
	rfree(n);
	ll->sz--;
	return v;
}
void* linked_list_remove_last(linked_list* ll)
{
	if(ll->last == NULL) return NULL;
	linked_list_node *n = ll->last;
	void* v = n->data;
	if(n->prev == NULL)
	{
		ll->first = NULL;
		ll->last = NULL;
	}
	else
	{
		ll->last = n->prev;
		ll->last->next = NULL;
	}
	rfree(n);
	ll->sz--;
	return v;
}
int linked_list_add_first(linked_list* ll, void* d)
{
	linked_list_node* n = NEW(linked_list_node);
	if(n == NULL) return 0;
	n->next = ll->first;
	n->prev = NULL;
	n->data = d;
	if(ll->first != NULL) ll->first->prev = n;
	ll->first =n;
	if(ll->last == NULL)
		ll->last = n;
	ll->sz++;
	return 1;	
}
int linked_list_add_last(linked_list* ll, void* d)
{
	linked_list_node* n = NEW(linked_list_node);
	if(n == NULL) return 0;
	n->prev = ll->last;
	n->next = NULL;
	n->data = d;
	if(ll->last != NULL) ll->last->next =n;
	ll->last = n;
	if(ll->first == NULL)
		ll->first = n;
	ll->sz++;
	return 1;	
}
int linked_list_is_empty(linked_list* ll)
{
	return ll->first == NULL;
}
unsigned int linked_list_size(linked_list* ll)
{
	return ll->sz;
}
linked_list_node* linked_list_first(linked_list* ll)
{
	return ll->first;
}
linked_list_node* linked_list_last(linked_list* ll)
{
	return ll->last;
}
linked_list_node* linked_list_prev(linked_list_node*n)
{
	return n->prev;
}
linked_list_node* linked_list_next(linked_list_node*n)
{
	return n->next;
}
void* linked_list_value(linked_list_node* n)
{
	return n->data;
}

