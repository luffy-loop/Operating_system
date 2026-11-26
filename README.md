# Operating Systems & Computer Networks Labs

A collection of hands-on **Operating Systems** and **Computer Networks** coursework, including C programs for Linux/POSIX concepts, a milestone-based mini shell (**ShellForge**), and Cisco Packet Tracer lab files.

## Repository contents

| Area | Contents |
| --- | --- |
| [Operating Systems labs](Operating_System/lab/) | Individual C exercises covering process creation, file system calls, IPC, memory, and signals |
| [Weekly OS labwork](Operating_System/labwork/) | Week-by-week C practice programs, and supporting text files |
| [OS class programs](Operating_System/class_programs/) | Classroom examples of pipes, shared memory, semaphores, and file operations |
| [ShellForge project](Operating_System/OS_Project/) | Five stages of a Unix-like command-line shell written in C |
| [Computer Networks Lab 01](Computer_Networks/Lab/Lab_01/) | Cisco Packet Tracer `.pkt` activity and screenshots |

## Operating Systems

### Concepts practiced

- **Process management:** `fork()`, `exec()` / `execvp()`, `wait()`, `waitpid()`, PIDs, exit status, and zombie processes
- **Inter-process communication:** anonymous pipes, named pipes (FIFOs), and shared memory
- **Synchronization:** POSIX semaphores
- **File operations:** `open()`, `read()`, `write()`, and related system calls
- **Memory management:** dynamic allocation, memory segments, `mmap()`, and memory-error demonstrations
- **Signals and error handling:** `SIGCHLD` and system-call error checks

Explore the [lab exercises](Operating_System/lab/), [weekly labwork](Operating_System/labwork/), and [classroom programs](Operating_System/class_programs/). Each C file is a separate example unless its source indicates otherwise.

### ShellForge — mini Unix-like shell

[ShellForge](Operating_System/OS_Project/) develops an interactive shell in five stages:

| Week | Feature | Source |
| --- | --- | --- |
| 1 | Read–eval–print loop and exit handling | [`week1_repl.c`](Operating_System/OS_Project/src/week1_repl.c) |
| 2 | Tokenize command-line arguments | [`week2_tokenizer.c`](Operating_System/OS_Project/src/week2_tokenizer.c) |
| 3 | Organize parsed commands into a structure | [`week3_organizer.c`](Operating_System/OS_Project/src/week3_organizer.c) |
| 4 | Run external commands with `fork()`, `execvp()`, and `waitpid()` | [`week4_process.c`](Operating_System/OS_Project/src/week4_process.c) |
| 5 | Add the built-in `cd` command with `chdir()` | [`week5_navigation.c`](Operating_System/OS_Project/src/week5_navigation.c) |

The project folder also contains output screenshots (`week1.png`–`week5.png`), a `Makefile`, and a more detailed [project README](Operating_System/OS_Project/README.md).

## Computer Networks

### Cisco Packet Tracer — Lab 01

The first networking lab includes:

- [`lab1.pkt`](Computer_Networks/Lab/Lab_01/lab1.pkt) — open this topology/activity file in **Cisco Packet Tracer**.
- [`output_ss/`](Computer_Networks/Lab/Lab_01/output_ss/) — screenshots captured from the lab.

The `.pkt` file is a Packet Tracer project, **not** a C program. Open it in a compatible version of Cisco Packet Tracer to inspect the topology and configuration. The repository does not currently include a written lab procedure or verified connectivity results.

## Getting started

### Requirements

- **Linux / Ubuntu / WSL** for the POSIX-based C exercises
- **GCC** for compiling the C programs; **make** for the ShellForge Makefile
- **Cisco Packet Tracer** for the networking lab

### Clone the repository

```bash
git clone https://github.com/luffy-loop/Operating_system.git
cd Operating_system
```

### Compile and run an OS lab program

For example:

```bash
gcc -Wall -Wextra Operating_System/lab/process_exit_status_week4.c -o process_exit_status
./process_exit_status
```

Some programs read or write files, create IPC resources, or require multiple terminals. Review the source code and its relative file paths before running it.

### Run the latest ShellForge milestone

```bash
cd Operating_System/OS_Project
make
./shellforge
```

Try commands such as `pwd`, `ls`, `cd ..`, and `exit` inside the shell.

Use `make milestones` to build all five standalone versions into `build/`, or `make clean` to remove generated outputs.

### Open the networking lab

Open `Computer_Networks/Lab/Lab_01/lab1.pkt` in Cisco Packet Tracer and refer to the screenshots in the adjacent `output_ss` directory.

## Repository layout

```text
.
├── Computer_Networks/
│   └── Lab/
│       └── Lab_01/
│           ├── lab1.pkt
│           └── output_ss/
├── Operating_System/
│   ├── OS_Project/
│   │   ├── src/
│   │   ├── include/
│   │   ├── docs/
│   │   ├── tests/
│   │   ├── Makefile
│   │   └── README.md
│   ├── class_programs/
│   ├── lab/
│   └── labwork/
└── README.md
```

## Notes

This is a **learning and coursework repository**, not a production-ready shell or networking toolkit. Programs are intended to illustrate OS concepts and may not include automated tests or production-level input validation. Generated lab executables are ignored; compile the retained C sources locally.

---

Maintained by [luffy-loop](https://github.com/luffy-loop).