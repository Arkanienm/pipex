*This project has been created as part of the 42 curriculum by amurtas*

# **Description**
Pipex is a project from school 42 that aims to reproduce in C the functioning of the "pipe" of a Unix shell. The goal is to create a program capable of redirecting data flows between files and commands, exactly as the terminal does.

# **Instructions**

* ### **Compilation :**

#### To compile the project you have to write the line below in a terminal :

```bash
make
```

* ### **Execution :**

#### This is how to exectue the project :

```bash
./pipex <infile> <command 1> <command 2> <outfile>
```

#### Here are some examples of commands to test the project :

```bash
./pipex Makefile cat cat outfile
```
```bash
./pipex Makefile "grep s" "wc -l" outfile
```

# **Resources**
I found several resources on the internet but the main ones are GeekforGeeks , gemini for the struct of the project and how pipes works , and some youtube tutorial for the function of a pipe and for the forks .