token_type get_id();
token_type get_num();
token_type get_eol();
token_type get_err();
token_type get_next_token()
{
if(ischar(input_buf[dot]))
return get_id();
else if(isdigit(input_buf[dot]))
return get_num();
else if(iput_buf[dot]=='\n')
return get_eol();
else
return get_err();
}


token_type get_id();
{
int temp=dot,i=0;
token_type t;
char r;
while((r=next_char(dot))!=' ') t.repr[i++]=r;
t.repr[i]='\0';
t.type=ID;
t.
}