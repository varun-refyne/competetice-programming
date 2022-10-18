# include<iostream>
# include<time.h>
# include<climits>
# include<chrono>
using namespace std;

void swa(int &a, int &b){
    int temp=a; a=b;b=temp;
}
void inser(int *pq, int ed) {


        int childIndex = ed;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }
 void remov(int *pq,int ei) {

      swa(pq[0],pq[ei]);
        int pt=0;
        while((2*pt+1)<ei){

            int lc=2*pt+1;
            int rc=2*pt+2;
            int minindex=pt;
            if(pq[lc]<pq[minindex]){
                minindex=lc;
            }
            if(ei>rc && pq[rc]<pq[minindex]){
                 minindex=rc;
            }
           if(pt==minindex){
               break;
           }
           swa(pq[minindex],pq[pt]);
           pt=minindex;



        }

    }


void heapSort(int arr[], int n) {

for(int i=0; i<n; i++){
    inser(arr,i);
}
 for(int i=0; i<n; i++){
    remov(arr,n-i-1);
}

}
int main(){
    int n;
    int t;
    cin>>t;
    for(int i=0; i<t ;i++){
    cin>>n;
    int * arr= new int [n];
    for(int i=0; i<n; i++){
            arr[i]=rand();

    }
    auto start = std::chrono::high_resolution_clock::now();
    heapSort(arr,n);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
     long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    cout<<"time:"<<microseconds<<"microseconds \n";
}
}

