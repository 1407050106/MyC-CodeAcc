#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

void MergeSortArr(int arr[],int left,int mid,int right){//该函数同于将两个有序列合并成一个有序列，同时当两个有序列都为同一个元素是一样可以处理 
	int i = left,j = mid + 1;//两个索引用来遍历两个有序列 
	int k=0;//k用来遍历暂存数组temp 
	int temp[right-left+1];//开一个数组暂时存放
	while(i <=mid && j <= right){//对两个有序列进行遍历排序，有一个序列遍历完成结束循环 
		if(arr[i] < arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++]; 
	}
	while(i <= mid){//将另外一个没有遍历完全的有序列全部插入到temp中 
		temp[k++] = arr[i++];
	} 
	while(j <= right){
		temp[k++] = arr[j++];
	}
	//！！这里需要注意循环的条件里面不能使用left因为left的值在改变 
	for(i = 0;i < k;i++)//将排好序的序列更新到目标数组中 
		arr[left++] = temp[i];
}
//递归方法 
void MergeSort(int arr[],int left,int right){
	if(left == right)//如果两个划分为同一元素，递归结束 
		return ;
	int mid = left+(right-left)>>1;//对本个划分再次进行划分 
	MergeSort(arr, left, mid);//对左边的序列进行划分此条命令结束代表左边的序列已经有序 
	MergeSort(arr, mid+1, right);//对右边的序列进行划分此条命令结束代表右边的序列已经有序 
	MergeSortArr(arr, left, mid, right);//和并两个序列 
} 

int main() {
    int arr[8] = {8, 4, 5, 7, 1, 3, 6, 2};
	for(int i = 0;i < 8;i++)
		cout<<arr[i]<<" ";
	cout<<endl; 
    MergeSort(arr,0,7);
    for(int i = 0;i < 8;i++)
		cout<<arr[i]<<" ";
	cout<<endl; 
}
