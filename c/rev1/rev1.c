#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
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

#define MAX_KEY 35
#define SECRET_KEY "c2VjcmV0S2V5MTIz"
#define BACON "BACONBACONBACONBACONBACONBACONBACONBACONBACONBACONBACONBACONBACONBACONBACONBACON"
#define ENCRYPTED_FLAG "040D0208351114130A1C1D12060C1C07151C0B010C151C1C0603130632"

#define TRUE 1
#define FALSE 0
#define PARAMS 2

#define PAUSE 150000

#define showstuff(x...) fprintf(stdout,x)

#define preparestuff(x...) do { \
    showstuff(x); \
    exit(0); \
  } while (0)

int N = 0;
int n = 1;

static char encoding_table[] =
{
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
        'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
        'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
        'w', 'x', 'y', 'z', '0', '1', '2', '3',
        '4', '5', '6', '7', '8', '9', '+', '/'
};

static char *decoding_table = NULL;
static int mod_table[] = {0, 2, 1};

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
        showstuff("What is the secret key? ");
        fflush(NULL);

        fflush(NULL);
}

static void author(void)
{
        printf("Level written by Javier (@javutin)\n");
}

char *base64_encode(const char *data, size_t input_length, size_t *output_length)
{
        *output_length = 4 * ((input_length + 2) / 3);

  char *encoded_data = malloc(*output_length);
        int i,j;

  if (encoded_data == NULL) return NULL;

  for (i=0,j=0; i<input_length;)
        {
                uint32_t octet_a = i < input_length ? (unsigned char)data[i++] : 0;
    uint32_t octet_b = i < input_length ? (unsigned char)data[i++] : 0;
    uint32_t octet_c = i < input_length ? (unsigned char)data[i++] : 0;

    uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

    encoded_data[j++] = encoding_table[(triple >> 3 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 2 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 1 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 0 * 6) & 0x3F];
        }

        for (i=0; i<mod_table[input_length % 3]; i++)
                encoded_data[*output_length - 1 - i] = '=';

        return encoded_data;
}

unsigned char *base64_decode(const char *data, size_t input_length, size_t *output_length)
{
  int i, j;

        if (decoding_table == NULL) build_decoding_table();

        if (input_length % 4 != 0) return NULL;

        *output_length = input_length / 4 * 3;
  if (data[input_length - 1] == '=') (*output_length)--;
  if (data[input_length - 2] == '=') (*output_length)--;

  unsigned char *decoded_data = malloc(*output_length);
  if (decoded_data == NULL) return NULL;

  for (i=0,j=0; i<input_length;)
        {
                uint32_t sextet_a = data[i] == '=' ? 0 & i++ : decoding_table[data[i++]];
                uint32_t sextet_b = data[i] == '=' ? 0 & i++ : decoding_table[data[i++]];
                uint32_t sextet_c = data[i] == '=' ? 0 & i++ : decoding_table[data[i++]];
                uint32_t sextet_d = data[i] == '=' ? 0 & i++ : decoding_table[data[i++]];

                uint32_t triple = (sextet_a << 3 * 6) + (sextet_b << 2 * 6) + (sextet_c << 1 * 6) + (sextet_d << 0 * 6);

                if (j < *output_length) decoded_data[j++] = (triple >> 2 * 8) & 0xFF;
    if (j < *output_length) decoded_data[j++] = (triple >> 1 * 8) & 0xFF;
    if (j < *output_length) decoded_data[j++] = (triple >> 0 * 8) & 0xFF;
        }

        return decoded_data;
}

int build_decoding_table()
{
        decoding_table = malloc(256);
  int i;

        for (i=0; i<64; i++)
        decoding_table[(unsigned char) encoding_table[i]] = i;
}

void base64_cleanup() {
        free(decoding_table);
}

/*int hide_flag()
{
        char flag[FLAG_LEN];
  int i;
        for (i=0; i<FLAG_LEN; i++) flag[i] = '0';

        for (i=0; i<FLAG_LEN; i++)
        {
                flag[i] = FLAG[i]^BACON[i];
        }
        showstuff("| %s |\n", flag);
}*/

int hex_to_int(char c){
    int first = c / 16 - 3;
    int second = c % 16;
    int result = first*10 + second;
    if(result > 9) result--;
    return result;
}

int to_byte(char c, char d){
    int high = hex_to_int(c) * 16;
    int low = hex_to_int(d);
    return high+low;
}

static void show_flag()
{
        int flag_len = strlen(ENCRYPTED_FLAG) / 2;
        char flag[flag_len];
        int i;

        for (i=0; i<flag_len; i++) flag[i] = '\0';

        for (i=0; i<flag_len; i++)
        {
            flag[i] = to_byte(ENCRYPTED_FLAG[2*i], ENCRYPTED_FLAG[2*i+1])^BACON[i];
        }

        showstuff("|  >  ");
        for (i=0; i<flag_len; i++) printf("%c", flag[i]);
        showstuff("\n");
}

int validate_secret_key(const char *data, size_t input_length)
{
        int check = TRUE;
  int i;

        if (input_length > MAX_KEY || input_length == 0) return FALSE;

        for (i=0; i<input_length; i++)
        {
                if (data[i] != SECRET_KEY[i])
                {
                        check = FALSE;
                        break;
                }
        }

        return check;
}

int main (int argc, char *argv[])
{
        N = 1;
        int i = 0, result = 0;
        char entered_key[MAX_KEY];
        char clean_entered_key[MAX_KEY-1];
        char *encoded;
        char *decoded;

        letsgo();

        if (fgets(entered_key, sizeof(entered_key), stdin) != NULL)
        {
                size_t len = strlen(entered_key), olen;
                strncpy(clean_entered_key, entered_key, len-1);
                encoded = base64_encode(clean_entered_key, (size_t)(len-1), &olen);
                base64_cleanup();

                decoded = base64_decode(encoded, (size_t)strlen(encoded), &olen);
                base64_cleanup();

                result = validate_secret_key(encoded, strlen(encoded));

                showstuff("|  \n");

                if (result)
                {
                        showstuff("|  Correct! Here is your flag :)\n");
                        showstuff("|  \n");
                        show_flag();
                } else {
                        showstuff("|\n"); usleep(PAUSE*N);
                        showstuff("|  Sorry! GAMEOVER! No flag for you!\n");
                }

                showstuff("|  \n");
                showstuff("%s\n", MSG21); usleep(PAUSE*n*N);
        }

        return 0;
}
