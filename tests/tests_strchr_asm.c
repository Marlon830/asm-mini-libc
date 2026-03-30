/*
** EPITECH PROJECT, 2023
** B-ASM-400-MPL-4-1-asmminilibc-marlon.pegahi
** File description:
** test_tests_strchr_asm.c
*/

#include <criterion/criterion.h>

char *strchr(const char *str, int c);

Test(strchr, returns_pointer_to_first_occurrence) {
    const char *str = "Hello, World!";
    int c = 'o';
    char *result = strchr(str, c);

    cr_assert_eq(result, &str[4]);
}

Test(strchr, returns_pointer_to_first_occurrence_1) {
    const char *str = "Hello, World!";
    int c = 'r';
    char *result = strchr(str, c);

    cr_assert_eq(result, &str[9]);
}

Test(strchr, returns_pointer_to_end_of_string) {
    const char *str = "Hello, World!";
    int c = '\0';
    char *result = strchr(str, c);

    cr_assert_eq(result, &str[13]);
}
