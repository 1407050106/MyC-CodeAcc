#include <iostream>
#include<array>
#include<queue>
using namespace std;

int main()
{
    //////////////////ARRAY//////////////////////////////////////
	// std::array <std::array <int, 4>, 5> arr = {};    //5hang4lie
	// arr.fill({ 1,2,3,4 });
    // arr.fill({ 4,3,2,1 });
	// std::cout << arr.size() << std::endl;            //hang
	// std::cout << arr[0].size() << std::endl;         //lie
	// for (int i = 0; i < arr.size(); i++)
	// {
	// 	for (int j = 0; j < arr[0].size(); j++) {
	// 		std::cout << arr[i][j] << " ";
	// 	}
	// 	std::cout << std::endl;
	// }
	// std::cin.get();

    //////////////////QUEUE//////////////////////////////////////
    std::queue <int> w1;
    w1.push(1);
    std::cout << w1.front() << std::endl;

	//return 0;
}
