/*
** EPITECH PROJECT, 2023
** B-ASM-400-MPL-4-1-asmminilibc-marlon.pegahi
** File description:
** test_tests_strstr_asm.c
*/

#include <criterion/criterion.h>

char *strstr(const char *haystack, const char *needle);

Test(strstr, returns_pointer_to_first_occurrence) {
    const char *haystack = "Hello, World!";
    const char *needle = "lo";
    char *result = strstr(haystack, needle);

    cr_assert_eq(result, &haystack[3]);
}

Test(strstr, returns_pointer_to_first_occurrence_1) {
    const char *haystack = "Hello, World!";
    const char *needle = "World";
    char *result = strstr(haystack, needle);

    cr_assert_eq(result, &haystack[7]);
}

Test(strstr, returns_null_pointer) {
    const char *haystack = "Hello, World!";
    const char *needle = "Salut monde!";
    char *result = strstr(haystack, needle);

    cr_assert_eq(result, NULL);
}

Test(strstr, returns_pointer_to_start_of_string) {
    const char *haystack = "Hello, World!";
    const char *needle = "\0";
    char *result = strstr(haystack, needle);

    cr_assert_eq(result, &haystack[0]);
}
