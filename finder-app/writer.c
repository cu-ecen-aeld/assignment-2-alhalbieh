#include <stdio.h>
#include <string.h>
#include <syslog.h>
int main (int argc, char* argv[])
{
	openlog("logger", LOG_PID, LOG_USER);

	if (argc != 3)
	{
		syslog(LOG_ERR, "Arguments passed count are not correct. Expected 2 but passed %d", argc);
		return 1;
	}

	char writefile[1024];
	char writestr[1024];
	strcpy(writefile, argv[1]);
	strcpy(writestr, argv[2]);

	FILE *fptr;
	fptr = fopen(writefile, "w");
	if ( fptr == NULL )
	{
		syslog(LOG_ERR, "The %s was not opened", writefile);
		return 1;
	}
	syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);
	fprintf(fptr, "%s", writestr);
	fclose(fptr);

	fptr = fopen(writefile, "r");
	char buffer[1024];
    	while (fgets(buffer, sizeof buffer, fptr)) {
		//buffer[strcspn(buffer, "\n")] = 0;
        	if (strcmp(buffer, writestr)) {
			syslog(LOG_ERR, "Expected value: %s, actual value: %s", buffer, writestr);
			syslog(LOG_ERR, "Failed to write %s to %s\n", writestr, writefile);
			return 1;
		}
    	}
	return 0;
}




