typedef struct
{
char filename[100];
int line_no;
int char_no
}location_info;

typedef struct
{
int type;
char repr[50];
location_info loc;
}token_type;
#define INT 256
#define ID 257
#define EOL 258
#define ERR 259
token_type get_next_token();
#define ischar(ch) (((ch)>='a') && ((ch)<='z'))
#define isdigit(ch) (((ch)>='0') && ((ch)<='9'))
#define next_char(dot) input_buf[++dot]
static int dot=0;
char input_buf[100];