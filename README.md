# Smart Waste Collection and Segregation Simulator

A beginner-friendly, menu-driven C program that records waste from different locations, classifies it by type, and plans collection according to the quantity and category of waste.

Made for the Innovative Examination (IE) 2026-27, Group 2.

## Features

- Record waste by **location** (Market, Hostel, Hospital, Canteen), **type** and **quantity (kg)**
- Classify waste into 6 categories with a colour-coded bin for each
- **Segregation summary**: entries, total kg and percentage share of each type
- **Collection plan** for every location with a priority level
- Estimate the number of **truck trips** needed (truck capacity: 500 kg)
- Save all records to a text file
- Input validation: wrong location, type or quantity is rejected

## Waste Categories

| Code | Type      | Bin colour |
|------|-----------|------------|
| 1    | Organic   | Green      |
| 2    | Plastic   | Blue       |
| 3    | Paper     | White      |
| 4    | Metal     | Grey       |
| 5    | Glass     | Yellow     |
| 6    | Hazardous | Red        |

## Collection Priority Rules

| Condition                  | Priority                       |
|----------------------------|--------------------------------|
| Hazardous waste            | URGENT (special vehicle)       |
| 100 kg or more             | High (collect daily)           |
| 50 kg to less than 100 kg  | Medium (alternate days)        |
| Less than 50 kg            | Low (weekly)                   |

## C Concepts Used

Strings, arrays, structures, functions, nested loops, switch-case, if-else, counters and file handling.

## How to Run

You need a C compiler such as GCC.

```bash
gcc waste_simulator.c -o waste_simulator
./waste_simulator
```

On Windows, run `waste_simulator.exe` instead.

## Menu

```
1. Add record
2. Show records
3. Segregation summary
4. Collection plan
5. Save to file
6. Exit
```

## Sample Output (Collection Plan)

```
Location: Market
  Organic     180.0 kg  [Green bin]  Priority: High - collect daily
  Plastic      60.0 kg  [Blue bin]  Priority: Medium - alternate days
  Metal        20.0 kg  [Grey bin]  Priority: Low - weekly

Location: Hospital
  Hazardous    12.0 kg  [Red bin]  Priority: URGENT - special vehicle

Total 442.0 kg, trips needed = 1
```

## Project Structure

```
.
├── waste_simulator.c   # complete source code
└── README.md
```

## Future Scope

- Read quantities from real fill-level or weight sensors
- Route planning and multiple vehicles
- Date-wise reports and charts
- Graphical interface or database storage

## Team

Group 2 (Roll Nos. 12–22), Thakur College of Engineering and Technology

- [Member name]
- [Member name]

## License

Educational project. Free to use and modify.
