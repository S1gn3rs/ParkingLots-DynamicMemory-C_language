# Parking Management System

🅿️🚘🎫 Parking Management System using dynamic memory 🎫🚘🅿️

## Introduction

This project is a Parking Management System created for the Introduction
to Algorithms and Data Structures subject. The system is designed to manage
parking lots, allowing for the definition of parking lots, registration of
vehicle entries and exits, querying and billing operations.


## Features

- **Parking Lot Management**: Create and remove parking lots with specific billing regimes.
- **Vehicle Entry and Exit**: Register entries and exits of vehicles in parking lots.
- **Billing**: Calculate billing based on time spent in the parking lot with specific rates.
- **Queries**: List entries and exits of vehicles, show billing details, and total income.
- **Error Handling**: Comprehensive input validation and error reporting.
- **Dynamic Memory Usage**: Utilizes dynamic memory for efficient data management.


## Commands

The system interacts through a series of commands:

- `q`: Terminate the program.
- `p`: Create a parking lot or list existing ones.
- `e`: Register a vehicle's entry.
- `s`: Register a vehicle's exit.
- `v`: List the entries and exits of a vehicle.
- `f`: Show the billing of a parking lot.
- `r`: Remove a parking lot from the system.
- `t`: Show the total income of a parking lot.


## Command Formats and Errors

- **Terminate Program**
  - Input: `q`
  - Output: None

- **Create or List Parking Lots**
  - Input: `p [ <parking-lot-name> <capacity> <rate-15-min-1st-hour> <rate-15-min-after-1st-hour> <max-daily-rate> ]`
  - Output: If no arguments are provided, lists all parking lots.
  - Errors:
    - `parking already exists`: If the parking lot name already exists.
    - `invalid capacity`: If the capacity is less than or equal to 0.
    - `invalid cost`: If any of the rates are less than or equal to 0 or not in increasing order.
    - `too many parks`: If the maximum number of parking lots (20) is reached.

- **Register Vehicle Entry**
  - Input: `e <parking-lot-name> <license-plate> <date> <time>`
  - Output: `<parking-lot-name> <available-spaces>`
  - Errors:
    - `no such parking`: If the parking lot does not exist.
    - `parking is full`: If the parking lot is full.
    - `invalid licence plate`: If the license plate format is invalid.
    - `invalid vehicle entry`: If the vehicle is already in a parking lot.
    - `invalid date`: If the date or time is invalid or earlier than the last recorded entry or exit.

- **Register Vehicle Exit**
  - Input: `s <parking-lot-name> <license-plate> <date> <time>`
  - Output: `<license-plate> <entry-date> <entry-time> <exit-date> <exit-time> <amount-paid>`
  - Errors:
    - `no such parking`: If the parking lot does not exist.
    - `invalid licence plate`: If the license plate format is invalid.
    - `invalid vehicle exit`: If the vehicle is not in the specified parking lot.
    - `invalid date`: If the date or time is invalid or earlier than the last recorded entry or exit.

- **List Vehicle Entries and Exits**
  - Input: `v <license-plate>`
  - Output: `<parking-lot-name> <entry-date> <entry-time> <exit-date> <exit-time>`
  - Errors:
    - `invalid licence plate`: If the license plate format is invalid.
    - `no entries found in any parking`: If the vehicle has no recorded entries.

- **Show Parking Lot Billing**
  - Input: `f <parking-lot-name> [ <date> ]`
  - Output: `<date> <billed-amount>` or `<license-plate> <exit-time> <amount-paid>`
  - Errors:
    - `no such parking`: If the parking lot does not exist.
    - `invalid date`: If the date is invalid or later than the last recorded entry or exit.

- **Remove Parking Lot**
  - Input: `r <parking-lot-name>`
  - Output: `<parking-lot-name>`
  - Errors:
    - `no such parking`: If the parking lot does not exist.

- **Show Total Income of a Parking Lot**
  - Input: `t <parking-lot-name>`
  - Output: `<total-income>`
  - Errors:
    - `no such parking`: If the parking lot does not exist.


## Compilation and Execution

To compile the project, use the following command:
```sh
gcc -Wall -Wextra -Werror -Wno-unused-result -o proj *.c
```

The compiler should not produce any errors or warnings.
It is recommended to use version 7 or higher of the compiler (check with **gcc --version**).
The automated evaluation system uses gcc version 12.3.

To execute the program, use the command:
```sh
./proj < input.txt > output.txt
```

You can compare the output with the expected result using the **diff** command:
```sh
diff output.txt expectedOutput.txt
```

**Note**: Ensure all .c and .h files are in the root directory of the repository.


## Example Usage

Create a parking lot:
```sh
p Saldanha 200 0.20 0.30 12.00
```

Register a vehicle entry:
```sh
e Saldanha AA-00-AA 01-03-2024 08:34
```

Register a vehicle exit:
```sh
s Saldanha AA-00-AA 01-03-2024 10:59
```

List vehicle entries and exits:
```sh
v AA-00-AA
```

Show billing:
```sh
f Saldanha 01-03-2024
```

Show total income:
```sh
t Saldanha
```

Remove a parking lot:
```sh
r "CC Colombo"
```

enjoy ;)
