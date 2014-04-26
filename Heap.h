#ifndef HEAP_H
#define HEAP_H

#include "HeapADT.h"

template <typename E> class Heap : HeapADT<E>
{
    E* content;          // Pointer to the heap array
    int maxsize;         // Maximum size of the content
    int n;               // Number of elements now in the heap
    void heapfy(int pos){
        while (!isLeaf(pos))
        {
        int j = left(pos); int i = righ(pos);
        if ((i < n) && content[i]<content[j]){
        j = i;
        }
        if (content[pos] < content[j]) return;
        pos = j;
        }
    }

public:
    Heap(E* h, int num, int max) {
        content = h; this->n = num; this->maxsize = max;
    }

    int size() const{
        return this->n;
    }

    bool isLeaf(int pos) const{
        { return (pos >= n/2) && (pos < n); }
    }

    int left(int pos) const{
        return pos*2;
    }

    int righ(int pos) const{
        return (pos*2+1);
    }

    int parent(int pos) const{
        return pos/2;
    }

    void buildMaxHeap(){
        for (int i = n/2-1; i>=0; i--) {
            this->heapfy(i);
        }

    }

    void insert(const E& it) {
        if(n == maxsize){
            cout<< "Heap cheia!" <<endl ;
        }
        int curr = n++;
        content[curr] = it;
        while ((curr!=0) && content[curr] < content[this->parent(curr)]) {
        swap(content, curr, this->parent(curr));

        curr = parent(curr);
        }
    }
    E removefirst(){
        if(n == 0){
            cout<< "Heap vazia!" <<endl ;
        }
        swap(content, 0, --n);
        if (n != 0) this->heapfy(0);
        return content[n];
    }
    E remove(int pos){
        Assert((pos >= 0) && (pos < n), "Bad position");
        if (pos == (n-1)) n--;
        else
        {
        swap(content, pos, --n);
        while ((pos != 0) && content[pos]< content[this->parent(pos)]) {
        swap(content, pos, parent(pos));
        pos = this->parent(pos);
        }
        if (n != 0) heapfy(pos);
        }
        return content[n];
    }

};

#endif // HEAP_H
