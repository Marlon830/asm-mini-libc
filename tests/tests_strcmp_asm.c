/*
** EPITECH PROJECT, 2023
** B-ASM-400-MPL-4-1-asmminilibc-marlon.pegahi
** File description:
** test_tests_strcmp_asm.c
*/

#include <criterion/criterion.h>

int strcmp(const char *s1, const char *s2);

Test(strcmp, returns_negative_value) {
    char str[13] = {0};
    char str2[13] = "Hello world";

    cr_assert_eq(strcmp(str, str2), -72);
}

Test(strcmp, returns_positive_value) {
    char str[13] = {0};
    char str2[13] = "Hello world";

    cr_assert_eq(strcmp(str2, str), 72);
}

Test(strcmp, returns_zero) {
    char str[13] = "Hello world";
    char str2[13] = "Hello world";

    cr_assert_eq(strcmp(str2, str), 0);
}
