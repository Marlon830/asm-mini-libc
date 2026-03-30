/*
** EPITECH PROJECT, 2023
** B-ASM-400-MPL-4-1-asmminilibc-marlon.pegahi
** File description:
** tests_strcspn_asm.c
*/

#include <criterion/criterion.h>

size_t strcspn(const char *str, const char *accept);

Test(strcspn, returns_pointer_to_first_occurrence)
{
    const char *str = "Hello, World!";
    const char *accept = "o";
    int result = strcspn(str, accept);

    cr_assert_eq(result, 4);
}

Test(strcspn, returns_pointer_to_first_occurrence_1)
{
    const char *str = "Hello, World!";
    const char *accept = "r";
    int result = strcspn(str, accept);

    cr_assert_eq(result, 9);
}

Test(strcspn, returns_null_pointer)
{
    const char *str = "Hello, World";
    const char *accept = "BZZZ!";
    int result = strcspn(str, accept);

    cr_assert_eq(result, 12);
}

Test(strcspn, returns_pointer_to_end_of_string)
{
    const char *str = "Hello, World!";
    const char *accept = "";
    int result = strcspn(str, accept);

    cr_assert_eq(result, 13);
}

Test(strcspn, returns_pointer_to_first_occurrence_2)
{
    const char *str = "Hello, World!";
    const char *accept = "W";
    int result = strcspn(str, accept);

    cr_assert_eq(result, 7);
}

Test(strcspn, returns_pointer_to_first_occurence_3)
{
    const char *str = "Hello, World!";
    const char *accept = "BZZZ!";
    int result = strcspn(str, accept);

    cr_assert_eq(result, 12);
}
