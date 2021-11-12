#include<bits/stdc++.h>
using namespace std;

#define NN 100000 //Heap size

struct maxHeap{
    int n; //number of nodes in heapArr
    int heapArr[NN+1]; //array is 1 based
    maxHeap(){ n=0 ;}
    void max_heapify(int index);
    void insert(int k);
    int search(int k);
    void deleteKey(int k);
    int getMax();
};
void maxHeap::max_heapify(int i){
        int l = 2*i;
        int r = 2*i+1;
        int max = i;
        if(l<n && heapArr[l]>heapArr[max])
            max = l;
        if(r<n && heapArr[r]>heapArr[max])
            max = r;
        if(max != i){
            swap(heapArr[i],heapArr[max]);
            max_heapify(max);
        }
    }
void maxHeap::insert(int k){
        if(n==NN) return;
        n++;
        heapArr[n]= k;
        int p= n;
        while(p>1){
            int pr= p/2;
            if(heapArr[pr]<heapArr[p]){
                swap(heapArr[pr],heapArr[p]);
                p= pr;
            }
            else break;
        }
}
int maxHeap::getMax(){
    if(n==0) return -1;
    else return heapArr[1];
}

int maxHeap::search(int ele){
    for(int i=1;i<=n;i++){
        if(heapArr[i] == ele)
            return i;
        }
        return -1;
    }

void maxHeap::deleteKey(int ele){
        int index = search(ele);
        heapArr[index] = heapArr[n];
        n--;
        max_heapify(index);
    }
int main(){
    maxHeap h;
    vector<int> vec;
    int q, t, x;
    cin>>q;
    while(q--){
        cin>>t;
        if(t==1){
            cin>>x;
            h.insert(x);
        }
        else if(t==2){
            cin >> x;
            h.deleteKey(x);
        }
        else{
            vec.push_back(h.getMax());
        }
    }
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }
}