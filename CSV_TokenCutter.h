/*
 *
 * CSV_TokenCutter.h
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

#ifndef DECLARE_CSV_TOKENCUTTER_H
#define DECLARE_CSV_TOKENCUTTER_H

typedef struct _csv_tokenCutter {
    int size;
    char * in;
    int c;
    char ** out;
    void (* setRowSize)(struct _csv_tokenCutter *, int);
    void (* set)(struct _csv_tokenCutter *, char *);
    struct _csv_tokenCutter * (* cut)(struct _csv_tokenCutter *);
    struct _csv_tokenCutter * (* skip)(struct _csv_tokenCutter *, int);
    char * (* get)(struct _csv_tokenCutter *, int);
    void (* dispose)(struct _csv_tokenCutter *);
} CSV_TokenCutter;

CSV_TokenCutter * CSV_TokenCutter_init(CSV_TokenCutter *);

#endif // DECLARE_CSV_TOKENCUTTER_H
