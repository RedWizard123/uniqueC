#ifndef TREECLASS_H
#define TREECLASS_H
class TreeNode{
	public:

		TreeNode(void*);//init the node and give it a value;
		~TreeNode();//free this node;
		void DeleteAllSub();//Delete all its sub nodes;
		void DeleteSub(int);////delete the sub node with subindex;
		void AddSubNode(class TreeNode*);//Add a SubNode to current Node;
		void InsertSubNode(int,class TreeNode*);//Insert
		class TreeNode* Item(int);//Return a sub node with subindex;
		int CountSub();//Return the amount of SubNode;


		void* value;
		int index;
		class TreeNode* pParent;
		class ChainList* ChildList;
	private:
		 class TreeNode* pNode;
};

struct Node{
    class TreeNode* value;
    struct Node* next;
};

class ChainList{
    private:
        struct Node* header;
    public:
        ChainList();
        virtual ~ChainList();
        void Insert(int after,class TreeNode* pv);
        void Add(class TreeNode* pv);
        void Delete(int position);
        int Count();
        class TreeNode* Item(int index);
};

class Tree{
	public:
		class TreeNode* Root;
		Tree();
		~Tree();
		int Count();//Count all nodes under the ROOT;


};
#endif // TREECLASS_H
