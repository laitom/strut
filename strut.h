#include <stdbool.h>

/**
 * Construct a new string of the same length as s1, filled with the characters of s2 repeated.
 * The string returned should be freed with free().
 *
 * @param s1 A null-terminated string.
 * @param s2 A null-terminated string
 * @return A dynamically allocated string.
 */
char *strut_fill(const char *s1, const char *s2);

/**
 * Calculate the frequency of s2 from s1.
 *
 * @param s1 A null-terminated string.
 * @param s2 A null-terminated string.
 * @return A percentage representing the frequency of s2 in s1.
 */
double strut_freq(const char *s1, const char *s2);

/**
 * Calculate the Hamming distance between s1 and s2.
 *
 * @param s1 A null-terminated string.
 * @param s2 A null-terminated string.
 * @return The Hamming distance between s1 and s2, -1 if s1 and s2 are not equal length.
 */
int strut_hamming_dist(const char *s1, const char *s2);

/**
 * Check whether the string s begins with the prefix pfx.
 *
 * @param s A possibly null-terminated string.
 * @param pfx A null-terminated string.
 * @return true if s starts with pfx, false otherwise.
 */
bool strut_has_prefix(const char *s, const char *pfx);

/**
 * Check whether the string s ends with the suffix sfx.
 *
 * @param s A null-terminated string.
 * @param sfx A null-terminated string.
 * @return true if s ends with sfx, false otherwise.
 */
bool strut_has_suffix(const char *s, const char *sfx);

/**
 * Check whether the string s is a palindrome.
 *
 * @param s A null-terminated string.
 * @return true if s is a palindrome, false otherwise.
 */
bool strut_is_palindrome(const char *s);

/**
 * Construct a new string from the first half of the characters of s. If s has an odd number of characters, the
 * middlemost letter is also included.
 * The returned string should be freed with free().
 *
 * @param s A null-terminated string.
 * @return A string of the first half of the characters of s.
 */
char *strut_lhalf(const char *s);

/**
 * Construct a new string from the second half of the characters of s. If s has an odd number of characters, the
 * middlemost letter is not included.
 * The returned string should be freed with free().
 *
 * @param s A null-terminated string.
 * @return A string of the first half of the characters of s.
 */
char *strut_rhalf(const char *s);

/**
 * Construct a new string from the n first characters of s.
 * The returned string should be freed with free().
 *
 * @param s A null-terminated string.
 * @param n An integer.
 * @return A string of the n first characters of s.
 */
char *strut_lsplit(const char *s, int n);

/**
 * Construct a new string starting from the n+1th character of s.
 * The returned string should be freed with free().
 *
 * @param s A null-terminated string.
 * @param n An integer.
 * @return A string of the strlen(s)-n last characters of s.
 */
char *strut_rsplit(const char *s, int n);

/**
 * Strip leading whitespace from s.
 * Should not be used with dynamically allocated strings.
 *
 * @param s A string.
 * @return The original string with leading whitespace removed.
 */
char *strut_lstrip(char *s);

/**
 * Strip leading whitespace from s.
 * The returned string should be freed with free().
 *
 * @param s A string.
 * @return A dynamically allocated string, a copy of s with leading whitespace removed.
 */
char *strut_rstrip(char *s);

/**
 * Reverse the string s and append it to the end of s.
 * The returned string should be freed with free().
 *
 * @param s A null-terminated string.
 * @return A dynamically allocated string, the original s with s reversed appended to the end of it.
 */
char *strut_mirror(const char *s);

/**
 * Replace every instance of s2 from s1 with s3.
 * The returned string should be freed with free().
 *
 * @param s1 A null-terminated string.
 * @param s2 A null-terminated string.
 * @param s3 A null-terminated string.
 * @return A dynamically allocated string, a copy of s1 with instances of s2 replaced with s3.
 */
char *strut_replace(const char *s1, const char *s2, const char *s3);

/**
 * Remove every instance of s2 from s1.
 * The returned string should be freed with free().
 *
 * @param s1 A null-terminated string.
 * @param s2 A null-terminated string.
 * @return A dynamically allocated string, a copy of s1 with instances of s2 removed.
 */
char *strut_remove(const char *s1, const char *s2);

/**
 * Reverse the string s.
 * The returned string should be freed with free().
 *
 * @param s A null-terminated string.
 * @return s reversed.
 */
char *strut_reverse(const char *s);

/**
 * Search for the number of non-overlapping occurences of s2 from s1.
 *
 * @param s1 A null-terminated string.
 * @param s2 A null-terminated string.
 * @return The number of non-overlapping occurences of s2 found from s1.
 */
int strut_str_occur(const char *s1, const char *s2);

/**
 * Search for the number of possibly overlapping occurences of s2 from s1.
 *
 * @param s1 A null-terminated string.
 * @param s2 A null-terminated string.
 * @return The number of possibly overlapping occurences of s2 found from s1.
 */
int strut_str_ol_occur(const char *s1, const char *s2);

/**
 * Search for the number of non-overlapping occurences of s2 from at most n of the first characters of s1.
 *
 * @param s1 A possibly null-terminated string.
 * @param s2 A null-terminated string.
 * @return The number of non-overlapping occurences of s2 found from s1.
 */
int strut_strn_occur(const char *s1, const char *s2, int n);

/**
 * Search for the number of possibly overlapping occurences of s2 from at most n of the first characters of s1.
 *
 * @param s1 A possibly null-terminated string.
 * @param s2 A null-terminated string.
 * @return The number of possibly overlapping occurences of s2 found from s1.
 */
int strut_strn_ol_occur(const char *s1, const char *s2, int n);
