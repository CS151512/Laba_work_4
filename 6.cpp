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

int Find(const double* a, int n,double target) {
    double eps = 1.0e-6;

    for (int i = 0; i < n; i++) {
        if (std::abs(a[i] - target) < eps) {
            return i;
        }
    }
    return -1;
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