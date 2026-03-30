/*
** EPITECH PROJECT, 2023
** B-ASM-400-MPL-4-1-asmminilibc-marlon.pegahi
** File description:
** test_tests_rindex_asm.c
*/

#include <criterion/criterion.h>

char *rindex(const char *str, int c);

Test(rindex, returns_pointer_to_last_occurrence) {
    const char *str = "Hello, World!";
    int c = 'l';
    char *result = rindex(str, c);

    cr_assert_eq(result, &str[10]);
}

Test(rindex, returns_pointer_to_last_occurrence_1) {
    const char *str = "Hello, World!";
    int c = 'r';
    char *result = rindex(str, c);

    cr_assert_eq(result, &str[9]);
}

Test(rindex, returns_pointer_to_end_of_string) {
    const char *str = "Hello, World!";
    int c = '\0';
    char *result = rindex(str, c);

    cr_assert_eq(result, &str[13]);
}
