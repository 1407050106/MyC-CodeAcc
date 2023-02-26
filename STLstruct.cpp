#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <numeric>
#include <algorithm>
#include <functional>
#include <math.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	//////////////////MATH AND TIME//////////////////////////////////////
	// time_t start = clock();

	// double a = 10;
	// double b = 10;
	// double d = log(b);     //e
	// cout<<d<<endl;
	// double c = pow(a,b);
	// int e = rand();
	// double f = sin(a);
	// cout<<M_PI<<endl;

	// time_t end = clock();

	// double consume = (end-start);  //ms
	// cout<<consume<<endl;

	// cout<<rand()%10;  //0~9




	// char a;
	// cin.get(a);   //only for char, and only get 1 char, but also for char[]
	// cout<<a<<endl;

	char b[5];
	cin.getline(b, 3);   //for char[], but read5, because last is '/0'
	cout<<b<<endl;

	// int a;
	// string b;
	// char c;    //zhi hui you 1 wei
	// cin>>a>>b>>c;
	// cout<<a<<b<<c<<endl;

	//////////////////ARRAY//////////////////////////////////////
	// array <array <int, 4>, 5> arr = {};    //5hang4lie  // 这种初始化方法好～
	// arr.fill({2,2});     //dui lie chushihua
	// arr[0].fill({1});    //dui hang chushihua
	// std::cout << arr.size() << std::endl;            //hang
	// std::cout << arr[0].size() << std::endl;         //lie
	// for (int i = 0; i < arr.size(); i++)
	// {
	// 	for (int j = 0; j < arr[0].size(); j++) {
	// 		std::cout << arr[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }


	//////////////////VECTOR//////////////////////////////////////
	// vector<vector<int>> v(4, vector<int>(5));
	// for (int i = 0; i < v.size(); i++)
	// {
	// 	for (int j = 0; j < v[0].size(); j++) {
	// 		std::cout << v[i][j] << " ";
	// 	}
	// 	printf("\n");
	// }
	// v[0].push_back(2);    //不像一维数组，增加删除等都是对行或者列操作的

	// vector<int> v1{ 1,2,3 };
	// for (int val :v1)
	//  {
	// 	 std::cout << val << endl;
	//  }
	//  v1.assign(4, 5);     //hui fugai
	//  std::cout << "vectorV1" << endl;
	//  for (int val :v1)
	//  {
	// 	 std::cout << val << endl;
	//  }
	//  vector<int> v2;
	//  std::cout << "vectorV2" << endl;
	//  v2.assign(v1.begin(), v1.end());
	//  for (int val : v2)
	//  {
	// 	 std::cout << val << endl;
	//  }


	//////////////////LIST//////////////////////////////////////
	// list<int> v(4,5);
	// list<int>::const_iterator it = v.begin();
	// for(; it!=v.end(); it++)
	// {
	// 	cout<<*it<<" ";
	// }
	// it--;
	// v.insert(it, 6);  //插入要靠迭代器
	// for(int val : v)
	// {
	// 	cout<<val<<" ";
	// }


	//////////////////MAP//////////////////////////////////////
	// 	unordered_map<string, int> hashmap;
		
	// 	hashmap["abc"]=8;
	// 	hashmap["abc"]=1;
	// 	hashmap["nba"]=2;
	// 	hashmap["wyl"]=5;
	// 	hashmap["cba"]=6;

	// 	auto it = hashmap.find("abc");           //meiyou chongfu!
	// 	cout<<it->first<<" "<<it->second<<endl;

	// 	hashmap.erase("abc");                //删除的参数是迭代器或者键值
	// 	for(unordered_map<string, int>::iterator is=hashmap.begin(); is!=hashmap.end(); is++)
	// 	{
	// 		cout<<is->first<<" "<<is->second<<endl;
	// 	}
}
