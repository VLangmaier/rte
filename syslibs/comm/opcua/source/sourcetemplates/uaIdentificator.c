
/******************************************************************************
*
*   FILE
*   ----
*   uaIdentificator.c
*
*   History
*   -------
*   2018-06-14   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_opcua
#define OV_COMPILE_LIBRARY_opcua
#endif


#include "opcua.h"
#include "libov/ov_macros.h"


OV_DLLFNCEXPORT OV_RESULT opcua_uaIdentificator_constructor(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_opcua_uaIdentificator pinst = Ov_StaticPtrCast(opcua_uaIdentificator, pobj);
    OV_RESULT    result;

    /* do what the base class does first */
    result = ov_object_constructor(pobj);
    if(Ov_Fail(result))
         return result;

    /* do what */


    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_BOOL opcua_uaIdentificator_identify (
	OV_INSTPTR_ksbase_ProtocolIdentificator this,
	OV_INSTPTR_ksbase_Channel pchannel
) {
    /*    
    *   local variables
    */

    return (OV_BOOL)0;
}

OV_DLLFNCEXPORT OV_RESULT opcua_uaIdentificator_createClientHandler (
	OV_INSTPTR_ksbase_ProtocolIdentificator this,
	OV_INSTPTR_ksbase_Channel pchannel
) {
    /*    
    *   local variables
    */

    return OV_ERR_OK;
}

