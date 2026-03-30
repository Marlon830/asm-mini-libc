/*
** EPITECH PROJECT, 2023
** B-ASM-400-MPL-4-1-asmminilibc-marlon.pegahi
** File description:
** test_tests_index_asm.c
*/

#include <criterion/criterion.h>

char *index(const char *str, int c);

Test(index, returns_pointer_to_first_occurrence) {
    const char *str = "Hello, World!";
    int c = 'o';
    char *result = index(str, c);

    cr_assert_eq(result, &str[4]);
}

Test(index, returns_pointer_to_first_occurrence_1) {
    const char *str = "Hello, World!";
    int c = 'r';
    char *result = index(str, c);

    cr_assert_eq(result, &str[9]);
}

Test(index, returns_pointer_to_end_of_string) {
    const char *str = "Hello, World!";
    int c = '\0';
    char *result = index(str, c);

    cr_assert_eq(result, &str[13]);
}
