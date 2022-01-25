# TaskManager

A small, header-only library whose sole purpose is to spawn threads
that run predefined void-returning methods at a certain time in the future.
In other words, you can create a void foo() and set it to run 5 minutes 
in the future, and repeat every 10 minutes after first execution. To exchange
data between these "Tasks" (as they are defined), it is recommended to use
concurrent-safe shared memory.

# Usage

Simply include the two header files under task_manager to use them.