#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct s_s
{
	char *str;
}	t_s;


bool has_unclosed_quotes(const char *str)
{
    bool in_single = false;
    bool in_double = false;
    
    while (*str) {
        // Handle quote states
        if (*str == '\'' && !in_double) {
            in_single = !in_single;
        }
        else if (*str == '"' && !in_single) {
            in_double = !in_double;
        }
        str++;
    }
    
    return (in_single || in_double);
}

int main(void)
{
	t_s shell;

	const char *s;
	shell.str = "hello";
	shell.str++;
	s = shell.str;
	printf("%s\n", shell.str);	
	printf("%s\n", s);	
//	int a = 5;
//	int b = !a;
//	printf("%d\n", !b);
}
