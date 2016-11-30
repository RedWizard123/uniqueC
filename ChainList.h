#ifndef CHAINLIST_H
#define CHAINLIST_H
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

#endif // CHAINLIST_H
