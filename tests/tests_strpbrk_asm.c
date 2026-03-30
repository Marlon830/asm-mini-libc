/*
** EPITECH PROJECT, 2023
** B-ASM-400-MPL-4-1-asmminilibc-marlon.pegahi
** File description:
** tests_strpbrk_asm.c
*/

#include <criterion/criterion.h>

char *strpbrk(const char *str, const char *accept);

Test(strpbrk, returns_pointer_to_first_occurrence)
{
    const char *str = "Hello, World!";
    const char *accept = "o";
    char *result = strpbrk(str, accept);

    cr_assert_eq(result, &str[4]);
}

Test(strpbrk, returns_pointer_to_first_occurrence_1)
{
    const char *str = "Hello, World!";
    const char *accept = "r";
    char *result = strpbrk(str, accept);

    cr_assert_eq(result, &str[9]);
}

Test(strpbrk, returns_null_pointer)
{
    const char *str = "Hello, World";
    const char *accept = "BZZZ!";
    char *result = strpbrk(str, accept);

    cr_assert_eq(result, NULL);
}

Test(strpbrk, returns_pointer_to_end_of_string)
{
    const char *str = "Hello, World!";
    const char *accept = "";
    char *result = strpbrk(str, accept);

    cr_assert_eq(result, NULL);
}

Test(strpbrk, returns_pointer_to_first_occurrence_2)
{
    const char *str = "Hello, World!";
    const char *accept = "W";
    char *result = strpbrk(str, accept);

    cr_assert_eq(result, &str[7]);
}

Test(strpbrk, returns_pointer_to_first_occurence_3)
{
    const char *str = "Hello, World!";
    const char *accept = "BZZZ!";
    char *result = strpbrk(str, accept);

    cr_assert_eq(result, &str[12]);
}
