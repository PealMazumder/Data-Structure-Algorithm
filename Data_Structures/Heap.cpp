//Problem Link: https://www.spoj.com/problems/RMID2/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct PriorityQueue {
    vector<int> heap;

    int heapSize() {
        return (int)heap.size();
    }
    bool isEmpty() {
        return heapSize() == 0;
    }
    int parent(int pos) {
        return (pos - 1) / 2;
    }
    int leftChild(int pos) {
        return (2 * pos + 1);
    }
    int rightChild(int pos) {
        return (2 * pos + 2);
    }

    void Heapify(int pos) {
        int left = leftChild(pos);
        int right = rightChild(pos);

        int smallest = pos;

        if(left < heapSize() && heap[left] < heap[pos]) {
            smallest = left;
        }
        if(right < heapSize() && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if(smallest != pos)
        {
            swap(heap[pos], heap[smallest]);
            Heapify(smallest);
        }
    }
    void insert(int element) {
        heap.push_back(element);
        int current = heapSize() - 1;
        while(heap[current] < heap[parent(current)]) {
            swap(heap[current], heap[parent(current)]);
            current = parent(current);
        }
    }
    int top() {
        return heap[0];
    }
    void pop() {
        heap[0] = heap.back();
        heap.pop_back();
        Heapify(0);
    }



};
void solve() {
    PriorityQueue mxheap, mnheap;
    int n;
    while(true) {
        cin >> n;
        if(n == 0) return;
        else if(n < 0) {
            cout << abs(mxheap.top()) << "\n";
            mxheap.pop();
            if(!mnheap.isEmpty() and mxheap.heapSize() != mnheap.heapSize()) {
                mxheap.insert(-mnheap.top());
                mnheap.pop();
            }
        }
        else {
            if(mxheap.isEmpty() || n < abs(mxheap.top()))
                mxheap.insert(-n);
            else mnheap.insert(n);

            if(mxheap.heapSize() > mnheap.heapSize() + 1) {
                mnheap.insert(abs(mxheap.top()));
                mxheap.pop();
            }
            if(mxheap.heapSize() < mnheap.heapSize()) {
                mxheap.insert(-mnheap.top());
                mnheap.pop();
            }
        }
    }
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);

	int t;
	cin>>t;
	while(t--)
	    solve();

	return 0;
}
