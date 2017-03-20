//author : Truong Huynh Tien
//date : 2017_03_20

typedef struct element
{
	int value;
	element *pNext = NULL;
}

typedef element *linked_list

int init(linked_list &pListA)
{
	pListA = NULL;
	// L tro toi NULL
}

bool isEmpty(linked_list pListA)
{
	return (pListA == NULL);
}

int add_Node_first(linked_list &pListA, int value)
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

int add_Node(linked_list &pListA, int value, int order)
{
	element pTemp = pListA;
	int i = 1;
	if (order < 1 || order > lengh_with_loop(pListA) + 1)
	{
		printf("Vi tri chen khong hop le");
	}
	else
	{	
		if (order == 1)
		{
			add_Node_first(pListA, value);
		}
		else
		{
			//tim vi tri thu (order - 1)
			while(pTemp != NULL && i != order - 1)
			{
				i++;
				pTemp = pTemp->pNext;
			}
			Node.pNext = pTemp->pNext;	// pNext cua Node moi tro vao Node thu order (trong danh sach cu)
			pTemp.pNext = &Node;		// node thu (order - 1) tro vao Node moi
		}
	}

	return 0;
}

int delete_first_Node(linked_list &pListA, int &x)
{
	x = pListA.value; // value cua node bi xoa se duoc gan vao x
	pListA = pListA->pNext;
}

int delete_Node_k(linked_list pListA, int order, int &x)
{
	if (order < 1 || lengh_with_loop(pListA) < order )
	{
		printf("Vi tri node can xoa khong hop le");
	}
	else
	{
		element pTemp = pListA;
		int i = 1;
		
		if (order == 1)
		{
			delete_first_Node(pListA, x);	// xoa vi tri dau tien
		}
		else
		{
			while(pTemp != NULL && i != order - 1 )
			{
				pTemp = pTemp->pNext;		// tim toi vi tri order - 1
				i++;
			}
			x = pTemp->pNext.value;
			pTemp->pNext = pTemp->pNext->pNext;	// Node thu (order - 1) tro vao node thu (order + 1)
		}
	}
	return 0;
}

int reverse_List(linked_list pListA)
{
	//TODO	
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
