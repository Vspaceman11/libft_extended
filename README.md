# 🧰 libft_extended

`libft_extended` is a personal C library that consolidates three foundational subprojects developed for learning purposes:

- 🧱 **libft** — Custom implementations of standard C library functions (memory, strings, lists, etc.)
- 🖨️ **ft_printf** — A simplified version of the standard `printf`.
- 📄 **get_next_line** — Function to read from a file descriptor line by line.

> ⚠️ This repository is for educational and integration use only. It respects all applicable rules and does **not** contain evaluation solutions.

## ✅ Project Scores

| Project         | Score     |
|----------------|-----------|
| libft          | 125/100   |
| ft_printf      | 125/100   |
| get_next_line  | 100/100   |

---

## 📦 Features

- Low-level memory and string handling
- Linked list utilities
- Minimal `printf` implementation with common format specifiers
- Buffered line-by-line reading with support for multiple file descriptors

---

## 📁 Project Structure
```
libft_extended/
├── inc/ # Header files
├── src/ # Source code
├── Makefile # Compilation rules
├── .gitignore # Ignored files (e.g. *.o, .DS_Store)
└── README.md # Project description
```
---

## ⚙️ Build Instructions

To build the library:

```bash
make
```

To clean object files:
```bash
make clean
```
To remove everything including the binary:
```bash
make clean
```
To remove everything including the binary:
```bash
make fclean
```
To force rebuild:
```bash
make re
```

🧪 Example Usage
```c
#include "libft_extended.h"

int main(void)
{
    char *line;
    int fd = open("file.txt", O_RDONLY);

    while ((line = get_next_line(fd)))
    {
        ft_printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
📄 License & Disclaimer
This project is provided for personal, non-commercial use and educational integration.
It does not contain or distribute official school content or solutions.
Respect the rules of your learning institution when using this code.
