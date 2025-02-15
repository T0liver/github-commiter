# GitHub Commiter written in C
A code which can be run with cron job and commit to github every day.

Now implemented in C language.

## Compiling

I'm releasing one version for 64 bits Windows but you can compile it anyways with this following command:

```
gcc include\funcs.h src\main.c src\funcs.c -o commiter.exe
```

## Help

I want to make more, platform specific releases but can't make *mingw* to work and - first of all - compile 32 bit version.

This should work with this flag: `-m32` but no.

Just won't work, and I can't find the requied libraries online :c

If anyone can help me pls drop a message [oliver@toliver.hu](mailto:oliver@toliver.hu)

Thank youu!
