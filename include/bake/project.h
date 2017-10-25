/* Copyright (c) 2010-2017 the corto developers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/** @file
 * @section project Project API
 * @brief API that exposes details about a project.
 */

#ifndef BAKE_PROJECT_H_
#define BAKE_PROJECT_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef enum bake_project_kind {
    BAKE_APPLICATION,
    BAKE_LIBRARY,
    BAKE_TOOL
} bake_project_kind;

typedef enum bake_project_attrKind {
    BAKE_ATTR_BOOLEAN,
    BAKE_ATTR_STRING,
    BAKE_ATTR_NUMBER,
    BAKE_ATTR_ARRAY
} bake_project_attrKind;

typedef struct bake_project_attr {
    char *name;
    bake_project_attrKind kind;
    union {
        bool boolean;
        char *string;
        double number;
        corto_ll array;
    } is;
} bake_project_attr;

typedef struct bake_project {
    char *id;
    bake_project_kind kind;
    corto_ll use;
    bool public;
    bool managed;
    char *path;
    corto_ll sources;
    char *includes;
    char *language;
    char *args;
    corto_ll attributes;
    bool error;

    bake_project_attr* (*get_attr)(const char *name);
    char* (*get_attr_string)(const char *name);
} bake_project;

#ifdef __cplusplus
}
#endif

#endif