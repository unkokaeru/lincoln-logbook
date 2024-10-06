**What did you learn in the lab tasks this week?**

In the lab session this week we focused on outputting to a data stream and handling special characters. In order to output to a data stream, I learned we use `cout` to declare console output and insert data into this with the insertion operator, `<<` - this differs from Python's `print` function, but is essentially how it works. This is because C++ is a lower level language, just above assembly code, and is thus more lightweight and efficient, e.g. you don't need input/output capabilities with all programs, as not all programs need a command-line interface, hence we include the line `#include <iostream>`to access these stream commands.

Additionally, we explored special characters (`\n`, `\a`, `\b`, `\f`, `\r`, and `\t`), escape sequences (`\\`, `\'`, `\"`, and `\?`), and the line terminator (`endl`). The special characters and escape sequences are similar to those used in Python, but the line terminator was completely new for me. Functionally, it seems to act the same as a newline character, but works by ending the data stream started by `cout`.

**How well did I learn it?**

I learned everything pretty quickly, making parallels with Python quite often. It's been really fun learning a completely new, more low-level language and deepening my understanding of programming in general. I did some extra work outside of my lab session, too, which definitely helped me reinforce any new knowledge and understand C++ even quicker.

**How does my solution compare with the official solution?**

There aren't any official solutions right now, so I'll write this next week if they get released.

**How can I extend the concepts used in the tasks to form a new project**

In my extra work this week, I've extended the concepts used to make Pascal's triangle by changing the logic to a more loop-based system so that I can use render any number of rows. I also tried an alternative to using the tab characters, `setd::setw`. Not only this, but I decided to take this number of rows as a user input with `std::cin` and validated the input, throwing an exception if invalid.

I also researched C++ best practices and styling guidelines, referencing documents like Google Style Guides and Doxygen. The main points are learned from this were: consistent comment style (I opted for /* and /**), function return rationale (i.e. when to use `void`), explicitly returning 0 in a main function (to tell the console it ran correctly), docstring placement (before a function, contrasting with Python), and function declaration (placing the opening curly bracket on the same line).

Finally, with the project I already explained, I explored functions, for loops, conditional statements, exception handling, and some basic libraries: `cmath`, `stdexcept`, and `iomanip`.

**Lesson Review Question Answers**

1. Facilitates complex simulations; differs by enabling exploration beyond physical limits.
2. Climate modeling, drug discovery, astrophysics simulations.
3. First computer-assisted proof; raises questions about proof validity.
4. Cost/feasibility issues; safety concerns.
5. From serial to parallel computing; enhances computational power for complex problems.
6. Serial: sequential processing; Parallel: simultaneous processing.
7. Physical limits in miniaturization; heat dissipation, quantum effects.
8. FLOPS: Floating Point Operations Per Second; measures computational performance.
9. Binary: two digits (0, 1); used for electronic circuitry efficiency.
10. Encapsulation, inheritance, polymorphism.

Multiple choice: BCCBCCBBBA