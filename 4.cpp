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

int IdxFind(int* a,int n) {
    int last_idx = -1;
    int max_val = -1;
    for (int i = 0; i < n; i++) {
        if (abs(a[i]) >= max_val) {
            max_val = abs(a[i]);
            last_idx = i;
        }
    }
    return last_idx;
}

void Solution(const int* a, const int n,int lst_idx) {
    long long prod = 1;
    if (lst_idx == 0 || lst_idx < 0) {
        std::cout<< 0 << "\n";
    }else {
        for (int i = 0; i < n; i++) {
            prod *= a[i];
        }
    }
    std::cout << prod << "\n";
}

void solve() {
    int n;
    std::cin>>n;

    auto* arr = new int[n];
    FillArr(arr, n);
    int idx = IdxFind(arr, n);
    Solution(arr, n,idx);

    delete[] arr;

}

int main() {
    solve();
    return 0;
}