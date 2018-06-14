
/******************************************************************************
*
*   FILE
*   ----
*   uaSimpleTicketAuthenticator.c
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


OV_DLLFNCEXPORT OV_RESULT opcua_uaSimpleTicketAuthenticator_constructor(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_opcua_uaSimpleTicketAuthenticator pinst = Ov_StaticPtrCast(opcua_uaSimpleTicketAuthenticator, pobj);
    OV_RESULT    result;

    /* do what the base class does first */
    result = ksbase_TicketAuthenticator_constructor(pobj);
    if(Ov_Fail(result))
         return result;

    /* do what */


    return OV_ERR_OK;
}

OV_DLLFNCEXPORT void opcua_uaSimpleTicketAuthenticator_startup(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_opcua_uaSimpleTicketAuthenticator pinst = Ov_StaticPtrCast(opcua_uaSimpleTicketAuthenticator, pobj);

    /* do what the base class does first */
    ksbase_TicketAuthenticator_startup(pobj);

    /* do what */


    return;
}

OV_DLLFNCEXPORT void opcua_uaSimpleTicketAuthenticator_shutdown(
	OV_INSTPTR_ov_object 	pobj
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_opcua_uaSimpleTicketAuthenticator pinst = Ov_StaticPtrCast(opcua_uaSimpleTicketAuthenticator, pobj);

    /* do what */

    /* set the object's state to "shut down" */
    ksbase_TicketAuthenticator_shutdown(pobj);

    return;
}

OV_DLLFNCEXPORT OV_TICKET* opcua_uaSimpleTicketAuthenticator_createticket(
	void *data,
	OV_TICKET_TYPE type
) {
    /*    
    *   local variables
    */

    return (OV_TICKET*)0;
}

OV_DLLFNCEXPORT void opcua_uaSimpleTicketAuthenticator_deleteticket(
	OV_TICKET *pticket
) {
    /*    
    *   local variables
    */

    return;
}

OV_DLLFNCEXPORT OV_BOOL opcua_uaSimpleTicketAuthenticator_encodereply(
	void *data, 
	OV_TICKET *pticket
) {
    /*    
    *   local variables
    */

    return (OV_BOOL)0;
}

OV_DLLFNCEXPORT OV_ACCESS opcua_uaSimpleTicketAuthenticator_TicketGetaccess(
	const OV_TICKET *pticket
) {
    /*    
    *   local variables
    */

    return (OV_ACCESS)0;
}

