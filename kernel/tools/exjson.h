/**
 * File:exjson.h for project exjson.
 * Author: Josin
 * Email: xeapplee@gmail.com
 * Website: https://www.supjos.cn
 */

#ifndef EXJSON_EXJSON_H
#define EXJSON_EXJSON_H

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define EX_ARRAY  2
#define EX_OBJECT 3

#define EXJSON_INT      2
#define EXJSON_DOUBLE   3
#define EXJSON_STRING   4
#define EXJSON_ARRAY    5
#define EXJSON_OBJECT   6
typedef struct _EXJSON_V
{
    char *name;
    void *value;
    unsigned char val_type;
} EXJSON_V;
#define EV_NAME(exjson_v) (exjson_v).name
#define EV_NAME_P(exjson_v) EV_NAME(*(exjson_v))
#define EV_VALUE(exjson_v) (exjson_v).value
#define EV_VALUE_P(exjson_v) EV_VALUE(*(exjson_v))
#define EV_TYPE(exjson_v) (exjson_v).val_type
#define EV_TYPE_P(exjson_v) EV_TYPE(*(exjson_v))

typedef struct _EXJSON
{
    unsigned char json_type;
    struct _EXJSON_V  *data;
    unsigned long   ele_num;
} EXJSON;
#define E_TYPE(exjson) (exjson).json_type
#define E_TYPE_P(exjson) E_TYPE(*(exjson))
#define E_DATA(exjson) (exjson).data
#define E_DATA_P(exjson) E_DATA(*(exjson))
#define E_NUM(exjson) (exjson).ele_num
#define E_NUM_P(exjson) E_NUM(*(exjson))

EXJSON_V *
INIT_EXJSON_V();

EXJSON *
INIT_EXJSON();

int add_object_int(EXJSON *exjson, char *key, int val);
int add_object_double(EXJSON *exjson, char *key, double val);
int add_object_string(EXJSON *exjson, char *key, char *val);
int add_object_object(EXJSON *exjson, char *key, void *val);
int add_object_array(EXJSON *exjson, char *key, void *val);
int add_object_ptr(EXJSON *exjson, char *key, void *val, unsigned char val_type);
int add_array_int(EXJSON *exjson, int val);
int add_array_double(EXJSON *exjson, double val);
int add_array_string(EXJSON *exjson, char *val);
int add_array_object(EXJSON *exjson, void *val);
int add_array_array(EXJSON *exjson, void *val);
int add_array_ptr(EXJSON *exjson, void *val, unsigned char val_type);
void print_exjson(EXJSON *exjson, int _num);
void destroy_exjson(EXJSON *exjson);
#define PRINT_EXJSON(exjson) print_exjson(exjson, 0)
EXJSON *exjson_get_array_or_object_from_key(EXJSON *exjson, char *key_name);
EXJSON *exjson_get_array_or_object_from_index(EXJSON *exjson, int index);
void *exjson_get_val_from_key(EXJSON *exjson, char *key);
void *exjson_get_val_from_index(EXJSON *exjson, int index);
extern EXJSON *decode_json(char *json_string);

#endif /* EXJSON_EXJSON_H */