# 🤖 Robot Coins: Maximizing Collection (Recursive, Memoized, & DP)

This project explores different algorithmic approaches—pure **Recursion**, **Memoization**, and **Dynamic Programming (DP)**—to solve the **Robot Coins Problem**.

The task is to find the **maximum number of coins** a robot can collect while traversing an $n \times m$ grid from the top-left cell **(1,1)** to the bottom-right cell **($n,m$)**. The robot is restricted to moving only **right** $\rightarrow$ or **down** $\downarrow$. Cells contain either a coin (`C`) or are empty (`.`).

---

## 🔑 Implementations

The repository provides three distinct solutions:

| Executable | Method | Path Output? | Description |
| :--- | :--- | :---: | :--- |
| `robotrec` | **Recursive** (Baseline) | No | A straightforward, potentially inefficient, recursive solution. |
| `robotmem` | **Memoization** | Yes | Recursive solution enhanced with an $n \times m$ memoization table. |
| `robotdp` | **Iterative DP** | Yes | An iterative DP solution, filling the table bottom-up. |

*The `robotmem` and `robotdp` executables not only compute the maximum coin count but also reconstruct and print a corresponding optimal **path**.*

---

## 🏗️ Build Instructions

The included `Makefile` allows for building all executables or a specific one.

### Build All

```bash
make

```

It appears you're asking for the nicely formatted text of the "Robot Coins" project summary to be wrapped in a single command block (likely for easy copying into a markdown editor or similar environment).

Here is the complete formatted text contained within a single markdown code block:

Markdown

# 🤖 Robot Coins: Maximizing Collection (Recursive, Memoized, & DP)

This project explores different algorithmic approaches—pure **Recursion**, **Memoization**, and **Dynamic Programming (DP)**—to solve the **Robot Coins Problem**.

The task is to find the **maximum number of coins** a robot can collect while traversing an $n \times m$ grid from the top-left cell **(1,1)** to the bottom-right cell **($n,m$)**. The robot is restricted to moving only **right** $\rightarrow$ or **down** $\downarrow$. Cells contain either a coin (`C`) or are empty (`.`).

---

## 🔑 Implementations

The repository provides three distinct solutions:

| Executable | Method | Path Output? | Description |
| :--- | :--- | :---: | :--- |
| `robotrec` | **Recursive** (Baseline) | No | A straightforward, potentially inefficient, recursive solution. |
| `robotmem` | **Memoization** | Yes | Recursive solution enhanced with an $n \times m$ memoization table. |
| `robotdp` | **Iterative DP** | Yes | An iterative DP solution, filling the table bottom-up. |

*The `robotmem` and `robotdp` executables not only compute the maximum coin count but also reconstruct and print a corresponding optimal **path**.*

---

## 🏗️ Build Instructions

The included `Makefile` allows for building all executables or a specific one.

### Build All

```bash
make
```
Build Specific Executables
```Bash

make robotrec
make robotmem
make robotdp
```

Artifacts
The build process generates the following executables:

```Bash

robotrec, robotmem, robotdp
```

```Clean
To remove generated binaries and object files:

Bash

make clean
```
▶️ Running the Programs
All programs read the grid input from standard input (stdin).

Input Format
First Line: n m (grid dimensions: n rows, m columns).

Next n Lines: m characters each (C for coin, . for empty).

Example Execution
Assuming an input file like data/grid7x8.txt:

```Bash

# Pure Recursive (Max coins only)
./robotrec < data/grid7x8.txt

# Memoized Recursion (Max coins + Path)
./robotmem < data/grid7x8.txt

# Iterative DP (Max coins + Path)
./robotdp < data/grid7x8.tx
```
Output Structure
The final output will always state the maximum count:

Maximum number of coins to pick up is : 13
For robotmem and robotdp, the path is printed first, detailing the coordinates and cumulative value:

The path is :
.(1,1)/0 ---> C(2,1)/1 ---> ... ---> .(n,m)/K --->
Picked up K coins
