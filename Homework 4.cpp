
#include<iostream>
#include<string>


using namespace std;


class TNode
{
public:
	int val;
	TNode() {
		val = NULL; left = NULL; right = NULL; parent = NULL;}
	TNode(int v) { this->val = v; left = NULL; right = NULL; parent = NULL;}
	 
	TNode * left;
	TNode * right;
	TNode * parent;
};



class BTree
{
public:

	//constructors and destructor
	BTree();
	BTree(TNode *r);// initialize BTree with the root r. r is the only node.
	BTree(const BTree & t); // copy constructor
	BTree(const int *p, const int n);// similar to the copy constructor, but your input is of the array form.
									 // input is given an array that denotes a tree that uses  up to n slots. The size of the tree is not given directly as input.
									 // the array is pointed by p and has size n, where p[0] is used to store the empty symbol.
									 //the function converts the array representation into a linked-list representation, i.e. BTree



	~BTree();

	int size;
	TNode *root;

	TNode * convertpos(int position);// find the pointer where the position points to

	void add2left(TNode *newnode, TNode *p); // you should new a node that copies newnode and then add to left of p
	void add2right(TNode *newnode, TNode *p);

	void add2left(TNode *newnode, int position);
	void add2right(TNode *newnode, int position);


	void add2left(BTree newsubtree, int position);    // you should create a separate new tree  that copies
													  //newsubtree and then add to left of p
	void add2right(BTree newsubtree, int position);


	void removeleaf(int position); // should check if position is leaf
	void removeleaf(TNode *p);

	void swapnodes(TNode *n1, TNode *n2);//swap-the-values is fine

	int * Toarray(int &n);// convert the BT into the array form. Determine what n should be, and new an array of size n+1, and store the empty symbol at array[0]. Convert the BT into the array form and  retrun the array pointer. The size of the array will be given to the variable n.

	void print_pre_order(TNode *order);// print the node as you traverse according to the order.
	void print_in_order(TNode *order);
	void print_post_order(TNode *order);
	bool isValidBST(); // return whether this BT is a valid BST
	void print(ostream &out)
	{
		TNode *w = root;
		for (int i =1; i < size; i++)
		{
			w = convertpos(i);
			if (w == NULL || w->val == NULL || w->val < 0)
				int x = i;
			//	cout << "Position:  " << i << "       Empty Branch";

			else
			{
				cout << "Position:  " << i << "       Value:  " << w->val << "   ";
				if (w->parent != NULL)
					cout << "       Parent Position:  " << i / 2 << "       Parent Value:  " << w->parent->val;
			cout << endl;
			}


		}
	}
	int height()
	{
		int temp = size;
		int count = 0;
		while (temp != 0)
		{
			temp = temp / 2;
			count++;
		}
		return count;
	}

};


bool isValidBT(const int *p, const int n);
//Determine whether the array forms a valid BT.
// the input format is the same as the above



int main()

{
	cout << "Binary Tree:" << endl;
	BTree test;
	test.print(cout);

	cout << endl << endl << "Binary Tree From Array:" << endl;
	int p[] = { NULL, 5,6, 3,5, NULL, 4, NULL, 10, 13, NULL, NULL, NULL, 8 };
	BTree tree(p, 14);
	BTree copy = tree;
	tree.print(cout);

	cout << endl << endl << "Add New Leafs:" << endl;
	TNode *one = new TNode(106);
	TNode *two = new TNode(4);
	TNode *three = new TNode(55);
	BTree example(one);
	example.add2left(two, one);
	example.add2right(three, one);
	example.print(cout);

	cout << endl << endl << "Add Left of Position 6:" << endl;
	TNode *add = new TNode(14);
	tree.add2left(add, 6);
	tree.print(cout);

	cout << endl << endl << "Add Right of Position 5:" << endl;
	TNode *add2 = new TNode(22);
	tree.add2left(add2, 5);
	tree.print(cout);

	cout << endl << endl << "Add Tree Left:" << endl;
	tree.add2left(test, 12);
	tree.print(cout);

	cout << endl << endl << "Add Tree Right:" << endl;
	copy.add2right(test, 12);
	copy.print(cout);

	cout << endl << endl << "Add Tree Right:" << endl;
	BTree test2;
	test2.print(cout);
	test2.removeleaf(13);
	test2.removeleaf(test2.convertpos(12));
	cout << endl;
	test2.print(cout);

	cout << endl << endl << "Convert to Array:" << endl;
	int n = 6;
	int *a = test2.Toarray(n);
	for (int i = 0; i < n; i++)
	{
		if(a[i] == NULL)
			cout << "Pos: " << i << "   Empty " << endl;
		else
			cout << "Pos: " << i << "   Val: " << a[i] << endl;
	}

	cout << endl << endl << "Preorder:" << endl;
	BTree convert;
	convert.print_pre_order(convert.root);
	cout << endl << endl << "Inorder:" << endl;
	convert.print_in_order(convert.root);
	cout << endl << endl << "Postorder:" << endl;
	convert.print_post_order(convert.root);
	cout << endl;

	cout << endl << endl << "Swap Nodes:" << endl;
	example.print(cout);
	cout << endl;
	example.swapnodes(two, three);
	example.print(cout);

	cout << endl << endl << "Check for Binary Search Tree:" << endl;
	int bst[] = { NULL, 8, 5, 10, 3, 7, 9, 19 };
	BTree valid(bst, 8);
	cout << "Tree: " << endl;
	valid.print(cout);
	if (valid.isValidBST() == true)
		cout << "Is Valid" << endl << endl;
	else
		cout << "Is Not Valid" << endl << endl;

	return 0;
}

//Task 1
bool isValidBT(const int *p, const int n)
{
	for (int i = 1; i < n + 1; i++)
	{
		if (p[i] == NULL)
		{
			if (i * 2 <= n)
				if (p[i * 2] != NULL)
					return false;
			if (i * 2 + 1 <= n)
				if (p[i * 2 + 1] != NULL)
					return false;
		}
	}
	return true;
}

//Task 2
BTree::BTree()
{
	size = 14;
	int num = 2;
	root = new TNode(num-1);
	for (int i = 2; i <= size; i++)
	{
		if (i % 2 == 0)
			convertpos(i / 2)->left = new TNode(num);
		else
			convertpos(i / 2)->right = new TNode(num);
		convertpos(i)->parent = convertpos(i / 2);
		num++;
	}

}
BTree::BTree(TNode *r)
{
	root = r;
	size = 1;
}
BTree::BTree(const BTree & t)
{
	size = t.size;
	root = t.root;
}
BTree::BTree(const int *p, const int n)
{
	size = n;
	root = new TNode(p[1]);
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
			convertpos(i / 2)->left = new TNode(p[i]);
		else
			convertpos(i / 2)->right = new TNode(p[i]);
		convertpos(i)->parent = convertpos(i / 2);
	}


}
BTree::~BTree()
{
	cout << "close" << endl;
}

//Task 3
TNode * BTree::convertpos(int position)
{
	if (position == 0 || position == 1)
		return root;
	else if (convertpos(position / 2) == NULL)
		return convertpos(position / 2);
	else if (position % 2 == 1)
		return convertpos(position / 2)->right;
	else
		return convertpos(position / 2)->left;
}

//Task 4
void BTree::add2left(TNode *newnode, TNode *p)
{
	if (p->left == NULL || p->left->val == NULL)
	{
		TNode *temp = newnode;
		p->left = temp;
		temp->parent = p;
		size = 2 * size + 1;
	}
	else
		cout << "Position Filled" << endl;

}
void BTree::add2right(TNode *newnode, TNode *p)
{
	if (p->right == NULL || p->right->val == NULL)
	{
		TNode *temp = newnode;
		p->right = temp;
		temp->parent = p;
		size = 2 * size + 2;
	}
	else
		cout << "Position Filled" << endl;
}
void BTree::add2left(TNode *newnode, int position) 
{
	if (convertpos(position)->left->val == NULL)
	{
		convertpos(position)->left = newnode;
		newnode->parent = convertpos(position);
		if (2 * position > size)
			size = 2 * position + 1;
	}

	else
		cout << "Position Filled" << endl;
}
void BTree::add2right(TNode *newnode, int position)
{
	if (convertpos(position)->right->val == NULL)
	{
		convertpos(position)->right = newnode;
		newnode->parent = convertpos(position);
		if (2 * position + 2 > size)
			size = 2 * position + 2;
	}

	else
		cout << "Position Filled" << endl;
	
}


void BTree::add2left(BTree newsubtree, int position)
{
	if (convertpos(position)->left == NULL)
	{
		BTree temp = newsubtree;
		convertpos(position)->left = temp.root;
		temp.root->parent = convertpos(position);
		size = size + size * temp.size;
	}

	else
		cout << "Position Filled" << endl;


}

void BTree::add2right(BTree newsubtree, int position)
{
	if (convertpos(position)->right == NULL)
	{
		BTree temp = newsubtree;
		convertpos(position)->right = temp.root;
		temp.root->parent = convertpos(position);
		size = size + size * temp.size;
	}

	else
		cout << "Position Filled" << endl;
}

//Task 5
void BTree::removeleaf(int position)
{
	if (convertpos(position)->left == NULL && convertpos(position)->right == NULL)
	{
		TNode * w = convertpos(position);
		w->val = NULL;
	}
	else
		cout << "Not a Leaf" << endl;
}
void BTree::removeleaf(TNode *p)
{
	if (p->left == NULL && p->right == NULL)
		p->val = NULL;
	else
		cout << "Not a Leaf" << endl;
}

//Task 6
int * BTree::Toarray(int &n)
{
	int *p = new int[n];
	p[0] = NULL;
	for (int i = 1; i <= n; i++)
		p[i] =  convertpos(i)->val;

	n++;
	return p;
}


//Task 7
void BTree::swapnodes(TNode *n1, TNode *n2)
{
	int temp = n1->val;
	n1->val = n2->val;
	n2->val = temp;
}
void BTree::print_pre_order(TNode *order)
{
	if (order == NULL)
		return;
	cout << order->val << "    ";
	print_pre_order(order->left);
	print_pre_order(order->right);

}
void BTree::print_in_order(TNode *order)
{
	if (order == NULL)
		return;
	print_in_order(order->left);
	cout << order->val << "    ";
	print_in_order(order->right);
}
void BTree::print_post_order(TNode *order)
{
	if (order == NULL)
		return;
	print_post_order(order->left);
	print_post_order(order->right);
	cout << order->val << "    ";
}

//Task 8
bool BTree::isValidBST()
{
	for (int i = 1; i <= size; i++)
	{
		if (convertpos(i)->left != NULL)
			if (convertpos(i)->left->val >= convertpos(i)->val)
				return false;
		if (convertpos(i)->right != NULL)
			if (convertpos(i)->right->val <= convertpos(i)->val)
				return false;
	}
	return true;
}