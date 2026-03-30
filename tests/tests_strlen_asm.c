/*
** EPITECH PROJECT, 2023
** B-ASM-400-MPL-4-1-asmminilibc-marlon.pegahi
** File description:
** test_tests_strlen_asm.c
*/

#include <criterion/criterion.h>

size_t strlen(const char *str);

Test(strlen, base_test) {
    const char *str = "Hello, World!";

    cr_assert_eq(strlen(str), 13);
}

Test(strlen, empty_string) {
    const char *str = "";

    cr_assert_eq(strlen(str), 0);
}
