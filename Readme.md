# 🎲 Random Sample Generator

A lightweight C++ command-line tool that generates reproducible random integer samples and saves them to a file. Useful for testing algorithms, benchmarking, simulation, and data science workflows.

---

## Features

- Generate any number of samples with any number of elements each
- Configurable integer range `[0, k-1]`
- Seeded RNG for fully reproducible output
- Saves results to a user-specified file with a metadata header
- Uses `std::mt19937` (Mersenne Twister) for high-quality randomness

---

## Requirements

- C++17 or later
- A C++ compiler: `g++`, `clang++`, or MSVC

---

## Build

```bash
g++ -o random_sample_generator random_sample_generator.cpp -std=c++17
```

---

## Usage

Run the compiled binary and follow the prompts:

```bash
./random_sample_generator
```

You will be asked to enter:

| Parameter | Description |
|-----------|-------------|
| `n` | Number of elements per sample |
| `m` | Number of samples to generate |
| `k` | Range upper bound — integers are drawn from `[0, k-1]` |
| `seed` | Random seed for reproducibility |
| `target path` | File path to save the output (e.g. `output.txt`) |

---

## Example

```
=== Random Sample Generator ===
Enter n (number of elements per sample): 5
Enter m (number of samples to generate): 3
Enter k (max range value, integers from 0 to k-1): 100
Enter seed (for reproducibility): 42
Enter target file path (e.g. output.txt): output.txt

Done! 3 sample(s) of 5 element(s) each (range [0, 99]) written to 'output.txt'.
```

**output.txt:**
```
# Random Sample Generator Output
# n=5 m=3 k=100 seed=42
# Format: Sample <index> | <n space-separated integers in [0, k-1]>

Sample 1: 37 79 95 18 73
Sample 2: 77 59 59 15 44
Sample 3: 15 9 5 45 86
```

---

## Output Format

- Lines starting with `#` are metadata/comments
- Each data line follows the format: `Sample <index>: <n space-separated integers>`
- The same seed always produces the same output, regardless of platform (using `std::mt19937`)

---

## Input Validation

The program will exit with an error message if:
- `n`, `m`, or `k` are zero or negative
- The target file path cannot be opened for writing

---

## Project Structure

```
.
├── random_sample_generator.cpp   # Main source file
└── README.md
```

---

## License

This project is released under the [MIT License](LICENSE).
