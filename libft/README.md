# libft
---

흔히 사용하고 있는 `unistd.h` 에 있는 함수들을 직접 구현하면서 각각의 함수들이 실제로 어떤식으로 동작하는지 공부해보고 c언어 문법과 `Makefile` 사용법을 익혔다

# **part 1 : Libc functions**

<details>
  <summary>ft_strlen</summary>

  - Man page

    **SYNOPSIS**
    ```c
    #include <string.h>
    
    size_t
    strlen(const char *s);
    ```

    **DESCRIPTION**
    The `strlen()` function computes the length of the string `s`. The `strnlen()` function attempts to compute the length of `s`, but never scans beyond the first `maxlen` bytes of `s`.

    **RETURN VALUES**
    The `strlen()` function returns the number of characters that precede the terminating NUL character. The `strnlen()` function returns either the same result as `strlen()` or `maxlen`, whichever is smaller.
</details>

<details>
  <summary>ft_strrchr</summary>

  - Man page

    **SYNOPSIS**
    ```c
    #include <string.h>
    
    char *
    strrchr(const char *s, int c);
    ```

    **DESCRIPTION**
    The `strchr()` function locates the first occurrence of `c` (converted to a char) in the string pointed to by `s`. The terminating null character is considered to be part of the string; therefore if `c` is `\0`, the function locates the terminating `\0`. The `strrchr()` function is identical to `strchr()`, except it locates the last occurrence of `c`.

    **RETURN VALUES**
    The functions `strchr()` and `strrchr()` return a pointer to the located character, or `NULL` if the character does not appear in the string.
  
  - 설명
    문자내에 일치하는 문자가 있는지 검사하는 함수
    `char *str` : 검색할 문자열
    `int c` : 존재하는지 확인할 문자열
    - 반환값
      문자가 존재하면 존재하는 곳의 포인터를 `char *` 형으로 반환
      없다면 `NULL` 반환
</details>

<details>
  <summary>첫번째 ft_strchr 토글</summary>

- ft_strdup

  - Man page

    **SYNOPSIS**
    ```c
    #include <string.h>
    
    char *
    strdup(const char *s1);
    ```

    **DESCRIPTION**
    The `strdup()` function allocates sufficient memory for a copy of the string `s1`, does the copy, and returns a pointer to it. The pointer may subsequently be used as an argument to the function `free(3)`. If insufficient memory is available, `NULL` is returned and `errno` is set to `ENOMEM`.

  - 설명
    - `s1`와 동일한 배열을 생성하는 함수
    - 리턴값: 생성한 배열의 주소값
</details>

<details>
  <summary>ft_strlcat</summary>

  - Man page

    **SYNOPSIS**
    ```c
    #include <string.h>
    
    size_t
    strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
    ```

    **DESCRIPTION**
    The `strlcpy()` and `strlcat()` functions copy and concatenate strings with the same input parameters and output result as `snprintf(3)`. They are designed to be safer, more consistent, and less error-prone replacements for the easily misused functions `strncpy(3)` and `strncat(3)`.

    `strlcpy()` and `strlcat()` take the full size of the destination buffer and guarantee NUL-termination if there is room. Note that room for the NULL should be included in `dstsize`.

    `strlcat()` appends string `src` to the end of `dst`. It will append at most `dstsize - strlen(dst) - 1` characters. It will then NUL-terminate unless `dstsize` is 0 or the original `dst` string was longer than `dstsize` (in practice this should not happen as it means that either `dstsize` is incorrect or that `dst` is not a proper string).

    If the `src` and `dst` strings overlap, the behavior is undefined.

    **RETURN VALUES**
    Besides quibbles over the return type (size_t versus int) and signal handler safety (`snprintf(3)` is not entirely safe on some systems), the following two are equivalent:
    ```c
    n = strlcpy(dst, src, len);
    n = snprintf(dst, len, "%s", src);
    ```

    Like `snprintf(3)`, the `strlcpy()` and `strlcat()` functions return the total length of the string they tried to create. For `strlcpy()` that means the length of `src`. For `strlcat()` that means the initial length of `dst` plus the length of `src`.

    If the return value is >= `dstsize`, the output string has been truncated. It is the caller's responsibility to handle this.

  - 설명
    - `dst`의 맨 뒤에 `src`를 `dstsize`만큼 붙이는 함수
    - `dstsize ≤ (dst 길이)`
      - 문자열을 붙이지 않음
      - 리턴값: `strlen(src) + dstsize`
    - `dstsize > (dst 길이)`
      - size - 1만큼 `src`를 붙이고 마지막에 `\0` 값을 넣어줌
      - 리턴값: `strlen(src) + strlen(dst)`
</details>

<details>
  <summary>ft_strlcpy</summary>

  - Man page

    **SYNOPSIS**
    ```c
    #include <string.h>
    
    size_t
    strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
    ```

    **DESCRIPTION**
    The `strlcpy()` and `strlcat()` functions copy and concatenate strings with the same input parameters and output result as `snprintf(3)`. They are designed to be safer, more consistent, and less error-prone replacements for the easily misused functions `strncpy(3)` and `strncat(3)`.

    `strlcpy()` and `strlcat()` take the full size of the destination buffer and guarantee NUL-termination if there is room. Note that room for the NULL should be included in `dstsize`.

    `strlcpy()` copies up to `dstsize - 1` characters from the string `src` to `dst`, NUL-terminating the result if `dstsize` is not 0.

    **RETURN VALUES**
    Besides quibbles over the return type (size_t versus int) and signal handler safety (`snprintf(3)` is not entirely safe on some systems), the following two are equivalent:
    ```c
    n = strlcpy(dst, src, len);
    n = snprintf(dst, len, "%s", src);
    ```

    Like `snprintf(3)`, the `strlcpy()` and `strlcat()` functions return the total length of the string they tried to create. For `strlcpy()` that means the length of `src`. For `strlcat()` that means the initial length of `dst` plus the length of `src`.

    If the return value is >= `dstsize`, the output string has been truncated. It is the caller's responsibility to handle this.

  - 설명
    - `dst` 안에 `src`를 복사해주는 함수
    - `dstsize`: `src`의 길이 이하일 때 사용됨
    - `src`의 `\0` 값을 만나거나 `dstsize - 1` 만큼 복사되면 복사를 중지한다.
    - `-1` 이 붙은 이유: 복사를 진행한 후 마지막에 `\0` 을 넣어주기 위해서 ⇒ `strcpy` 나 `strncpy` 보다 안정성이 있다.
    - 리턴값: 복사하려했던 문자열의 길이 = `src` 의 길이
</details>

<details>
  <summary>ft_strncmp</summary>

  - Man page

    **SYNOPSIS**
    ```c
    #include <string.h>
    
    int
    strncmp(const char *s1, const char *s2, size_t n);
    ```

    **DESCRIPTION**
    The `strcmp()` and `strncmp()` functions lexicographically compare the null-terminated strings `s1` and `s2`. The `strncmp()` function compares not more than `n` characters. Because `strncmp()` is designed for comparing strings rather than binary data, characters that appear after a `\0` character are not compared.

    **RETURN VALUES**
    The `strcmp()` and `strncmp()` functions return an integer greater than, equal to, or less than 0, according as the string `s1` is greater than, equal to, or less than the string `s2`. The comparison is done using unsigned characters, so that `\200` is greater than `\0`.

  - 설명
    - `s1`, `s2` 두 문자열의 내용을 1바이트씩 unsigned char로 크고 작음을 비교하는 함수
    - `n` : 검사할 범위
    - 리턴값
      - 계속 비교하다가 두 문자열이 다르다면 ⇒ `s1 - s2` 리턴
      - 두 문자열이 완전히 같다면 ⇒ 0 리턴
</details>

<details>
  <summary>ft_strrchr</summary>

  - Man page

    **SYNOPSIS**
    ```c
    #include <string.h>
    
    char *
    strrchr(const char *s, int c);
    ```

    **DESCRIPTION**
    The `strchr()` function locates the first occurrence of `c` (converted to a char) in the string pointed to by `s`. The terminating null character is considered to be part of the string; therefore if `c` is `\0`, the function locates the terminating `\0`. The `strrchr()` function is identical to `strchr()`, except it locates the last occurrence of `c`.

    **RETURN VALUES**
    The functions `strchr()` and `strrchr()` return a pointer to the located character, or `NULL` if the character does not appear in the string.

  - 설명
    `s` 문자열 처음부터 `c` 와 같은 문자를 찾을때까지 루프를 돈다 만약 문자를 찾으면 현재 포인터의 위치를 반환
</details>

<details>
  <summary>ft_tolower</summary>

  - Man page

    **SYNOPSIS**
    ```c
    #include <ctype.h>
    
    int
    tolower(int c);
    ```

    **DESCRIPTION**
    The `tolower()` function converts an upper-case letter to the corresponding lower-case letter. The argument must be representable as an unsigned char or the value of `EOF`. Although the `tolower()` function uses the current locale, the `tolower_l()` function may be passed a locale directly. See `xlocale(3)` for more information.

    **RETURN VALUES**
    If the argument is an upper-case letter, the `tolower()` function returns the corresponding lower-case letter if there is one; otherwise, the argument is returned unchanged.
</details>
<details>
  <summary>ft_toupper</summary>
  
  - Man page
    **SYNOPSIS**
    #include <ctype.h>
    ```c
     int
     toupper(int c);
    ```
    **DESCRIPTION**
    The toupper() function converts a lower-case letter to the corresponding upper-case letter. The argument must be representable as
    an unsigned char or the value of EOF.
    Although the toupper() function uses the current locale, the toupper_l() function may be passed a locale directly. See xlocale(3)
    for more information.
    **RETURN VALUES**
    If the argument is a lower-case letter, the toupper() function returns the corresponding upper-case letter if there is one; other-
    wise, the argument is returned unchanged.
</details>
<details>
  <summary>ft_atoi</summary>

  - **Man page**

    **SYNOPSIS**
    ```c
    #include <stdlib.h>
    
    int
    atoi(const char *str);
    ```

    **DESCRIPTION**
    The `atoi()` function converts the initial portion of the string pointed to by `str` to `int` representation. It is equivalent to: `(int)strtol(str, (char **)NULL, 10)`. While the `atoi()` function uses the current locale, the `atoi_l()` function may be passed a locale directly. See `xlocale(3)` for more information.

  - **설명**
    - 문자열을 숫자로 바꿔주는 함수
    - 공백(whitespace)을 모두 지나치고 '-' 또는 '+'로 부호를 판별한 후 숫자('0' ~ '9')가 아닌 값이 나올 때까지 숫자로 바꿔준다.
    - **리턴값:** 변환된 숫자
    - long형을 넘어서는 값
      - 오버플로우(long max 초과) ⇒ long max, 즉 -1 리턴
      - 언더플로우(long min 이하) ⇒ long min, 즉 0 리턴
</details>
<details>
  <summary>ft_calloc</summary>

  - **Man page**

    **SYNOPSIS**
    ```c
    #include <stdlib.h>
    
    void *
    calloc(size_t count, size_t size);
    ```

    **DESCRIPTION**
    The `malloc()`, `calloc()`, `valloc()`, `realloc()`, and `reallocf()` functions allocate memory. The allocated memory is aligned such that it can be used for any data type, including AltiVec- and SSE-related types. The `aligned_alloc()` function allocates memory with the requested alignment. The `free()` function frees allocations that were created via the preceding allocation functions.

    **RETURN VALUES**
    If successful, `calloc()`, `malloc()`, `realloc()`, `reallocf()`, `valloc()`, and `aligned_alloc()` functions return a pointer to allocated memory. If there is an error, they return a `NULL` pointer and set `errno` to `ENOMEM`.
</details>

<details>
  <summary>ft_bzero</summary>

  - **Man page**

    **SYNOPSIS**
    ```c
    #include <strings.h>
    
    void
    bzero(void *s, size_t n);
    ```

    **DESCRIPTION**
    The `bzero()` function writes `n` zeroed bytes to the string `s`. If `n` is zero, `bzero()` does nothing.
</details>

<details>
  <summary>ft_isalnum</summary>

  - **Man page**

    **SYNOPSIS**
    ```c
    #include <ctype.h>
    
    int
    isalnum(int c);
    ```

    **DESCRIPTION**
    The `isalnum()` function tests for any character for which `isalpha(3)` or `isdigit(3)` is true. The value of the argument must be representable as an unsigned char or the value of `EOF`.

    **RETURN VALUES**
    The `isalnum()` function returns zero if the character tests false and returns non-zero if the character tests true.
</details>

<details>
  <summary>ft_isalpha</summary>

  - **Man page**

    **SYNOPSIS**
    ```c
    #include <ctype.h>
    
    int
    isalpha(int c);
    ```

    **DESCRIPTION**
    The `isalpha()` function tests for any character for which `isupper(3)` or `islower(3)` is true. The value of the argument must be representable as an unsigned char or the value of `EOF`.
</details>

<details>
  <summary>ft_isascii</summary>

  - **Man page**

    **SYNOPSIS**
    ```c
    #include <ctype.h>
    
    int
    isascii(int c);
    ```

    **DESCRIPTION**
    The `isascii()` function tests for an ASCII character, which is any character between 0 and octal 0177 inclusive.
</details>

<details>
  <summary>ft_isdigit</summary>

  - **Man page**

    **SYNOPSIS**
    ```c
    #include <ctype.h>
    
    int
    isdigit(int c);
    ```

    **DESCRIPTION**
    The `isdigit()` function tests for a decimal digit character.

    **RETURN VALUES**
    The `isdigit()` and `isnumber()` functions return zero if the character tests false and return non-zero if the character tests true.
</details>

<details>
  <summary>ft_isprint</summary>

  - **Man page**

    **SYNOPSIS**
    ```c
    #include <ctype.h>
    
    int
    isprint(int c);
    ```

    **DESCRIPTION**
    The `isprint()` function tests for any printing character, including space (`' '`). The value of the argument must be representable as an unsigned char or the value of `EOF`.

    **RETURN VALUES**
    The `isprint()` function returns zero if the character tests false and returns non-zero if the character tests true.
</details>

<details>
  <summary>ft_memchr</summary>

  - **Man page**

    **SYNOPSIS**
    ```c
    #include <string.h>
    
    void *
    memchr(const void *s, int c, size_t n);
    ```

    **DESCRIPTION**
    The `memchr()` function locates the first occurrence of `c` (converted to an unsigned char) in string `s`.

    **RETURN VALUES**
    The `memchr()` function returns a pointer to the byte located, or `NULL` if no such byte exists within `n` bytes.

    - **설명**
      메모리 블럭 안에서 원하는 문자를 바이트 단위로 찾는 함수.
      `ptr` 이 가리키는 메모리와 처음 `len` 바이트 중에서 처음으로 `c` 와 일치하는 값의 주소를 반환하다.
      - `c`: int 로 값이 전달되지만 함수 내부적으로는 한 바이트씩 비교하기 때문에 이 값은 unsigned char로 변환되어서 사용된다.
      - c가 존재 ⇒ `(unsigned char *)` 해당 포인터를 리턴
      - 없다면 ⇒ `NULL` 리턴
</details>

<details>
  <summary>ft_memcmp</summary>

  - **Man page**

    **SYNOPSIS**
    ```c
    #include <string.h>
    
    int
    memcmp(const void *s1, const void *s2, size_t n);
    ```

    **DESCRIPTION**
    The `memcmp()` function compares byte string `s1` against byte string `s2`. Both strings are assumed to be `n` bytes long.

    **RETURN VALUES**
    The `memcmp()` function returns zero if the two strings are identical, otherwise returns the difference between the first two differing bytes (treated as unsigned char values, so that `\200` is greater than `\0`, for example). Zero-length strings are always identical. This behavior is not required by C and portable code should only depend on the sign of the returned value.

    - **설명**
      Memory + compare. 비교하는 함수
      `s1` 와 `s2` 의 내용을 `len` 만큼 비교하는 함수.
      - 내용이 같다면 ⇒ 0
      - 내용이 다르다면 ⇒ unsigned char형으로 `*s1 - *s2` 만큼 리턴
</details>

<details>
  <summary>ft_memcpy</summary>

  - **Man page**

    **SYNOPSIS**
    ```c
    #include <string.h>
    
    void *
    memcpy(void *restrict dst, const void *restrict src, size_t n);
    ```

    **DESCRIPTION**
    The `memcpy()` function copies `n` bytes from memory area `src` to memory area `dst`. If `dst` and `src` overlap, behavior is undefined.
    Applications in which `dst` and `src` might overlap should use `memmove(3)` instead.

    **RETURN VALUES**
    The `memcpy()` function returns the original value of `dst`.

    - **설명**
      원본인 `src` 를 `n` 만큼의 길이만큼 복사해서 `dest` 에 붙여넣는 함수
      메모리 값을 복사하는 함수
      - 주의할점 : `char *` 타입의 c언어 문자열 형태의 문자열의 전체를 복사할 때 `\0` 도 넣어야 하기 때문에 +1만큼 더해주어야 한다.
      - `src` 의 메모리 블록과 `dest` 의 메모리 블록이 겹쳐져 있는 곳에는 사용하지 못한다. 만약 필요하다면 `memmove` 함수를 사용해야 한다.
</details>

<details>
  <summary>ft_memmove</summary>

  - **Man page**

    **SYNOPSIS**
    ```c
    #include <string.h>
    
    void *
    memmove(void *dst, const void *src, size_t len);
    ```

    **DESCRIPTION**
    The `memmove()` function copies `len` bytes from string `src` to string `dst`.
    The two strings may overlap; the copy is always done in a non-destructive manner.

    **RETURN VALUES**
    The `memmove()` function returns the original value of `dst`.

    - **설명**
      `src` 가 가리키는 메모리부터 `n` 바이트 사이즈 만큼 `dest` 가 가리키는 메모리에 옮김.
      move라서 잘라내서 붙이는 게 아닌 복사의 개념이다.
      - `memcpy` 와 `memmove`의 차이점:
        `memcpy`는 어디에 거치지 않고 그 위치에 복사해서 붙여넣는 반면
        `memmove`는 안전하게 복사할 것을 버퍼에 복사하고 해당 위치에 가서 버퍼된 것을 붙여넣는 방식으로 동작 구현
        `memmove`는 버퍼를 이용하기 때문에 좀 더 안정성이 뛰어남
</details>

<details>
  <summary>ft_memset</summary>

  - **Man page**

    **SYNOPSIS**
    ```c
    #include <string.h>
    
    void *
    memset(void *b, int c, size_t len);
    ```

    **DESCRIPTION**
    The `memset()` function writes `len` bytes of value `c` (converted to an unsigned char) to the string `b`.

    **RETURN VALUES**
    The `memset()` function returns its first argument.

    - **설명**
      `b`를 `len`만큼 `ptr`로 초기화하는 함수
      - `b`: 메모리를 세팅하고자 하는 값 (int로 받지만 내부에서는 unsigned char로 변환)
      - `ptr`: 세팅하고자 하는 메모리의 시작 주소 (주소가 가리키고 있는 포인터가 위치한 자리)
      - `len`: 길이 (바이트 단위로서 메모리 크기 한 조각 단위의 길이)
      - 반환값: 성공하면 `void *ptr` 실패하면 `NULL`  
</details>

# Part 2 - Additional functions

<details>
  <summary>ft_substr</summary>

  - **man page**

    Allocates (with `malloc(3)`) and returns a substring from the string 's'.
    The substring begins at index 'start' and is of maximum size 'len'.

  - **함수 설명**
    부분 문자열을 가져오는 함수.
    `malloc(3)`을 사용하여 할당하고 원본 문자열 `str`에서 하위 문자열을 반환, 하위 문자열은 `start` 인덱스에서 시작되며 최대 크기는 `len` 이다.
</details>

<details>
  <summary>ft_strjoin</summary>

  - **man page**

    Allocates (with `malloc(3)`) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.

  - **함수설명**
    원하는 만큼 문자열을 합칠 수 있는 함수.
    `malloc`을 할당하고 새 문자열을 반환하며, 이는 접두사 문자열 `s1`, 접미사 문자열 `s2`를 연결한 결과물.
    - 반환값: 이어붙인 새 문자열, 실패 시 `NULL` 반환.
</details>

<details>
  <summary>ft_strtrim</summary>

  - **man page**

    Allocates (with `malloc(3)`) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.

  - **함수설명**
    `malloc`을 사용하여 할당하고 문자열의 처음과 끝에서 `set`에 지정된 문자가 제거된 `s1` 복사본을 반환.
    원본 문자열 `s1`.
    - 반환값: `s1`에서 찾은 `set`에 포함된 문자들을 양 끝에서 제거한 후 결과 문자열, 할당 실패 시 `NULL` 반환.
</details>

<details>
  <summary>ft_split</summary>

  - **man page**

    Allocates (with `malloc(3)`) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter.
    The array must be ended by a NULL pointer.
</details>

<details>
  <summary>ft_itoa</summary>

  - **man page**

    Allocates (with `malloc(3)`) and returns a string representing the integer received as an argument.
    Negative numbers must be handled.

  - **함수설명**
    `int`형의 숫자를 `str`형으로 변환해주는 함수
    `malloc`을 사용하여 할당하고 인수로 받은 정수를 나타내는 문자열을 반환한다. 음수는 반드시 처리해야 한다.
    `'0' + (n % 10)` 식으로 나머지를 구한 뒤 문자 아스키 코드로 변환해 배열의 뒷 부분 부터 채워준다.
    정수의 길이를 잴 때는 몫 나머지 연산을 사용한다. 몫이 0이 될 때 까지, 그리고 음수일 경우에는 ‘-’ 부호가 들어가야 하기 때문에 `len`에 +1을 해준다.
    - 반환값: 정수를 나타내는 문자열, 할당 실패시 `null`로 반환.
</details>

<details>
  <summary>ft_strmapi</summary>

  - **man page**

    Applies the function ’f’ to each character of the string ’s’, and passing its index as the first argument to create a new string (with `malloc(3)`) resulting from successive applications of ’f’.

  - **함수설명**
    인자로 받은 문자열 `str`의 각 요소에 `f` 함수를 적용한 값들로 새로운 하나의 문자열을 만들고 문자열의 주소값을 반환하는 함수.
    일차원 배열을 먼저 할당하고 그 배열에 `str`의 요소들에 `f` 함수를 적용한 것을 차례대로 넣는다.
    만든 문자열의 가장 끝에는 `\0` 문자가 들어 있어야 한다.
    - 반환값: 할당 실패시 `null` 반환한다.
</details>

<details>
  <summary>ft_striteri</summary>

  - **man page**

    Applies the function `f` to each character of the string `s`, and passing its index as the first argument.
    Each character is passed by address to `f` to be modified if necessary.
</details>

<details>
  <summary>ft_putchar_fd</summary>

  - **man page**

    Outputs the character ’c’ to the given file descriptor.

  - **함수설명**
    - `void` 함수에 return ?
      `open()` 함수는 다음과 같이 사용하기 때문에, `fd=open("data.txt", O_RDONLY)` 파일 오픈에 실패하면 file descriptor는 음수값을 갖게 된다.
      이때 함수의 종결을 의미하는 `return ;` 사용한다.
</details>

<details>
  <summary>ft_putstr_fd</summary>

  - **man page**

    Outputs the string ’s’ to the given file descriptor.
</details>

<details>
  <summary>ft_putendl_fd</summary>

  - **man page**

    Outputs the string ’s’ to the given file descriptor, followed by a newline.
</details>

<details>
  <summary>ft_putnbr_fd</summary>

  - **man page**

    Outputs the integer ’n’ to the given file descriptor.
</details>


# bonus part

- 참조
  **메모리와 문자열을 조작하는 함수를 갖는 것은 매우 유용하지만 목록을 조작하는 함수를 갖는 것이 훨씬 더 유용하다는 것을 곧 알게 될 것이다.**
  **make 보너스는 libft.a 라이브러리에 보너스 함수를 추가합니다.**
  **다음 구조를 사용하여 목록의 요소를 나타냅니다. 이 구조를 libft.h 파일에 추가해야 합니다.**

  ```c
  typedef struct s_list
  {
  		void *content;
  		struct s_list *next;
  }             t_list;
  ```

  **다음은 t_list 구조체의 필드에 대한 설명입니다.**

  - _content : 데이터는 요소에 포함되어 있습니다. void 는 데이터의 모든 종류를 저장할 수 있습니다. • next : 다음 요소의 주소 혹은 마지막 요소인 경우엔 NULL._
    <aside>
    💡 연결리스트

    </aside>
    
    ![Untitled 2](https://github.com/mantoing/libft/assets/90916425/373dccb9-a2d5-424a-9c2f-a38aa439032f)

                                                             연결리스트의 기본 구조

    먼저 구조체로 “노드"의 틀을 만든다.
    노드에는 데이터가 들어갈 데이터의 변수와 다음 노드를 가리킬 포인터 변수가 있어야 한다.
    데이터 변수에는 어떠한 자료형이어도 상관없다.
    typedef으로 구조체의 별칭을 Node로 정해둔다.
    연결리스트의 맨 앞 노드는 head라 부르며 head는 첫번째 노드를 가리키고 있어야 한다.
    ( = 첫번째 노드의 주소를 가지고 있어야 함.)
    위와 같이 head를 선언한 것을 그림으로 그리면 아래와 같다.

    ![Untitled](https://github.com/mantoing/libft/assets/90916425/3078c2cf-9d28-4f32-8b57-e4c3cfa2aa06)


<details>
  <summary>ft_lstnew</summary>
  
  - **man page**
    
    **Prototype**: `t_list *ft_lstnew(void *content);`
    
    **Parameters:** `#1. The content to create the new element with.`
    
    **Return value:** The new element.
    
    **External functs.**: `malloc`
    
    **Description:** Allocates (with `malloc(3)`) and returns a new element. The variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL.
    
    `(malloc(3)을 사용하여) 할당하고 새 요소를 반환합니다. 'content' 변수는 'content' 매개변수의 값으로 초기화됩니다. 변수 'next'는 NULL로 초기화됩니다.`
    
  - **함수설명**
    
    그냥 새 노드만 만드는 함수. 연결은 하지 않는다.
</details>

<details>
  <summary>ft_lstadd_front</summary>
  
  - **man page**
    
    **Prototype**: `void ft_lstadd_front(t_list **lst, t_list *new);`
    
    **Parameters:** 
    - `#1. The address of a pointer to the first link of a list.`
    - `#2. The address of a pointer to the element to be added to the list.`
    
    **Return value:** None
    
    **External functs**: None
    
    **Description:** Adds the element ’new’ at the beginning of the list.
    
    `리스트의 시작 부분에 new를 추가한다.`
    
    1. 새 노드의 다음 주소를 head로 설정
    2. head를 새 노드로 설정
    
    - ft_lstadd_front의 함수 코드는 아래와 같다.
      맨 앞쪽에 리스트를 만들어 추가하므로 다음 주소값만 담는 것이 아니라 시작 지점도 알아야 한다는 것이 중요하다.
      ft_lstadd_front함수는 리턴 값이 없다. 따라서 마지막에 *lst = new를 통해서 헤더가 첫 노드를 잡을 수 있게 한다.
      이 작업을 위해 이중포인터 파라미터를 갖는다.
      첫 번째 매개변수 \*\*lst는 첫 번째 노드의 포인터다. 이중포인터 인것은 *lst에 저장되는 값이 연결된 리스트들의 첫 값을 담고 있기 때문이다.
    
    ## 1. **연결리스트 구현시 이중 포인터를 사용하는 이유**
    
    - 단일 연결 리스트에서 삽입과 삭제를 통해 head 포인터의 값을 변화시킬 수 있다.
    - 이때, 호출함수의 포인터변수가 참조하는 객체를 피호출 함수에서 바꾸고자 할 경우 이중 포인터를 사용하면 된다.
    - `t_list **lst` 는 t_list 포인터(lst)의 주소를 가리키는 포인터다.
    - `t_list **lst` 변수가 담고 있는 값은 `t_list *`의 주소.
    - `t_list **lst` 가 담고 있는 `t_list *` 의 주소는 어떤 리스트의 첫번째 주소
    - 즉, \*lst는 head의 주소
    
    ## 2.\*lst == NULL 과 lst == NULL의 차이
    
    - lst는 lst의 첫번째 주소, 즉 헤드의 주소를 의마한다. 헤드가 비었다는 건, \*lst는 빈 리스트 라는 뜻
    - lst == NULL은 리스트 자체가 존재하지 않는다는 뜻
    
  - **함수 설명**
    
    리스트의 시작 부분에 `new` 를 추가한다.
</details>

<details>
  <summary>ft_lstsize</summary>
  
  - **man page**
    
    **Prototype**: `int ft_lstsize(t_list *lst);`
    
    **Parameters:** `#1. The beginning of the list.`
    
    **Return value:** Length of the list.
    
    **External functs.:** None
    
    **Description:** Counts the number of elements in a list.
    
    리스트의 요소의 개수를 카운트한다.
</details>

<details>
  <summary>ft_lstlast</summary>
  
  - **man page**
    
    **Prototype**: `t_list *ft_lstlast(t_list *lst);`
    
    **Parameters:** `#1. The beginning of the list.`
    
    **Return value:** Last element of the list.
    
    **External functs.:** None
    
    **Description:** Returns the last element of the list.
    
    리스트의 마지막 주소를 리턴.
</details>

<details>
  <summary>ft_lstadd_back</summary>
  
  - **man page**
    
    **Prototype**: `void ft_lstadd_back(t_list **lst, t_list *new);`
    
    **Parameters:** 
    - `#1. The address of a pointer to the first link of a list.`
    - `#2. The address of a pointer to the element to be added to the list.`
    
    **Return value:** None
    
    **External functs.:** None
    
    **Description:** Adds the element ’new’ at the end of the list.
    
    리스트의 끝에 new를 추가한다.
    
    - 함수 설명
      ![Untitled 1](https://github.com/mantoing/libft/assets/90916425/09a1adf6-d060-46e4-be22-549faf4f34b1)

      “리스트의 마지막에 새 노드를 추가하는 함수”
      1. new의 다음 주소는 원래 last의 다음주소 (=NULL)로 설정
      2. last의 다음 주소가 new를 가리키도록 변경
    
    - ft_islast(); 함수의 인자로 lst를 보내야 하는지 \*lst를 보내야하는지 헷갈림.
    - lstlast함수는 파라미터로 `t_list *` 즉, 첫 번째 요소의 주소를 받는다.
    - `ft_lstadd_back` 함수에서 우리가 받은 인자의 자료형은 t*list *이고 , (t*list *)= t_list 이기 때문에 \*lst를 인자로 보내면 된다.
    - `*lst ==NULL` 과 `lst == NULL` 의 파이
    - lst는 lst의 첫번째 주소, 즉 헤드의 주소를 의마한다. 헤드가 비었다는건, lst는 빈 리스트 라는 뜻
      -lst == NULL은 리스트 자체가 존재하지 않는다는 뜻이다.
</details>

<details>
  <summary>ft_lstdelone</summary>
  
  - **man page**
    
    **Prototype**: `void ft_lstdelone(t_list *lst, void (*del)(void*));`
    
    **Parameters:** 
    - `#1. The element to free.`
    - `#2. The address of the function used to delete the content.`
    
    **Return value:** None
    
    **External functs.:** `free`
    
    **Description:** Takes as a parameter an element and frees the memory of the element’s content using the function ’del’ given as a parameter and free the element. The memory of ’next’ must not be freed.
    
    lst의 content를 지워주고 free하는 함수
    
    - 함수설명
      free(lst)만 하면 안되는 이유.
      - content 변수는 주소만 담고 있어서 그 주소가 가리키는 값까지 삭제를 해줘야 하는데, free(lst)를 한 후에는 lst → content로 접근이 불가능하다. 그래서 content 를 먼저 free해주고 그 다음에 lst를 free해줘야 한다.
</details>

<details>
  <summary>ft_lstclear</summary>
  
  - **man page**
    
    **Prototype**: `void ft*lstclear. t_list **lst, void (*_del)(void*));`
    
    **Parameters:** 
    - `#1. The address of a pointer to an element.`
    - `#2. The address of the function used to delete the content of the element.`
    
    **Return value:** None
    
    **External functs.:** `free`
    
    **Description:** Deletes and frees the given element and every successor of that element, using the function ’del’ and `free(3)`. Finally, the pointer to the list must be set to NULL.
    
    연결 리스트 전체 노드 데이터를 삭제하는 함수.
    
    - 함수 설명
      - lst가 NULL이면 리스트가 존재하지 않는가는 뜻. 이 때에는 삭제할 리스트가 없는 것이므로 `return;`
      - content와 노드를 삭제할 때, free(lst)한 이후 lst는 그 다음 노드를 가리킬 수 없으므로 그 다음 노드의 주소를 `t_list포린터에 저장해 놓아야 한다.`
</details>

<details>
  <summary>ft_lstiter</summary>
  
  - **man page**
    
    **Prototype**: `void ft_lstiter(t_list *lst, void (*f)(void *));`
    
    **Parameters:** 
    - `#1. The address of a pointer to an element.`
    - `#2. The address of the function used to iterate on the list.`
    
    **Return value:** None
    
    **External functs.:** None
    
    **Description:** Iterates the list ’lst’ and applies the function ’f’ to the content of each element.
    
    리스트 `lst` 를 반복하고 각 요소의 내용에 함수 `f` 를 적용한다.
</details>

<details>
  <summary>ft_lstmap</summary>
  
  - **man page**
    
    **Prototype**: `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));`
    
    **Parameters:** 
    - `#1. The address of a pointer to an element.`
    - `#2. The address of the function used to iterate on the list.`
    - `#3. The address of the function used to delete the content of an element if needed.`
    
    - `t_list *lst : t_list 포인터`
    - `void *(*f)(void *) : lst의 content에 적용할 함수 포인터`
    - `void *(del)(void *) : lst의 content를 free하기 위한 함수 포인터`
    
    **Return value:** The new list. `NULL if the allocation fails.`
    
    **External functs.:** `malloc`, `free`
    
    **Description:** Iterates the list ’lst’ and applies the function ’f’ to the content of each element. Creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of an element if needed.
    
    리스트 'lst'를 반복하고 각 요소의 내용에 함수 'f'를 적용합니다.
    함수 'f'의 연속 적용 결과로 새 리스트를 만듭니다.
    'del' 함수는 필요한 경우 요소의 내용을 삭제하는 데 사용됩니다.
    
    `ft_lstmap`은 연결리스트 lst의 content를 함수 f로 보내서 `바뀐 값을 content로 갖고있는 새로운 연결리스트`를 만들어서 리턴해주는 함수이다.
    만약 새로운 연결리스트를 만들다 노드 할당이 실패하면 여태까지 만든 새로운 연결리스트를 모두 할당 해제해준다.
</details>

# Makefile

make : library 함수와 additional 함수에 대해서만 컴파일 후 해당 오브젝트를 아카이브에 포함

make bonus : bonus를 포함한 모든 함수들을 컴파일 후 해당 오브젝트를 아카이브에 포함(relink 방지)

make clean : 컴파일 후 생성된 오브젝트들 삭제
make flcean : 컴파일 후 생성된 오브젝트와 make를 통해 생된 아카이브 또한 삭제

make re : fcelan 작업 후 다시 make

과제에는 명시된 파일 이외의 파일이 포함될 수 없으므로 .PHONY의 필요성을 느끼지 못해 사용하지 않음

```c
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rc
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
SRC_BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c ft_lstnew.c ft_lstsize.c \
		   	ft_lstiter.c ft_lstclear.c ft_lstmap.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
RM = /bin/rm -f

ifdef WITH_B
	OBJECTS = $(OBJ) $(OBJ_BONUS)
else
	OBJECTS = $(OBJ)
endif

all: $(NAME)

.c.o: $(SRC) $(SRC_BONUS)
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJECTS)
	$(AR) $@ $(OBJECTS)

bonus:
	@make WITH_B=1 all

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re:	fclean all
```

### **참고**

## C 프로그래밍 개념

<details>
  <summary>size_t</summary>
	
  `size_t`은 문자열이나 메모리의 크기를 나타내는 데 사용되는 부호 없는 정수입니다. `typedef unsigned int size_t;`로 정의되며 부호 없는 정수를 나타냅니다. 32비트 OS에서는 "부호 없는 32비트 정수"이며, 64비트 OS에서는 "부호 없는 64비트 정수"입니다. 64비트 OS에서도 "unsigned int"나 "int"는 반드시 64비트 정수가 아닐 수 있지만, `size_t`은 메모리나 문자열의 길이를 다룰 때 올바른 크기를 보장합니다.
</details>

<details>
  <summary>포인터 연산시 unsigned char 사용 이유</summary>
	
  포인터 연산시 `unsigned char` 사용이 권장됩니다. GCC에서는 void 포인터가 `char` 또는 `unsigned char` 크기만큼 연산됩니다(1바이트 씩). 포인터는 주소 연산이기 때문에 부호를 사용하지 않습니다. `unsigned char`를 사용하는 것이 `char`보다 적절합니다.
</details>

<details>
  <summary>restrict 키워드</summary>
	
  `restrict` 키워드는 메모리 접근과 관련된 최적화 기능입니다. 각 포인터가 서로 다른 메모리 위치를 가리키고 있고 다른 곳에서 접근하지 않음을 컴파일러에 알려 최적화할 수 있도록 합니다. 동일한 메모리 공간을 가리키는 포인터에 `restrict`를 사용하면 최적화로 인해 잘못된 결과가 나올 수 있으므로 주의가 필요합니다.
</details>

<details>
  <summary>memcpy와 memmove의 차이</summary>
	
  - `memcpy`는 `restrict`가 있고 `memmove`는 `restrict`가 없습니다. `memmove`는 메모리가 겹치는지 여부를 확인하므로 성능이 떨어집니다. 두 메모리 공간이 다르고 겹치지 않는 경우 최적화된 `memcpy`를 사용하면 성능을 향상시킬 수 있습니다.
  - `memcpy`는 메모리 내용을 직접 복사하고, `memmove`는 메모리 내용을 임시 저장소에 저장한 후 복사합니다. 따라서 `memcpy`의 속도는 `memmove`보다 빠르지만 안정성 면에서는 떨어집니다. 메모리를 복사할 때 `memcpy`는 자기 자신의 내용을 덮어쓸 때 이웃한 메모리에 의한 겹침 문제가 발생합니다.
</details>

<details>
  <summary>strncpy와 memcpy의 차이</summary>
	
  - `strncpy`는 문자열의 끝(0x00)을 만나면 중지되지만 `memcpy`는 바이트 단위로 계산되어 바이트가 끝날 때까지 계속 복사합니다.
  - 즉, `memcpy`는 형에 관계없이 지정된 바이트 수만큼 임의의 영역을 복사합니다.
</details>

<details>
  <summary>const와 *(포인터) 위치에 따른 차이</summary>
	
  - 상수 포인터 → `const int *ptr = &a;` 또는 `int const *ptr = &a;`
	
    ```c
    // ptr이 가리키는 주소의 값 변경 불가
    *ptr = 30; // 오류
    ptr = &b; // 허용
    ```
  - 포인터 상수 → `int *const ptr = &a;`
	
    ```c
    // ptr이 가리키는 주소 변경 불가
    *ptr = 40; // 허용
    ptr = &b; // 오류
    ```
  - 상수 포인터 상수 → `const int *const ptr = &a;`
	
    ```c
    // ptr이 가리키는 주소와 주소의 값 변경 불가
    *ptr = 50; // 오류
    ptr = &b; // 오류
    ```
 ![Untitled 3](https://github.com/mantoing/libft/assets/90916425/c3736ac0-4695-4853-8571-7563dbd99f1b)
</details>

<details>
  <summary>void 포인터</summary>
	
  `void` 포인터는 대상 데이터의 타입을 명시하지 않는 포인터로, 변수, 함수, 포인터 등 어떠한 값도 가리킬 수 있습니다. 그러나 포인터 연산이나 메모리 참조와 같은 작업은 수행할 수 없으며, `void` 포인터를 사용할 때는 반드시 명시적 타입 변환을 거친 후 사용해야 합니다.
</details>
