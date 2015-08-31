#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &v, int start, int end) 
{
    int i = start, j = end + 1, pv = start;
    
    while (true) {
        while (v[++i] < v[pv]) 
            if (i == end) break;
        while (v[--j] > v[pv])
            if (j == start) break;
        if (j <= i) break;
        swap(v[i], v[j]);
    }
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
