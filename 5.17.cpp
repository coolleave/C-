#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;

// 二叉排序树结点结构
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 简单选择排序
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

// 顺序查找
bool sequentialSearch(const vector<int> &arr, int target)
{
    for (int num : arr)
    {
        if (num == target)
            return true;
    }
    return false;
}

// 折半查找（二分查找）
bool binarySearch(const vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return true;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

// 插入节点到二叉排序树
TreeNode *insert(TreeNode *root, int val)
{
    if (!root)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    return root;
}

// 查找节点在二叉排序树中
bool bstSearch(TreeNode *root, int target)
{
    while (root)
    {
        if (root->val == target)
            return true;
        else if (target < root->val)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

int main()
{
    const int n = 10000; // 查找表长度
    const int m = 1000;  // 待查找数据数量
    vector<int> table(n);
    vector<int> searchData(m);
    srand(time(nullptr));

    // 1. 初始化查找表
    for (int i = 0; i < n; ++i)
        table[i] = rand();

    // 简单选择排序
    selectionSort(table);

    // 生成待查找数据（从已有表中随机取或新生成）
    for (int i = 0; i < m; ++i)
        searchData[i] = rand(); // 可改成 table[rand() % n] 保证部分数据可命中

    // 2. 顺序查找计时
    auto start1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < m; ++i)
        sequentialSearch(table, searchData[i]);
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed1 = end1 - start1;
    cout << "顺序查找耗时: " << elapsed1.count() << " 秒" << endl;

    // 3. 折半查找计时
    auto start2 = chrono::high_resolution_clock::now();
    for (int i = 0; i < m; ++i)
        binarySearch(table, searchData[i]);
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed2 = end2 - start2;
    cout << "折半查找耗时: " << elapsed2.count() << " 秒" << endl;

    // 4. 创建二叉排序树
    TreeNode *root = nullptr;
    for (int i = 0; i < n; ++i)
        root = insert(root, table[i]);

    // 二叉树查找计时
    auto start3 = chrono::high_resolution_clock::now();
    for (int i = 0; i < m; ++i)
        bstSearch(root, searchData[i]);
    auto end3 = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed3 = end3 - start3;
    cout << "二叉排序树查找耗时: " << elapsed3.count() << " 秒" << endl;

    return 0;
}
