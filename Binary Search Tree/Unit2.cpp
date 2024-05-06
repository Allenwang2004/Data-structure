//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

struct BSTreeNode
{
	struct BSTreeNode *leftchild;
	int data;
	struct BSTreeNode *rightchild;
};
struct StackNode

{   struct BSTreeNode *treenode;

    struct StackNode *next;

};
struct QNode

{   struct BSTreeNode *treenode;

    struct QNode *next;

};
struct DrawTreeNode

{   struct DrawTreeNode* leftchild;

    int data;

	int index;
	struct DrawTreeNode* rightchild;

};
struct StackNode *top;

struct BSTreeNode *root;

struct DrawTreeNode* DrawRoot;
int* X;

int* Y;

int count_node;

String tree;

int** treenode;
int tempcount;
struct QNode *front, *rear;

struct BSTreeNode *NewBSTNode(int x)
{
	struct BSTreeNode *node = (struct BSTreeNode*)
		malloc(sizeof(struct BSTreeNode));
	node->data = x;
    node->leftchild = NULL;
}

struct BSTreeNode *InsertBST(struct BSTreeNode *node, int x)    //���j�@�k
{
	if(node==NULL)
		return NewBSTNode(x);
	if(x<node->data)
		node->leftchild = InsertBST(node->leftchild,x);
	else
		node->rightchild = InsertBST(node->rightchild,x);
	return node;
}

int InsertBSTNR(int x)          //�D���j�@�k
{
	struct BSTreeNode *p, *q;
	p = root; q = NULL;   //p�O�s��x���s�`�I q�O�ӰO��p�����˸`�I����m
	while (p != NULL)
	{
		q = p;
		// if (x == p->data) return 0;
		if (x < p->data)
			p = p->leftchild;
		else
			p = p->rightchild;
	}
	p = new struct BSTreeNode;
	p->data = x;
	p->leftchild = p->rightchild = NULL;
	if (root == NULL)
	{
		root = p;
		count_node++;
	}
	else if(x < q->data)
	{
		q->leftchild = p;
		count_node++;
	}
	else
	{
		q->rightchild = p;
		count_node++;
	}
	return 1;
}
struct BSTreeNode *InorderSucc(struct BSTreeNode *node)
{
    struct BSTreeNode *p;
    for(p=node;p->leftchild!=NULL;p=p->leftchild);
    return p;
}struct BSTreeNode *DeleteBST(struct BSTreeNode *node,int x)
{
    struct BSTreeNode *temp;
    if(node == NULL)
        return node;
    if(x<node->data)
        node->leftchild=DeleteBST(node->leftchild,x);
    else if(x>node->data)
        node->rightchild=DeleteBST(node->rightchild,x);
    else
    {
        if((node->leftchild==NULL)||(node->rightchild==NULL))
        {
            temp = (node->leftchild)? node->leftchild: node->rightchild;
            if(temp==NULL)
            {
                temp = node;
                node = NULL;
            }
            else *node = *temp;
            free(temp);
        }
        else
        {
            temp=InorderSucc(node->rightchild);
            node->data = temp->data;
            node->rightchild = DeleteBST(node->rightchild,temp->data);
        }
        return node;
    }
}int DeleteBSTree(int x)    //�D���j
{
	struct BSTreeNode *p , *father, *k, *f;
	p = root; father = NULL;
	while (p != NULL)
	{
		if (x == p->data) // ��� x �Ҧb���`�I p �F
		{
			if ((p->leftchild == NULL) && (p->rightchild == NULL))
				k = NULL; // p ���𸭸`�I
			else if (p->leftchild != NULL ) // p �t�����l��
			{
				f = p; // ��X p ���l�𪺳̥k��
				k = p->leftchild;
				while (k->rightchild !=NULL)
				{
					f = k;
					k = k->rightchild;
				}  // k �Y�� p ���l�𪺳̥k��
				if (p == f)     // k �Y�� p ������l
					f->leftchild = k->leftchild;
				else
					f->rightchild = k->leftchild;
				}
				else    // p �L���l��, �ˬd�k�l��
				{
					f = p; //��X p �k�l�𪺳̥���
					k = p->rightchild;
					while (k->leftchild != NULL)
					{
						f = k;
						k = k ->leftchild;
					}  // k �Y�� p �k�l�𪺳̥���
					if (p == f)    // k �Y�� p ���k��l
					   f->rightchild = k->rightchild;
					else
					   f->leftchild = k->rightchild;
				 }
				 if (k != NULL)   // k ���ܭ� p �B, �~�� p �����k����
				 {
					k->leftchild = p->leftchild;
					k->rightchild = p->rightchild;
				 }
				 if (father == NULL) root = k;
				 else
				 {
					if (x < father->data)  //�M�wk�Ofather�����Υk��l
						father->leftchild = k;
					else
						father->rightchild = k;
				 }
				 free(p);
				 count_node--;
				 return 1; //���\�a�R�� x�A�󦹶Ǧ^1��^�I�s�B
		}
		else //�|�����x�A�~�򩹤U�@���h��
			{
				father = p;
				if (x < p->data)
				   p = p->leftchild;
				else
				   p = p->rightchild;
			}
	 }
	 return 0; //�����x�A�Ǧ^0
}

int searchBST(struct BSTreeNode *node,int x)
{
	while(node!=NULL)
	{
		if(x==node->data)
			return 0;
		if(x<node->data)
			node=node->leftchild;
		else
			node=node->rightchild;
	}
	return 1;
}

void print_BSTree(struct BSTreeNode *node)

{
	if (node != NULL)
	{
		print_BSTree(node->leftchild);
		tree += IntToStr(node->data)+"_";
		print_BSTree(node->rightchild);
	}
}

void inorder(struct BSTreeNode *node)
{
	if(node!=NULL)
	{
		inorder(node->leftchild);
		tree += IntToStr(node->data)+"_";
		inorder(node->rightchild);
	}
}

void preorder(struct BSTreeNode *node)
{
	if(node!=NULL)
	{
		tree += IntToStr(node->data)+"_";
		preorder(node->leftchild);
		preorder(node->rightchild);
	}
}

void postorder(struct BSTreeNode *node)
{
	if(node!=NULL)
	{
		postorder(node->leftchild);
		postorder(node->rightchild);
		tree += IntToStr(node->data)+"_";
	}
}

void AddQueue(struct BSTreeNode *Tnode)
{
	struct QNode *node;
	node = (struct QNode *) malloc(sizeof(struct QNode));
	node->treenode = Tnode;
	node->next = NULL;
	if (front == NULL)
		front = node;
	else
		rear->next = node;
	rear = node;
}

struct BSTreeNode *DeleteQueue()
{
	struct BSTreeNode *Tnode;
	struct QNode *old_front;
	if (front == NULL) ; //QueueEmpty();
	else
	{
		Tnode = front->treenode;
		old_front = front;
		front = front->next;
		free(old_front);
		return Tnode;
	}
}

void LevelOrder (struct BSTreeNode *node)
{
	AddQueue(node);
	while (front != NULL)
	{
		node = DeleteQueue();
		tree += IntToStr(node->data)+"_";
		if (node->leftchild != NULL)
			AddQueue(node->leftchild);
		if (node->rightchild != NULL)
			AddQueue(node->rightchild);
	}
}

void Clear_BST(struct BSTreeNode* BSTnode)
{
	if (BSTnode != NULL)
	{
		Clear_BST(BSTnode->leftchild);
		Clear_BST(BSTnode->rightchild);
		delete(BSTnode);
    }
}void push_node(struct BSTreeNode *node )

{ struct StackNode *old_top;

  old_top = top;

  top = (struct StackNode *) malloc (sizeof(struct StackNode));

  top->treenode = node;

  top->next = old_top;

}

struct BSTreeNode *pop_node()

{ struct BSTreeNode *Tnode;

  struct StackNode *old_top;

  if (top == NULL)

  ;       // StackEmpty();

  else

  {  Tnode = top->treenode;

     old_top = top;

     top = top->next;

     free(old_top);

     return Tnode;

  }

}void Inorder_Stack(struct BSTreeNode * node)

{   // node = root;

  do

  {  while (node != NULL)

     {  push_node(node);

        node = node->leftchild;

     }  // phsh all left children

     if (top != NULL)

     {  node = pop_node();

        tree += IntToStr(node->data)+"_";

        node = node->rightchild;

     } // inorder printing and check right child

  } while ((top!=NULL)||(node!=NULL));

}

void Postorder_Stack(struct BSTreeNode * node)

{  do

   {  while (node != NULL)

      {   tree = IntToStr(node->data)+"_"+tree;

          push_node(node);

          node = node->rightchild;

      }   // push all left children

      if (top != NULL)

      {   node = pop_node();

          node = node->leftchild;

      }

  } while ((top!=NULL)||(node!=NULL));

}

void Preorder_Stack(struct BSTreeNode * node)

{  do

   { while (node != NULL)

     {   tree += IntToStr(node->data)+"_";

         push_node(node);

         node = node->leftchild;

     }   // push all left children

     if (top != NULL)

     {   node = pop_node();

         node = node->rightchild;

     }

   } while ((top!=NULL)||(node!=NULL));

}




int Depth_BTree(struct BSTreeNode* node, int level)

{   int depth, l_depth, r_depth;

    if (node!=NULL)

	{

       l_depth = Depth_BTree(node->leftchild, (level+1));

       r_depth = Depth_BTree(node->rightchild, (level+1));

       depth = l_depth>r_depth? l_depth : r_depth;

       return depth;

    }

    else return (level-1);

}
void determine_X(struct DrawTreeNode* node, int left, int right)

{   if (node != NULL)

    {  int m = (left+right)/2;

       X[node->index] = (m == 0) ? left : m;

       determine_X(node->leftchild, left, (m-1<left)?left:m-1);

       determine_X(node->rightchild, (m+1<right)?m+1:right, right);

    }

}

void determine_Y(struct DrawTreeNode* node, int top, int bottom, int depth)

{  int detH = (top+bottom)/(depth+1);

   for (int i=0; i<depth+1; i++)

   {  Y[i] = (detH < 10) ? 10*i : detH*i;

   }

}
struct DrawTreeNode* CopyBSTtoDT(struct BSTreeNode* TreeRoot, int index, int depth)

{   if (TreeRoot==NULL)

    {   return NULL;

    }

    struct DrawTreeNode* copyRoot = (struct DrawTreeNode*)malloc(sizeof(DrawTreeNode));

    copyRoot->data = TreeRoot->data;

    copyRoot->index = index;

    copyRoot->leftchild = CopyBSTtoDT(TreeRoot->leftchild, 2*index, depth);

    copyRoot->rightchild = CopyBSTtoDT(TreeRoot->rightchild, 2*index+1, depth);

    return copyRoot;

}
void Draw_BST(struct DrawTreeNode* DrawRoot, int node_radius)

{   if (DrawRoot!=NULL)

    {  int level = ceil(log(DrawRoot->index+1)/log(2.0));

       if (DrawRoot->leftchild!=NULL)

       {   Form2->Image1->Canvas->MoveTo(X[DrawRoot->index], Y[level]);

		   Form2->Image1->Canvas->LineTo(X[DrawRoot->leftchild->index], Y[level+1]);


       }

       if (DrawRoot->rightchild)

	   {   Form2->Image1->Canvas->MoveTo(X[DrawRoot->index], Y[level]);

		   Form2->Image1->Canvas->LineTo(X[DrawRoot->rightchild->index], Y[level+1]);


       }

      Form2->Image1->Canvas->Ellipse(X[DrawRoot->index]- node_radius,

           Y[level] - node_radius,

           X[DrawRoot->index]+ node_radius,

           Y[level] + node_radius);


       Draw_BST(DrawRoot->leftchild, node_radius);

       Draw_BST(DrawRoot->rightchild, node_radius);

    }

}

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{


}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	int element = StrToInt(Edit1->Text);
	if(CheckBox1->Checked)
	{
		int success = InsertBSTNR(element);
		if (!success)
		{
			Memo1->Lines->Add("Fail to insert: "+IntToStr(element));
		}
		else
		{
			tree = "";
			print_BSTree(root);
			Memo1->Lines->Add("Tree:      "+tree);
		}
	}
	else
	{
		root = InsertBST(root,element);
		tree = "";
		print_BSTree(root);
		Memo1->Lines->Add("Tree:      "+tree);
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
    int target = StrToInt(Edit1->Text);
	if(CheckBox1->Checked)
	{
        int success = DeleteBSTree(target);
		if (success)
		{
			Memo1->Lines->Add(IntToStr(target) +" has been deleted.");
		}
		else Memo1->Lines->Add(IntToStr(target) +" has not been found.");
		tree = "";
		print_BSTree(root);
		Memo1->Lines->Add(tree);
	}
	else
	{
        int success = searchBST(root,target);
	    if (success==0)
	    {
		    DeleteBST(root,target);
		    tree = "";
		    print_BSTree(root);
		    Memo1->Lines->Add("Tree:      "+tree);
	    }
	    else Memo1->Lines->Add(IntToStr(target) +" has not been found.");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
	int n = StrToInt(Edit4->Text);
	int * data = new int [n];
	String inp = "";
	srand(time(NULL));
	int range_min = 0;
	int range_max = StrToInt(Edit5->Text);
	for (int i=0; i<n; i++)
	{
		data[i] = rand()%(range_max-range_min+1)+range_min;
		int success = InsertBSTNR(data[i]);
		inp += IntToStr(data[i]) +"-";
	}
	Memo1->Lines->Add(inp);
	tree = "";
	print_BSTree(root);
	Memo1->Lines->Add("Inorder (recursively):      "+tree);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button4Click(TObject *Sender)
{
	int target = StrToInt(Edit2->Text);
	int success = searchBST(root,target);
	if (success==0)
	{
		Memo1->Lines->Add(IntToStr(target) +" has been found.");
	}
	else Memo1->Lines->Add(IntToStr(target) +" has not been found.");
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender)
{
if(CheckBox2->Checked)
{
    tree = "";
	Inorder_Stack(root);
	Memo1->Lines->Add("Inorder Sequence (nonrecursively): "+tree);
}
else
{
    tree = "";
	inorder(root);
	Memo1->Lines->Add("Inorder Sequence (recursively): "+tree);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button6Click(TObject *Sender)
{
if(CheckBox2->Checked)
{
    tree = "";
	Preorder_Stack(root);
	Memo1->Lines->Add("Preorder Sequence (nonrecursively): "+tree);
}
else
{
    tree = "";
	preorder(root);
	Memo1->Lines->Add("Preorder Sequence (recursively): "+tree);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button7Click(TObject *Sender)
{
if(CheckBox2->Checked)
{
	tree = "";
	Postorder_Stack(root);
	Memo1->Lines->Add("Inorder Sequence (nonrecursively): "+tree);
}
else
{
	tree = "";
	postorder(root);
	Memo1->Lines->Add("Inorder Sequence (recursively): "+tree);
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button8Click(TObject *Sender)
{
    Memo1->Text = "";
	Clear_BST(root);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button9Click(TObject *Sender)
{
    tree = "";
    LevelOrder(root);
	Memo1->Lines->Add("Level-order :    "+tree);
}
//---------------------------------------------------------------------------








void __fastcall TForm2::PageControl1Change(TObject *Sender)
{
    Image1->Picture->Assign(NULL);




 tempcount=0;

 int depth = Depth_BTree(root, 1);

 Memo1->Lines->Add("depth:"+IntToStr(depth));

 int tree_Height = ScrollBox1->Height;

 int tree_Width = ScrollBox1->Width;



 int total_node = pow(2, depth)-1;

 int detW = tree_Width/(total_node+1);

 int detH = tree_Height/(depth+1);

 int node_radius = (detW*5/6 > detH/2) ? detH/2 : detW*5/6;

 Image1->Top = 0;

 Image1->Left = 0;

 Image1->Height = tree_Height;

 Image1->Width = tree_Width;

 DrawRoot = CopyBSTtoDT(root, 1, depth);

 X = new int [total_node+2];

 Y = new int [depth+1];

 determine_X(DrawRoot, 0+node_radius, tree_Width-node_radius);

 determine_Y(DrawRoot, 0, tree_Height, depth);

 Draw_BST(DrawRoot, node_radius);

 delete(X);

 delete(Y);
}
//---------------------------------------------------------------------------

