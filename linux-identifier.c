#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ANSI_RED_COLOR "\033[1;31m"
#define ANSI_GREEN_COLOR "\033[1;32m"
#define ANSI_MAGENTA_COLOR "\033[1;35m"
#define ANSI_BLUE_COLOR "\033[34m"
#define ANSI_CYAN_COLOR "\033[1;36m"

/*
#define BLACK_TEXT(x) "\033[30;1m" x "\033[0m"
#define RED_TEXT(x) "\033[31;1m" x "\033[0m"
#define GREEN_TEXT(x) "\033[32;1m" x "\033[0m"
#define YELLOW_TEXT(x) "\033[33;1m" x "\033[0m"
#define BLUE_TEXT(x) "\033[34;1m" x "\033[0m"
#define MAGENTA_TEXT(x) "\033[35;1m" x "\033[0m"
#define CYAN_TEXT(x) "\033[36;1m" x "\033[0m"
#define WHITE_TEXT(x) "\033[37;1m" x "\033[0m"
*/
#define ANSI_RESET_COLOR "\033[0m"


int pacManagers(){
	const unsigned int a = 6;
	const char *packageManagers[a] = {"/usr/bin/apt-get",
									  "/usr/bin/snap",
									  "/usr/bin/dpkg",
									  "/usr/bin/pacman",
									  "/usr/bin/yum",
									  "/usr/bin/flatpak"};

	for ( unsigned int i = 0; i < (a); i++)
	{		
		printf("Checking for %s .... ", packageManagers[i]);
		if (access(packageManagers[i], X_OK) != -1 )
			printf( ANSI_GREEN_COLOR "[OK]\n" ANSI_RESET_COLOR );
		else
			printf( ANSI_RED_COLOR "[NOT FOUND]\n" ANSI_RESET_COLOR );
	}

	return 0;
}

int defs()
{
	printf("%c%c", 10, 10);

	system("echo 'Logged On User  : ' " ANSI_BLUE_COLOR "\"${USER}\"" ANSI_RESET_COLOR );
	system("echo 'Home Directory  : ' " ANSI_BLUE_COLOR "\"${HOME}\"" ANSI_RESET_COLOR );
	system("printf 'Hostname        :  '" ANSI_BLUE_COLOR " ; echo \"$(<'/etc/hostname')\"" ANSI_RESET_COLOR );
	system("echo 'Default Browser : ' " ANSI_BLUE_COLOR "\"${BROWSER}\"" ANSI_RESET_COLOR );
	system("echo 'Default Editor  : ' " ANSI_BLUE_COLOR "\"${EDITOR}\"" ANSI_RESET_COLOR );

	return 0;
}

int OSD()
{
	printf("%c%c", 10, 10);

	system("printf 'Operating System    : ' ; cat /etc/os-release | grep '^NAME=' | sed -ne 's/NAME=//p'");
	system("printf 'Bassid On [ID_LIKE] : ' ; cat /etc/os-release | grep '^ID_LIKE=' | sed -ne 's/ID_LIKE=//p'");
	printf("%c", 10, 10);

	return 0;
}

int recommended_packages()
{
	printf("");

	return 0;
}

int main(int argc, char *argv[])
{
	char a[] = {9, 83, 101, 97, 114, 99, 104, 105, 110, 103, 32, 70, 111, 114, 32, 80, 97, 99, 107, 97, 103, 101, 32, 77, 97, 110, 97, 103, 101, 114, 115, 10, 10};
	for ( unsigned int i = 0; i < sizeof(a); i++ )
		printf( ANSI_MAGENTA_COLOR "%c" ANSI_RESET_COLOR , a[i]);
	pacManagers();

	char b[] = {10, 9, 83, 101, 97, 114, 99, 104, 105, 110, 103, 32, 70, 111, 114, 32, 85, 115, 101, 102, 117, 108, 32, 86, 97, 114, 105, 97, 98, 108, 101, 115};
	for (unsigned int i = 0; i < sizeof(b); i++)
		printf( ANSI_MAGENTA_COLOR "%c" ANSI_RESET_COLOR , b[i]);
	defs();

	char c[] = {10, 9, 83, 101, 97, 114, 99, 104, 105, 110, 103, 32, 70, 111, 114, 32, 79, 112, 101, 114, 97, 116, 105, 110, 103, 32, 83, 121, 115, 116, 101, 109, 32, 68, 101, 116, 97, 105, 108, 115 };
	for ( unsigned int i = 0; i < sizeof(c); i++)
		printf( ANSI_MAGENTA_COLOR "%c" ANSI_RESET_COLOR , c[i]);
	OSD();

	/*
	char d[] = {9, 83, 101, 97, 114, 99, 104, 105, 110, 103, 32, 70, 111, 114, 32, 82, 101, 99, 111, 109, 109, 101, 110, 100, 101, 100, 32, 80, 97, 99, 107, 97, 103, 101, 115, 10, 10};
	for (unsigned int i = 0; i < sizeof(d); i++)
		printf( ANSI_MAGENTA_COLOR "%c" ANSI_RESET_COLOR , d[i]);
	recommended_packages();
	*/

	return 0;
}
