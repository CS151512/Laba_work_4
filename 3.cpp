#include "iostream"
#include "random"
#include "chrono"

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void FillArr(double *a,int n) {
    std::uniform_real_distribution<double> dist(1.0,100.0);

    for (int i = 0.0; i < n; i++) {
        a[i] = dist(rng);
    }
}

void Solution(const double* a, const int n) {
    double prod = 1.0;
    for (int i = 0; i < n; i++) {
        if ((i & 1) == 0) {
            prod *= a[i];
            // std::cout<<i<<"\n";
        }
    }

    // for (int i = 0; i < n; i++) {
    //     std::cout << a[i] << ", ";
    // }

    std::cout << prod;
}

void solve() {
    int n;
    std::cin>>n;

    auto* arr = new double[n];
    FillArr(arr, n);
    Solution(arr, n);

    delete[] arr;
}

int main() {
    solve();
    return 0;
}