## Reversing a Linked List

### Iterative Method

1. Initialize three pointers as follows.

// you can complete this.

void reverse(list *l) {
	node *p, *q, *r, *tmp;
	if(l->p == NULL)
		return;          	//empty list
	q = l->p;
	p = q->next;
	r = p->next;
	while(r != q) {
		p->next = q;
		q = p;
		p = r;
		r = r->next;
	}
	q = l->q;
	p = q->prev;
	r = p->prev;
	while(r != q) {
		p->prev = q;
		q = p;
		p = r;
		r = r->prev;
	}
	tmp = l->p;
	l->p = l->q;
	l->q = tmp;
//	traverse(*l);
}


Above function can reverse the linked list in which 3 pointers are used  
q points to node, p points to nodes's next and r points to p's next node  
