**Yardmaster - "Assemble, load, dispatch-one node at a time."**

**Backstory**

You've joined Granite Ridge Freight Cooperative as the new systems engineer. Your job is to build **YardMaster**, a console tool that models a freight train being assembled in a rail yard. Each railroad car is a node in a singly linked list (<https://www.geeksforgeeks.org/dsa/linked-list-data-structure/>). Dispatch wants to add/remove cars, update cargo, and get quick summaries - under pressure and with zero room for crashes.

**Learning Goals**

- Implement and manipulate a **singly linked list** (insert by index, delete by index, traversal, search).
- Practice **dynamic memory management** and **robust input handling** in C.
- Design a **small, testable CLI** system with clear success/error messages.
- Implement **case-insensitive string handling** and safe integer validation.

**Model**

- Represent the train as a **singly linked list** of Car nodes.
- Each Car has:
  - id (auto-incrementing integer)
  - label (string)
  - **one** cargo record: `good_name` (string, may be empty meaning "no cargo yet") and `quantity`
    (non-negative int).
  - pointer to the next attached car.
- **Case-insensitive** equality for good_name (e.g., "WHEAT", "Wheat", "wheat" are the same).
- If a car has no cargo, treat it as **empty**.

**Train operations**

- **Append** a car to the end
  - **Input:** `append "Hopper-A"`
  - **Success:** `OK: added car id=CAR_ID label=Hopper-A at index=INDEX`
    (Your program will generate and fill in the `CAR_ID` and `INDEX`).
  - **Failure:** label already exists.
- **Insert** a car at a specified position. A car can be inserted in the middle of the train as well.
  - **Input:** insert 1 "Reefer-12"
  - **Success:** `OK: added car id=CAR_ID label=Reefer-12 at index=5`
  - **Failure (index > length or negative or label already exists):**
    `ERROR: invalid index INDEX`
- **Delete** a car at a specified position
  - **Input:** `delete 1`
  - **Success:** `OK: deleted car id=CAR_ID label=LABEL from index=1`
  - **Failure (out of range):** `ERROR: invalid index INDEX`
- **Print the current train**
  - A car is labelled as empty if no cargo is assigned to it.
  - **Input**: print
  - **Success**:
    - `Train length=3`
    - `id=0 label=Hopper-A cargo=empty`
    - `id=1 label=Boxcar-42 cargo=Wheat qty=30`
    - `id=2 label=Reefer-12 cargo=Apples qty=100`
    - `id=3 label=Erfete-14 cargo=Grapes qty=0`
  - **Train is empty:**
    - `Train length=0`
    - `(empty)`
- **Search for good_name across the train.**
  - Case-insensitive match on `good_name`.
  - Show each car that has it and a total.
  - **Input:** search "Wheat"
  - **Success:**
    - `search "Wheat"`
    - `id=0, label=Boxcar-42, qty=30`
    - `id=3, label=Hopper-B, qty=10`
    - `TOTAL Wheat = 40`
 - If good_name not found say `"NOT FOUND: Wheat"`

**Goods Operations (per-car single cargo)**

Each car can hold **one** good_name and quantity. Adding a different good **replaces the existing good** unless you use the "increase" verb for the same name.
- **Add or increase a named good in a chosen car**
  - If the car is empty: set good_name and quantity.
  - If the car already has the **same** good_name (case-insensitive): increase quantity.
  - If the car has a **different** good_name: by default **replace** it (quantity becomes the provided amount).
  - **Input:** goods add 1 "Wheat" 25  
  - **Success:** OK: car id=CAR_ID label=LABEL cargo=Wheat qty=NEW_QTY  
  - **Failure (bad index / name mismatch / negative qty):**
    - ERROR: invalid index 2
    - ERROR: car has different cargo "Wheat"
    - ERROR: quantity must be >= 0
- **Set (replace) a named good in a chosen car**
    - Replaces any existing good_name with the new name and sets quantity.
    - **Input:** goods set 1 "Apples" 100  
    - **Success:** OK: car id=CAR_ID label=LABEL cargo=Apples qty=100  
    - **Failure:** ERROR: invalid index 1 or ERROR: quantity must be >= 0
- **Decrease or remove a named good in a chosen car**
  - Decrease by amount; if quantity would drop below 0 display an error message.
  - If quantity becomes **0**, cargo becomes **empty** (good_name=NULL or empty string, quantity=0).
  - **Input:** goods remove 2 "Apples" 40  
  - **Success:**
    - If remaining > 0: OK: car id=CAR_ID label=LABEL cargo=Apples qty=NEW_QTY
    - If becomes 0: OK: car id=CAR_ID label=LABEL cargo=empty
  - **Failure (bad index / name mismatch / negative qty / would go below 0):**
    - ERROR: invalid index 2
    - ERROR: car has different cargo "Wheat"
    - ERROR: quantity must be >= 0
    - ERROR: removal exceeds current quantity 35.

**Command Line Interface**
  - Provide a **looped, text-based** interface that accepts a command per line.
  - Support **quoted strings with spaces** for labels/goods: "Reefer 12-East", "Rolled Oats".
  - Invalid inputs **must not crash** the program. Print specific error messages and continue the loop.
  - Provide help and exit commands.

**Edge Cases (must handle gracefully)**
  - Adding goods to an **empty** car (create cargo).
  - **Case-insensitive** matching for goods everywhere.
  - Reject **negative indices/quantities**.
  - Do not allow quantities to **fall below zero**.
  - Inserting at **exactly length** is allowed (append equivalently).
  - Deleting from an **empty list** or out-of-range index → helpful error.

**Constraints**
  - **Language:** C99/C11; no external libraries beyond the C standard library.
  - **Data structure:** **one** singly linked list for the entire program (the train). No secondary linked lists or dynamic containers for goods.
  - **Cargo rule:** **one good per car** (name + quantity).
  - **Style:** readable code, consistent naming, comments for major design choices and invariants.

**Deliverables**

- **Source files**
  - yardmaster.c (main + CLI loop).
  - train.c / train.h (list ops: create/destroy, length, append/insert/delete, get by index).
  - cargo.c / cargo.h (helpers: case-insensitive compare/normalize, set/add/remove cargo, validate quantities).
  - Makefile which generates the executable.
- **README.md**
  - Design decisions (how case-insensitive matching is done).
  - Data structures and invariants (e.g., quantity >= 0, empty cargo representation).
- **Test script**
  - tests.txt with a sequence of commands covering all required features + edge cases.  
        (can be piped: ./yardmaster < tests.txt)
  - Include cases: invalid index, negative qty, replace cargo, remove to zero, search miss/hit, summary on empty list.

**What we're looking for:**

- **Data structures & memory**
  - Correct singly linked list implementation
  - No leaks; correct frees on deletion; safe string allocation/copy
- **Core operations**
  - Append/insert/delete cars by index
  - goods set/add/remove/list
  - search by good (case-insensitive), summary aggregation
- **Robustness**
  - Input validation and error messages
  - Case-insensitive name handling
  - Reject negative indices/quantities; prevent underflow
- **CLI & usability**
  - Clear prompts/help
  - Quoted strings supported
  - Stable under malformed inputs
- **Code quality & docs**
  - File organization, comments, invariants documented
  - README clarity
  - Test coverage of edge case
