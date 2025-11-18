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

void PrintArr(const double* a, int n) {
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";
}

void Solution(double* a, int n) {
    std::uniform_real_distribution<double> neg_dist(-100.0, -1.0);

    for (int i = 0; i < n; ++i) {
        if (a[i] != 0.0) {
            a[i] = neg_dist(rng);
        }
    }
}

void solve() {
    int n;
    std::cin>>n;

    auto* arr = new double[n];
    FillArr(arr, n);
    PrintArr(arr, n);
    std::cout<<"----------"<<"\n";

    Solution(arr, n);
    PrintArr(arr, n);

    delete[] arr;
}

int main() {
    solve();
    return 0;
}