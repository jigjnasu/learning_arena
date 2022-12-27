#include "../../code/cpp/bubble.h"

#include <random>
#include <chrono>
#include <cassert>
#include <algorithm>
#include <iostream>

int random(int s, int e) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(s, e);
    return dist(mt);
}

std::vector<int> get_random_vector(int n) {
    std::vector<int> v;
    for (int i = 0; i < n; ++i)
        v.emplace_back(random(-1e9, 1e9));
    return v;
}

void assert_array(const std::vector<int> &v1, const std::vector<int> &v2) {
    assert(v1.size() == v2.size());
    for (std::size_t i = 0; i < v1.size(); ++i)
        assert(v1[i] == v2[i]);
}

void test_bubble_sort(std::vector<int>& v, const std::vector<int> &v_sorted) {
    Bubble b;
    auto start = std::chrono::high_resolution_clock::now();
    b.sort(v);
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - start);
    std::cout << "bubble sort execution time == " << duration.count() / 1e9 << " seconds" << std::endl;
    assert_array(v, v_sorted);
}

int main() {
    const int n = 1e5;
    std::vector<int> v = get_random_vector(n);
    std::vector<int> v_sorted = v;
    std::sort(v_sorted.begin(), v_sorted.end());

    std::vector<int> v1 = v;
    test_bubble_sort(v1, v_sorted);
   
    return 0;
}