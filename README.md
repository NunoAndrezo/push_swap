```markdown
# 🔀 push_swap – 42 Lisboa

> Sorting integers on a stack with a minimal set of operations — using a “Turkish” chunking algorithm for optimal performance.

---

## 🧠 Project Overview

**push_swap** is a sorting algorithm challenge: given a list of integers, sort them in ascending order using two stacks (`A` and `B`) and a limited set of operations. The goal is to minimize the total number of operations.

This implementation uses a **Turkish chunking algorithm**, dividing the input into dynamic chunks based on quantiles to efficiently push and rotate elements between stacks.

---

## 🎯 Objectives & Requirements

- Read a list of integers (with no duplicates) from command-line arguments.
- Use only the following operations:
  - `sa`, `sb`, `ss` — swap top two elements of `A`, `B`, or both.
  - `pa`, `pb` — push top element from `B` to `A`, or `A` to `B`.
  - `ra`, `rb`, `rr` — rotate stack up.
  - `rra`, `rrb`, `rrr` — rotate stack down.
- Sort stack `A` in ascending order; `B` must be empty at the end.
- Print each operation on its own line.
- Optimize to use as few operations as possible.

---

## ⚙️ Installation & Setup

### Requirements

- **GCC** or **clang** compiler (C99 compliant)
- **Make**

### Build

1. Clone your repo:
   ```bash
   git clone https://github.com/NunoAndrezo/push_swap.git
   cd push_swap
   ```
2. Build with:
   ```bash
   make
   ```
   Targets:
   - `all` (default): builds `push_swap` and `checker`
   - `clean`: removes object files
   - `fclean`: removes object files and executables
   - `re`: `fclean` + `all`

---

## 🏃‍♂️ Usage

### push_swap

```bash
./push_swap <list of integers>
```

**Example:**

```bash
./push_swap 3 2 5 1 4
```

*Output* (example sequence):

```
pb
pb
sa
pa
pa
ra
ra
```

### checker

A helper program to verify that your operations sort correctly:

```bash
./checker <list of integers>
```
Then input your operations one per line, ending with `EOF`.  
Or pipe operations:

```bash
./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4
```

*Expected output:*

```
OK
```

---

## 🧩 Turkish Chunking Algorithm

1. **Preprocessing**  
   - Copy and sort the input array to calculate quantiles.
   - Determine **N** chunks dynamically:  
     - `chunk_size = total_elements / sqrt(total_elements)`  
     - Adjust chunk count so each chunk ≈ `sqrt(N)` elements.

2. **Phase 1 – Push to B by Chunks**  
   - For each chunk (from smallest to largest):  
     - Scan stack `A`, pushing elements belonging to the current chunk into `B` using `pb`.  
     - Use `ra`/`rra` to bring target elements to top with minimal rotations (choose direction by distance to top/bottom).

3. **Phase 2 – Sort B & Push Back to A**  
   - While `B` not empty:  
     - Find the current maximum in `B`.  
     - Rotate `B` (`rb`/`rrb`) to bring that max to top.  
     - `pa` it back to `A`.  
     - Optionally perform `ra` on `A` if next element belongs later.

4. **Final Cleanup**  
   - After all elements are in `A`, perform final `ra`/`rra` to align smallest element at top (optional, depends on comparator).

**Benefits of Turkish Algo:**  
- Balances number of pushes and rotations.  
- Dynamic chunk sizing adapts to varying `N`.  
- Empirically yields low operation counts for N up to 500.

---

## 🧪 Testing & Performance

- **Small lists (≤ 5):** hardcoded minimal solutions (3–12 operations).  
- **Medium lists (≤ 100):** chunk count ≈ 5–7.  
- **Large lists (≤ 500):** chunk count ≈ 10–20.  
- Use `./push_swap | wc -l` to count operations and compare against reference thresholds:
  - ≤ 700 ops for 100 numbers.
  - ≤ 5500 ops for 500 numbers.

**Valgrind** check:

```bash
valgrind --leak-check=full ./push_swap 3 2 5 1 4
```

---

## 🛠️ Project Structure

```
push_swap/
├── src/
│   ├── main.c
│   ├── parse.c
│   ├── ops.c
│   ├── algo_chunk.c
│   ├── utils.c
│   └── checker.c
├── includes/
│   └── push_swap.h
├── Makefile
└── README.md
```

---

## 📚 Resources & References

- 📘 [42 push_swap Subject PDF](https://cdn.intra.42.fr/pdf/push_swap.pdf)  
- 🔄 [Stack Sorting Techniques](https://www.chrisstinson.com/stack-sort/)  
- 📊 [Algorithm Chunking Strategies](https://arxiv.org/abs/algorithm-chunking)  
- 🔍 [Norminette Rules](https://github.com/42School/norminette)

---

## 👤 Author

**Nuno Andrezo**  
42 Lisboa Student  
🔗 GitHub: [@NunoAndrezo](https://github.com/NunoAndrezo)

---
```
```
::contentReference[oaicite:0]{index=0}
