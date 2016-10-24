
// PracticeDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "Practice.h"
#include "PracticeDlg.h"
#include "afxdialogex.h"
#include <stdlib.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPracticeDlg 對話方塊



CPracticeDlg::CPracticeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPracticeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPracticeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPracticeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CPracticeDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPracticeDlg 訊息處理常式

BOOL CPracticeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO:  在此加入額外的初始設定

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CPracticeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CPracticeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CPracticeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//------------------------------------Tools----------------------------------------
int comparefunc(const void *a, const void *b) {
	return  (*(int *)a - *(int *)b);
}
int comparefunc_char(const void *a, const void *b) {
	return  (*(char *)a - *(char *)b);
}

void CPracticeDlg::swap(int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void CPracticeDlg::bubblesort(int *data, int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (data[j] > data[j + 1])
			{
				swap(&data[j], &data[j + 1]);
			}
		}
	}
}

// push a value into a stack
ListNode * CPracticeDlg::push(ListNode *input, int val)
{
	// allocate a new node for val
	ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node->val = val;
	new_node->next = input;
	input = new_node;
	return new_node;
}
// pop a value out from the stack
int pop(ListNode *input)
{
	// tmp for record the top node
	ListNode *tmp;
	int return_value;
	// if there is an existing data in stack
	if (input != NULL) {
		// get the value of the top
		return_value = input->val;
		// record the top node
		tmp = input;
		// change top
		input = input->next;
		free(tmp);
		return return_value;
	}
	else
		printf("no existing data in the stack!\n");
}

// show the stack
void show_stack(ListNode *input)
{
	ListNode *rush = input;
	printf("\nthe stack is:\n");
	while (rush != NULL) {
		printf("%d ", rush->val);
		rush = rush->next;
	}
	puts("");
}





void CPracticeDlg::OnBnClickedButton1() //Testing button
{
	ListNode *Node = new ListNode(1);
	Node->next = new ListNode(2);
	Node->next->next = new ListNode(3);
	Node->next->next->next = Node;
	//ListNode *Output = ReverseLinkedList(Node);
	//DeleteNode(Node->next);
	
	//--------------------------------------------------
	/*int test[] = { 2, 4, 1, 11, 9 };
	qsort(test, 5, sizeof(int), comparefunc);*/
	//--------------------------------------------------
	//-------tree-------
	/*TreeNode *Tree = new TreeNode(1);
	Tree->left = new TreeNode(2);
	Tree->right = new TreeNode(3);
	Tree->left->left = new TreeNode(6);
	Tree->left->right = new TreeNode(7);
	Tree->right->left = new TreeNode(8);
	Tree->right->right = new TreeNode(9);*/
	//int Depth = MaxDepth(Tree);
	
	//--------------------------------------------------
	/*int test[] = { 2, 4, 1, 11, 9 };
	twoSum(test,5,10);*/
	//--------------------------------------------------
	/*char *Result = ReverString("Helllllo yoyo");
	char Yo[64] = { 0 };
	sprintf(Yo,Result);*/

	//--------------------------------------------------
	//int Result = Adder(12, 24);


	//int result = addDigit(128);

	/*char S[] = "abfc";
	char T[] = "afbcde";
	char *Result = FindTheDifference(S, T);*/


	//inverseTree(Tree);

	/*int NUM[] = { 1, 5, 0, 2, 0, 8 };
	MoveZeros(NUM,6);*/

	/*int S[] = { 1, 5, 5, 3, 7, 8, 9 };
	int T[] = { 1, 2, 3, 5, 8 };
	int *result = intersection(S, 7, T, 5);*/

	//int K = Myatoi("145a3");

	/*char **output = new char*[64];
	char input[] = "o,rr,t";
	int count = spilt(output, input, ",");*/

	//int count = bitcount(64);

	//int Num = Exceltitle2Number("AA");

	//char *title = ExcelNumber2title(27);

	//levelOrderBottom(Tree);

	//bool test = ListHasCycle(Node);

	//int output = IntegerReverse(-321);

	//int output = ReverseBit(1,4);

	//char *output = MyStrstr("abcdefg", "de");
	
	/*int in[] = { 1, 2, 3, 4, 5 };
	int *output = RotateIntArray(in, 5, 3);*/


	//int **output = PascalTriangle(5);

	/*Queue TestQueue;
	TestQueue.push(1);
	TestQueue.push(2);
	TestQueue.push(3);
	TestQueue.pop();
	TestQueue.push(4);
	int z = TestQueue.peek();
	TestQueue.pop();*/

	//int x = TrailingZeroes(8);

	//double x = Mysqrt(9);

	/*
	char **table = new char*[2];
	for (int i = 0; i < 2; i++)
	{
		table[i] = new char[4];
	}
	table[0] = "SFCS";
	table[1] = "ADEE";
	bool x = exist(table, 2, 4, "SEE");*/

	//char *result = BullandCows("1492", "1489");
	
	/*int A[] = { 1, 5, 2, 7, 8 };
	int B[] = { 2, 3 };
	int * Result = merge_two_int_array(A, 5, B, 2);*/
}
//----------------------------------------------------------Linklist------------------------------------------------------
//-------------------------------ReverseLinkedList---------------------------------
struct ListNode* CPracticeDlg::ReverseLinkedList(struct ListNode *head)
{
	if (!head){ return head; }
	ListNode *Temp, *Pre = 0, *Cur;
	Cur = head;
	while (Cur)
	{
		Temp = Cur->next;
		Cur->next = Pre;
		Pre = Cur;
		Cur = Temp;
	}
	return Pre;
}
//-------------------------------ReverseLinkedList end---------------------------------

//-------------------------------------DeleteNode--------------------------------------
void CPracticeDlg::DeleteNode(struct ListNode* head)
{
	if (!head){ return; }
	ListNode *Temp = head;
	if (Temp->next)
	{
		Temp->val = Temp->next->val;
		if (Temp->next->next)
		{
			Temp->next = Temp->next->next;
		}
		else{ Temp->next = NULL; }
	}
}

bool CPracticeDlg::ListHasCycle(ListNode* head)
{
	ListNode* slow = head;
	ListNode* fast = head;
	while (true)
	{
		if (!slow || !fast)
		{ break; }
		if (slow->next)
		{
			slow = slow->next;
		}
		else{ slow = NULL; }
		if (fast->next )
		{
			if (fast->next->next)
			fast = fast->next->next;
		}
		else{ fast = NULL; }
		if (slow == fast)
		{return true;}
	}
	return false;
}



//----------------------------------------------------------Tree-------------------------------------------------------
//------------------------------Maximum Depth of Binary-------------------------------
int CPracticeDlg::MaxDepth(struct TreeNode*root)
{
	int Left = 0;
	int Right = 0;
	if (!root){ return 0; }
	else{
		if (root->left)
		Left = MaxDepth(root->left);
		if (root->right)
		Right = MaxDepth(root->right);
		return max(Left, Right)+1;
	}
}

struct TreeNode* CPracticeDlg::inverseTree(TreeNode* root)
{
	if (!root){ return root; }
	if (root->left)
	{
		root->left = inverseTree(root->left);
	}
	if (root->right)
	{
		root->right = inverseTree(root->right);
	}
	TreeNode* Temp = root->left;
	root->left = root->right;
	root->right = Temp;
	return root;
}

bool CPracticeDlg::isSameTree(TreeNode* A, TreeNode* B){
	if (!A && !B){ return true; }
	else if (!A || !B){ return false; }
	else if (A->val != B->val){ return false; }
	bool Left = true;
	bool Right = true;
	Left = isSameTree(A->left, B->left);
	Right = isSameTree(A->right, B->right);

	return Left & Right;
}

void CPracticeDlg::DFS(TreeNode *root, int level)
{
	if (!root){ return; }
	int count = 0;

	if (level == stackBuff.size()){
		stackBuff.push_back(std::vector<int>());
	}
	stackBuff[level].push_back(root->val);

	if (root->left)
	{
		DFS(root->left, level + 1);
	}
	if (root->right)
	{
		DFS(root->right, level + 1);
	}
	


	//int k = pop(NodeStack[level]);
}

std::vector<std::vector<int>> CPracticeDlg::levelOrderBottom(TreeNode *root)
{
	DFS(root, 0);
	return stackBuff;
}

bool CPracticeDlg::isSymmetric(TreeNode *root){
	return isMirror(root->left, root->right); 
}

bool CPracticeDlg::isMirror(TreeNode *tree1, TreeNode *tree2)
{
	if (!tree1 && !tree2){ return true; }
	else if (!tree1 || !tree2){ return false; }
	bool nextMirror1 = false, nextMirror2 = false;
	nextMirror1 = isMirror(tree1->left, tree1->right);
	nextMirror2 = isMirror(tree2->left, tree2->right);
	if (nextMirror1 && nextMirror2 && tree1->val == tree2->val)
		return true;
	else
		return false;
}


//-----------------------------------------------------------------------------------------------------------------------------
//---------------------------------------twoSum---------------------------------------
int* CPracticeDlg::twoSum(int* nums, int numsSize, int target) {
	int i = 0, j = numsSize-1;
	int *temp = (int*)malloc(numsSize*2*sizeof(int));
	int *output = (int*)malloc(2 * sizeof(int));
	
	for (i = 0; i < numsSize; i++)
	{
		temp[2 * i] = nums[i];   // temp[num1][1][num2][2]...
		temp[2 * i + 1] = i;
	}
	qsort(temp, numsSize, 2 * sizeof(temp[0]), comparefunc);
	i = 0;
	while(i < numsSize && j >= 0)
	{
		if (temp[2 * i] + temp[2 * j] > target)
		{
			j--;
		}
		else if (temp[2 * i] + temp[2 * j] < target)
		{
			i++;
		}
		else{ break; }
	}
	output[0] = temp[2 * i + 1];
	output[1] = temp[2 * j + 1];
	return output;
}


//ReverseString
char *CPracticeDlg::ReverString(char *Input)
{
	int Len = strlen(Input);
	char *Buff = new char[Len];
	int j = 0;
	for (int i = 0; i < Len; i++)
	{
		j = Len - i - 1;
		Buff[i] = Input[j];
	}
	return Buff;
}

//adder
int CPracticeDlg::Adder(int a, int b)
{
	int carry = 0;
	while(b)
	{
		carry = (a & b) << 1;
		a = a ^ b;
		b = carry;
	}
	return a;
}

int CPracticeDlg::singleNumber(int *Num, int sizeNum)
{
	int XORSum = 0;
	for (int i = 0; i < sizeNum; i++)
	{
		XORSum ^= Num[i];
	}
	return XORSum;
}


int CPracticeDlg::addDigit(int num)
{
	int check = num;
	int sum = 0;
	int checkcount = 0; //確認有幾位數
	while (check)
	{
		check /= 10;
		checkcount++;
	}
	int *Temp = new int[checkcount+1];
	int i = 0;
	while (true)
	{
		i = 0;
		while (num)
		{
			Temp[i] = num % 10;
			num = num / 10;
			sum += Temp[i];
			i++;
		}
		if (sum < 10)
		{break;}
		else{ num = sum; sum = 0; }
	}
	return sum;
}

char* CPracticeDlg::FindTheDifference(char *s, char *t)// abcf  abcdef  // def len_s < len_t
{
	int Len_s = strlen(s);
	int Len_t = strlen(t);
	char *DiffBuff = new char[Len_t];
	//int Len_max = max(Len_s, Len_t);
	int i = 0, j = 0, XORSum = 0, Buffcount = 0;
	qsort(s, Len_s, sizeof(char), comparefunc_char);
	qsort(t, Len_t, sizeof(char), comparefunc_char);
	while (i < Len_t)
	{
		XORSum = t[i] ^ s[j];
		if (XORSum != 0)
		{
			DiffBuff[Buffcount] = t[i];
			i++;
			Buffcount++;
		}
		else
		{
			i++; j++;
		}
	}
	return DiffBuff;
}

void CPracticeDlg::MoveZeros(int *nums, int numsize)
{
	int nonezerocount = 0;
	for (int i = 0; i < numsize; i++)
	{
		if (nums[i] != 0)
		{
			nums[nonezerocount] = nums[i];
			nonezerocount++;
		}
	}
	for (int i = nonezerocount; i < numsize; i++)
	{
		nums[i] = 0;
	}
}

int CPracticeDlg::SumOfLeftLeaves(TreeNode *root)
{
	if (!root){ return 0; }
	int sum = 0;
	if (root->left)
	{
		sum = SumOfLeftLeaves(root->left);
	}
	sum += root->val;
	return sum;
}

int* CPracticeDlg::intersection(int *num1, int size1, int *num2, int size2)
{
	qsort(num1, size1, sizeof(int), comparefunc);
	qsort(num2, size2, sizeof(int), comparefunc);
	int *Temp = new int[max(size1, size2)];
	int i = 0, j = 0, samecount = 0;
	int XORsum = 0;
	while (i < size1 && j < size2)
	{
		if (num1[i] == num2[j])
		{
			if (samecount == 0 || Temp[i - 1] != num1[i])
			{
				Temp[samecount] = num1[i];
				i++;
				j++;
				samecount++;
			}
		}
		else if (num1[i] > num2[j])
		{
			j++;
		}
		else if (num1[i] < num2[j])
		{
			i++;
		}
	}

	return Temp;
}

int CPracticeDlg::Myatoi(char *input)
{
	int len = strlen(input);
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		if (input[i] <= '9' && input[i] >='0')
		{
			sum = sum*10 + input[i] - '0';
		}
		else{ return sum; } //碰到字母就跳出
	}
	return sum;
}
int CPracticeDlg::spilt(char **output, char *input, const char *delim)
{
	int spiltcount = 0;
	char *temp = strtok(input, delim);
	while (temp != NULL)
	{
		output[spiltcount] = temp;
		temp = strtok(NULL, delim);
		spiltcount++;
	}
	return spiltcount;
}

int CPracticeDlg::bitcount(unsigned int n)
{
	int count = 0;
	int temp = 0;
	int num = n;
	while (num)
	{
		temp = num & 1;
		if (temp == 1)
		{ count++; }
		num = num >> 1;
	}
	return count;
}

int CPracticeDlg::Exceltitle2Number(char *input)
{
	int i = 0;
	int sum = 0;
	while (input[i])
	{
		sum = sum*26 + input[i] - 'A' + 1;
		i++;
	}
	return sum;
}

char* CPracticeDlg::ExcelNumber2title(int input)
{
	char sum[64] = { 0 }, recurSumBuff[64] = {0};
	char temp;
	while (input != 0)
	{
		temp = (char)(input - 1)%26 + 'A';
		input = (input - 1) / 26;
		sprintf(sum, "%c%s", temp, recurSumBuff);
		sprintf(recurSumBuff, sum);
	}
	return sum;
}

int CPracticeDlg::Fibonacci(int n)
{
	if (n < 2){ return 1; }
	int *result = new int[n + 1];
	result[0] = 1;
	result[1] = 1;
	for (int i = 2; i < n; i++)
	{
		result[i] = result[i - 1] + result[i - 2];
	}
	return result[n];
}

int CPracticeDlg::IntegerReverse(int x)
{
	int sigma = 0;
	if (x < 0){ sigma = -1; }
	else{ sigma = 1; }
	x = x*sigma;
	int sum = 0;
	//----------------
	while (x)
	{
		sum *= 10;
		sum += x % 10;
		x /= 10;
	}
	sum *= sigma;
	return sum;
}

int CPracticeDlg::ReverseBit(int x, int maxbit)
{
	int sum = 0;
	int temp = 0;
	for (int i = 0; i < maxbit; i++)
	{
		sum = sum << 1;
		temp = x & 1;
		if (temp == 1) { sum++; }
		x = x >> 1;
	}
	return sum;
}

char* CPracticeDlg::MyStrstr(char *input, char* indexString)
{
	int len_input = strlen(input);
	int len_index = strlen(indexString);
	int i = 0, j = 0;
	int offset = 0;
	bool checkfirstflag = false;
	while (i < len_input && j < len_index)
	{
		if (input[i] == indexString[j])
		{
			if (!checkfirstflag)
			{
				checkfirstflag = true;
				offset = i;
			}
			i++; j++;
		}
		else{ checkfirstflag = false; offset = 0; j = 0; i++; }
	}
	if (checkfirstflag && j == len_index)
		return &input[offset];
	else
		return input;
}

int *CPracticeDlg::RotateIntArray(int *num, int numsize, int rotateindex)
{
	int *temp = new int[numsize];
	for (int i = 0; i < numsize; i++)
	{
		temp[(i + rotateindex) % numsize] = num[i];
	}
	return temp;
}

int **CPracticeDlg::PascalTriangle(int level)
{
	int **LevelBuff = new int*[level];
	for (int i = 0; i < level; i++)
	{
		LevelBuff[i] = new int[i+1];
		LevelBuff[i][0] = 1;
		if (i > 0)
		{
			LevelBuff[i][i] = 1;
			if (i > 1)
			{
				for (int j = 1; j < i; j++)
				{
					LevelBuff[i][j] = LevelBuff[i - 1][j - 1] + LevelBuff[i - 1][j];
				}
			}
		}
	}
	return LevelBuff;
}

int CPracticeDlg::TrailingZeroes(int n)//去計算 n! 的值 後面有幾個0   EX: n =5  5! =120  1個0
{
	int sum = 1, zerocount = 0, step = 0;
	for (int i = 1; i <= n; i++)
	{
		sum *= i;
	}
	while (true)
	{
		step = sum % 10;
		if (step != 0){ break; }
		else{ 
			zerocount++; 
			sum /= 10;
		}
	}
	return zerocount;
}




//--------------------------------medium-------------------------------
double CPracticeDlg::Mysqrt(int num)
{
	float start = 0, end = num / 2 + 1;
	float sum = 0;
	char temp[16] = { 0 };
	while (end > start)
	{
		sum = (start + end) / 2;
		sprintf(temp,"%0.2f", sum);
		sum = atof(temp);
		if (sum * sum == num){ break; }
		else if (sum * sum < num)
		{
			start = sum;
		}
		else
		{
			end = sum;
		}
	}
	return sum;
}

bool CPracticeDlg::exist(char **board, int row_size, int col_size, char *word)
{
	int wordlen = strlen(word);
	bool **visit_board = new bool*[row_size];
	for (int i = 0; i < row_size; i++)
	{ 
		visit_board[i] = new bool[col_size];
		for (int j = 0; j < col_size; j++){ visit_board[i][j] = false; }
	}


	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
		{
			if (DFS_FindWord(board, visit_board, row_size, col_size, word, i, j, 0, wordlen)){ return true; }
		}
	}

	return false;
}

bool CPracticeDlg::DFS_FindWord(char **board, bool **visit, int row_size, int col_size, char *word, int row, int col, int word_index, int word_size)
{
	if (word_index == word_size){ return true; }
	if (row < 0 || row >= row_size || col < 0 || col >= col_size || visit[row][col] || board[row][col] != word[word_index])
	{
		return false;
	}
	visit[row][col] = true;
	if (DFS_FindWord(board, visit, row_size, col_size, word, row + 1, col, word_index+1, word_size)){ return true; }
	if (DFS_FindWord(board, visit, row_size, col_size, word, row - 1, col, word_index+1, word_size)){ return true; }
	if (DFS_FindWord(board, visit, row_size, col_size, word, row, col + 1, word_index+1, word_size)){ return true; }
	if (DFS_FindWord(board, visit, row_size, col_size, word, row, col - 1, word_index+1, word_size)){ return true; }
	/*if (DFS_FindWord(board, visit, row_size, col_size, word, row + 1, col + 1, word_index + 1, word_size)){ return true; }
	if (DFS_FindWord(board, visit, row_size, col_size, word, row - 1, col - 1, word_index + 1, word_size)){ return true; }
	if (DFS_FindWord(board, visit, row_size, col_size, word, row - 1, col + 1, word_index + 1, word_size)){ return true; }
	if (DFS_FindWord(board, visit, row_size, col_size, word, row + 1, col - 1, word_index + 1, word_size)){ return true; }*/
	visit[row][col] = false;
	return false;
}

char* CPracticeDlg::BullandCows(char *secret, char*guess)
{
	int  Anum = 0, Bnum = 0;
	char Output[32] = { 0 };
	char hashtable[10] = { 0 };
	int seretcLen = strlen(secret);
	int guessLen = strlen(guess);
	if (seretcLen != guessLen){ return "0"; }
	// && '0' <= (guess[i] - '0') && (guess[i] - '0') <= '9'
	for (int i = 0; i < seretcLen; i++)
	{
		hashtable[secret[i] - '0']++;
		if (secret[i] == guess[i]){ Anum++; hashtable[secret[i] - '0']--; }
	}

	for (int i = 0; i < guessLen; i++)
	{
		if (hashtable[guess[i] - '0']){ Bnum++; hashtable[guess[i] - '0']--; }
	}
	sprintf(Output, "%dA%dB \r\n", Anum, Bnum);
	return Output;
}

//Merge Sorted Array
int* CPracticeDlg::merge_two_int_array(int* num1, int num1_len, int* num2, int num2_len)
{
	int *temp = new int[num1_len + num2_len];
	int i = 0, j = 0, k = 0;
	qsort(num1, num1_len, sizeof(int), comparefunc);
	qsort(num2, num2_len, sizeof(int), comparefunc);
	while (k < (num1_len + num2_len))
	{
		if (num1[i] <= num2[j] || j >= num2_len)
		{
			temp[k] = num1[i];
			k++;
			i++;
		}
		else if (num1[i] > num2[j] || i >= num1_len)
		{
			temp[k] = num2[j];
			k++;
			j++;
		}
	}
	return temp;
}