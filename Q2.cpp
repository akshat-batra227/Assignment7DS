#include <iostream>
#include <vector>
using namespace std;

void improvedSelectionSort(vector<int> &a) {
    int left = 0;
    int right = (int)a.size() - 1;
    while (left < right) {
        int minIndex = left;
        int maxIndex = left;
        for (int i = left; i <= right; i++) {
            if (a[i] < a[minIndex]) minIndex = i;
            if (a[i] > a[maxIndex]) maxIndex = i;
        }
        int temp = a[left];
        a[left] = a[minIndex];
        a[minIndex] = temp;
        if (maxIndex == left) maxIndex = minIndex;
        temp = a[right];
        a[right] = a[maxIndex];
        a[maxIndex] = temp;
        left++;
        right--;
    }
}

void printArray(const vector<int> &a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    improvedSelectionSort(a);

    cout << "Sorted array: ";
    printArray(a);
    return 0;
}