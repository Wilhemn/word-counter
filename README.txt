Project 0: Counting Words
====================

The purpose of this assignment is to help you create, debug and extend C
programs that run within a shell environment and utilize basic I/O and string
manipulation functions.

The scenario:  your well-intentioned-but-inexperienced pair-programming buddy
has just written some code for the first assignment.  Unfortunately, they
dropped the course/were abducted by aliens, and it is now up to you to pick up
where they left off.

The accompanying program files (Makefile and main.c) contain examples of good
and bad programming practices and includes deliberate errors.  Your job is to
find and fix the errors, implement missing features, and learn some tricks of
the trade in the process.

Luckily, a test program is included to help you along.  You can (and should) use
it to check your work.  See the Self-Evaluation section for details.

There are four parts to this project.


Part One:  Crash Course in C
----------------------------

Read the file review.txt.  The list of topics it contains is useful for
self-assessment and as a study guide.

Answer the questions in A-Pointers.txt.  Try to identify the key to each problem
and keep your answers concise and to the point; 2-3 sentences should suffice.
These questions bring up important points about pointer usage in C. Keep these
in mind when working on the remainder of the project.
NOTE: The answers to these questions are due way before the due date of the Enhancements


Part Two:  Fixing the Bugs
--------------------------

The purpose of the provided program is to count words specified as command-line
arguments.  Read the description of the program and its functionality in the
comment at the top of main.c.  Now read through the rest of main.c and the
Makefile and understand what each part does.

Finally, compile and run the program from the shell:
> make
(ignore the compiler warning for now)
> ./main

The program compiles and links... so it must work!  But is it really
doing what it is supposed to do?

Answer the questions in B-Debugging.txt and fix the corresponding bugs
in main.c.  Again, try to keep your answers brief and focused.
NOTE: The answers to these questions are due way before the due date of the Enhancements


Part Three:  Enhancements
-------------------------

Now that the bugs have been ironed out, it's time to add some
functionality to our word counting program.  Follow the instructions in
C-Enhancements.txt to complete the word counter.
HINT: The Enhancements can be easier if you work on Part Four a bit

Part Four: Debugging
------------------------

Debugging in the terminal can be overwhelming at first, but practice makes perfect.
C programs use gdb to debug applications and see the data flowing through the program;
I have included a cheatsheet for gdb in D-GDB.txt so you can have a reference on what 
can be done in the debugger. 

Try to debug your program and see the flow of control and data within the running program.


Self-Evaluation
---------------

The testrunner program is included so that you can check your progress
as you implement different parts of the project.

To run all tests:
> make test

To run a specific test, e.g., stderr_output:
> ./main -test stderr_output

As you can see, testrunner is implemented entirely in C.  If you found
this project too easy, or are just plain curious, feel free to look at the
implementation and see if you can figure out how everything works.  The
relevant files are: smp0_test.* and testrunner.*.

Note: You should remove or disable any additional debugging output you may have
created before running the tests.  One way to do this easily is through the use
of the preprocessor directive #ifdef:

#ifdef DEBUG
fprintf(stderr, "My string %s %d\n", var1, var2);
#endif

Then add -DDEBUG to the CCOPTS line in the Makefile during development, and
remove it before testing.  Make sure that your code still compiles and runs
without the debug output!

Submission
--------------

1. Include your name (and your partner's if any) on top of your main.c file, and 
comment any modifications made by you throughout the file.
2. Submit a picture in Blackboard of your program running in our class server 
the command `make test` I must be able to see your username in the server 
(the username has 2 letters then 3 numbers, e.g. abc123)
Not all tests need to pass to recieve credit, but the program must compile 
to get some credit. If you do not submit a picture the project will not be graded.
3. Commit all changes made to the project to GitHub, this will trigger the CI tests
in the repo and confirm the program compiles. (The check mark in GitHub will always
be green unless the program does not compile, check the details to see the tests result)