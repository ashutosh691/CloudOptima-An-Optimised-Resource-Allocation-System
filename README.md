# ☁️ CloudOptima – Cloud Resource Allocation System

## 📌 Overview

CloudOptima is a GUI-based application built using **Qt (C++)** that simulates a cloud resource allocation system. It allows users to define tasks with CPU, RAM, and Profit values, and optimally allocates resources using the **0/1 Knapsack Algorithm (Dynamic Programming)**.

The system helps in selecting the most profitable set of tasks under given resource constraints.

---

## 🎯 Objectives

* Simulate a real-world cloud resource allocation system
* Apply **DAA concepts (0/1 Knapsack with multiple constraints)**
* Provide a **visual and interactive GUI**
* Display optimal task selection with resource usage

---

## 🛠️ Technologies Used

* **Language:** C++
* **Framework:** Qt (Qt Widgets)
* **Concepts:** Data Structures & Algorithms (Dynamic Programming)
* **IDE:** Qt Creator

---

## 🚀 Features

### ✅ Phase 1 – GUI Development

* Add Task Dialog (Task ID, CPU, RAM, Profit)
* Task Table View
* Buttons: Add Task, Run Allocation, Reset

### ✅ Phase 2 – Allocation Engine

* Multi-dimensional **0/1 Knapsack (CPU + RAM)**
* Optimal task selection
* Backtracking to identify selected tasks
* Highlight selected tasks in UI
* Display:

  * Total CPU Used
  * Total RAM Used
  * Maximum Profit

### 🔜 Phase 3 – Final Enhancements

* Cloud Plan Selection (Basic / Standard / Premium)
* Dynamic resource allocation based on selected plan
* Improved UI layout and branding

---

## 🧠 Algorithm Used

### 0/1 Knapsack (2 Constraints)

We use **Dynamic Programming** to maximize profit under CPU and RAM limits.

State definition:

```
dp[i][c][r]
```

Where:

* `i` = number of tasks considered
* `c` = CPU capacity
* `r` = RAM capacity

Transition:

```
dp[i][c][r] = max(
    dp[i-1][c][r],
    profit[i] + dp[i-1][c - cpu[i]][r - ram[i]]
)
```

Backtracking is used to determine which tasks were selected.

---

## 🖥️ How It Works

1. User adds tasks using the dialog
2. Tasks appear in the table
3. User selects a cloud plan (Phase 3)
4. Click **Run Allocation**
5. System:

   * Runs DP algorithm
   * Selects optimal tasks
   * Highlights them
   * Displays resource usage and profit

---

## 📊 Example

| Task ID | CPU | RAM | Profit |
| ------- | --- | --- | ------ |
| 1       | 2   | 4   | 10     |
| 2       | 3   | 6   | 15     |
| 3       | 1   | 2   | 5      |

For a given capacity, the system selects the most profitable subset.

---

## 📂 Project Structure

```
CloudOptima/
│
├── main.cpp
├── mainwindow.cpp / .h / .ui
├── addtaskdialog.cpp / .h / .ui
├── CMakeLists.txt
└── README.md
```

---

## 🧪 How to Run

1. Open project in **Qt Creator**
2. Configure kit (Qt 6.x recommended)
3. Build and Run
4. Use GUI to add tasks and run allocation

---

## 🎓 Learning Outcomes

* Understanding of **0/1 Knapsack with multiple constraints**
* Integration of **algorithms with GUI**
* Practical implementation of **resource allocation problems**
* Experience with **Qt framework**

---

## 📌 Future Scope

* Add Greedy algorithm comparison
* Graphical performance analysis
* Real-time resource monitoring
* Integration with cloud APIs

---

## 📜 License

This project is for academic purposes.

---
