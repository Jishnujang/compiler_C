# MiniC — A Compiler Built from Scratch

> **Learning how compilers work by building one from the ground up.**

MiniC is a small educational compiler written in **C**, developed from scratch to understand what happens between writing source code and executing machine code.

The goal of this project is not to create another programming language, but to **build and understand the fundamental components of a real compiler** — from lexical analysis and parsing to intermediate representation and eventually machine-code generation.

---

## 🧠 Compiler Pipeline

MiniC is being developed as a complete compilation pipeline:

```text
                 MiniC Source
                      │
                      ▼
              ┌───────────────┐
              │ Source Reader │
              └───────┬───────┘
                      │
                      ▼
              ┌───────────────┐
              │    Lexer      │
              │   Tokens      │
              └───────┬───────┘
                      │
                      ▼
              ┌───────────────┐
              │    Parser     │
              └───────┬───────┘
                      │
                      ▼
              ┌───────────────┐
              │      AST      │
              │ Syntax Tree   │
              └───────┬───────┘
                      │
                      ▼
              ┌───────────────┐
              │   Semantic    │
              │   Analysis    │
              └───────┬───────┘
                      │
                      ▼
              ┌───────────────┐
              │      IR       │
              │ Intermediate  │
              │ Representation│
              └───────┬───────┘
                      │
                      ▼
              ┌───────────────┐
              │ Optimization  │
              └───────┬───────┘
                      │
                      ▼
              ┌───────────────┐
              │ Code Generator│
              └───────┬───────┘
                      │
                      ▼
                Assembly (.s)
                      │
                      ▼
                  Assembler
                      │
                      ▼
                Object (.o)
                      │
                      ▼
                   Linker
                      │
                      ▼
                 Executable
```

The compiler is being implemented **stage by stage**, with each stage tested before moving to the next.

---

# 🚀 Current Progress

| Stage | Component                   | Status     |
| ----- | --------------------------- | ---------- |
| 1     | Source Reading              | ✅          |
| 2     | Lexer                       | ✅          |
| 3     | Tokenization                | ✅          |
| 4     | Parser                      | ✅          |
| 5     | AST                         | ✅          |
| 6     | Semantic Analysis           | ✅          |
| 7     | Intermediate Representation | ✅          |
| 8     | Optimization                | 🔄 Planned |
| 9     | Code Generation             | 🔄 Planned |
| 10    | Assembly Generation         | 🔄 Planned |
| 11    | Assembler                   | 🔄 Planned |
| 12    | Linker                      | 🔄 Planned |
| 13    | Executable                  | 🔄 Planned |

> The project is intentionally being developed incrementally so each compiler stage can be understood rather than hidden behind existing compiler infrastructure.

---

# 🧪 Current MiniC Language

The current language is intentionally tiny.

Example:

```c
give 53;
```

This statement means:

> Generate a program that returns the value `53`.

The current grammar is:

```text
statement
    → GIVE NUMBER SEMICOLON
```

For example:

```text
give 53;
```

is processed approximately as:

```text
Source
  │
  ▼
"give 53;"
  │
  ▼
Tokens
  │
  ├── GIVE
  ├── NUMBER(53)
  └── SEMICOLON
  │
  ▼
AST

       GIVE
         │
         ▼
      NUMBER
         53
  │
  ▼
Semantic Analysis
  │
  ▼
IR

IR_GIVE 53
```

---

# 🔍 Example

Build the compiler:

```bash
gcc src/main.c \
    src/lexer.c \
    src/parser.c \
    src/ast.c \
    src/semantic.c \
    src/ir.c \
    -o minic
```

Run it:

```bash
./minic examples/hello.ml
```

Input:

```text
give 53;
```

Output:

```text
Parsing successful

AST:
GIVE
  NUMBER: 53

Semantic Analysis:
Semantic analysis successful

IR:
IR_GIVE 53
```

---

# 🧩 Project Structure

```text
compiler_C/
│
├── src/
│   ├── main.c
│   │
│   ├── lexer.c
│   ├── lexer.h
│   │
│   ├── parser.c
│   ├── parser.h
│   │
│   ├── ast.c
│   ├── ast.h
│   │
│   ├── semantic.c
│   ├── semantic.h
│   │
│   ├── ir.c
│   └── ir.h
│
├── examples/
│   └── hello.ml
│
├── build/
│
└── .gitignore
```

---

# 🛠️ Technologies

* **C**
* **Linux / WSL2**
* **GCC**
* **GNU Assembler**
* **Git**
* **GitHub**
* **ELF / x86-64**
* Compiler construction concepts

---

# 🎯 Why Build a Compiler?

As an embedded systems engineer, I wanted to go deeper than simply writing application code.

A compiler connects many areas of computer engineering:

```text
C Programming
      │
      ├── Memory
      ├── Data Structures
      ├── Parsing
      ├── Computer Architecture
      ├── Assembly
      ├── Machine Code
      ├── ELF
      ├── Linker
      └── Operating System
              │
              ▼
           Compiler
```

Building MiniC is a way to understand what actually happens underneath the code we normally write.

For example:

```c
return 42;
```

eventually becomes machine instructions represented by bytes such as:

```text
B8 2A 00 00 00
C3
```

MiniC aims to make that entire journey visible.

---

# 🗺️ Roadmap

### Phase 1 — Front End

* [x] Source reading
* [x] Lexer
* [x] Token system
* [x] Parser
* [x] AST
* [x] Semantic analysis

### Phase 2 — Intermediate Representation

* [x] Basic IR
* [ ] Multiple IR instructions
* [ ] Variables
* [ ] Expressions
* [ ] Control flow

### Phase 3 — Optimization

* [ ] Constant folding
* [ ] Dead code elimination
* [ ] Basic optimization passes

### Phase 4 — Back End

* [ ] x86-64 code generation
* [ ] Assembly generation
* [ ] Register handling
* [ ] Function generation

### Phase 5 — Binary Generation

* [ ] Assembly
* [ ] Object files
* [ ] ELF understanding
* [ ] Linking
* [ ] Executable generation

### Phase 6 — Language Expansion

Eventually MiniC will support features such as:

```c
int main()
{
    int a = 10;
    int b = 20;

    return a + b;
}
```

and gradually grow into a much more capable C-like language.

---

# 📚 Learning Philosophy

This project follows one simple rule:

> **Don't just use the compiler. Build one.**

Instead of immediately depending on an existing compiler framework, MiniC is being developed component by component.

Each stage should answer a fundamental question:

| Question                                         | Component          |
| ------------------------------------------------ | ------------------ |
| What characters are in the source?               | Lexer              |
| What do those characters mean?                   | Tokens             |
| Is the program grammatically valid?              | Parser             |
| What is the structure of the program?            | AST                |
| Does the program make semantic sense?            | Semantic Analysis  |
| How can the program be represented internally?   | IR                 |
| Can the program be improved?                     | Optimization       |
| How can the program become machine instructions? | Code Generation    |
| How does machine code become a binary?           | Assembler + Linker |

---

# 🔬 Development Approach

MiniC is developed incrementally.

Each major compiler stage is:

1. Implemented
2. Compiled
3. Tested
4. Verified
5. Committed to Git

This makes the repository a visible record of the compiler's evolution.

---

# ⭐ Project Goal

The final goal is not simply:

```text
MiniC → executable
```

The real goal is to understand:

```text
Source Code
     ↓
Characters
     ↓
Tokens
     ↓
Syntax
     ↓
AST
     ↓
Semantics
     ↓
IR
     ↓
Optimization
     ↓
Machine Instructions
     ↓
Object File
     ↓
ELF Executable
```

**One compiler stage at a time.**

---

## 👨‍💻 Author

**Jishnu E**

Embedded Systems Engineer

This project is part of my journey into **compiler construction, systems programming, computer architecture, and low-level software engineering**.

---

## ⭐ Follow the Journey

If you find this project interesting, consider ⭐ starring the repository.

The compiler will continue evolving from a tiny language into a progressively more complete compiler.

**Built from scratch. One stage at a time.**
