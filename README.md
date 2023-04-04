<h1 align="center">
	⏤ get_next_line
</h1>
<p align="center">
	<b><i>Reading a line from a fd is way too tedious</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/linhtng/Get_next_line?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/linhtng/Get_next_line?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/linhtng/Get_next_line?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/linhtng/Get_next_line?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/linhtng/Get_next_line?color=green" />
</p>
<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 💡 About the project
This project is about programming a function that returns a line read from a file descriptor.
  You will understand how files are opened, read and closed in an OS,
	and how they are interpreted by a programming language for further analysis.
	This task is crucial to understand for a future programmer since much of the time is based
	on manipulating files for data management and persistence.

For more detailed information, look at the [gnl.subject.pdf](https://github.com/linhtng/Get_next_line/files/10086482/gnl.subject.pdf)

## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Using it in your code**

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```

and, when compiling your code, add the source files and the required flag:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

## 📋 Testing
* [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)
