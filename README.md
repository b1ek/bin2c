# bin2c
A program that converts any file(binary and text) into C code. The code is printed to the terminal.

Its written in plain C99, so i think any compiler should compile it.

By the way, the executable file contains its own source code inside it. Just open it in any text editor, scroll a bit down, and voila, here it is.

```c
char* file[SIZE]="\x4b\xf\0......\xff\xa5";
```

The executable contains its own source code built into it, just open it with any text editor, scroll down a little bit and you will see it.

## Difference between bin2c and bin2c.v2
The first version consumes A LOT of file size. Second one is way better optimized, and you should use the second one.
