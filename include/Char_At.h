/*
 *
 * Char_At.h
 *
 * Copyright 2019 Yuichi Yoshii
 *     吉井雄一 @ 吉井産業  you.65535.kir@gmail.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef INCLUDE_STDIO_H
#define INCLUDE_STDIO_H

#include <stdio.h>

#endif // INCLUDE_STDIO_H

#ifndef INCLUDE_STDLIB_H
#define INCLUDE_STDLIB_H

#include <stdlib.h>

#endif // INCLUDE_STDLIB_H

#ifndef INCLUDE_STRING_H
#define INCLUDE_STRING_H

#include <string.h>

#endif // INCLUDE_STRING_H

#ifndef INCLUDE_ERRNO_H
#define INCLUDE_ERRNO_H

#include <errno.h>

#endif // INCLUDE_ERRNO_H

#ifndef DECLARE_CHAR_AT_H
#define DECLARE_CHAR_AT_H

typedef struct _char_at {
    char * arg;
    int size;
    int start;
    int end;
    void (* set)(struct _char_at *, char *);
    struct _char_at * (* without)(struct _char_at *, char, char *);
    struct _char_at * (* within)(struct _char_at *, char, char *);
    struct _char_at * (* next)(struct _char_at *, char);
    struct _char_at * (* tail)(struct _char_at *, char);
    struct _char_at * (* skip)(struct _char_at *, int);
    int (* getStart)(struct _char_at *);
    int (* getEnd)(struct _char_at *);
    void (* dispose)(struct _char_at *);
} Char_At;

Char_At * Char_At_init(Char_At *);

#endif // DECLARE_CHAR_AT_H
