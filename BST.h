#include <iostream>
#include <string>
using namespace std;

class bnode
{
public:
	string name;
	bnode *lchild, *rchild;
};




class btree
{
public:
	btree();
	~btree();
	void Delete_Tree(bnode *&);
	bool Is_Empty();
	void Insert(const string &);
	void Aux_Insert(bnode * & loc_ptr, const string & key);
	void Print();
	void Print(bnode *);

	void Remove(bnode *&, const string &);
	void Remove(const string &);
private:
	bnode * Search(const string &);
	bnode * Aux_Search(bnode *&, const string &);
	bnode * Inorder_Successor(bnode *);
	bnode *root;
};

inline btree::btree()
{
	root = 0;
}