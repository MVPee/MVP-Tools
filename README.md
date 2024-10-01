<h1 align="center">
	🌟 MVP-Tools
</h1>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/MVPee/MVP-Tools?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/MVPee/MVP-Tools?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/MVPee/MVP-Tools?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/MVPee/MVP-Tools?color=green" />
</p>

<h3 align="center">
	<a href="#-about">About</a>
	<span> · </span>
	<a href="#-running">Running</a>
  <span> · </span>
	<a href="#-features">Features</a>
</h3>


# 💡 About
>This project aims to create a powerful binary tool to automate various tasks.

You can create cannonical class in cpp for the moments.
Lots of tools is comming soon...

## 🚀 Running 

❗ You need to install Homebrew on macOS if you don't have the necessary permissions.
```bash
git clone git@github.com:MVPee/MVP-Tools.git; ./start.sh
```
It will automatically compile the project and place the binary in the appropriate /bin directory.
```bash
make; mv MVP /usr/bin
```
You can now launch the program using the following command:
```
MVP [OPTION/CMD]
```

## 💻 Features

**OPTIONS**  

| Option           | Description                           |
|------------------|---------------------------------------|
| `-h`, `--help`   | Show all available commands           |
| `-v`, `--version`| Show the version of the application   |

**CMDS**  

| Command          | Description                                                      |
|------------------|------------------------------------------------------------------|
| `c`, `cannonical`| Create a canonical class. You can also add your class name directly after the `c` command (e.g., `MVP c file1 file2...`) |



