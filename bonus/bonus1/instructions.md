# Guru challenge 1: Bash Scripting for Stock Management

## Description

Develop a Bash script named stock.sh to manage a simple stock inventory in a
text file stock.txt, where each line is formatted as `item_name:quantity:price`
(e.g., `Samsung_S14:10:1.5`). The script must handle the following commands via
command-line arguments:

- `add <item_name> <quantity> <price>`: Add a new item or update an existing
  item by adding to its quantity if it exists.
- `remove <item_name> <quantity>`: Reduce the quantity of an item; remove the
  line if quantity becomes zero or negative.
- `list`: Display all items in a formatted output, including subtotals
  (quantity * price).
- `total`: Compute and print the total stock value (sum of quantity * price for
  all items).

## Requirements

The script must be well-written with clear structure and readability.
Implement separate Bash functions for add, remove, list, and total.
Perform all input validation (e.g., check for non-numeric quantity/price, missing arguments) before calling functions from the command-line argument parser.

## Hints

Use grep for searching items in stock.txt.
Use sed for in-place file modifications.
Use awk for calculations (e.g., subtotals, total) and formatting output.
Include error handling for invalid inputs, such as non-numeric values or incorrect argument counts.

## Assessment

Challenge assignments are pass/fail. There is slight tolerance for minor bugs,
but your solution must be overall excellent. The point of these assignments is
to push you.

You must write the code yourself, or use AI as an _assistant,_ not as your
personal developer agent to do the work for you. **To check this,** the
evaluation is a 10-minute interview with a TA.

1. You will first demonstrate that your program works, by going through the
   features.
2. The TA will look at your code and ask questions about it. If you're unsure
   how your program works, even if you wrote it yourself without the use of AI,
   you will not receive any credit.

There are only a limited number of time slots available for interviews with the
TA. These are first-come-first-served.

**To register for a time-slot,** you must first `git push` your completed work,
then use a link made available by the TA in #announcements. The code that you
`git push` is the code that will be assessed.

### Concrete assessment rubric

#### Script structure and modularity

Includes shebang (#!/bin/bash), separate functions for add, remove, list, and total, clear comments with student info, and logical flow using a central parser (e.g., case statement).


#### Input parsing and validation

Robust parser handles all arguments before
calling functions; validates numeric inputs, missing arguments, and float
prices; exits with clear error messages (e.g., "Invalid quantity").

#### Add

Correctly checks item existence with grep, updates quantity with **`sed`** (use
AI to learn about this tool and how the command you'll use with it works),
appends new items, ensures price consistency, avoids data loss.

#### Remove

Reduces quantity with sed, removes line if <=0, checks existence with grep, prevents negative quantities.

#### List

Use **`awk`** to produce a nicely formatted table, handles empty file gracefully.

#### Total

Computes total with awk, handles empty file (returns 0.00).

#### Overall quality and tool usage:

Efficient use of grep, sed, awk; handles edge cases (e.g., empty file, no matches); clean, readable code; no temporary files or security risks (e.g., avoids eval).
