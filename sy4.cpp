#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

const int MAXN = 20000;
int arr[MAXN], temp[MAXN];
int n;

// 工具函数：复制数组
void copyArray(int dest[], int src[], int len)
{
    for (int i = 0; i < len; ++i)
        dest[i] = src[i];
}

// 直接插入排序
void insertionSort(int a[], int len)
{
    for (int i = 1; i < len; ++i)
    {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// 冒泡排序
void bubbleSort(int a[], int len)
{
    for (int i = 0; i < len - 1; ++i)
        for (int j = 0; j < len - i - 1; ++j)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

// 选择排序
void selectionSort(int a[], int len)
{
    for (int i = 0; i < len - 1; ++i)
    {
        int minIdx = i;
        for (int j = i + 1; j < len; ++j)
            if (a[j] < a[minIdx])
                minIdx = j;
        swap(a[i], a[minIdx]);
    }
}

// 快速排序
void quickSort(int a[], int low, int high)
{
    if (low >= high)
        return;
    int i = low, j = high, pivot = a[low];
    while (i < j)
    {
        while (i < j && a[j] >= pivot)
            j--;
        if (i < j)
            a[i++] = a[j];
        while (i < j && a[i] <= pivot)
            i++;
        if (i < j)
            a[j--] = a[i];
    }
    a[i] = pivot;
    quickSort(a, low, i - 1);
    quickSort(a, i + 1, high);
}

// 堆排序相关函数
void heapify(int a[], int n, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
        heapify(a, len, i);
    for (int i = len - 1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

// 归并排序相关函数
void merge(int a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= m)
        temp[k++] = a[i++];
    while (j <= r)
        temp[k++] = a[j++];
    for (i = l; i <= r; i++)
        a[i] = temp[i];
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

// 主函数
int main()
{
    int original[MAXN];
    cout << "请输入排序元素个数（如10000或20000）: ";
    cin >> n;

    // 初始化随机数种子
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
        original[i] = rand() % (n * 10);

    DWORD start, end;

    // 插入排序
    copyArray(arr, original, n);
    start = GetTickCount();
    insertionSort(arr, n);
    end = GetTickCount();
    cout << "直接插入排序的时间为： " << end - start << " 毫秒" << endl;

    // 冒泡排序
    copyArray(arr, original, n);
    start = GetTickCount();
    bubbleSort(arr, n);
    end = GetTickCount();
    cout << "冒泡排序的时间为：      " << end - start << " 毫秒" << endl;

    // 快速排序
    copyArray(arr, original, n);
    start = GetTickCount();
    quickSort(arr, 0, n - 1);
    end = GetTickCount();
    cout << "快速排序的时间为：      " << end - start << " 毫秒" << endl;

    // 选择排序
    copyArray(arr, original, n);
    start = GetTickCount();
    selectionSort(arr, n);
    end = GetTickCount();
    cout << "直接选择排序的时间为：  " << end - start << " 毫秒" << endl;

    // 堆排序
    copyArray(arr, original, n);
    start = GetTickCount();
    heapSort(arr, n);
    end = GetTickCount();
    cout << "堆排序的时间为：        " << end - start << " 毫秒" << endl;

    // 归并排序
    copyArray(arr, original, n);
    start = GetTickCount();
    mergeSort(arr, 0, n - 1);
    end = GetTickCount();
    cout << "归并排序的时间为：      " << end - start << " 毫秒" << endl;

    return 0;
}
