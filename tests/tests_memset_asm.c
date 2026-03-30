/*
** EPITECH PROJECT, 2023
** B-ASM-400-MPL-4-1-asmminilibc-marlon.pegahi
** File description:
** test_tests_memset_asm.c
*/

#include <criterion/criterion.h>

void *memset(void *str, int c, size_t n);

Test(memset, returns_correct_pointer) {
    char str[13] = {0};

    cr_assert_eq(memset(str, 'r', 13), &str[0]);
}

Test(memset, change_correctly_bytes) {
    char str[13] = {0};
    char str2[13] = {0};

    for (int i = 0; i != 13; i++)
        str2[i] = 'r';

    memset(str, 'r', 13);
    cr_assert_eq(strncmp(str, str2, 13), 0);
}
