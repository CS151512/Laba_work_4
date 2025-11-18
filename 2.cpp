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

void PrintArr(const double* a, const int n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << (i == n - 1 ? "" : " ");
    }
    std::cout<< "\n";
}

void solve() {
    int n;
    std::cin>>n;

    auto* arr = new double[n];
    FillArr(arr, n);
    PrintArr(arr, n);

    delete[] arr;

}

int main() {
    solve();
    return 0;
}