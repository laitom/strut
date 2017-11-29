#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strut.h"

void test_strut_fill();
void test_strut_freq();
void test_strut_hamming_dist();
void test_strut_has_prefix();
void test_strut_has_suffix();
void test_strut_is_palindrome();
void test_strut_lhalf();
void test_strut_rhalf();
void test_strut_lsplit();
void test_strut_rsplit();
void test_strut_lstrip();
void test_strut_rstrip();
void test_strut_mirror();
void test_strut_replace();
void test_strut_remove();
void test_strut_reverse();
void test_strut_str_occur();
void test_strut_str_ol_occur();
void test_strut_strn_occur();
void test_strut_strn_ol_occur();

static const char *str = "hiololo;ihiohloi98olowxx";
static const char *search1 = "olo";
static const char *search2 = "xx";
static const char *search3 = "hi";
static const char *search4 = ";";
static const char *search5 = "xx\0";
static const char *search6 = "o";
static const char *search7 = ";ihiohlo";
static const char *search8 = "ole";

int main(int argc, char *argv[]) {
    test_strut_fill();
    test_strut_freq();
    test_strut_hamming_dist();
    test_strut_has_prefix();
    test_strut_has_suffix();
    test_strut_is_palindrome();
    test_strut_lhalf();
    test_strut_rhalf();
    test_strut_lsplit();
    test_strut_rsplit();
    test_strut_lstrip();
    test_strut_rstrip();
    test_strut_mirror();
    test_strut_replace();
    test_strut_remove();
    test_strut_reverse();
    test_strut_str_occur();
    test_strut_str_ol_occur();
    test_strut_strn_occur();
    test_strut_strn_ol_occur();
}

void test_strut_fill() {
    printf("Testing strut_fill()... ");

    char *s1 = "aabbaabbc";
    char *s2 = "dedededed";
    char *r = "de";
    s1 = strut_fill(s1, r);
    assert(strcmp(s1, s2) == 0);
    free(s1);

    s1 = "aabbaabbc";
    s2 = "hbghbghbg";
    r =  "hbghbghbgh234";
    s1 = strut_fill(s1, r);
    assert(strcmp(s1, s2) == 0);
    free(s1);

    printf("OK\n");
}

void test_strut_freq() {
    printf("Testing strut_freq()... ");

    assert(strut_freq(search1, search6) > 66.6);
    assert(strut_freq(search1, search6) < 66.7);
    assert(strut_freq(search1, search8) == 0.0);
    assert(strut_freq(search6, search1) == 0.0);

    char *s1 = "\nhello\n\nhj";
    char *s2 = "\n";
    assert(strut_freq(s1, s2) == 30.0);

    s1 = "1\t2\t3\t4\t5\n6\t7\t8\t9\t0\t";
    s2 = "3";
    assert(strut_freq(s1, s2) == 5.0);
    s2 = "\t";
    assert(strut_freq(s1, s2) == 45.0);

    printf("OK\n");
}

void test_strut_hamming_dist() {
    printf("Testing strut_hamming_dist()... ");

    char *s1 = "otto";
    char *s2 = "akko";
    assert(strut_hamming_dist(s1, s2) == 3);
    assert(strut_hamming_dist(s2, s1) == 3);

    s1 = "gee";
    s2 = "geeo";
    assert(strut_hamming_dist(s1, s2) == -1);

    s1 = "home";
    s2 = "hom";
    assert(strut_hamming_dist(s1, s2) == -1);

    s2 = "home";
    assert(strut_hamming_dist(s1, s2) == 0);

    s1 = "line";
    s2 = "li!e";
    assert(strut_hamming_dist(s1, s2) == 1);

    printf("OK\n");
}

void test_strut_has_prefix() {
    printf("Testing strut_has_prefix()... ");

    assert(strut_has_prefix(str, search1) == false);
    assert(strut_has_prefix(str, search3) == true);
    assert(strut_has_prefix(search1, search6) == true);
    assert(strut_has_prefix(search6, search1) == false);
    assert(strut_has_prefix(search1, search8) == false);

    printf("OK\n");
}

void test_strut_has_suffix() {
    printf("Testing strut_has_suffix()... ");

    assert(strut_has_suffix(str, search2) == true);
    assert(strut_has_suffix(str, search3) == false);
    assert(strut_has_suffix(str, search5) == true);
    assert(strut_has_suffix(search2, str) == false);

    printf("OK\n");
}

void test_strut_is_palindrome() {
    printf("Testing strut_is_palindrome()... ");

    assert(strut_is_palindrome(search1) == true);
    assert(strut_is_palindrome(search2) == true);
    assert(strut_is_palindrome(search4) == true);
    assert(strut_is_palindrome(search6) == true);
    assert(strut_is_palindrome(search7) == false);
    assert(strut_is_palindrome(search8) == false);

    printf("OK\n");
}

void test_strut_lhalf() {
    printf("Testing strut_lhalf()... ");

    char *s1 = "hellohello";
    char *s2 = "hello";
    s1 = strut_lhalf(s1);
    assert(strcmp(s1, s2) == 0);
    free(s1);

    s1 = "doggo";
    s2 = "dog";
    char *s3 = "dogg";
    char *s4 = "do";
    s1 = strut_lhalf(s1);
    assert(strcmp(s1, s2) == 0);
    assert(strcmp(s1, s3) != 0);
    assert(strcmp(s1, s4) != 0);
    free(s1);

    printf("OK\n");
}

void test_strut_rhalf() {
    printf("Testing strut_rhalf()... ");

    char *s1 = "xellohello";
    char *s2 = "hello";
    s1 = strut_rhalf(s1);
    assert(strcmp(s1, s2) == 0);
    free(s1);

    s1 = "doggo";
    s2 = "go";
    char *s3 = "ggo";
    s1 = strut_rhalf(s1);
    assert(strcmp(s1, s2) == 0);
    assert(strcmp(s1, s3) != 0);
    free(s1);

    printf("OK\n");
}

void test_strut_lsplit() {
    printf("Testing strut_lsplit()... ");

    char *s1 = "hello, world";
    char *s2 = "hello,";
    s1 = strut_lsplit(s1, 6);
    assert(strcmp(s1, s2) == 0);
    free(s1);

    s1 = "\t\t\tcat in a hat";
    s2 = "\t\t\tca";
    s1 = strut_lsplit(s1, 5);
    assert(strcmp(s1, s2) == 0);
    free(s1);

    printf("OK\n");
}

void test_strut_rsplit() {
    printf("Testing strut_rsplit()... ");

    char *s1 = "hello, world";
    char *s2 = " world";
    s1 = strut_rsplit(s1, 6);
    assert(strcmp(s1, s2) == 0);
    free(s1);

    s1 = "\t\t\tcat in a hat";
    s2 = "a hat";
    s1 = strut_rsplit(s1, 10);
    assert(strcmp(s1, s2) == 0);
    free(s1);

    printf("OK\n");
}

void test_strut_lstrip() {
    printf("Testing strut_lstrip()... ");

    char *s1 = "\n   \tHello";
    char *t1 = "Hello";
    s1 = strut_lstrip(s1);
    assert(strlen(s1) == 5);
    assert(strcmp(s1, t1) == 0);

    s1 = "\t\t\t\nmy name is Jack";
    t1 = "my name is Jack";
    s1 = strut_lstrip(s1);
    assert(strlen(s1) == 15);
    assert(strcmp(s1, t1) == 0);
    
    printf("OK\n");
}

void test_strut_rstrip() {
    printf("Testing strut_rstrip()... ");

    char *s = "Hello\n   \t";
    char *t = "Hello";
    s = strut_rstrip(s);
    assert(strlen(s) == 5);
    assert(strcmp(s, t) == 0);
    free(s);

    s = "my name is Jack\t\t\t\n";
    t = "my name is Jack";
    s = strut_rstrip(s);
    assert(strlen(s) == 15);
    assert(strcmp(s, t) == 0);
    free(s);
    
    printf("OK\n");
}

void test_strut_mirror() {
    printf("Testing strut_mirror()... ");

    char *s = "hog";
    char *t = "hoggoh";
    s = strut_mirror(s);
    assert(strcmp(s, t) == 0);
    free(s);

    s = "line\n\tends";
    t = "line\n\tendssdne\t\nenil";
    s = strut_mirror(s);
    assert(strcmp(s, t) == 0);
    free(s);

    printf("OK\n");
}

void test_strut_replace() {
    printf("Testing strut_replace()... ");

    char *s1 = "ummagumma";
    char *s2 = "mm";
    char *s3 = "ggg";
    char *t1 = "ugggaguggga";
    s1 = strut_replace(s1, s2, s3);
    assert(strlen(s1) == strlen(t1));
    assert(strcmp(s1, t1) == 0);
    free(s1);

    s1 = "ummagumma";
    s2 = "u";
    s3 = "I ";
    t1 = "I mmagI mma";
    s1 = strut_replace(s1, s2, s3);
    assert(strlen(s1) == strlen(t1));
    assert(strcmp(s1, t1) == 0);
    free(s1);

    s1 = "drop\nof\na\nhat";
    s2 = "\n";
    s3 = " ";
    t1 = "drop of a hat";
    s1 = strut_replace(s1, s2, s3);
    assert(strlen(s1) == strlen(t1));
    assert(strcmp(s1, t1) == 0);
    free(s1);

    printf("OK\n");
}

void test_strut_remove() {
    printf("Testing strut_remove()... ");

    char *s1 = "ummagumma";
    char *s2 = "mm";
    char *t1 = "uagua";
    s1 = strut_remove(s1, s2);
    assert(strlen(s1) == strlen(t1));
    assert(strcmp(s1, t1) == 0);
    free(s1);

    printf("OK\n");
}

void test_strut_reverse() {
    printf("Testing strut_reverse()... ");

    char *s1 = "reverse";
    char *s2 = "esrever";
    s1 = strut_reverse(s1);
    assert(strcmp(s1, s2) == 0);
    free(s1);

    s1 = "ottoman  man";
    s2 = "nam  namotto";
    s1 = strut_reverse(s1);
    assert(strcmp(s1, s2) == 0);
    free(s1);

    printf("OK\n");
}

void test_strut_str_occur() {
    printf("Testing strut_str_occur()... ");
    
    assert(strut_str_occur(str, search1) == 2);
    assert(strut_str_occur(str, search2) == 1);
    assert(strut_str_occur(str, search3) == 2);
    assert(strut_str_occur(str, search4) == 1);
    assert(strut_str_occur(str, search5) == 1);
    assert(strut_str_occur(str, search6) == 7);
    assert(strut_str_occur(str, search7) == 1);
    assert(strut_str_occur(str, search8) == 0);

    printf("OK\n");
}

void test_strut_str_ol_occur() {
    printf("Testing strut_str_ol_occur... ");
    
    assert(strut_str_ol_occur(str, search1) == 3);
    assert(strut_str_ol_occur(str, search2) == 1);
    assert(strut_str_ol_occur(str, search3) == 2);
    assert(strut_str_ol_occur(str, search4) == 1);
    assert(strut_str_ol_occur(str, search5) == 1);
    assert(strut_str_ol_occur(str, search6) == 7);
    assert(strut_str_ol_occur(str, search7) == 1);
    assert(strut_str_ol_occur(str, search8) == 0);

    printf("OK\n");
}

void test_strut_strn_occur() {
    printf("Testing strut_strn_occur()... ");
    
    assert(strut_strn_occur(str, search1, 8) == 1);
    assert(strut_strn_occur(str, search2, 100) == 1);
    assert(strut_strn_occur(str, search3, 20) == 2);
    assert(strut_strn_occur(str, search4, 7) == 0);
    assert(strut_strn_occur(str, search5, 100) == 1);
    assert(strut_strn_occur(str, search6, 12) == 4);
    assert(strut_strn_occur(str, search7, 14) == 0);
    assert(strut_strn_occur(str, search8, 10) == 0);

    printf("OK\n");
}

void test_strut_strn_ol_occur() {
    printf("Testing strut_strn_ol_occur()... ");
    
    assert(strut_strn_ol_occur(str, search1, 8) == 2);
    assert(strut_strn_ol_occur(str, search2, 100) == 1);
    assert(strut_strn_ol_occur(str, search3, 20) == 2);
    assert(strut_strn_ol_occur(str, search4, 7) == 0);
    assert(strut_strn_ol_occur(str, search5, 100) == 1);
    assert(strut_strn_ol_occur(str, search6, 12) == 4);
    assert(strut_strn_ol_occur(str, search7, 15) == 1);
    assert(strut_strn_ol_occur(str, search8, 10) == 0);

    printf("OK\n");
}
