#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFF_A_SIZE 20


// Setup a structure to easily allow an overflow to occur.
typedef struct Exec_S
{
    char a[BUFF_A_SIZE];
    char b[236];
} exec_t;


int func( exec_t* value )
{
    // Shortcut to execution, 
    return execl( value->b, (char* const) NULL );
}



int main( int argc, char** argv )
{
    // Start struct up.
    exec_t tmp = { .b = "tar" };

    // Print out the user input.
    printf("Input: %s\n", *(argv+1));

    // Copy the user input into a part of the struct.
    // This should use: 
    // strncopy( tmp.a, 
    //           *(argv+1), 
    //           strnlen( *( argv+1 ), BUFF_A_SIZE ) );
    // Otherwise we can overflow into tmp.b which is supposed to execute tar.
    strcpy( tmp.a, *(argv+1) );

    // Return the exec of b.
    return func( &tmp );
    
}