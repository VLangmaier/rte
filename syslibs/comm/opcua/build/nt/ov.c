/*
*   This file was generated by the ACPLT/OV C-Code Generator.
*
*   C-Code Generator version: 1.6.4
*   ACPLT/OV library version: 2.0.0
*   Date of file generation:  21-Jun-2018 (17:14:54)
*
*   DO NOT EDIT THIS FILE!
*/

#ifndef OV_COMPILE_LIBRARY_ov
#define OV_COMPILE_LIBRARY_ov
#endif

#include "ov.h"

OV_DLLVAREXPORT OV_INSTPTR_ov_class pclass_ov_object = NULL;
OV_DLLVAREXPORT OV_INSTPTR_ov_class pclass_ov_domain = NULL;
OV_DLLVAREXPORT OV_INSTPTR_ov_class pclass_ov_library = NULL;
OV_DLLVAREXPORT OV_INSTPTR_ov_class pclass_ov_structure = NULL;
OV_DLLVAREXPORT OV_INSTPTR_ov_class pclass_ov_class = NULL;
OV_DLLVAREXPORT OV_INSTPTR_ov_class pclass_ov_association = NULL;
OV_DLLVAREXPORT OV_INSTPTR_ov_class pclass_ov_variable = NULL;
OV_DLLVAREXPORT OV_INSTPTR_ov_class pclass_ov_part = NULL;
OV_DLLVAREXPORT OV_INSTPTR_ov_class pclass_ov_operation = NULL;

OV_DLLVAREXPORT OV_INSTPTR_ov_association passoc_ov_containment = NULL;
OV_DLLVAREXPORT OV_INSTPTR_ov_association passoc_ov_instantiation = NULL;
OV_DLLVAREXPORT OV_INSTPTR_ov_association passoc_ov_inheritance = NULL;
OV_DLLVAREXPORT OV_INSTPTR_ov_association passoc_ov_parentrelationship = NULL;
OV_DLLVAREXPORT OV_INSTPTR_ov_association passoc_ov_childrelationship = NULL;
OV_DLLVAREXPORT OV_INSTPTR_ov_association passoc_ov_construction = NULL;
OV_DLLVAREXPORT OV_INSTPTR_ov_association passoc_ov_embedment = NULL;

OV_VTBL_ov_object OV_VTABLE_ov_object = {
    ov_object_constructor,
    ov_object_checkinit,
    ov_object_destructor,
    ov_object_startup,
    ov_object_shutdown,
    ov_object_rename,
    ov_object_getaccess,
    ov_object_getflags,
    ov_object_getcomment,
    ov_object_gettechunit,
    ov_object_getvar,
    ov_object_setvar
};

OV_VTBL_ov_domain OV_VTABLE_ov_domain = {
    ov_object_constructor,
    ov_object_checkinit,
    ov_object_destructor,
    ov_object_startup,
    ov_object_shutdown,
    ov_object_rename,
    ov_object_getaccess,
    ov_object_getflags,
    ov_object_getcomment,
    ov_object_gettechunit,
    ov_object_getvar,
    ov_object_setvar
};

OV_VTBL_ov_library OV_VTABLE_ov_library = {
    ov_library_constructor,
    ov_object_checkinit,
    ov_library_destructor,
    ov_object_startup,
    ov_object_shutdown,
    ov_object_rename,
    ov_object_getaccess,
    ov_object_getflags,
    ov_object_getcomment,
    ov_object_gettechunit,
    ov_object_getvar,
    ov_object_setvar
};

OV_VTBL_ov_structure OV_VTABLE_ov_structure = {
    ov_object_constructor,
    ov_object_checkinit,
    ov_object_destructor,
    ov_object_startup,
    ov_object_shutdown,
    ov_object_rename,
    ov_object_getaccess,
    ov_object_getflags,
    ov_object_getcomment,
    ov_object_gettechunit,
    ov_object_getvar,
    ov_object_setvar
};

OV_VTBL_ov_class OV_VTABLE_ov_class = {
    ov_object_constructor,
    ov_object_checkinit,
    ov_object_destructor,
    ov_object_startup,
    ov_object_shutdown,
    ov_object_rename,
    ov_object_getaccess,
    ov_object_getflags,
    ov_object_getcomment,
    ov_object_gettechunit,
    ov_object_getvar,
    ov_object_setvar
};

OV_VTBL_ov_association OV_VTABLE_ov_association = {
    ov_object_constructor,
    ov_object_checkinit,
    ov_object_destructor,
    ov_object_startup,
    ov_object_shutdown,
    ov_object_rename,
    ov_object_getaccess,
    ov_object_getflags,
    ov_object_getcomment,
    ov_object_gettechunit,
    ov_object_getvar,
    ov_object_setvar
};

OV_VTBL_ov_variable OV_VTABLE_ov_variable = {
    ov_object_constructor,
    ov_object_checkinit,
    ov_object_destructor,
    ov_object_startup,
    ov_object_shutdown,
    ov_object_rename,
    ov_object_getaccess,
    ov_object_getflags,
    ov_object_getcomment,
    ov_object_gettechunit,
    ov_object_getvar,
    ov_object_setvar
};

OV_VTBL_ov_part OV_VTABLE_ov_part = {
    ov_object_constructor,
    ov_object_checkinit,
    ov_object_destructor,
    ov_object_startup,
    ov_object_shutdown,
    ov_object_rename,
    ov_object_getaccess,
    ov_object_getflags,
    ov_object_getcomment,
    ov_object_gettechunit,
    ov_object_getvar,
    ov_object_setvar
};

OV_VTBL_ov_operation OV_VTABLE_ov_operation = {
    ov_object_constructor,
    ov_object_checkinit,
    ov_object_destructor,
    ov_object_startup,
    ov_object_shutdown,
    ov_object_rename,
    ov_object_getaccess,
    ov_object_getflags,
    ov_object_getcomment,
    ov_object_gettechunit,
    ov_object_getvar,
    ov_object_setvar
};


OV_VARIABLE_DEF OV_VARIABLE_DEF_ov_object[] = {{
    &OV_VARIABLE_DEF_ov_object[1],
    "identifier",
    1,
    0,
    48,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_STRING),
    offsetof(OV_INST_ov_object, v_identifier),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    NULL,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_object[2],
    "idH",
    1,
    3,
    17,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_UINT),
    offsetof(OV_INST_ov_object, v_idH),
    0,
    (OV_STRING)NULL,
    "high dword of this object's unique id within the server (as long as it exists)",
    (OV_FNCPTR_GET)ov_object_idH_get,
    (OV_FNCPTR_SET)ov_object_idH_set
}, {
    &OV_VARIABLE_DEF_ov_object[3],
    "idL",
    1,
    3,
    17,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_UINT),
    offsetof(OV_INST_ov_object, v_idL),
    0,
    (OV_STRING)NULL,
    "low dword of this object's unique id within the server (as long as it exists)",
    (OV_FNCPTR_GET)ov_object_idL_get,
    (OV_FNCPTR_SET)ov_object_idL_set
}, {
    &OV_VARIABLE_DEF_ov_object[4],
    "creationtime",
    1,
    0,
    49,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_TIME),
    offsetof(OV_INST_ov_object, v_creationtime),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    NULL,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_object[5],
    "pouterobject",
    1,
    0,
    65,
    "OV_INSTPTR",
    (OV_STRING)NULL,
    1*sizeof(OV_INSTPTR),
    offsetof(OV_INST_ov_object, v_pouterobject),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    NULL,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_object[6],
    "objectstate",
    1,
    0,
    16,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_INT),
    offsetof(OV_INST_ov_object, v_objectstate),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    NULL,
    NULL
}, {
    (OV_VARIABLE_DEF*)0,
    "linktable",
    1,
    0,
    65,
    "OV_ATBLPTR",
    (OV_STRING)NULL,
    1*sizeof(OV_ATBLPTR),
    offsetof(OV_INST_ov_object, v_linktable),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    NULL,
    NULL
}};

OV_OPERATION_DEF OV_OPERATION_DEF_ov_object[] = {{
    &OV_OPERATION_DEF_ov_object[1],
    "constructor",
    0,
    "OV_FNC_CONSTRUCTOR"
}, {
    &OV_OPERATION_DEF_ov_object[2],
    "checkinit",
    0,
    "OV_FNC_CHECKINIT"
}, {
    &OV_OPERATION_DEF_ov_object[3],
    "destructor",
    0,
    "OV_FNC_DESTRUCTOR"
}, {
    &OV_OPERATION_DEF_ov_object[4],
    "startup",
    0,
    "OV_FNC_STARTUP"
}, {
    &OV_OPERATION_DEF_ov_object[5],
    "shutdown",
    0,
    "OV_FNC_SHUTDOWN"
}, {
    &OV_OPERATION_DEF_ov_object[6],
    "rename",
    0,
    "OV_FNC_RENAME"
}, {
    &OV_OPERATION_DEF_ov_object[7],
    "getaccess",
    0,
    "OV_FNC_GETACCESS"
}, {
    &OV_OPERATION_DEF_ov_object[8],
    "getflags",
    0,
    "OV_FNC_GETFLAGS"
}, {
    &OV_OPERATION_DEF_ov_object[9],
    "getcomment",
    0,
    "OV_FNC_GETCOMMENT"
}, {
    &OV_OPERATION_DEF_ov_object[10],
    "gettechunit",
    0,
    "OV_FNC_GETTECHUNIT"
}, {
    &OV_OPERATION_DEF_ov_object[11],
    "getvar",
    0,
    "OV_FNC_GETVAR"
}, {
    (OV_OPERATION_DEF*)0,
    "setvar",
    0,
    "OV_FNC_SETVAR"
}};

OV_CLASS_DEF OV_CLASS_DEF_ov_object = {
    &OV_CLASS_DEF_ov_domain,
    "object",
    (OV_STRING)NULL,
    0,
    0,
    (OV_STRING)NULL,
    Ov_GetInstSize(ov_object),
    Ov_GetStaticInstSize(ov_object),
    (OV_POINTER)&OV_VTABLE_ov_object,
    &OV_VARIABLE_DEF_ov_object[0],
    (OV_PART_DEF*)0,
    &OV_OPERATION_DEF_ov_object[0]
};


OV_CLASS_DEF OV_CLASS_DEF_ov_domain = {
    &OV_CLASS_DEF_ov_library,
    "domain",
    "ov/object",
    1,
    0,
    (OV_STRING)NULL,
    Ov_GetInstSize(ov_domain),
    Ov_GetStaticInstSize(ov_domain),
    (OV_POINTER)&OV_VTABLE_ov_domain,
    (OV_VARIABLE_DEF*)0,
    (OV_PART_DEF*)0,
    (OV_OPERATION_DEF*)0
};


OV_VARIABLE_DEF OV_VARIABLE_DEF_ov_library[] = {{
    &OV_VARIABLE_DEF_ov_library[1],
    "version",
    1,
    1,
    48,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_STRING),
    offsetof(OV_INST_ov_library, v_version),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_library_version_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_library[2],
    "author",
    1,
    1,
    48,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_STRING),
    offsetof(OV_INST_ov_library, v_author),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_library_author_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_library[3],
    "copyright",
    1,
    1,
    48,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_STRING),
    offsetof(OV_INST_ov_library, v_copyright),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_library_copyright_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_library[4],
    "comment",
    1,
    1,
    48,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_STRING),
    offsetof(OV_INST_ov_library, v_comment),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_library_comment_get,
    NULL
}, {
    (OV_VARIABLE_DEF*)0,
    "handle",
    1,
    0,
    65,
    "OV_DLLHANDLE",
    (OV_STRING)NULL,
    1*sizeof(OV_DLLHANDLE),
    offsetof(OV_INST_ov_library, v_handle),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    NULL,
    NULL
}};

OV_OPERATION_DEF OV_OPERATION_DEF_ov_library[] = {{
    &OV_OPERATION_DEF_ov_library[1],
    "constructor",
    0,
    "OV_FNC_CONSTRUCTOR"
}, {
    (OV_OPERATION_DEF*)0,
    "destructor",
    0,
    "OV_FNC_DESTRUCTOR"
}};

OV_CLASS_DEF OV_CLASS_DEF_ov_library = {
    &OV_CLASS_DEF_ov_structure,
    "library",
    "ov/domain",
    1,
    0,
    (OV_STRING)NULL,
    Ov_GetInstSize(ov_library),
    Ov_GetStaticInstSize(ov_library),
    (OV_POINTER)&OV_VTABLE_ov_library,
    &OV_VARIABLE_DEF_ov_library[0],
    (OV_PART_DEF*)0,
    &OV_OPERATION_DEF_ov_library[0]
};


OV_VARIABLE_DEF OV_VARIABLE_DEF_ov_structure[] = {{
    (OV_VARIABLE_DEF*)0,
    "size",
    1,
    0,
    17,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_UINT),
    offsetof(OV_INST_ov_structure, v_size),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    NULL,
    NULL
}};

OV_CLASS_DEF OV_CLASS_DEF_ov_structure = {
    &OV_CLASS_DEF_ov_class,
    "structure",
    "ov/domain",
    1,
    0,
    (OV_STRING)NULL,
    Ov_GetInstSize(ov_structure),
    Ov_GetStaticInstSize(ov_structure),
    (OV_POINTER)&OV_VTABLE_ov_structure,
    &OV_VARIABLE_DEF_ov_structure[0],
    (OV_PART_DEF*)0,
    (OV_OPERATION_DEF*)0
};


OV_VARIABLE_DEF OV_VARIABLE_DEF_ov_class[] = {{
    &OV_VARIABLE_DEF_ov_class[1],
    "comment",
    1,
    1,
    48,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_STRING),
    offsetof(OV_INST_ov_class, v_comment),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_class_comment_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_class[2],
    "flags",
    1,
    1,
    17,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_UINT),
    offsetof(OV_INST_ov_class, v_flags),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_class_flags_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_class[3],
    "classprops",
    1,
    1,
    16,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_INT),
    offsetof(OV_INST_ov_class, v_classprops),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_class_classprops_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_class[4],
    "size",
    1,
    1,
    17,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_UINT),
    offsetof(OV_INST_ov_class, v_size),
    0,
    "Byte",
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_class_size_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_class[5],
    "staticsize",
    1,
    1,
    17,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_UINT),
    offsetof(OV_INST_ov_class, v_staticsize),
    0,
    "Byte",
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_class_staticsize_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_class[6],
    "linktablesize",
    1,
    1,
    17,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_UINT),
    offsetof(OV_INST_ov_class, v_linktablesize),
    0,
    "Byte",
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_class_linktablesize_get,
    NULL
}, {
    (OV_VARIABLE_DEF*)0,
    "pvtable",
    1,
    0,
    65,
    "OV_VTBLPTR",
    (OV_STRING)NULL,
    1*sizeof(OV_VTBLPTR),
    offsetof(OV_INST_ov_class, v_pvtable),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    NULL,
    NULL
}};

OV_CLASS_DEF OV_CLASS_DEF_ov_class = {
    &OV_CLASS_DEF_ov_association,
    "class",
    "ov/domain",
    1,
    0,
    (OV_STRING)NULL,
    Ov_GetInstSize(ov_class),
    Ov_GetStaticInstSize(ov_class),
    (OV_POINTER)&OV_VTABLE_ov_class,
    &OV_VARIABLE_DEF_ov_class[0],
    (OV_PART_DEF*)0,
    (OV_OPERATION_DEF*)0
};


OV_VARIABLE_DEF OV_VARIABLE_DEF_ov_association[] = {{
    &OV_VARIABLE_DEF_ov_association[1],
    "assoctype",
    1,
    1,
    16,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_INT),
    offsetof(OV_INST_ov_association, v_assoctype),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_association_assoctype_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_association[2],
    "assocprops",
    1,
    1,
    16,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_INT),
    offsetof(OV_INST_ov_association, v_assocprops),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_association_assocprops_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_association[3],
    "childrolename",
    1,
    1,
    48,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_STRING),
    offsetof(OV_INST_ov_association, v_childrolename),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_association_childrolename_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_association[4],
    "parentrolename",
    1,
    1,
    48,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_STRING),
    offsetof(OV_INST_ov_association, v_parentrolename),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_association_parentrolename_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_association[5],
    "parentoffset",
    1,
    1,
    17,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_UINT),
    offsetof(OV_INST_ov_association, v_parentoffset),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_association_parentoffset_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_association[6],
    "childoffset",
    1,
    1,
    17,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_UINT),
    offsetof(OV_INST_ov_association, v_childoffset),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_association_childoffset_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_association[7],
    "parentcomment",
    1,
    1,
    48,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_STRING),
    offsetof(OV_INST_ov_association, v_parentcomment),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_association_parentcomment_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_association[8],
    "childcomment",
    1,
    1,
    48,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_STRING),
    offsetof(OV_INST_ov_association, v_childcomment),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_association_childcomment_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_association[9],
    "parentflags",
    1,
    1,
    17,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_UINT),
    offsetof(OV_INST_ov_association, v_parentflags),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_association_parentflags_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_association[10],
    "childflags",
    1,
    1,
    17,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_UINT),
    offsetof(OV_INST_ov_association, v_childflags),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_association_childflags_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_association[11],
    "linkfnc",
    1,
    0,
    65,
    "OV_FNCPTR_LINK",
    (OV_STRING)NULL,
    1*sizeof(OV_FNCPTR_LINK),
    offsetof(OV_INST_ov_association, v_linkfnc),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    NULL,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_association[12],
    "unlinkfnc",
    1,
    0,
    65,
    "OV_FNCPTR_UNLINK",
    (OV_STRING)NULL,
    1*sizeof(OV_FNCPTR_UNLINK),
    offsetof(OV_INST_ov_association, v_unlinkfnc),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    NULL,
    NULL
}, {
    (OV_VARIABLE_DEF*)0,
    "getaccessfnc",
    1,
    0,
    65,
    "OV_FNCPTR_GETACCESS",
    (OV_STRING)NULL,
    1*sizeof(OV_FNCPTR_GETACCESS),
    offsetof(OV_INST_ov_association, v_getaccessfnc),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    NULL,
    NULL
}};

OV_CLASS_DEF OV_CLASS_DEF_ov_association = {
    &OV_CLASS_DEF_ov_variable,
    "association",
    "ov/object",
    1,
    0,
    (OV_STRING)NULL,
    Ov_GetInstSize(ov_association),
    Ov_GetStaticInstSize(ov_association),
    (OV_POINTER)&OV_VTABLE_ov_association,
    &OV_VARIABLE_DEF_ov_association[0],
    (OV_PART_DEF*)0,
    (OV_OPERATION_DEF*)0
};


OV_VARIABLE_DEF OV_VARIABLE_DEF_ov_variable[] = {{
    &OV_VARIABLE_DEF_ov_variable[1],
    "vartype",
    1,
    1,
    16,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_INT),
    offsetof(OV_INST_ov_variable, v_vartype),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_variable_vartype_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_variable[2],
    "ctypename",
    1,
    1,
    48,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_STRING),
    offsetof(OV_INST_ov_variable, v_ctypename),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_variable_ctypename_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_variable[3],
    "varprops",
    1,
    1,
    16,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_INT),
    offsetof(OV_INST_ov_variable, v_varprops),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_variable_varprops_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_variable[4],
    "veclen",
    1,
    1,
    17,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_UINT),
    offsetof(OV_INST_ov_variable, v_veclen),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_variable_veclen_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_variable[5],
    "comment",
    1,
    1,
    48,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_STRING),
    offsetof(OV_INST_ov_variable, v_comment),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_variable_comment_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_variable[6],
    "flags",
    1,
    1,
    17,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_UINT),
    offsetof(OV_INST_ov_variable, v_flags),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_variable_flags_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_variable[7],
    "techunit",
    1,
    1,
    48,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_STRING),
    offsetof(OV_INST_ov_variable, v_techunit),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_variable_techunit_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_variable[8],
    "initialvalue",
    1,
    1,
    255,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_ANY),
    offsetof(OV_INST_ov_variable, v_initialvalue),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_variable_initialvalue_get,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_variable[9],
    "size",
    1,
    0,
    17,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_UINT),
    offsetof(OV_INST_ov_variable, v_size),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    NULL,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_variable[10],
    "offset",
    1,
    0,
    17,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_UINT),
    offsetof(OV_INST_ov_variable, v_offset),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    NULL,
    NULL
}, {
    &OV_VARIABLE_DEF_ov_variable[11],
    "getfnc",
    1,
    0,
    65,
    "OV_FNCPTR_GET",
    (OV_STRING)NULL,
    1*sizeof(OV_FNCPTR_GET),
    offsetof(OV_INST_ov_variable, v_getfnc),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    NULL,
    NULL
}, {
    (OV_VARIABLE_DEF*)0,
    "setfnc",
    1,
    0,
    65,
    "OV_FNCPTR_SET",
    (OV_STRING)NULL,
    1*sizeof(OV_FNCPTR_SET),
    offsetof(OV_INST_ov_variable, v_setfnc),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    NULL,
    NULL
}};

OV_CLASS_DEF OV_CLASS_DEF_ov_variable = {
    &OV_CLASS_DEF_ov_part,
    "variable",
    "ov/object",
    1,
    0,
    (OV_STRING)NULL,
    Ov_GetInstSize(ov_variable),
    Ov_GetStaticInstSize(ov_variable),
    (OV_POINTER)&OV_VTABLE_ov_variable,
    &OV_VARIABLE_DEF_ov_variable[0],
    (OV_PART_DEF*)0,
    (OV_OPERATION_DEF*)0
};


OV_VARIABLE_DEF OV_VARIABLE_DEF_ov_part[] = {{
    &OV_VARIABLE_DEF_ov_part[1],
    "offset",
    1,
    0,
    17,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_UINT),
    offsetof(OV_INST_ov_part, v_offset),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    NULL,
    NULL
}, {
    (OV_VARIABLE_DEF*)0,
    "flags",
    1,
    1,
    17,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_UINT),
    offsetof(OV_INST_ov_part, v_flags),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_part_flags_get,
    NULL
}};

OV_CLASS_DEF OV_CLASS_DEF_ov_part = {
    &OV_CLASS_DEF_ov_operation,
    "part",
    "ov/object",
    1,
    0,
    (OV_STRING)NULL,
    Ov_GetInstSize(ov_part),
    Ov_GetStaticInstSize(ov_part),
    (OV_POINTER)&OV_VTABLE_ov_part,
    &OV_VARIABLE_DEF_ov_part[0],
    (OV_PART_DEF*)0,
    (OV_OPERATION_DEF*)0
};


OV_VARIABLE_DEF OV_VARIABLE_DEF_ov_operation[] = {{
    &OV_VARIABLE_DEF_ov_operation[1],
    "opprops",
    1,
    1,
    16,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_INT),
    offsetof(OV_INST_ov_operation, v_opprops),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_operation_opprops_get,
    NULL
}, {
    (OV_VARIABLE_DEF*)0,
    "cfnctypename",
    1,
    1,
    48,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    1*sizeof(OV_STRING),
    offsetof(OV_INST_ov_operation, v_cfnctypename),
    0,
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    (OV_FNCPTR_GET)ov_operation_cfnctypename_get,
    NULL
}};

OV_CLASS_DEF OV_CLASS_DEF_ov_operation = {
    (OV_CLASS_DEF*)0,
    "operation",
    "ov/object",
    1,
    0,
    (OV_STRING)NULL,
    Ov_GetInstSize(ov_operation),
    Ov_GetStaticInstSize(ov_operation),
    (OV_POINTER)&OV_VTABLE_ov_operation,
    &OV_VARIABLE_DEF_ov_operation[0],
    (OV_PART_DEF*)0,
    (OV_OPERATION_DEF*)0
};

OV_ASSOCIATION_DEF OV_ASSOCIATION_DEF_ov_containment = {
    &OV_ASSOCIATION_DEF_ov_instantiation,
    "containment",
    1,
    1,
    "child",
    "ov/domain",
    "parent",
    "ov/object",
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    0,
    0,
    0,
    0,
    (OV_FNCPTR_LINK)ov_containment_link,
    (OV_FNCPTR_UNLINK)ov_containment_unlink,
    (OV_FNCPTR_GETACCESS)ov_containment_getaccess
};

OV_ASSOCIATION_DEF OV_ASSOCIATION_DEF_ov_instantiation = {
    &OV_ASSOCIATION_DEF_ov_inheritance,
    "instantiation",
    1,
    0,
    "instance",
    "ov/class",
    "objectclass",
    "ov/object",
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    0,
    0,
    0,
    0,
    (OV_FNCPTR_LINK)ov_instantiation_link,
    (OV_FNCPTR_UNLINK)ov_instantiation_unlink,
    (OV_FNCPTR_GETACCESS)ov_instantiation_getaccess
};

OV_ASSOCIATION_DEF OV_ASSOCIATION_DEF_ov_inheritance = {
    &OV_ASSOCIATION_DEF_ov_parentrelationship,
    "inheritance",
    1,
    0,
    "derivedclass",
    "ov/class",
    "baseclass",
    "ov/class",
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    0,
    0,
    0,
    0,
    (OV_FNCPTR_LINK)ov_inheritance_link,
    (OV_FNCPTR_UNLINK)ov_inheritance_unlink,
    (OV_FNCPTR_GETACCESS)ov_inheritance_getaccess
};

OV_ASSOCIATION_DEF OV_ASSOCIATION_DEF_ov_parentrelationship = {
    &OV_ASSOCIATION_DEF_ov_childrelationship,
    "parentrelationship",
    1,
    0,
    "parentassociation",
    "ov/class",
    "parentclass",
    "ov/association",
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    0,
    0,
    0,
    0,
    (OV_FNCPTR_LINK)ov_parentrelationship_link,
    (OV_FNCPTR_UNLINK)ov_parentrelationship_unlink,
    (OV_FNCPTR_GETACCESS)ov_parentrelationship_getaccess
};

OV_ASSOCIATION_DEF OV_ASSOCIATION_DEF_ov_childrelationship = {
    &OV_ASSOCIATION_DEF_ov_construction,
    "childrelationship",
    1,
    0,
    "childassociation",
    "ov/class",
    "childclass",
    "ov/association",
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    0,
    0,
    0,
    0,
    (OV_FNCPTR_LINK)ov_childrelationship_link,
    (OV_FNCPTR_UNLINK)ov_childrelationship_unlink,
    (OV_FNCPTR_GETACCESS)ov_childrelationship_getaccess
};

OV_ASSOCIATION_DEF OV_ASSOCIATION_DEF_ov_construction = {
    &OV_ASSOCIATION_DEF_ov_embedment,
    "construction",
    1,
    0,
    "variable",
    "ov/structure",
    "structure",
    "ov/variable",
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    0,
    0,
    0,
    0,
    (OV_FNCPTR_LINK)ov_construction_link,
    (OV_FNCPTR_UNLINK)ov_construction_unlink,
    (OV_FNCPTR_GETACCESS)ov_construction_getaccess
};

OV_ASSOCIATION_DEF OV_ASSOCIATION_DEF_ov_embedment = {
    (OV_ASSOCIATION_DEF*)0,
    "embedment",
    1,
    0,
    "part",
    "ov/class",
    "partclass",
    "ov/part",
    (OV_STRING)NULL,
    (OV_STRING)NULL,
    0,
    0,
    0,
    0,
    (OV_FNCPTR_LINK)ov_embedment_link,
    (OV_FNCPTR_UNLINK)ov_embedment_unlink,
    (OV_FNCPTR_GETACCESS)ov_embedment_getaccess
};

OV_LIBRARY_DEF OV_LIBRARY_DEF_ov = {
    "ov",
    "1.9.0",
    "2.0.0",
    "Dirk Meyer/Ansgar Muennemann",
    "Copyright (C) 1998-2006 Lehrstuhl fuer Prozessleittechnik, RWTH Aachen",
    "Metamodel of ACPLT/OV",
    (OV_STRUCTURE_DEF*)0,
    &OV_CLASS_DEF_ov_object,
    &OV_ASSOCIATION_DEF_ov_containment,
    ov_library_setglobalvars_ov
};

#include "libov/ov_macros.h"

OV_RESULT ov_library_setglobalvars_ov(void) {
    OV_INSTPTR_ov_library plib;
    Ov_ForEachChildEx(ov_instantiation, pclass_ov_library, plib, ov_library) {
        if(!strcmp(plib->v_identifier, "ov")) {
            pclass_ov_object = Ov_SearchChildEx(ov_containment, plib, "object", ov_class);
            if(!pclass_ov_object) {
                return OV_ERR_GENERIC;
            }
            pclass_ov_domain = Ov_SearchChildEx(ov_containment, plib, "domain", ov_class);
            if(!pclass_ov_domain) {
                return OV_ERR_GENERIC;
            }
            pclass_ov_library = Ov_SearchChildEx(ov_containment, plib, "library", ov_class);
            if(!pclass_ov_library) {
                return OV_ERR_GENERIC;
            }
            pclass_ov_structure = Ov_SearchChildEx(ov_containment, plib, "structure", ov_class);
            if(!pclass_ov_structure) {
                return OV_ERR_GENERIC;
            }
            pclass_ov_class = Ov_SearchChildEx(ov_containment, plib, "class", ov_class);
            if(!pclass_ov_class) {
                return OV_ERR_GENERIC;
            }
            pclass_ov_association = Ov_SearchChildEx(ov_containment, plib, "association", ov_class);
            if(!pclass_ov_association) {
                return OV_ERR_GENERIC;
            }
            pclass_ov_variable = Ov_SearchChildEx(ov_containment, plib, "variable", ov_class);
            if(!pclass_ov_variable) {
                return OV_ERR_GENERIC;
            }
            pclass_ov_part = Ov_SearchChildEx(ov_containment, plib, "part", ov_class);
            if(!pclass_ov_part) {
                return OV_ERR_GENERIC;
            }
            pclass_ov_operation = Ov_SearchChildEx(ov_containment, plib, "operation", ov_class);
            if(!pclass_ov_operation) {
                return OV_ERR_GENERIC;
            }
            passoc_ov_containment = Ov_SearchChildEx(ov_containment, plib, "containment", ov_association);
            if(!passoc_ov_containment) {
                return OV_ERR_GENERIC;
            }
            passoc_ov_instantiation = Ov_SearchChildEx(ov_containment, plib, "instantiation", ov_association);
            if(!passoc_ov_instantiation) {
                return OV_ERR_GENERIC;
            }
            passoc_ov_inheritance = Ov_SearchChildEx(ov_containment, plib, "inheritance", ov_association);
            if(!passoc_ov_inheritance) {
                return OV_ERR_GENERIC;
            }
            passoc_ov_parentrelationship = Ov_SearchChildEx(ov_containment, plib, "parentrelationship", ov_association);
            if(!passoc_ov_parentrelationship) {
                return OV_ERR_GENERIC;
            }
            passoc_ov_childrelationship = Ov_SearchChildEx(ov_containment, plib, "childrelationship", ov_association);
            if(!passoc_ov_childrelationship) {
                return OV_ERR_GENERIC;
            }
            passoc_ov_construction = Ov_SearchChildEx(ov_containment, plib, "construction", ov_association);
            if(!passoc_ov_construction) {
                return OV_ERR_GENERIC;
            }
            passoc_ov_embedment = Ov_SearchChildEx(ov_containment, plib, "embedment", ov_association);
            if(!passoc_ov_embedment) {
                return OV_ERR_GENERIC;
            }
            return OV_ERR_OK;
        }
    }
    return OV_ERR_GENERIC;
}

OV_DLLFNCEXPORT OV_LIBRARY_DEF *ov_library_open_ov(void) {
    return &OV_LIBRARY_DEF_ov;
}

/*
*   End of file
*/
