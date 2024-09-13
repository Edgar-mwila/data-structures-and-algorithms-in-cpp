#include <iostream>

using namespace std;
int arr[100];

//binary search
int binarySearch(int target)
{
    int low = 0;
    int high = 99;

    while(low <= high)
    {
        int middle = low + (high - low) / 2;
        int value = arr[middle];

        if(value < target) low = middle + 1;
        else if(value > target) high =  middle - 1;
        else return middle;
    }

    return -1;
}

//interpolation search
int interpolationSearch(int target)
{
    int low = 0;
    int count = 1;
    int high = 99;

    while(low <= high && target >= arr[low] && target <= arr[high])
    {
        cout<<"interpolation "<< count<< endl;
        int probe = low + (high - low) * (target - arr[low]) / (arr[high] - arr[low]);
        
        if(arr[probe] == target) return probe;
        else if(arr[probe] < target) low = probe + 1;
        else high = probe - 1;
    }

    return -1;
}

int main()
{
    for (int i = 0; i < 100; i++)
    {
        arr[i] = i + 1;
    }
    int target;
    cout<<"enter search item: ";
    cin >> target;

    int index = interpolationSearch(target);

    if(index < 0)
    {
        cout<<"target not found in the array";
    } else cout << "Target fount at index: "<<index<<endl;

    return 0;
}