# 🧰 libft_extended

`libft_extended` is a personal C library that consolidates three essential subprojects developed for learning purposes:

- 🧱 [`libft`](https://github.com/Vspaceman11/libft_42) — Custom implementations of standard C library functions.
- 🖨️ `ft_printf` — A simplified version of the standard `printf`.
- 📄 `get_next_line` — Line-by-line input reading from file descriptors.

This repository is intended for personal use and educational integration.

---

## 📦 Features

- Memory & string handling (`memcpy`, `strlcpy`, `strchr`, etc.)
- Custom `printf` with basic format specifiers: `%c`, `%s`, `%d`, `%x`, `%p`, etc.
- Buffered file reading with support for multiple file descriptors.

---

## 📁 Project Structure

libft_extended/
├── inc/ # Header files
├── src/ # Source code
├── Makefile # Compilation instructions
├── .gitignore # Ignored files (e.g. *.o, .DS_Store)
└── README.md # Project overview

yaml
Copy
Edit

---

## ⚙️ Build & Usage

Build the library:

```bash
make
Clean object files:

bash
Copy
Edit
make clean
Full clean including library:

bash
Copy
Edit
make fclean
Rebuild everything:

bash
Copy
Edit
make re
Include libft_extended.a in your own projects by linking the compiled static library and including the headers from inc/.

⚠️ Disclaimer
This repository contains personal implementations created for educational purposes.
It does not include any official solutions or content intended to bypass evaluation policies of any institution such as 42 Network.
Use it responsibly and in accordance with your school's rules.

📝 License
This project is open for personal and non-commercial use.
No warranty or guarantee of correctness is provided.
