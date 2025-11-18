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

void Solution(int* a, int l,int r) {//Quick
    if (l >= r) return;

    int pivot = a[l + (r - l) / 2];

    int i = l;
    int j = r;

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            std::swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (l < j) Solution(a, l, j);
    if (i < r) Solution(a, i, r);
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