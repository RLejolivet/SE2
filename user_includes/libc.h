#ifndef MINI_LIBC_HEADER
#define MINI_LIBC_HEADER

/* Format is a string that will be printed
 * and may contain the following sequences to insert values :
 * - %s for a string
 * - %d for an int
 * - %x for an int printed in hex form 
 * Additional arguments must be the ones referred to in format
 * Return value is 0 or the opposite of an error code
 */
int printf(const char* format, ...);

/*
 * Format is the same as printf above
 * Additional arguments are pointers to result buffers
 * Return value is the number of read arguments
 */
int scanf(const char* format, ...);

/*
 * Pauses the program's excecution for at least 'time' seconds
 * Exact time isn't really known since commuting may not give the processor back
 * as soon as the sleeping time is over
 */
void sleep(int time);

/*
 * Read waits for keyboard interrupt(s), reads the typed character(s)
 * and writes them into the buffer pointed to by result.
 * It will read at most 'max' or 1024 characters (whichever is lower)
 * The return value is the number of characters read
 * The actual number of characters written in the buffer is one higher (due to '\0' added)
 */
int read(char* result, int max);

/*
 * Write writes the character 'input' on the vga screen,
 * in the parameter of the current active process.
 */
int write(char input);

#endif
