# Asm Mini LibC

> Made by **Marlon PEGAHI** and **Alexandre BRET**

A minimal reimplementation of essential C standard library functions, written entirely in **x86-64 assembly**.
---

## Overview

`libasm.so` is a shared library that reimplements 15 functions from the standard C library at the assembly level, following the x86-64 System V AMD64 ABI. It can be injected into any dynamically-linked program via `LD_PRELOAD` to replace the system libc implementations.

---

## Implemented Functions

| Function | Description |
|---|---|
| `strlen` | Byte-by-byte null scan to compute string length |
| `strchr` / `index` | Find first occurrence of a character in a string |
| `strrchr` / `rindex` | Find last occurrence of a character in a string |
| `strcmp` | Lexicographic string comparison, returns byte difference |
| `strncmp` | Bounded string comparison |
| `strcasecmp` | Case-insensitive string comparison |
| `strstr` | Find first occurrence of a substring |
| `strpbrk` | Find first character from an accept set |
| `strcspn` | Count leading characters not in a reject set |
| `memset` | Fill a memory region with a byte value |
| `memcpy` | Copy non-overlapping memory regions |
| `memmove` | Copy memory with overlap handling |
| `memfrob` | XOR each byte with 42 (GNU extension) |
| `ffs` | Find first set bit, returns 1-indexed position |
| `strfry` | Stub (GNU extension, not implemented) |

---

## Requirements

- [NASM](https://nasm.us/) — Netwide Assembler
- `gcc` — for compiling tests
- [Criterion](https://github.com/Snaipe/Criterion) — unit test framework
- `python3` — for functional tests
- `ld` — GNU linker (part of `binutils`)

---

## Build

```bash
make        # Build libasm.so
make re     # Full rebuild
make clean  # Remove object files
make fclean # Remove all generated artifacts
```

---

## Testing

**Unit tests** (Criterion framework, with coverage):
```bash
make tests_run
```

**Functional tests** (injects the library via `LD_PRELOAD` and compares output against the system libc):
```bash
make fonctionnal_tests_run
```

**Debug with GDB** (builds a static `libasm.a` and a `gdb_exe` binary):
```bash
make gdb_test
gdb ./gdb_exe
```

---

## Usage

Once built, you can preload the library into any program:

```bash
LD_PRELOAD=./libasm.so ./your_program
```

---

## Architecture

Each function is implemented in its own `.asm` file following the **x86-64 System V AMD64 ABI**:

- **Arguments:** `rdi`, `rsi`, `rdx`, `rcx`, `r8`, `r9`
- **Return value:** `rax`
- **Callee-saved registers:** `rbx`, `rbp`, `r12`–`r15` (preserved when used)

All exported symbols are declared `global`. Functions that call other library functions (e.g. `strrchr` calling `strlen`) use PLT relocations: `call strlen wrt ..plt`.

---

## CI

GitHub Actions runs three jobs on every push and pull request:

1. **Compilation check** — verifies `libasm.so` builds successfully
2. **Unit tests** — runs the Criterion test suite
3. **Functional tests** — runs the Python `LD_PRELOAD` injection tests
