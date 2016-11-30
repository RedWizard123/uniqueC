#ifndef TREECHAINLIST_H
#define TREECHAINLIST_H
struct Node{
    void* value;
    struct Node* next;
};
class ChainList{
    private:
        struct Node* header;
    public:
        ChainList();
        virtual ~ChainList();
        void Insert(int after,void* pv);
        void Add(void* pv);
        void Delete(int position);
        int Count();
        void* Item(int index);
};

#endif // TREECHAINLIST_H
