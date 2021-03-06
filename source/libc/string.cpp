// Copyright (C) 2022  ilobilo

#include <cstddef>
#include <cstdint>

extern "C"
{
    void *memchr(const void *ptr, int ch, size_t len)
    {
        const uint8_t *src = static_cast<const uint8_t*>(ptr);

        while (len-- > 0)
        {
            if (*src == ch) return const_cast<uint8_t*>(src);
            src++;
        }

        return nullptr;
    }

    size_t strlen(const char *str)
    {
        if (str == nullptr) return 0;
        size_t length = 0;
        while(str[length]) length++;
        return length;
    }

    char *strcat(char *dest, const char *src)
    {
        if (dest == nullptr) return nullptr;
        char *ptr = dest + strlen(dest);
        while (*src != '\0') *ptr++ = *src++;
        *dest = '\0';
        return dest;
    }

    char *strncat(char *dest, const char *src, size_t len)
    {
        if (dest == nullptr) return nullptr;
        char* ptr = dest + strlen(dest);
        while (*src != '\0' && len--) *ptr++ = *src++;
        *dest = '\0';
        return dest;
    }

    char *strchr(const char *str, int ch)
    {
        if (str == nullptr) return nullptr;
        while (*str && *str != ch) ++str;
        return const_cast<char*>(ch == *str ? str : nullptr);
    }

    int strcmp(const char *str1, const char *str2)
    {
        while (*str1 && *str2 && *str1 == *str2)
        {
            str1++;
            str2++;
        }
        return *str1 - *str2;
    }

    int strncmp(const char *str1, const char *str2, size_t len)
    {
        while (*str1 && *str2 && *str1 == *str2 && len--)
        {
            str1++;
            str2++;
        }
        if (len == 0) return 0;
        return *str1 - *str2;
    }

    char *strcpy(char *dest, const char *src)
    {
        if (dest == nullptr) return nullptr;
        char *ptr = dest;
        while (*src != '\0')
        {
            *dest = *src;
            dest++;
            src++;
        }
        *dest = '\0';
        return ptr;
    }

    char *strncpy(char *dest, const char *src, size_t len)
    {
        if (dest == nullptr) return nullptr;
        char *ptr = dest;
        while (*src != '\0' && len--)
        {
            *dest = *src;
            dest++;
            src++;
        }
        *dest = '\0';
        return ptr;
    }

    char *strstr(const char *str, const char *substr)
    {
        const char *a = str, *b = substr;
        while (true)
        {
            if (!*b) return const_cast<char*>(str);
            if (!*a) return nullptr;
            if (*a++ != *b++)
            {
                a = ++str;
                b = substr;
            }
        }
    }

    void strrev(char *str)
    {
        char a;
        size_t len = strlen(reinterpret_cast<const char*>(str));

        for (size_t i = 0, j = len - 1; i < j; i++, j--)
        {
            a = str[i];
            str[i] = str[j];
            str[j] = a;
        }
    }
} // extern "C"