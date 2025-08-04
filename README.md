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

```bash
git clone https://github.com/NunoAndrezo/push_swap.git
cd push_swap
make
```

Makefile targets:  
- `all` (default): builds `push_swap` and `checker`  
- `clean`: removes object files  
- `fclean`: removes objects and executables  
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

Possible output sequence:

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

Verify your sequence sorts correctly:

```bash
./checker <list of integers>
```

Then input operations one per line (end with EOF), or pipe:

```bash
./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4
```

Expected output:

```
OK
```

---

## 🧩 Turkish Chunking Algorithm

1. **Preprocessing**  
   - Copy and sort the input to calculate quantile thresholds.  
   - Determine `chunk_size ≈ total_elements / √total_elements`.

2. **Phase 1 – Push to B**  
   - For each chunk (smallest to largest):  
     - Scan `A` and `pb` elements in the current chunk.  
     - Use `ra`/`rra` to minimize rotations.

3. **Phase 2 – Retrieve from B**  
   - While `B` not empty:  
     - Find max in `B`.  
     - Rotate (`rb`/`rrb`) to top, then `pa` to `A`.  
     - Optionally `ra` to maintain order.

4. **Final Alignment**  
   - Rotate `A` so the smallest element is at the top.

Benefits: balances pushes and rotations, adapts to N, yields low op counts.

---

## 🧪 Testing & Performance

- **Small (≤ 5):** hardcoded minimal sequences.  
- **Medium (≤ 100):** ~5–7 chunks.  
- **Large (≤ 500):** ~10–20 chunks.

Count operations:

```bash
./push_swap ... | wc -l
```

Goals:  
- ≤ 700 ops for 100 numbers  
- ≤ 5500 ops for 500 numbers

Memory check:

```bash
valgrind --leak-check=full ./push_swap 3 2 5 1 4
```

---

## 🛠️ Project Structure

```text
push_swap/
├── include/
├── printf/
├── push_swap_42/
├── src/
├── LICENSE
├── Makefile
└── README.md
```

---

## 📚 Resources & References

- [42 push_swap Subject PDF](https://cdn.intra.42.fr/pdf/push_swap.pdf)  
- [Stack Sorting Techniques](https://www.chrisstinson.com/stack-sort/)  
- [Norminette Rules](https://github.com/42School/norminette)
## 👤 Author

**Nuno Andrezo**  
42 Lisboa Student  
🔗 GitHub: [@NunoAndrezo](https://github.com/NunoAndrezo)
