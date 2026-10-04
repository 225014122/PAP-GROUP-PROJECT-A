# MUNICIPAL FINANCIAL MANAGEMENT SYSTEM (MFMS)
**Group Project A**

## Group number 
15

---

## Project Description

The Municipal Financial Management System (MFMS) is a menu-driven C application developed for PAP521S – Programming in Practice. The system provides a foundation version of a municipal information system, allowing municipal staff to manage employee records, department budgets, suppliers, and municipal assets, and to generate basic reports across all four areas.

---

## System Features
- **Employee Management** — add, display, search employees, and calculate salaries
  (basic salary + housing + transport allowance).
- **Budget Management** — capture departmental budgets and expenditure, calculate
  remaining budget, and flag departments that have exceeded their allocation.
- **Supplier Management** — add, display, and search registered suppliers.
- **Asset Management** — add, display, and search municipal assets, with data
  persisted to `assets.txt` between sessions.
- **Reports** — generate summary reports across employees, budgets, suppliers,
  and assets.
- **Input Validation** — rejects negative salaries/budgets, empty names, and
  invalid menu selections throughout the system.

---

## 👥 Group Members & Credentials
| Name | Student Number | Assigned Module |
| :--- | :--- | :--- |
| **Komesho Rosalia** | 225065843 | `budget.c` / `budget.h` |
| **Florida Mbiki** | 225061562 | `assets.c` / `assets.h` |
| **Amunyela Johannes** | 224014129 | `employees.c` / `employees.h` |
| **Saara Ndakeva** | 224017888 | `suppliers.c` / `suppliers.h` |
| **Ashel Simubali** |225113481  | `reports.c` / `reports.h` |
| **Da-olva Nangombe** | 225144840 | `main.c` / System Integration |
| **Ashanti Ngweda** | 225014122 | testing / Git coordination |



---

## 🛠️ Compilation & Execution Instructions

To compile the modular system locally using GCC C99:

```bash
gcc -Wall -Wextra -std=c99 main.c budget.c assets.c employees.c suppliers.c reports.c -o mfms_system

## ▶️ How to Run 
1. Compile the system using the command above.
2. Run the compiled program:
     -Windows: .\mfms_system.exe
     -macOS/Linux: ./mfms_system
3. Use the on-screen menu (options 1–6) to navigate between modules.
4. Select option 6 at any time to exit the system.

# Part 7: System Testing & Quality Assurance

## 7.1 Testing Methodology
To ensure system stability, modular integrity, and reliable user interactions, a comprehensive multi-tier testing approach was conducted on the **Municipal Financial Management System (MFMS)**. Testing was executed locally using the GCC C99 compiler within Visual Studio Code.

1. **Compilation & Linkage Testing:** Verification that all source files compile cleanly without missing headers or linkage errors.
2. **Functional Menu & Routing Testing:** Verification that top-level menu selections execute their corresponding module routines.
3. **Input Validation & Exception Handling:** Testing system behavior against unexpected user entries (e.g., non-numeric input, out-of-bounds options) to prevent crashes.

---

## 7.2 Test Execution Results Matrix

| Test ID | Testing Target | Input / Test Action | Expected Result | Actual Result | Pass/Fail |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **TC-01** | Multi-file Build Integrity | `gcc -Wall -Wextra -std=c99 main.c budget.c assets.c employees.c suppliers.c reports.c -o mfms_system` | Clean compilation with zero build errors or broken links | Binaries compiled successfully (`mfms_system.exe` generated) | **PASS** |
| **TC-02** | Execution & Startup | `.\mfms_system.exe` | Main menu renders cleanly with options 1–6 | Main system menu printed cleanly | **PASS** |
| **TC-03** | Menu Navigation Routing | Select Option `1` | Navigates to `--- EMPLOYEE MANAGEMENT ---` sub-menu | Employee Management module loaded correctly | **PASS** |
| **TC-04** | Invalid Input Guard | Enter non-numeric string (`abc`) at menu prompt | System catches non-integer input, clears buffer, and reprompts | Buffer cleared smoothly without crash or infinite loop | **PASS** |
| **TC-05** | Out-of-Bounds Choice Guard | Enter invalid option number (`99` or `-1`) | Displays error message and re-prompts for valid entry | Error flagged gracefully; user prompted to enter option 1–6 | **PASS** |
| **TC-06** | System Termination | Select Option `6` (Exit) | Displays termination message and exits cleanly to terminal | Printed `Exiting system...` and returned cleanly to prompt | **PASS** |

---

## 7.3 Testing Conclusion
The modular architecture successfully satisfies all functional requirements for Group Project A. All 5 core functional modules (`budget`, `assets`, `employees`, `suppliers`, `reports`) integrate seamlessly through `main.c`, demonstrating clean input parsing, robust stack management, and stable cross-module execution.
