/*
** EPITECH PROJECT, 2023
** B-ASM-400-MPL-4-1-asmminilibc-marlon.pegahi
** File description:
** test_tests_strncmp_asm.c
*/

#include <criterion/criterion.h>

int strncmp(const char *s1, const char *s2, size_t n);

Test(strncmp, returns_zero_1) {
    char str[] = "Hello not world";
    char str2[] = "Hello world";

    cr_assert_eq(strncmp(str, str2, 5), 0);
}

Test(strncmp, returns_positive_value) {
    char str[] = {0};
    char str2[] = "Hello world";

    cr_assert_eq(strncmp(str2, str, 5), 72);
}

Test(strncmp, returns_negative_value) {
    char str[] = {0};
    char str2[] = "Hello world";

    cr_assert_eq(strncmp(str, str2, 5), -72);
}

Test(strncmp, returns_zero_2) {
    char str[] = "Hello world not";
    char str2[] = "Hello world";

    cr_assert_eq(strncmp(str2, str, 11), 0);
}

Test(strncmp, returns_negative_value_2) {
    char str[] = "Hello world not";
    char str2[] = "Hello world";

    cr_assert_eq(strncmp(str2, str, 12), -32);
}

Test(strncmp, returns_positive_value_2) {
    char str[] = "Hello world not";
    char str2[] = "Hello world";

    cr_assert_eq(strncmp(str, str2, 12), 32);
}
