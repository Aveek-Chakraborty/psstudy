#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class heap
{
public:
    vector<int> h;

    heap() {}
    heap(int n)
    {
        h.resize(n);
        cout << "Enter element" << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
    }

    void insert(int val) // logn
    {
        h.push_back(val);

        int index = h.size() - 1;

        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (h[parent] < h[index])
            {
                swap(h[index], h[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletefromheap() // logn
    {
        if (h.size() == 0)
        {
            cout << "Nothing to delete";
            return;
        }

        // Swap first and last element, then remove the last
        h[0] = h[h.size() - 1];
        h.pop_back();

        int i = 0;
        int n = h.size();

        while (i < n)
        {
            int l = 2 * i + 1; // left child
            int r = 2 * i + 2; // right child
            int largest = i;

            // Find the largest among the current node, left, and right children
            if (l < n && h[l] > h[largest])
            {
                largest = l;
            }

            if (r < n && h[r] > h[largest])
            {
                largest = r;
            }

            // If the current node is larger than both children, we stop
            if (largest == i)
            {
                return;
            }

            // Otherwise, swap and continue
            swap(h[i], h[largest]);
            i = largest;
        }
    }

    void heapify(int i, int n)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && h[largest] < h[l])
        {
            largest = l;
        }
        if (r < n && h[largest] < h[r])
        {
            largest = r;
        }

        if (largest != i)
        {
            swap(h[largest], h[i]);
            heapify(largest,n);
        }
    }

    void buildHeap()
    {
        int n = h.size();
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(i,n);
        }
    }

    void heapSort() //mlogn
    {
        int n = h.size();
        buildHeap();
        for(int i = n-1; i>=1 ; i--){
            swap(h[0] , h[i]);
            heapify(0,i);
        }
    }

    void printHeap()
    {
        for (int i = 0; i < h.size(); i++)
        {
            cout << h[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    // heap maxHeap;

    // maxHeap.insert(10);
    // maxHeap.insert(5);
    // maxHeap.insert(15);
    // maxHeap.insert(7);
    // maxHeap.insert(20);

    // cout << "Max Heap before deletion: ";
    // maxHeap.printHeap();

    // maxHeap.deletefromheap();

    // cout << "Max Heap after deletion: ";
    // maxHeap.printHeap();

    // cout << "Max Heap: ";
    // maxHeap.printHeap();

    heap mh(5);

    mh.heapSort();

    // Print the heap after heapifying
    mh.printHeap();

    return 0;
}