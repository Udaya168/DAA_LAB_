#include <iostream>
using namespace std;

int main() {
    // Predefined sorted array
    int arr[] = {3, 7, 12, 18, 25, 31, 42, 56};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 25;   // Value to search

    int low = 0;
    int high = n - 1;
    int mid;
    bool found = false;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == target) {
            cout << "Element found at index: " << mid << endl;
            found = true;
            break;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (!found) {
        cout << "Element not found" << endl;
    }

    return 0;
}