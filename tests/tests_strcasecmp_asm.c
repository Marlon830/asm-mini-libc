/*
** EPITECH PROJECT, 2023
** B-ASM-400-MPL-4-1-asmminilibc-marlon.pegahi
** File description:
** test_tests_strcasecmp_asm.c
*/

#include <criterion/criterion.h>

int strcasecmp(const char *s1, const char *s2);

Test(strcasecmp, returns_zero_1) {
    char str[] = "hello, WORLD!";
    char str2[] = "Hello, world!";

    cr_assert_eq(strcasecmp(str, str2), 0);
}

Test(strcasecmp, returns_zero_2) {
    char str[] = "hello, WORLD!";
    char str2[] = "HELLO, world!";

    cr_assert_eq(strcasecmp(str, str2), 0);
}

Test(strcasecmp, returns_positive_value) {
    char str[] = "hello, WORLD!";
    char str2[] = "Hello, world";

    cr_assert_eq(strcasecmp(str, str2), 33);
}

Test(strcasecmp, returns_negative_value) {
    char str[] = "hello, WORLD!";
    char str2[] = "Hello, world! ";

    cr_assert_eq(strcasecmp(str, str2), -32);
}
