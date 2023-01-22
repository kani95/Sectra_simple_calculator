# Simple calculator
## Assumptions   
 - The registers have alphanumeric characters as identifier then each identifier composed of only integers could be used as a register name.
 - The calculator calculates using long integers and not floating point numbers as the examples are showing.
 - The operations for the calculator is not case sensitive.
 - An operation cannot be across multiple lines. 

## Execution

Given that the user has **GNU compiler** installed.
The calculator is executed by running the following command:

>**make**
>**./calculator *example.txt***

Otherwise, to use the compiler of their choice the user can update the makefile variables:
>**CC** = *compiler of choice*
>**CFLAGS** = *flags of choice*

And then run the same commands as above.