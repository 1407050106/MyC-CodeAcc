#include <iostream>
#include <vector>
using namespace std;
// 既包含计数也包含记录全部结果，两种方法都有!
class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        if (n==1) 
        {
            vector<string> res1;
            res1.push_back("Q");
            vector<vector<string>> res2;
            res2.push_back(res1);
            return res2;
        }
        if (n<4) return{}; 
        vector<string> ans;
        vector<int> record;
        record.resize(n);
        int counts = process1(0, record, n, ans);
        return res;
    }

    int process1(int i, vector<int> record, int n, vector<string>& ans) {  // 你就假设你现在来到了i行
		if (i == n) {
            res.push_back(ans);
            return 1;
		}
		int resm=0;
		for (int j = 0; j < n; j++) {
			// 如果跟之前的皇后不打架，就记录一下，然后继续统计去吧。如果打架，换一列！
			if (isValid(record, i, j)) {
				record[i] = j;
                string temp = recordQ(n, j);
                // cout<<temp<<endl;
                ans.push_back(temp);
				resm+=process1(i + 1, record, n, ans);
                ans.pop_back();
			}
		}
        return resm;
	}

    string recordQ(int n, int j)
    {
        string res="";
        for (int i=0; i<n; i++)
        {
            if (i==j)
            {
                res+="Q";
                continue;
            }
            res+=".";
        }
        return res;
    }

    bool isValid(vector<int> record, int i, int j) { // 第i行j列的皇后跟之前打架嘛？
		// 0..i-1
		for (int k = 0; k < i; k++) {  // 遍历record里的记录
			// 如果发现共列或者共斜线
			if (j == record[k] || abs(record[k] - j) == abs(i - k)) {
				return false;
			}
		}
		return true;
	}

    int getnums(int n)
    {
        if (n<1) return 0;
        vector<int> record;
        record.resize(n);
        return process2(0, record, n);
    }

    int process2(int i, vector<int> record, int n) {  // 你就假设你现在来到了i行
		if (i == n) {
            return 1;
		}
		int resm=0;
		for (int j = 0; j < n; j++) {
			// 如果跟之前的皇后不打架，就记录一下，然后继续统计去吧。如果打架，换一列！
			if (isValid(record, i, j)) {
				record[i] = j;
				resm+=process2(i + 1, record, n);
			}
		}
        return resm;
	}
};

int main() {
    vector<vector<string>> res;
    Solution sc;
    res=sc.solveNQueens(5);
    int m=res.size(), n=res[0].size();
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout<<res[i][j]<<" ";
        }
        printf("\n");
    }

    cout<<sc.getnums(5)<<endl;   // no problem
}