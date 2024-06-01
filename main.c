#include <stdio.h>
#include <stdbool.h>

int fetch();
void eval();


typedef enum {
    A, B, C, D, E, F,
    NUM_OF_REGISTERS
} Registers;

typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    HLT

} InstructionSet;

const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT
};


int stack[256];
int registers[NUM_OF_REGISTERS];


int ip = 0;
int sp = -1;
bool isRunning = true;



int main() {

    while ( isRunning )
    {    
        int x = fetch();
        eval( x );
        ip++;
     //   printf("%d ", x);  
       
    }

    registers[A] = 0x10;

    printf("\nRegister A %x \n", registers[A]);


    return 0;
}




int fetch() {
    return program[ip];
}

void eval( int instr ) {

    switch ( instr )

    {
        case HLT:
            isRunning = false;
            break;

        case PSH: {
            stack[++sp] = program[++ip];
            break;
        }

        case POP:
            printf("\nValue on Top Of Stack is : %d\n", stack[sp--]);
            break;
        
        case ADD: {

            int a = stack[sp--];

            int result = a + stack[sp];
            stack[sp] = result; 

            break;
            
        }

    }

}




