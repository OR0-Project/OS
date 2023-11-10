# Code Standards
1. Type Names and Pointers 
2. Variables, Constants and Functions
3. Comments and Info Blocks
4. Code Spacing


# 1. Type Names and Pointers
> ## 1.1. Types
> ### 1.1.1. Common
> ```c
> int8_t    signed_byte;            // char
> uint8_t   unsigned_byte;          // unsigned char
> int16_t   signed_word;            // short
> uint16_t  unsigned_word;          // unsigned short
> int32_t   signed_double_word;     // long
> uint32_t  unsigned_double_word;   // unsigned long
> int64_t   signed_quad_word;       // long long
> uint64_t  unsigned_quad_word;     // unsigned long long
> f32_t     single_precision_real;  // float
> f64_t     double_precision_real;  // double
> ```
> ### 1.1.2. Custom
> custom types must end with the following suffix: ```_t```
> ```c
> typedef struct flag_t {
>   uint8_t f0 : 1;
>   ...
>   uint8_t f7 : 1;
> } flag_t;
> ```
> ## 1.2. Pointers
> the ```*``` of a pointer type should be attached to the type name like so: ```uint8_t*```
> **except** in the case of multi variable declaration like so: ```uint8_t *a, *b;```


# 2. Variables, Constants and Functions
> variable and function names should be **exclusively** formatted using **snake_case**
> additionally the opening function scope bracket: ```{``` should be put after the function declaration
> like so:
> ```c
> void merge_sort(uint8_t* buffer, uint64_t size) {
>   ...
> }
> ```
> constants should be defined like so: (also **ALWAYS** use uppercase when using hex numbers)
> ```c
> const uint8_t magic_number = 0x5A;
> #define MAGIC_NUMBER 0x5A
> ```


# 3. Comments and Info Blocks
> ## 3.1. Comments
> adding comments should not be needed within functions so long as the code is written in a concise and simple way,
> additionally variable names should be chosen so that comments can be avoided.
> also **NEVER** use upper case letters.
> for function declarations and typedefs the following comment style should be used:
> ```c
> /*!< entry point
>  * @function main
>  * @param argc
>  * @param argv
>  */
> void main(uint32_t argc, uint8_t** argv);
> 
> /*!<
>  * @struct flag_t
>  * @var f0
>  * ...
>  * @var f7
>  */
> typedef struct flag_t {
>   uint8_t f0 : 1;
>   ...
>   uint8_t f7 : 1;
> } flag_t;
> ```
> 
> ## 3.2. Info Blocks
> info blocks should be added to each file with some basic information about the contents of the file and its author
> they should look like this:
> ```asm
>; //////////////////////////////////////////////////////////////////////////////
>; // File:     Name:        smp_ap.asm                                        //
>; //           Language:    x86_64 NASM assembly                              //
>; //                                                                          //
>; // Details:  this file contains the code responsible for initializing       //
>; //           the symmetric multiprocessing system for the                   //
>; //           application processor                                          //
>; //                                                                          //
>; // Author:   Name:        Marijn Verschuren                                 //
>; //           Email:       email@address.com                                 //
>; //                                                                          //
>; // Date:     2023-03-10                                                     //
>; //////////////////////////////////////////////////////////////////////////////
> ```



# 4. Code Spacing
> after the preprocessor statements at the beginning of the file **3** newlines should be added.
> after each function or type definition **2** newlines should be added (**except** for function and type declarations).
> additionally each line should be shorter than (or equal to) **80** characters.