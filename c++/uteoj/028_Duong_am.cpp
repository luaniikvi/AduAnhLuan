#include <iostream>
#include <vector>

void rearrange_alternate(std::vector<int>& arr) {
    std::vector<int> negative, positive;
    
    // Separate the numbers into negative and positive
    for (int num : arr) {
        if (num < 0) {
            negative.push_back(num);
        } else {
            positive.push_back(num);
        }
    }
    
    // Merge back into the original array with alternating signs
    int i = 0, neg_index = 0, pos_index = 0;
    while (neg_index < negative.size() && pos_index < positive.size()) {
        if (i % 2 == 0) {
            arr[i++] = negative[neg_index++];
        } else {
            arr[i++] = positive[pos_index++];
        }
    }
    
    // Append remaining elements
    while (neg_index < negative.size()) {
        arr[i++] = negative[neg_index++];
    }
    while (pos_index < positive.size()) {
        arr[i++] = positive[pos_index++];
    }
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;
    
    std::vector<int> arr(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    
    rearrange_alternate(arr);
    
    std::cout << "Rearranged array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
