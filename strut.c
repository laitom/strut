#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "strut.h"

static int _str_occur(const char *, const char *, bool);
static int _strn_occur(const char *, const char *, int, bool);

char *strut_fill(const char *s1, const char *s2) {
    char *rs = (char *) malloc(strlen(s1)+1);

    for (int i = 0; i < strlen(s1); i += strlen(s2))
	strncpy((rs+i), s2, strlen(s2));

    *(rs+strlen(s1)) = '\0';
    return rs;
}

double strut_freq(const char *s1, const char *s2) {
    return (100.0/strlen(s1)) * (strlen(s2)*_str_occur(s1, s2, false));
}

int strut_hamming_dist(const char *s1, const char *s2) {
    int dist = 0;

    while (*s1 != '\0' && *s2 != '\0')
	if (*s1++ != *s2++)
	    ++dist;

    if (*s1 == '\0' && *s2 == '\0')
	return dist;
    else
	return -1;
}

bool strut_has_prefix(const char *s, const char *pfx) {
    for ( ; *s == *pfx; ++s, ++pfx)
	;

    if (*pfx == '\0')
	return true;

    return false;
}

bool strut_has_suffix(const char *s, const char *sfx) {
    int n;

    if (strlen(s) < strlen(sfx))
	return false;
    
    for ( ; *(s+1) != '\0'; ++s)
	;
    for (n = 0; *sfx != '\0'; ++sfx, ++n)
	;
    --sfx;
    
    for ( ; n > 0; --s, --sfx, --n)
	if (*s != *sfx)
	    return false;

    return true;
}

bool strut_is_palindrome(const char *s) {
    for (int i = 0, j = strlen(s)-1; i < j; ++i, --j)
	if (*(s+i) != *(s+j))
	    return false;

    return true;
}

char *strut_lhalf(const char *s) {
    return strut_lsplit(s, (strlen(s)/2) + (strlen(s)%2));
}

char *strut_rhalf(const char *s) {
    return strut_rsplit(s, (strlen(s)/2) + (strlen(s)%2));
}

char *strut_lsplit(const char *s, int n) {
    char *rs = (char *) malloc(n+1);
    rs = strncpy(rs, s, n);
    *(rs+n) = '\0';

    return rs;
}

char *strut_rsplit(const char *s, int n) {
    char *rs = (char *) malloc(strlen(s)-n+1);
    rs = strncpy(rs, s+n, strlen(s)-n);
    *(rs+strlen(s)-n) = '\0';

    return rs;
}

char *strut_lstrip(char *s) {
    for ( ; isspace((unsigned char) *s); ++s)
	;

    return s;
}

char *strut_rstrip(char *s) {
    int i, n, len = strlen(s);
    char *rs;

    for (i = len-1, n = 0; isspace((unsigned char) *(s+i)); --i, ++n)
	;

    rs = (char *) malloc(len-n+1);
    strncpy(rs, s, len-n);
    *(rs+len-n+1) = '\0';
    
    return rs;
}

char *strut_mirror(const char *s) {
    char *temp, *rs;
    
    temp = strut_reverse(s);
    rs = (char *) malloc((strlen(s)*2)+1);
    rs = strcpy(rs, s);
    rs = strcat(rs, temp);
    free(temp);

    return rs;
}

char *strut_replace(const char *s1, const char *s2, const char *s3) {
    char *rs;
    int n = _str_occur(s1, s2, false);
    int newlen = strlen(s1) - n*strlen(s2) + n*strlen(s3);

    rs = (char *) malloc(newlen+1);

    for (int i = 0; *s1 != '\0'; ++i, ++s1) {
	if (strut_has_prefix(s1, s2)) {
	    strncpy((rs+i), s3, strlen(s3));
	    s1 += strlen(s2)-1;
	    i += strlen(s3)-1;
	}
	else
	    *(rs+i) = *s1;
    }

    *(rs+newlen) = '\0';
    return rs;
}

char *strut_remove(const char *s1, const char *s2) {
    char *s3 = "";
    return strut_replace(s1, s2, s3);
}

char *strut_reverse(const char *s) {
    char *rs = (char *) malloc(strlen(s)+1);
    
    for (int i = 0, j = strlen(s)-1; i < strlen(s); ++i, --j)
	*(rs+i) = *(s+j);

    *(rs+strlen(s)) = '\0';
    return rs;
}

int strut_str_occur(const char *s1, const char *s2) {
    return _str_occur(s1, s2, false);
}

int strut_str_ol_occur(const char *s1, const char *s2) {
    return _str_occur(s1, s2, true);
}

int strut_strn_occur(const char *s1, const char *s2, int n) {
    return _strn_occur(s1, s2, n, false);
}

int strut_strn_ol_occur(const char *s1, const char *s2, int n) {
    return _strn_occur(s1, s2, n, true);
}

static int _str_occur(const char *s1, const char *s2, bool count_overlap) {
    int i, occur = 0;

    if (strlen(s2) == 0 || strlen(s1) < strlen(s2))
	return occur;

    for ( ; *s1 != '\0'; ++s1) {
	for (i = 0; *(s2+i) != '\0'; ++i)
	    if (*(s1+i) != *(s2+i))
		break;

	if (*(s2+i) == '\0') {
	    ++occur;
	    s1 += count_overlap ? 0 : strlen(s2)-1;
	}
    }

    return occur;
}

static int _strn_occur(const char *s1, const char *s2, int n, bool count_overlap) {
    int i, occur = 0;

    if (strlen(s2) == 0 || n < strlen(s2))
	return occur;

    for (int j = n; *s1 != '\0' && j > 0; ++s1, --j) {
	for (i = 0; j-i > 0 && *(s2+i) != '\0'; ++i)
	    if (*(s1+i) != *(s2+i))
		break;

	if (*(s2+i) == '\0') {
	    ++occur;
	    s1 += count_overlap ? 0 : strlen(s2)-1;
	}
    }

    return occur;
}
