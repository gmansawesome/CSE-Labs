#include <iostream>
#include <climits>
#include <tuple>

using namespace std;

tuple<int, int, int> find_max_crossing_subarray(int* arr, int low, int mid, int high) {
    int LHS_sum = INT_MIN;
    int max_left = low;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > LHS_sum) {
            LHS_sum = sum;
            max_left = i;
        }
    }

    int RHS_sum = INT_MIN;
    int max_right = mid+1;
    sum = 0;
    for (int i = mid+1; i <= high; i++) {
        sum += arr[i];
        if (sum > RHS_sum) {
            RHS_sum = sum;
            max_right = i;
        }
    }

    return make_tuple(max_left, max_right, (LHS_sum + RHS_sum));
}

tuple<int, int, int> find_max_subarray(int* arr, int low, int high) {
    if (high == low) {
        return make_tuple(low, high, arr[low]);
    }
    else {
        int mid = (low+high)/2;

        int LHS_low, LHS_high, LHS_sum;
        tie(LHS_low, LHS_high, LHS_sum) = find_max_subarray(arr, low, mid);

        int RHS_low, RHS_high, RHS_sum;
        tie(RHS_low, RHS_high, RHS_sum) = find_max_subarray(arr, mid+1, high);

        int CC_low, CC_high, CC_sum;
        tie(CC_low, CC_high, CC_sum) = find_max_crossing_subarray(arr, low, mid, high);

        if (LHS_sum >= RHS_sum && LHS_sum >= CC_sum) {
            return make_tuple(LHS_low, LHS_high, LHS_sum);
        }
        else if (RHS_sum >= LHS_sum && RHS_sum >= CC_sum) {
            return make_tuple(RHS_low, RHS_high, RHS_sum);
        }
        else {
            return make_tuple(CC_low, CC_high, CC_sum);
        }
    }
}

int main() {
    int size = 0;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int low, high, sum;
    tie(low, high, sum) = find_max_subarray(arr, 0, size-1);

    cout << sum;
}