#include <iostream>
#include <cstdio>
using namespace std;

//=====================================
//找出第一个与key想等的元素的位置
//=====================================
int searchfirstEqual(int *arr,int n ,int key){
    int left=0;
    int right =n-1;
    while(left<right){
        int mid=(left+right)/2;
        if(arr[mid]>key){
            right=mid-1;
        }else if(arr[mid]<key){
            left=mid+1;
        }else if(arr[mid]==key){
            right =  mid;
        }
    }
    if(arr[left]==key||arr[right]==key){
        return left;
    }
    return -1;
}

//=====================================
//找出最后一个与key想等的元素的位置
//=====================================

int searchLastEqual(int *arr,int n ,int key){
    int left =0;
    int right = n-1;
    while(left<right-1){
        int mid=(left+right)/2;
        if(arr[mid]>key){
            right=mid-1;
        }else if(arr[mid]<key){
            left=mid+1;
        }else{
            left=mid;
        }

    }
    if(arr[left]<=key&&arr[right]==key){
        return right;
    }
    if(arr[left]==key&&arr[right]>key){
        return left;
    }
    return -1;

}

//=====================================
//找出第一个大于等于key的元素的位置
//=====================================

int searchFirstEqualOrLarger(int *arr, int n, int key)
{
    int left =0;
    int right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]>=key){
            right=mid-1;
        }else if(arr[mid]<key){
            left=mid+1;
        }
    }
    return left;
}

//=====================================
//找出第一个大于key的元素的位置
//=====================================

int searchFirstEqualOrLarger(int *arr, int n, int key)
{
    int left =0;
    int right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]>key){
            right=mid-1;
        }else if(arr[mid]<=key){
            left=mid+1;
        }
    }
    return left;
}



//=====================================
//找出最后一个等于或者小于key的元素的位置
//=====================================

int searchFirstEqualOrLarger(int *arr, int n, int key)
{
    int left =0;
    int right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]>key){
            right=mid-1;
        }else if(arr[mid]<=key){
            left=mid+1;
        }
    }
    return right;
}

//=====================================
//找出最后一个等于key的元素的位置
//=====================================

int searchFirstEqualOrLarger(int *arr, int n, int key)
{
    int left =0;
    int right=n-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]>=key){
            right=mid-1;
        }else if(arr[mid]<key){
            left=mid+1;
        }
    }
    return right;
}
int main(int agrc, char* argv[])
{
    int arr[17] = {1, 
                   2, 2, 5, 5, 5, 
                   5, 5, 5, 5, 5, 
                   5, 5, 6, 6, 7};
    printf("First Equal           : %2d \n", searchFirstEqual(arr, 16, 5));
    printf("Last Equal            : %2d \n", searchLastEqual(arr, 16, 5));
    printf("First Equal or Larger : %2d \n", searchFirstEqualOrLarger(arr, 16, 5));
    printf("First Larger          : %2d \n", searchFirstLarger(arr, 16, 5));
    printf("Last Equal or Smaller : %2d \n", searchLastEqualOrSmaller(arr, 16, 5));
    printf("Last Smaller          : %2d \n", searchLastSmaller(arr, 16, 5));
    system("pause");
    return 0;
}
