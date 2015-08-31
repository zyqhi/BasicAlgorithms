#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &v, int start, int end) 
{
    // 注意后面的比较都是先自增，后比较。
    // 因此对于i而言，其初始值为start，所以比较是从start后面一个元素开始的。
    // 对于j而言，初始指向end+1，所以比较是从end开始的。
    // 一定要清楚i和j的不同。
    int i = start, j = end + 1, pv = start;
    
    while (true) {
        // 元素小于哨兵的话，则一直向右，直到找到第一个不小于（大于或等于）
        // 哨兵的元素，或者找到终点。i最终指向大于等于哨兵的元素或者终点。
        while (v[++i] < v[pv]) 
            if (i == end) break;
        while (v[--j] > v[pv])
            if (j == start) break;
        if (j <= i) break;
        swap(v[i], v[j]);
    }
    // 程序执行到最后，此时j指向的位置为哨兵的位置
    //// 为什么最终是j指向哨兵的位置，而非i？ 
    // 因为i指向的元素是大于等于哨兵元素的，如果和i位置的元素互换的话，
    // 那么互换后不能保证哨兵左边的元素都大于等于哨兵，程序也就不正确。
    // 由于结束时j指向的元素肯定小于等于哨兵，而j也小于等于i，因此j左边的元素
    // 肯定小于等于哨兵，而j指向的元素也小于哨兵，因此交换j和哨兵后满足哨兵
    // 左边都小于哨兵，右边都大于哨兵
    swap(v[pv], v[j]);

    return j;
}

void quickSortHelper(vector<int> &v, int start, int end)
{
    if (end <= start)
        return;
    int j = partition(v, start, end);
    quickSortHelper(v, start, j-1);
    quickSortHelper(v, j+1, end);
}

void quickSort(vector<int> &v) 
{
    if (v.size() == 0)
        return;
    quickSortHelper(v, 0, v.size() - 1);
}


int main(int argc, char *argv[])
{
    vector<int> v;
    v.push_back(3); 
    v.push_back(6); 
    v.push_back(4); 
    v.push_back(2); 
    v.push_back(9); 

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    quickSort(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
