
/******************************************************************************
*
*   FILE
*   ----
*   getParentIdentifier.c
*
*   History
*   -------
*   2017-09-06   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_SSChelper
#define OV_COMPILE_LIBRARY_SSChelper
#endif


#include "SSChelper.h"
#include "libov/ov_macros.h"


OV_DLLFNCEXPORT void SSChelper_getParentIdentifier_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_SSChelper_getParentIdentifier pinst = Ov_StaticPtrCast(SSChelper_getParentIdentifier, pfb);

    //Level 0 equals its own identifier
    OV_INSTPTR_ov_domain parent = Ov_StaticPtrCast(ov_domain,pinst);
    for(size_t i = 0; i < pinst->v_level ; i++){
    	parent = Ov_GetParent(ov_containment, parent);
    }
    if(parent != NULL ){
    	ov_string_setvalue(&pinst->v_id, parent->v_identifier);
    }else {
    	ov_string_setvalue(&pinst->v_id, "");
    }
    return;
}

