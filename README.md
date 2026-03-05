# Cybersecurity & Automation Scripts

A collection of PowerShell, Bash, and C scripts demonstrating automation, system administration, and security-focused programming. These projects were developed during my Cybersecurity Diploma at NSCC and through self-directed learning.

## Repository Structure

### PowerShell Scripts
| Script | Description | Skills Demonstrated |
|--------|-------------|---------------------|
| `loadfromcsv.ps1` | Bulk imports 50+ users into Active Directory from a CSV file, sets default passwords, and adds users to security groups | AD administration, CSV parsing, error handling, automation |
| `list_large_files.ps1` | Recursively scans directories and lists all files larger than 50KB | File system traversal, arrays, conditional logic |

### Bash Scripts
| Script | Description | Skills Demonstrated |
|--------|-------------|---------------------|
| `guessing-game.sh` | Interactive number guessing game with random number generation, attempt limits, and replay option | Loops, user input, random generation, input validation |
| `evenodd.sh` | Classifies command-line arguments as even or odd numbers, with input validation and formatted output | Arrays, functions, arithmetic evaluation, argument handling |

### C Programming
| Script | Description | Skills Demonstrated |
|--------|-------------|---------------------|
| `filebasedcalculator.c` | Reads arithmetic expressions from a text file, parses them left-to-right, and writes results to an output file | File I/O, string tokenization, pointer manipulation, low-level programming |

## Getting Started

### Prerequisites
- **PowerShell scripts**: Windows with Active Directory module (for AD script) or any Windows system (for file scanner)
- **Bash scripts**: Linux/macOS or WSL on Windows
- **C program**: GCC compiler (`gcc filebasedcalculator.c -o calculator`)

### Usage Examples

#### Active Directory Bulk User Creation
```powershell
# Prepare a CSV file with columns: username, first name, last name, id number
# Then run:
.\loadfromcsv.ps1
File Scanner
powershell
# Run in any directory to scan for files >50KB
.\list_large_files.ps1
Bash Scripts
bash
# Make scripts executable first
chmod +x guessing-game.sh evenodd.sh

# Run guessing game
./guessing-game.sh

# Run even/odd classifier with numbers
./evenodd.sh 1 2 3 4 5 6
C Calculator
bash
# Compile
gcc filebasedcalculator.c -o calculator

# Create a math.txt file with expressions like:
# 5 + 3
# 10 - 2 * 4

# Run
./calculator
🛡️ Security Notes
The AD script uses a default password (Passw0rd!!) – change this for production use

All scripts are for educational purposes and should be tested in isolated environments first

Review any script before running it with administrative privileges

📚 Learning Outcomes
These scripts demonstrate proficiency in:

PowerShell: Active Directory automation, file system operations, array handling

Bash: User interaction, control flow, functions, command-line argument processing

C: Memory management, file I/O, string parsing, pointer arithmetic

General: Problem-solving, documentation, error handling, code organization

🔗 Connect With Me
Portfolio: https://x-alted.ca

LinkedIn: https://linkedin.com/in/ajtmacintyre

Email: altimaeus@proton.me
