#include <string.h>
#include "stack.h"

int main() {
    int max_line = 105000;
	char input_buffer[max_line];
	int input_len = 0;	
	
	fgets(input_buffer, max_line, stdin);	
	input_buffer [strcspn (input_buffer, "\r\n")] = '\0';  //remove end-of-line characters

    input_len = strlen(input_buffer);
    printf("%d characters were read.\n",input_len);
    // printf("The input was: '%s'\n",input_buffer);
	fflush(stdout);
    Stack * opening_brackets_stack = createStack(max_line); 
    for (int position = 0; position < input_len; ++position) {
        char next = input_buffer[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket b;
            b.position = position;
            if (next == '('){
            b.type=0;
            } else if (next == '['){
            b.type=1;
            } else {
            b.type=2;
            }
            push(opening_brackets_stack, b);
        }

        if (next == ')' || next == ']' || next == '}') {
            Bracket last = pop(opening_brackets_stack);
            int type;
            if (next == ')'){
            type=0;
            } else if (next == ']'){
            type=1;
            } else {
            type=2;
            }
            if (last.type != type){
                printf("My result is: %d \n", position+1);
                return 0;
            }
        }
    }
    if (!isEmpty(opening_brackets_stack)){
        printf("My result is: %d \n", pop(opening_brackets_stack).position+1);
    } else {
        printf("Success\n");
    }
    // Printing answer, write your code here
	
    return 0;
}