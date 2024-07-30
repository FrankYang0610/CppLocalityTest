#include <iostream>
#include <vector>
#include <chrono>
#define N 50

std::vector <std::array<char,3>> choices {
    {'i','j','k'}, // 1
    {'i','k','j'}, // 2
    {'j','i','k'}, // 3
    {'j','k','i'}, // 4
    {'k','i','j'}, // 5
    {'k','j','i'}  // 6
};

int summarize_test(int b[N][N][N], int choice) {
    int i,j,k;
    int sum = 0;
    switch (choice) {
        case 1: {
            auto start = std::chrono::high_resolution_clock::now();
            for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                    for (k = 0; k < N; k++) {
                        sum += b[i][j][k];
                    }
                }
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            return duration.count();
        }
        case 2: {
            auto start = std::chrono::high_resolution_clock::now();
            for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                    for (k = 0; k < N; k++) {
                        sum += b[i][k][j];
                    }
                }
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            return duration.count();
        }
        case 3: {
            auto start = std::chrono::high_resolution_clock::now();
            for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                    for (k = 0; k < N; k++) {
                        sum += b[j][i][k];
                    }
                }
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            return duration.count();
        }
        case 4: {
            auto start = std::chrono::high_resolution_clock::now();
            for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                    for (k = 0; k < N; k++) {
                        sum += b[j][k][i];
                    }
                }
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            return duration.count();
        }
        case 5: {
            auto start = std::chrono::high_resolution_clock::now();
            for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                    for (k = 0; k < N; k++) {
                        sum += b[k][i][j];
                    }
                }
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            return duration.count();
        }
        case 6: {
            auto start = std::chrono::high_resolution_clock::now();
            for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                    for (k = 0; k < N; k++) {
                        sum += b[k][j][i];
                    }
                }
            }
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            return duration.count();
        }
        default:
            return -1;
    }
}

int global_b[N][N][N];

int main()
{
    // init
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                global_b[i][j][k] = i * j + k;
            }
        }
    }

    // test
    for (int i = 1; i <= 6; i++) {
        auto time_used = summarize_test(global_b, i);
        std::cout << "Choice" << " " << i << " " << "(" << choices[i-1][0] << "," << choices[i-1][1] << "," << choices[i-1][2] << ")" << ":" << " " << "Time used = " << time_used << ". " << std::endl;
    }

    return 0;
}
