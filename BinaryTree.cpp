#include <conio.h>
#include <stdio.h>

typedef struct TNode
{
	int key;
	TNode *pLeft, *pRight;	
}TNode;
typedef TNode* TREE;

TNode* createNewNode(int data)
{
	TNode* node = new TNode; 
	
	node->key = data;
	
	node->pLeft = NULL;
	node->pRight = NULL;	
	
	return node;
}

TNode* insert(TNode  *Root, int data)
{
	if(Root==NULL)
	{		
		
		printf("Add %d as root \n", data);
		TNode* node = createNewNode(data);	
		
		return node;
	}
	else
	{
		if (data < Root->key)
		{
				printf("Add %d as left child of %d\n", data, Root->key);
				Root->pLeft = insert(Root->pLeft, data);			
		}		
		else
		{
				printf("Add %d as right child of %d\n", data, Root->key);
				Root->pRight = insert(Root->pRight, data);							
		}
		
	}
	return Root;	
}

void NLR(TNode* Root)
{
	if (Root !=NULL)
	{
		
		printf("%d ", Root->key);
		
		NLR(Root->pLeft);		
		NLR(Root->pRight);
	}
	
}

int countNode(TNode *Root)
{
	int count = 0;
	if (Root !=NULL)
	{
		count ++;
		
		count+= countNode(Root->pLeft);		
		count+= countNode(Root->pRight);
	}
	return count;
}


int countLeafNode(TNode *Root)
{
	int count = 0;
	if (Root !=NULL)
	{
		if ((Root->pLeft==NULL)&&(Root->pRight==NULL))
			count++;
			
		count+= countNode(Root->pLeft);		
		count+= countNode(Root->pRight);	
	}
	return count;
}

int countOneLeafNode(TNode *Root)
{
	int count = 0;
	if (Root !=NULL)
	{
		if (((Root->key != NULL) && (Root->key == NULL)) || ((Root->key ==NULL) && (Root->key != NULL)))
			count++;
			
		count+= countOneLeafNode(Root->pLeft);		
		count+= countOneLeafNode(Root->pRight);	
	}
	return count;
}

int countTwoLeafNode(TNode *Root)
{
	int count = 0;
	if (Root !=NULL)
	{
		if ((Root->pLeft!=NULL)&&(Root->pRight!=NULL))
			count++;
			
		count+= countTwoLeafNode(Root->pLeft);		
		count+= countTwoLeafNode(Root->pRight);	
	}
	return count;
}

int countLeafSmaillNode(TNode *Root, int x)
{
	int count = 0;
	if (Root !=NULL)
	{
		if (Root->key < x)
			count++;
			
		count+= countLeafSmaillNode(Root->pLeft, x);		
		count+= countLeafSmaillNode(Root->pRight, x);	
	}
	return count;
}

int countLeafBigNode(TNode *Root, int x)
{
	int count = 0;
	if (Root !=NULL)
	{
		if (Root->key > x)
			count++;
			
		count+= countLeafBigNode(Root->pLeft, x);		
		count+= countLeafBigNode(Root->pRight, x);	
	}
	return count;
}

int countLeafXYNode(TNode *Root, int x, int y)
{
	int count = 0;
	if (Root !=NULL)
	{
		if (Root->key > x && Root->key < y)
			count++;
			
		count+= countLeafXYNode(Root->pLeft, x, y);		
		count+= countLeafXYNode(Root->pRight, x, y);	
	}
	return count;
}

int getTreeHeight(TNode *Root)
{
	if (Root ==NULL)
		return 0;		
	    		
	int maxLeft = getTreeHeight(Root->pLeft);
			
	int maxRight = getTreeHeight(Root->pRight);	
	
	if (maxLeft> maxRight)
		return maxLeft+1;
	else
		return maxRight+1;
}


TNode* FindMin(TNode *root) {
   if (root == NULL) {
      return NULL; // or undefined.
   }
   if (root->pLeft != NULL) {
      return FindMin(root->pLeft); // left tree is smaller
   }
   return root;
}


TREE Delete(TREE root, int data) {
  if (root == NULL) {
     return NULL;
  }
  if (data < root->key) {  // data is in the left sub tree.
      root->pLeft = Delete(root->pLeft, data);
  } else if (data > root->key) { // data is in the right sub tree.
      root->pRight = Delete(root->pRight, data);
  } else {
     // case 1: no children
     if (root->pLeft == NULL && root->pRight == NULL) {
        delete(root); // wipe out the memory, in C, use free function
        root = NULL;
     }
     // case 2: one child (right)
     else if (root->pLeft == NULL) {
        TNode *temp = root; // save current node as a backup
        root = root->pRight;
        delete temp;
     }
     // case 3: one child (left)
     else if (root->pRight == NULL) {
        TNode *temp = root; // save current node as a backup
        root = root->pLeft;
        delete temp;
     }
     // case 4: two children
     else {
        TNode *temp = FindMin(root->pRight); // find minimal value of right sub tree
        root->key = temp->key; // duplicate the node
        root->pRight = Delete(root->pRight, temp->key); // delete the duplicate node
     }
  }
  return root; // parent node can update reference
}



int main()
{
	TREE myTree =NULL;
	
	myTree = insert(myTree, 10);
	myTree =insert(myTree, 7);
	myTree =insert(myTree, 12);
	myTree =insert(myTree, 8);
	myTree =insert(myTree, 9);
	myTree =insert(myTree, 11);
	myTree =insert(myTree, 14);
	
	
	printf("Duyet cay theo thu tu giua\n");
	NLR(myTree);
	
	printf("\n\nSo node tren cay la %d\n", countNode(myTree));
	printf("\n\nSo leafnode tren cay la %d", countLeafNode(myTree));
	printf("\n\nChieu cao cua cay la %d", getTreeHeight(myTree));
	printf("\n\nSo leafnode co 1 cay con la %d", countOneLeafNode(myTree));
	printf("\n\nSo leafnode co 2 cay con la %d", countTwoLeafNode(myTree));
	int x; printf("\nNhap x = "); scanf("%d", &x);
	printf("\n\nSo leafnode nho hon %d la %d", x, countLeafBigNode(myTree, x));
	printf("\n\nSo leafnode lon hon %d la %d", x, countLeafSmaillNode(myTree, x));
	int y; printf("\nNhap y = "); scanf("%d", &y);
	printf("\n\nSo leafnode lon hon %d nho hon %d la %d", x, y, countLeafXYNode(myTree, x, y));
	int i =10;
	
	printf("\n\nCay sau khi delete %d \n", i);
	Delete(myTree, i);
	NLR(myTree);
	
	
	return 0;
}




/* Viet ham
1. Tim X tren cay 
2. Them X vào cay (lam roi)
3. Huy phan tu gia tri X
*/


