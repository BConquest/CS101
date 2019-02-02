/*
Bryant Conquest

This is a Program that makes a doubly-linked list.
*/

typedef struct node
{
	int num;
	char let;

	node *prev;
 	node *next;
}node;

class dList
{
	public:
		dList();
		dList(int keyArray[],char typeArray[],int length);
		void addFront(int key, char type);
		void addBack(int key, char type);
		void out(int k, char = 'f');
		void find(char type);
		 node* search(int key);
		void moveFront( node *list);
		void moveBack( node *list);
		int sizeOf( node *start);

		 node* merge( node* first,  node* second);
		~dList();
		 node* mergeSort( node* head);
		 node* split( node* head);

		//TODO
		void sort();

	private:
		void kill();
		 node* head;
		 node* tail;
};

dList::~dList()
{
	kill();
}


dList::dList()
{
	head = NULL;
	tail = NULL;
	return;
}

dList::dList(int keys[], char types[], int length)
{
     head = NULL;
	tail = NULL;
	for(int i = 0; i < length; i++)
		addBack(keys[i], types[i]);

	return;
}

void dList::kill()
{
	while(head != NULL)
     {
           node* old = head;
          head = head->next;
          delete old;
	}
}

void dList::addFront(int key, char type)
{
      node *temp;
	temp = new( node);

	temp->num = key;
	temp->let = type;
     temp->prev = NULL;
	if(head == NULL)
     {
          head = temp;
          tail = temp;
          temp->next = NULL;
          temp->prev = NULL;
          return;
	}

	head -> prev = temp;
     temp -> next = head;
     head = temp;
	return;
}

void dList::addBack(int key, char type)
{
	node *temp;
	temp = new( node);

	temp->num = key;
	temp->let = type;
     temp->next = NULL;
	if(head == NULL)
     {
          head = temp;
          tail = temp;
          temp->next = NULL;
          temp->prev = NULL;
          return;
	}

	tail -> next = temp;
     temp -> prev = tail;
     tail = temp;
	return;
}

 node* dList::search(int key)
{
	 node *temp;

	temp = head;
	while(temp != NULL)
	{
		if(temp->num == key)
		{
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}


void dList::find(char type)
{
	 node *temp;

	temp = head;

	while(temp != NULL)
	{
		if(temp->let == type)
		{
			cout << temp->num << " " << temp->let << "\t";
		}
		temp = temp -> next;
	}
	cout<< endl;
	return;
}

void dList::moveFront( node *list)
{
     if(list->prev != NULL)
	    list->prev->next = list->next;
     else
          head = list->next;
     if(list->next != NULL)
          list->next->prev = list->prev;
     else
          tail = list->prev;

	list->prev = NULL;
	head->prev = list;
	list->next = head;

	head = list;
	return;
}

void dList::moveBack( node *list)
{
     if(list->prev != NULL)
	    list->prev->next = list->next;
     else
          head = list->next;
     if(list->next != NULL)
          list->next->prev = list->prev;
     else
          tail = list->prev;

	list->prev = tail;
	tail->next = list;
	list->next = NULL;

	tail = list;
	return;
}

void dList::out(int k, char dir)
{
	 node* temp;
	int size = 0;
	switch(dir)
	{
		case 'f':
			temp = head;
			while(temp != NULL && size<k)
			{
				cout << temp->num << " " << temp->let << "\t";
				temp = temp->next;
				size++;
			}
			break;
		case 'b':
			temp = tail;
			while(temp != NULL && size<k)
			{
				cout << temp->num << " " << temp->let << "\t";
				temp = temp->prev;
				size++;
			}
			break;
		default:
			cout << "Error: Invalid print option(\'f\'or\'b\')" << endl;
			break;
	}
	cout << endl;
	return;
}

void dList::sort()
{
	 node *temp;
	head = mergeSort(head);

	temp = head;
	while(temp-> next != NULL)
	{
		temp = temp -> next;
	}

	tail = temp;
}

 node* dList::merge( node *first,  node *second)
{
    if (!first)
        return second;

    if (!second)
        return first;

    if (first->num < second->num)
    {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else
    {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

 node* dList::mergeSort( node *head)
{
    if (!head || !head->next)
        return head;
     node *second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    return merge(head,second);
}

 node* dList::split( node *head)
{
    node *fast = head,*slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    node *temp = slow->next;
    slow->next = NULL;
    return temp;
}
