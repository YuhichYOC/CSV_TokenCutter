/*
 *
 * CSV_TokenCutter.c
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

#include "include/Char_At.h"

#include "CSV_TokenCutter.h"

void csv_tokenCutter_extend(CSV_TokenCutter *);
int csv_tokenCutter_seek(CSV_TokenCutter *);

void csv_tokenCutter_setRowSize(CSV_TokenCutter * t, int s) {
    t->size = s;
}

void csv_tokenCutter_set(CSV_TokenCutter * t, char * arg) {
    t->in = arg;
}

CSV_TokenCutter * csv_tokenCutter_cut(CSV_TokenCutter * t) {
    int l = csv_tokenCutter_seek(t);
    if (-1 == l) {
        return t;
    }
    csv_tokenCutter_extend(t);
    if (NULL == t->out) {
        return t;
    }
    errno = 0;
    t->out[t->c] = (char *) malloc((size_t) l);
    if (NULL == t->out[t->c]) {
        return t;
    }
    for (int i = 0; l > i; ++i) {
        t->out[t->c][i] = 0;
    }
    for (int j = 0; l > j; ++j) {
        t->out[t->c][j] = t->in[j];
    }
    ++t->c;
    return t;
}

CSV_TokenCutter * csv_tokenCutter_skip(CSV_TokenCutter * t, int offset) {
    int l = csv_tokenCutter_seek(t);
    if (-1 == l) {
        return t;
    }
    int size = (int) strlen(t->in);
    for (int i = (l + offset); size > i; ++i) {
        t->in[i - (l + offset)] = t->in[i];
    }
    for (int j = size - (l + offset); size > j; ++j) {
        t->in[j] = 0;
    }
    return t;
}

char * csv_tokenCutter_get(CSV_TokenCutter * t, int i) {
    return t->out[i];
}

void csv_tokenCutter_dispose(CSV_TokenCutter * t) {
    errno = 0;
    for (int i = 0; t->c - 1 > i; ++i) {
        free(t->out[i]);
    }
    free(t->out);
    free(t);
}

CSV_TokenCutter * CSV_TokenCutter_init(CSV_TokenCutter * t) {
    t->c = 0;
    t->setRowSize = csv_tokenCutter_setRowSize;
    t->set = csv_tokenCutter_set;
    t->cut = csv_tokenCutter_cut;
    t->skip = csv_tokenCutter_skip;
    t->get = csv_tokenCutter_get;
    t->dispose = csv_tokenCutter_dispose;
    return t;
}

void csv_tokenCutter_extend(CSV_TokenCutter * t) {
    errno = 0;
    if (0 == t->c) {
        t->out = (char **) malloc(sizeof(char *));
    }
    else {
        t->out = (char **) realloc(t->out, sizeof(char *) * (t->c + 1));
    }
}

int csv_tokenCutter_seek(CSV_TokenCutter * t) {
    errno = 0;
    Char_At * c = (Char_At *) malloc(sizeof(Char_At));
    if (NULL == c) {
        return -1;
    }
    c = Char_At_init(c);
    c->set(c, t->in);
    c->next(c, ',');
    int i = c->getEnd(c);
    if (0 <= i) {
        c->dispose(c);
    }
    else {
        c->tail(c, ',');
        i = c->getEnd(c);
        c->dispose(c);
    }
    if (0 != errno) {
        return -1;
    }
    return i;
}