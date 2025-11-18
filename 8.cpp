#include <iomanip>

#include "iostream"
#include "random"
#include "chrono"

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void FillArr(double *a,int n) {
    std::uniform_real_distribution<double> dist(0.0,100.0);

    for (int i = 0.0; i < n; i++) {
        a[i] = dist(rng);
    }
}

int Solution(double* a, int n) {
    int inter_idx = 0;

    for (int i = 0; i < n; i++) {
        if (static_cast<long long>(a[i]) % 2 == 0) {
            if (i != inter_idx) {
                std::swap(a[i], a[inter_idx]);
            }
            inter_idx++;
        }
    }
}


void solve() {
    int n;
    std::cin>>n;

    auto* arr = new double[n];
    FillArr(arr, n);

    delete[] arr;
}

int main() {
    solve();
    return 0;
}