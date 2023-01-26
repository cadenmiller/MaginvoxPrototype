#ifndef WAE_REFLECT_H
#define WAE_REFLECT_H

/* If you are using reflection, this file must be included. */

/* Do not include any other WAE files! We don't want any circular dependencies. */
#include <cstdint>
#include <stddef.h>
#include <stdint.h>

/* In this file we are defining all the classes for doing reflection. 
    A secondary program running before the CMakeBuild process will
    do a simple parse of our code to add reflection data using a
    keyword implemented by what is basically an advanced macro. */


#define reflect(name) /* Guaranteed to return a "const waeReflectAmbiguous*". Is overwritten when Preprocessor Reflection program activates. */

typedef enum waeReflectType
{
    WAE_REFLECT_TYPE_PRIMITIVE,
    WAE_REFLECT_TYPE_ENUM,
    WAE_REFLECT_TYPE_STRUCT,
    WAE_REFLECT_TYPE_UNION,
} waeReflectType;

typedef struct waeReflectAmbiguous
{
    waeReflectType type;
} waeReflectAmbiguous;

typedef enum waeReflectPrimitiveType
{
    WAE_REFLECT_PRIMITIVE_CHAR,
    WAE_REFLECT_PRIMITIVE_SHORT,
    WAE_REFLECT_PRIMITIVE_LONG,
    WAE_REFLECT_PRIMITIVE_LONG_LONG,
    WAE_REFLECT_PRIMITIVE_UNSIGNED_CHAR,
    WAE_REFLECT_PRIMITIVE_UNSIGNED_SHORT,
    WAE_REFLECT_PRIMITIVE_UNSIGNED_LONG,
    WAE_REFLECT_PRIMITIVE_UNSIGNED_LONG_LONG,
    WAE_REFLECT_PRIMITIVE_FLOAT,
    WAE_REFLECT_PRIMITIVE_DOUBLE,
    WAE_REFLECT_PRIMITIVE_LONG_DOUBLE
} waeReflectPrimitiveType;

typedef struct waeReflectPrimitive
{
    waeReflectType type;
    const char* pName;
    size_t size;
    waeReflectPrimitiveType primitiveType;
} waeReflectPrimitive;

typedef struct waeReflectEnumerator
{
    const char* pName;
    int64_t value;
} waeReflectEnumerator;

typedef struct waeReflectEnum
{
    waeReflectType type;
    const char* pName;
    size_t size;
    uint32_t enumeratorCount;
    waeReflectEnumerator* pEnumerators;
} waeReflectEnum;

typedef struct waeReflectStruct
{
    waeReflectType type;
    const char* pName;
    size_t size;
    uint32_t fieldsCount;
    waeReflectAmbiguous* pFields;
} waeReflectStruct;

#define WAE_REFLECT_STRUCT(structure, fields)

#endif /* WAE_REFLECT_H */