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
 */
void sleep(int time);

#endif
