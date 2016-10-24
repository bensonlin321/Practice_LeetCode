
// PracticeDlg.h : 標頭檔
//
#include <vector>
#include <stack>

#pragma once
/*class TreeNode{
public:
	class TreeNode *left;
	class TreeNode *right;
	TreeNode(){
		left = NULL;
		right = NULL;
	}
	~TreeNode(){
	};
};*/

//Implement Stack using Queues
class Queue{
private:
	std::stack<int> input, output;
public:
	//Push
	void push(int x)
	{
		reversepouring(input, output);
		input.push(x);
	}
	void pouring(std::stack<int> &input, std::stack<int> &output)
	{
		if (output.empty())
		{
			while (!input.empty())
			{
				output.push(input.top());
				input.pop();
			}
		}
	}
	void reversepouring(std::stack<int> &input, std::stack<int> &output)
	{
		while (!output.empty())
		{
			input.push(output.top());
			output.pop();
		}
	}
	void pop(void) //delete the top element
	{
		pouring(input, output);
		output.pop();
	}
	int peek(void)
	{
		pouring(input, output);
		int x = output.top();
		return x;
	}
};


//-----------------Benson------------------

struct ListNode{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};


// TOP of a stack





//---------------Benson end-----------------

// CPracticeDlg 對話方塊
class CPracticeDlg : public CDialogEx
{
// 建構
public:
	CPracticeDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
	enum { IDD = IDD_PRACTICE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援



// 程式碼實作
	struct ListNode* ReverseLinkedList(ListNode *head);
	void bubblesort(int *data, int n);
	void swap(int *a, int *b);
	void DeleteNode(struct ListNode* head);
	int MaxDepth(struct TreeNode*root);
	int* twoSum(int* nums, int numsSize, int target);
	char *ReverString(char *Input);
	int Adder(int a, int b);
	int singleNumber(int *Num, int sizeNum);
	int addDigit(int num);
	char *FindTheDifference(char *s, char *t);
	struct TreeNode* inverseTree(TreeNode* root);
	void MoveZeros(int *nums, int numsize);
	int SumOfLeftLeaves(TreeNode *root);
	int* intersection(int *num1, int size1, int *num2, int size2);
	bool isSameTree(TreeNode* A, TreeNode* B);
	int Myatoi(char *input);
	int spilt(char **output, char *input, const char *delim);
	int bitcount(unsigned int n);
	int Exceltitle2Number(char *input);
	char* ExcelNumber2title(int input);
	int Fibonacci(int n);
	std::vector<std::vector<int>> stackBuff;
	void DFS(TreeNode *root, int level);
	ListNode * push(ListNode *input, int val);
	std::vector<std::vector<int>> levelOrderBottom(TreeNode *root);
	bool ListHasCycle(ListNode* head);
	int IntegerReverse(int x);
	int ReverseBit(int x, int maxbit);
	char* MyStrstr(char *input, char* indexString);
	bool isSymmetric(TreeNode *root);
	bool isMirror(TreeNode *tree1, TreeNode *tree2);
	int *RotateIntArray(int *num, int numsize, int rotateindex);
	int **PascalTriangle(int level);
	int TrailingZeroes(int n);
	char* BullandCows(char *secret, char*guess);
	int* merge_two_int_array(int* num1, int num1_len, int* num2, int num2_len);
	//medium
	double Mysqrt(int num);
	bool exist(char **board, int row_size, int col_size, char *word);
	bool DFS_FindWord(char **board, bool **visit, int row_size, int col_size, char *word, int row, int col, int word_index, int word_size);
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
