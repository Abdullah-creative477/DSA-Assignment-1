#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sys/stat.h>

#ifdef _WIN32
#include <direct.h>
#define MKDIR(path) _mkdir(path)
#else
#define MKDIR(path) mkdir(path, 0755)
#endif

int main() {
    int n, m, k, seed;
    std::string targetPath;

    // --- User Inputs ---
    std::cout << "=== Random Sample Generator ===" << std::endl;

    std::cout << "Enter number of elements per sample (n): ";
    std::cin >> n;

    std::cout << "Enter number of samples to generate (m): ";
    std::cin >> m;

    std::cout << "Enter maximum range value (k) [generates integers from 0 to k-1]: ";
    std::cin >> k;

    std::cout << "Enter random seed for repeatability: ";
    std::cin >> seed;

    std::cout << "Enter target directory path to save samples: ";
    std::cin >> targetPath;

    // --- Input Validation ---
    if (n <= 0 || m <= 0 || k <= 0) {
        std::cerr << "Error: n, m, and k must all be positive integers." << std::endl;
        return 1;
    }

    // --- Create target directory if it doesn't exist ---
    struct stat info;
    if (stat(targetPath.c_str(), &info) != 0) {
        if (MKDIR(targetPath.c_str()) != 0) {
            std::cerr << "Error: Could not create directory: " << targetPath << std::endl;
            return 1;
        }
        std::cout << "Created directory: " << targetPath << std::endl;
    }

    // --- Seed the random number generator ---
    srand(seed);

    // --- Generate samples ---
    for (int i = 1; i <= m; i++) {
        // Build file path: targetPath/sample_i.txt
        std::string filePath = targetPath + "/sample_" + std::to_string(i) + ".txt";

        std::ofstream outFile(filePath);
        if (!outFile.is_open()) {
            std::cerr << "Error: Could not open file for writing: " << filePath << std::endl;
            return 1;
        }

        // Write n random integers in range [0, k-1]
        for (int j = 0; j < n; j++) {
            int randomVal = rand() % k;
            outFile << randomVal;
            if (j < n - 1) {
                outFile << "\n";
            }
        }

        outFile.close();
        std::cout << "Generated: " << filePath << std::endl;
    }

    std::cout << "\nDone! " << m << " sample(s) saved to: " << targetPath << std::endl;
    return 0;
}
