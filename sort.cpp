#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
class Sort
{
public:
	virtual void sort(T *p_array,size_t n)=0;
};

template <class T>
class Bubble : public Sort<T>
{
public:
	void intercambio(T *p_array, int i, int j)
	{
		T p;
		p = p_array[i];
		p_array[i] = p_array[j];
		p_array[j] = p;
		return;
	}

	void sort(T *p_array, size_t n)
	{
		int i,j;
		for(i=n-1;i>=0;i--){
		    for(j=0;j<=p_array[j+1];j++) {
		       intercambio(p_array,j,j+1);
		    }
		}
	}
};

template <class T>
class Insert : public Sort<T>
{
public:

	void sort(T *p_array,size_t n){
		int i, key, j;
	   	for (i = 1; i < n; i++)
	   	{
	       key = p_array[i];
	       j = i-1;
	       while (j>=0 and p_array[j]>key)
	       {
	           p_array[j+1] = p_array[j];
	           j = j-1;
	       }
	       p_array[j+1] = key;
	    }
	}
};

template <class T>
class Quick : public Sort<T>
{
public:
	void sort(T *p_array,size_t n){
		quicksort(p_array,0,n-1);
	}

	void quicksort(T *Ar,int start, int finish){
		int i = start, j = finish, tmp; 
	    int p = Ar[(start + finish) / 2]; 
	    while (i <= j) 
	    { 
	        while (Ar[i] < p) i++; 
	        while (Ar[j] > p) j--; 
	        if (i <= j) 
	        { 
	            swap(Ar[i],Ar[j]); 
	            i++; j--; 
	        } 
	    } 

	    if (start < j) 
	        quicksort(Ar, start, j); 
	    if (i < finish) 
	        quicksort(Ar, i, finish); 
	}
};

template<class T>
void fill_randon(T *p_array,size_t n){
	for(int i=0;i<n;i++){
		p_array[i]=rand()%10000+1;
	}
}

int main(){
	int N=100000;
	int *A=new int[N];
	Sort<int>*sarray[3]={new Insert<int>,new Bubble<int>,new Quick<int>};
	for(int n=10;n<=N;n*=10)
	{
		cout<<n;
		fill_randon(A,n);
		for(int i=0;i<3;i++){
			double time=clock();
			sarray[i]->sort(A,N);
			time=clock()-time;
			cout<<" "<<time / CLOCKS_PER_SEC;
		}
		cout<<endl;
	}
	return 0;
}