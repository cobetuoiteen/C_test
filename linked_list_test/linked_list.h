typedef struct element
{
	int value;
	element *pNext;
}

typedef element *linked_list

int init(linked_list &pListA)
{
	pListA = NULL;
	// L tro toi NULL
}

bool isEmpty(linked_list pListA)
{
	if (pListA == NULL)
	{
		return true;
	}
	return false;
}

int add_Node(linked_list pListA, int value)
{
	//tao 1 node
	element Node;
	Node.value = value;
	
	// them node do vao danh sach
	if (pListA == NULL)
	{
		//danh sach rong
		pListA = &Node;
	}
	else 
	{
		//danh sach ko rong
		Node.pNext = pListA;
		pListA = &Node;	
	}
	return 0;
}

int delete_Node(linked_list pListA, int order)
{
	if (isEmpty(pListA) && lengh_with_loop(pListA) >= order )
	{
		
	}
	else
	{
		printf("Danh sach rong hoac khong co phan tu thu %d", order);
	}
}

int reverse_List(linked_list pListA)
{
	
}

int lengh_with_loop(linked_list pListA)
{
	element *pTemp = pListA;
	int count = 0;
	
	while(pTemp != NULL)
	{
		count++;
		pTemp = pTemp.pNext;
	}
	return count;
}
