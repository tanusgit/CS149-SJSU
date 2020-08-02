#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Print current date and time in C
int main(void)
{
	// variables to store date and time components
	int hours, minutes, seconds, day, month, year;

	// time_t is arithmetic time type
	time_t now;
	
	// Obtain current time
	// time() returns the current time of the system as a time_t value
	time(&now);

	// Convert to local time format and print to stdout
	printf("Today is : %s", ctime(&now));
}