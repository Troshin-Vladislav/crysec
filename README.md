CRYSEC
======

Program create for encrypt information
Security information


VERSION 8.0
-----------

+ auto generation key
+ option --string
+ support OS Window

INSTALL:
--------

**Linux:**

install by Makefile

	$ make

**Windows:**

	> g++ main.cpp -o crysec

You can compil and run application by IDE (CodeBlocks, Visual Studio, ...)


SYNTAX:
-------

	$ crysec -i <file> -m <method> -k <key> (-E|-D) [options...]


EXAMPLES:
---------

Encrypt information by method Caesar with shift 1
Encrypt contain in file login.txt

	$ crysec -i login.txt -m caesar --encrypt -k 1 -o login.txt.enc

create files:
- login.txt.enc - encrypt info
- login.txt.enc.key - key for decrypt info

Decrypt information by method caesar with shift 1

	$ crysec -i login.txt.enc -m caesar -k login.txt.enc.key --decrypt

More examples in test directory


OPTIONS:
--------

**-i, --in:*

Specified in file

**-o, --out:**

Specified out file

**-m, --method:**

Set method ecrypt

**-g, --genkey:**

Auto-generation key for select method

**-k, --key:**

Set key, search file with specified string and use contain as key for encrypt

**-s, --string:**

Specify string as argument

**-H, --hide:**

Turn off output console

**-E, --encrypt:**

Encrypt mode

**-D, --decrypt:**

Decrypt mode

**-d, --debug:**

Debug mode

**-v, --version:**

Show version program, last updates and exit

**-h, --help:**

Show help page and exit
