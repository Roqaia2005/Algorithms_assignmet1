#include <iostream>
#include <vector>
using namespace std;

// implement sequential search

// implement recursive sequential search---------->//Done

  int RBsearch(int arr[], int low,int high,int key){
    if (low > high) {
        return -1; // Not found
    }
      else
      {
          int mid =(low+high)/2;
          if(key==arr[mid])
              return mid;
          if(key<arr[mid])
              return RBsearch(arr,low,mid-1,key);
          else
              return RBsearch(arr,mid+1,high,key);
      }

  }

// implement binary search
int arr[5];


int binarySearch(int arr[], int low, int high, int target)
{

    while (low <= high) {
        int mid = low + (high - low) / 2;


        if (arr[mid] == target)
            return mid;


        if (arr[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

// implement recursive binary search

// test your function in main

int main(){


    int arr[5]={1,2,3,4,5};
    int key;
     cout<< "enter element you search for "<<endl;
     cin>>key;
    cout<<binarySearch(arr, 0, 4, key)<<endl;
    cout<<RBsearch(arr,0,4,key)<<endl;
    return 0;
}
