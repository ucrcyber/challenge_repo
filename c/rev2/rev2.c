#include <time.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

#define MSG1 " =================================================================================="
#define MSG2 "|    /$$$$$$$$                           /$$                           /$$            "
#define MSG3 "|   | $$_____/                          | $$                          | $$            "
#define MSG4 "|   | $$    /$$$$$$   /$$$$$$$  /$$$$$$ | $$$$$$$   /$$$$$$   /$$$$$$ | $$   /$$      "
#define MSG5 "|   | $$$$$|____  $$ /$$_____/ /$$__  $$| $$__  $$ /$$__  $$ /$$__  $$| $$  /$$/      "
#define MSG6 "|   | $$__/ /$$$$$$$| $$      | $$$$$$$$| $$  \\ $$| $$  \\ $$| $$  \\ $$| $$$$$$/       "
#define MSG7 "|   | $$   /$$__  $$| $$      | $$_____/| $$  | $$| $$  | $$| $$  | $$| $$_  $$       "
#define MSG8 "|   | $$  |  $$$$$$$|  $$$$$$$|  $$$$$$$| $$$$$$$/|  $$$$$$/|  $$$$$$/| $$ \\  $$      "
#define MSG9 "|   |__/   \\_______/ \\_______/ \\_______/|_______/  \\______/  \\______/ |__/  \\__/      "
#define MSG10 "|                                                                                    "
#define MSG11 "|                                                                                   "
#define MSG12 "|                                                                                   "
#define MSG13 "|                          /$$$$$$  /$$$$$$$$ /$$$$$$$$                             "
#define MSG14 "|                         /$$__  $$|__  $$__/| $$_____/                             "
#define MSG15 "|                        | $$  \\__/   | $$   | $$                                   "
#define MSG16 "|                        | $$         | $$   | $$$$$                                "
#define MSG17 "|                        | $$         | $$   | $$__/                                "
#define MSG18 "|                        | $$    $$   | $$   | $$                                   "
#define MSG19 "|                        |  $$$$$$/   | $$   | $$                                   "
#define MSG20 "|                         \\______/    |__/   |__/                                   "
#define MSG21 "  ================================================================================="

#define LINE_LEN 80
#define HEADER "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s"
#define HEADER_LEN 1024

#define TRUE 1
#define FALSE 0

#define FLAG_LEN 62

#define PAUSE 150000

#define showstuff(x...) fprintf(stdout,x)

#define preparestuff(x...) do { \
    showstuff(x); \
    exit(0); \
  } while (0)

int this_is_what_you_are_looking_for[FLAG_LEN] =
{
    70, 76, 65, 71, 123, 85, 67, 82, 95, 82, 69, 86, 49, 50, 51, 51, 50, 49, 33, 125 
};

int N = 0;
int n = 1;

char flag[FLAG_LEN];

static void banner(void)
{
        showstuff("%s\n", MSG1); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG2); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG3); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG4); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG5); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG6); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG7); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG8); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG9); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG10); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG11); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG12); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG13); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG14); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG15); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG16); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG17); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG18); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG19); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG20); usleep(PAUSE*n*N);
        showstuff("%s\n", MSG21); usleep(PAUSE*n*N);
}

static void letsgo(void)
{
        banner(); fflush(NULL);

        usleep(PAUSE*N);
        showstuff("|\n"); usleep(PAUSE*N);
        showstuff("|\n"); usleep(PAUSE*N);

        fflush(NULL);

        showstuff("|  >  ");
        fflush(NULL);
        showstuff("What you are looking for is in my memory...\n"); usleep(PAUSE*3*N);
        fflush(NULL);

        fflush(NULL);
}

static last_tip(void)
{
        showstuff("|\n"); usleep(PAUSE*N);
        showstuff("|\n"); usleep(PAUSE*N);

        fflush(NULL);

        showstuff("|  >  "); usleep(PAUSE*n*N);
        fflush(NULL);
        showstuff("The only thing you need is to find it! :)\n"); usleep(PAUSE*3*N);
}

static void author(void)
{
    printf("Level written by Javier (@javutin)\n");
}

static void generate_flag()
{
        int i, x=0;

        for (i=0; i<FLAG_LEN; i++)
        {
                flag[i] = (char)this_is_what_you_are_looking_for[i];
        }
        if (x) printf("Flag: %s\n",flag);
}

int main (int argc, char *argv[])
{
        int i;

        N = 1;

        for (i=0; i<FLAG_LEN; i++) flag[i] = '\0';

        letsgo();

        generate_flag();

        usleep(PAUSE*2*N);

        last_tip();

        showstuff("|\n"); usleep(PAUSE*N);
        showstuff("|\n"); usleep(PAUSE*N);
        showstuff("%s\n", MSG21); usleep(PAUSE*n*N);

        return 0;
}
