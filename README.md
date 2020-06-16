# Interpreter

Homework #4 and #5 for Compilers Design course. Given a [Context Free grammar](#context-free-grammar) program an Intepreter which implements a symbol table and a reduced syntax tree.

## Compile

```bash
make
```

## Execute

```bash
make one
make two
...
make eight
make custom
```

## Run and print manually

```bash
./interpreter tests/<file_name{0...8, custom}>.txt
```
If you wish to **print the syntax tree**, enter the next flag at the end of the previous instruction

```bash
--print-tree
```

## Context Free Grammar

![](cfg1.png)


![](cfg2.png)

## Clean folder

Many files are autogenerated by _flex_ and _bison_. To clean the root folder, type:

```bash
make clean
```