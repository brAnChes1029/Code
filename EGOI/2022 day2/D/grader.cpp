#include "cheat.h"
#include <iostream>
#include <vector>
#include <utility>

int main() {
    int Q;
    std::cin >> Q;
    while (Q--) {
        int N;
        std::cin >> N;
        std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> P = BuildPattern(N);
        int N_output = GetCardNumber(P);
        std::cout << N_output << "\n";
    }
    return 0;
}
