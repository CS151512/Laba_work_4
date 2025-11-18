#include "iostream"
#include "random"
#include "chrono"

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void FillArr(int *a,int n) {
    std::uniform_int_distribution<int> dist(1,100);

    for (int i = 0; i < n; i++) {
        a[i] = dist(rng);
    }
}

int Solution(const int* a, int n,int target) {//bin
    int l =0;
    int r = n-1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == target) {
            return m;
        }

        if (a[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
}

void solve() {
    int n;
    std::cin>>n;

    auto* arr = new int[n];
    FillArr(arr, n);

    delete[] arr;

}

int main() {
    solve();
    return 0;
}