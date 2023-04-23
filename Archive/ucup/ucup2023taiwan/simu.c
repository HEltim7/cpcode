/* simu.c */
/* gcc -o simu simu.c */
#include <stdio.h>
#include <string.h>

char * cmds[10] =
    { "CCC", "ACG", "UGA", "UGC", "UAC"
    , "GCG", "UCC", "AGG", "UGU", "CAC"
    };
char code[1000002], memory[2000001], input[1000001];
static inline int get_cmd(char * code){
    for(int i=9; i>=0; --i)
        if( strncmp(cmds[i], code, 3)==0 )
            return i;
    return -1;
}
int main(){
    if( !fgets(code, 1000002, stdin) ){
        puts("no code");
        return 1;
    }
    int code_len = strlen(code);
    if( code[code_len-1]!='\n' ){
        puts("code too long");
        return 1;
    }
    code[--code_len] = 0;

    while( fgets(input, 1000001, stdin) ){
        char * ip = code, * input_p = input;
        char *mem = memory + 1000000;
        char *mem_begin=mem, *mem_end=mem;
        *mem = 0;
        int step = 0, eof = 0;
        while(1){
            if( step == 1000000 ){
                puts(" step out of bound");
                break;
            }
            if( code+code_len-ip < 3 ){
                puts(" code out of bound");
                break;
            }
            int cmd = get_cmd(ip);
            if( cmd<0 ){
                printf(" invalid code point: %c%c%c\n",
                    ip[0], ip[1], ip[2]);
                break;
            }
            if( cmd==0 ){
                puts(" stop normally");
                break;
            }
            if( cmd==1 ){
                ++mem;
                if( mem>mem_end )
                    *++mem_end = 0;
            }
            else if( cmd==2 ){
                --mem;
                if( mem<mem_begin )
                    *--mem_begin = 0;
            }
            else if( cmd==3 ){
                if( *mem==9 )
                    *mem = -1;
                else
                    ++*mem;
            }
            else if( cmd==4 ){
                if( *mem==-1 )
                    *mem = 9;
                else
                    --*mem;
            }
            else if( cmd==5 ){
                if( *mem==-1 )
                    putchar('-');
                else
                    putchar('0' + *mem);
            }
            else if( cmd==6 ){
                while(1){
                    if( !*input_p || *input_p=='\n' ){
                        *mem = -1;
                        break;
                    }
                    if( *input_p=='-' ){
                        *mem = -1;
                        ++input_p;
                        break;
                    }
                    if( '0'<=*input_p && *input_p<='9' ){
                        *mem = *input_p++ - '0';
                        break;
                    }
                    ++input_p;
                }
            }
            else if( cmd==7 ){
                if( !*mem ){
                    int skip = 1;
                    while(skip){
                        ip += 3;
                        if( code+code_len-ip < 3 ){
                            puts(" 7 can't find matched 8");
                            goto END;
                        }
                        if( strncmp(cmds[8], ip, 3)==0 )
                            --skip;
                        else if( strncmp(cmds[7], ip, 3)==0 )
                            ++skip;
                    }
                }
            }
            else if( cmd==8 ){
                if( *mem ){
                    int skip = 1;
                    while(skip){
                        ip -= 3;
                        if( ip < code ){
                            puts(" 8 can't find matched 7");
                            goto END;
                        }
                        if( strncmp(cmds[7], ip, 3)==0 )
                            --skip;
                        else if( strncmp(cmds[8], ip, 3)==0 )
                            ++skip;
                    }
                }
            }
            else if( cmd==9 ){
                printf("\nstep: %d, state: ", step);
                for(char *p=mem_begin; p<=mem_end; ++p)
                    if( p==mem )
                        printf("[%c]", *p<0 ? '-' : '0'+*p);
                    else
                        putchar(*p<0 ? '-' : '0'+*p);
                printf(", code:");
                for(char *p=code; p<code+code_len; p+=3)
                    printf("%c%c%c%c",
                        p==ip ? '[' : p==ip+3 ? ']' : ' ',
                        p[0], p[1], p[2]);
                if( code+code_len==ip+3 )
                    putchar(']');
                puts("");
                --step;
            }
            ++step;
            ip += 3;
        }
        END:;
    }
    return 0;
}
