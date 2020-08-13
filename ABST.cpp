#include "ABST.h"
ABST::ABST()
{
	this->root = NULL;
}
ABST::ABST(Asteroids dat)
{
	this->root = new ATnode(dat);
}
bool ABST::isEmpty()
{
	if (root == NULL)
		return true;
	else
		return false;
}
void ABST::insert(ATnode** curr, Asteroids val)
{
	if (*curr == NULL)
	{
		ATnode* node = new ATnode(val);
		*curr = node;
	}
	else
	{
		if (val.getdistance() < (*curr)->data.getdistance())
			insert(&(*curr)->left, val);
		else if (val.getdistance() >= (*curr)->data.getdistance())
			insert(&(*curr)->right, val);
	}
}
void ABST::inorder(ATnode* curr)
{
	if (curr == NULL)
		return;
	inorder(curr->left);
	curr->data.getall();
	inorder(curr->right);
}
bool ABST::Search(ATnode* curr, int key)
{
	if (curr == NULL)
		return false;
	else if (curr->data.getdistance() == key)
		return true;
	else if (curr->data.getdistance() > key)
		Search(curr->left, key);
	else if (curr->data.getdistance() < key)
		Search(curr->right, key);
}

ATnode* ABST::getParent(ATnode* curr, int key)
{
	if (curr == NULL)
		return NULL;
	else if ((curr->left != NULL) && (curr->left->data.getdistance() == key))
		return curr;
	else if ((curr->right != NULL) && (curr->right->data.getdistance() == key))
		return curr;
	else if (curr->data.getdistance() > key)
		return getParent(curr->left, key);
	else if (curr->data.getdistance() < key)
		return getParent(curr->right, key);
}
ATnode* ABST::findMin(ATnode* curr)
{
	if (curr->left == NULL)
		return curr;
	else
		return findMin(curr->left);
}

void ABST::delnode(ATnode** curr, Asteroids val)
{
	if (*curr == NULL)
	{
		cout << "Node not found" << endl;
		return;
	}
	else if ((*curr)->data.getdistance() > val.getdistance())
		delnode(&(*curr)->left, val);
	else if ((*curr)->data.getdistance() < val.getdistance())
		delnode(&(*curr)->right, val);
	else if ((*curr)->data.getdistance() == val.getdistance())
	{
		if (((*curr)->left == NULL) && ((*curr)->right == NULL))
		{
			ATnode* p = getParent(*curr, val.getdistance());
			if (p->left == *curr)
				p->left = NULL;
			else if (p->right == *curr)
				p->right = NULL;
			*curr = NULL;
			delete* curr;
		}
		else if ((((*curr)->left == NULL) && ((*curr)->right != NULL)) || (((*curr)->left != NULL) && ((*curr)->right == NULL)))
		{
			ATnode* p = getParent(root, (*curr)->data.getdistance());
			if ((*curr)->left != NULL)
			{
				if (p->left == *curr)
				{
					p->left = (*curr)->left;
					*curr = p->left;
				}
				else if (p->right == *curr)
				{
					p->right = (*curr)->left;
					*curr = p->right;
				}
			}
			else if ((*curr)->right != NULL)
			{
				if (p->left == *curr)
				{
					p->left = (*curr)->right;
					*curr = p->right;
				}
				else if (p->right == *curr)
				{
					p->right = (*curr)->right;
					*curr = p->right;
				}
			}
		}
		else if (((*curr)->left != NULL) && ((*curr)->right != NULL))
		{
			ATnode* min = findMin((*curr)->right);
			int m = min->data.getdistance();
			delnode(&(*curr), min->data);
			(*curr)->data.setdistance(m);
		}
	}
}
