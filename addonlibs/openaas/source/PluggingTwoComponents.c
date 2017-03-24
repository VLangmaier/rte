
/******************************************************************************
*
*   FILE
*   ----
*   PluggingTwoComponents.c
*
*   History
*   -------
*   2017-03-24   File created
*
*******************************************************************************
*
*   This file is generated by the 'acplt_builder' command
*
******************************************************************************/


#ifndef OV_COMPILE_LIBRARY_openaas
#define OV_COMPILE_LIBRARY_openaas
#endif


#include "openaas.h"
#include "libov/ov_macros.h"
#include "openaas_helpers.h"


OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_AASIdString1_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_AASIdString1,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_AASIdType1_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_UINT  value
) {
    pobj->v_AASIdType1 = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_LCECreatingInstanceIdString1_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_LCECreatingInstanceIdString1,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_LCECreatingInstanceIdType1_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_UINT  value
) {
    pobj->v_LCECreatingInstanceIdType1 = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_LCEWritingInstanceIdString1_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_LCEWritingInstanceIdString1,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_LCEWritingInstanceIdType1_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_UINT  value
) {
    pobj->v_LCEWritingInstanceIdType1 = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_LCEEventClass1_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_LCEEventClass1,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_LCESubject1_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_LCESubject1,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_LCETimeStamp1_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_TIME*  value
) {
    pobj->v_LCETimeStamp1 = *value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_LCETimeStampExtern1_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_BOOL  value
) {
    pobj->v_LCETimeStampExtern1 = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_PVSLName1_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_PVSLName1,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_PVSName1_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_PVSName1,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_AASIdString2_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_AASIdString2,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_AASIdType2_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_UINT  value
) {
    pobj->v_AASIdType2 = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_LCECreatingInstanceIdString2_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_LCECreatingInstanceIdString2,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_LCECreatingInstanceIdType2_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_UINT  value
) {
    pobj->v_LCECreatingInstanceIdType2 = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_LCEWritingInstanceIdString2_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_LCEWritingInstanceIdString2,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_LCEWritingInstanceIdType2_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_UINT  value
) {
    pobj->v_LCEWritingInstanceIdType2 = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_LCEEventClass2_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_LCEEventClass2,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_LCESubject2_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_LCESubject2,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_LCETimeStamp2_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_TIME*  value
) {
    pobj->v_LCETimeStamp2 = *value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_LCETimeStampExtern2_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_BOOL  value
) {
    pobj->v_LCETimeStampExtern2 = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_PVSLName2_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_PVSLName2,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_PVSName2_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_PVSName2,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_Plugged_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_BOOL  value
) {
    pobj->v_Plugged = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_PluggingTwoComponents_Generate_set(
    OV_INSTPTR_openaas_PluggingTwoComponents          pobj,
    const OV_BOOL  value
) {
    pobj->v_Generate = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT void openaas_PluggingTwoComponents_typemethod(
	OV_INSTPTR_fb_functionblock	pfb,
	OV_TIME						*pltc
) {
    /*    
    *   local variables
    */
    OV_INSTPTR_openaas_PluggingTwoComponents pinst = Ov_StaticPtrCast(openaas_PluggingTwoComponents, pfb);

    pinst->v_Status = 0;
    LifeCycleEntry lce1;
	LifeCycleEntry_init(&lce1);

	ov_string_setvalue(&lce1.creatingInstance.IdSpec, pinst->v_LCECreatingInstanceIdString1);
	lce1.creatingInstance.IdType =  pinst->v_LCECreatingInstanceIdType1;

	ov_string_setvalue(&lce1.writingInstance.IdSpec,  pinst->v_LCEWritingInstanceIdString1);
	lce1.writingInstance.IdType =  pinst->v_LCECreatingInstanceIdType1;

	ov_string_setvalue(&lce1.eventClass,  pinst->v_LCEEventClass1);

	ov_string_setvalue(&lce1.subject,  pinst->v_LCESubject1);

	if (pinst->v_LCETimeStampExtern1 == FALSE)
		ov_time_gettime(&lce1.data.TimeStamp);
	else
		lce1.data.TimeStamp = pinst->v_LCETimeStamp2;

	IdentificationType aasId1;
	IdentificationType_init(&aasId1);
	ov_string_setvalue(&aasId1.IdSpec, pinst->v_AASIdString1);
	aasId1.IdType = pinst->v_AASIdType1;

	PropertyValueStatement pvs1;
	PropertyValueStatement_init(&pvs1);

	LifeCycleEntry lce2;
	LifeCycleEntry_init(&lce2);

	ov_string_setvalue(&lce2.creatingInstance.IdSpec, pinst->v_LCECreatingInstanceIdString2);
	lce2.creatingInstance.IdType =  pinst->v_LCECreatingInstanceIdType2;

	ov_string_setvalue(&lce2.writingInstance.IdSpec,  pinst->v_LCEWritingInstanceIdString2);
	lce2.writingInstance.IdType =  pinst->v_LCECreatingInstanceIdType2;

	ov_string_setvalue(&lce2.eventClass,  pinst->v_LCEEventClass2);

	ov_string_setvalue(&lce2.subject,  pinst->v_LCESubject2);

	if (pinst->v_LCETimeStampExtern1 == FALSE)
		ov_time_gettime(&lce2.data.TimeStamp);
	else
		lce2.data.TimeStamp = pinst->v_LCETimeStamp2;

	IdentificationType aasId2;
	IdentificationType_init(&aasId2);
	ov_string_setvalue(&aasId2.IdSpec, pinst->v_AASIdString2);
	aasId2.IdType = pinst->v_AASIdType2;

	PropertyValueStatement pvs2;
	PropertyValueStatement_init(&pvs2);

	OV_ANY tmpany;
	tmpany.value.vartype = OV_VT_STRING;
	tmpany.value.valueunion.val_string = NULL;
	OV_STRING tmpString1 = NULL;
	if (aasId1.IdType == URI)
		ov_string_setvalue(&tmpString1, "URI:");
	else if (aasId1.IdType == ISO)
		ov_string_setvalue(&tmpString1, "ISO:");
	OV_STRING tmpString2 = NULL;
	if (aasId2.IdType == URI)
		ov_string_setvalue(&tmpString2, "URI:");
	else if (aasId2.IdType == ISO)
		ov_string_setvalue(&tmpString2, "ISO:");

	if (pinst->v_Plugged == TRUE)
		ov_string_print(&tmpany.value.valueunion.val_string, "AASId: %s%s and AASId: %s%s plugged", tmpString1, pinst->v_AASIdString1, tmpString2, pinst->v_AASIdString2);
	else
		ov_string_print(&tmpany.value.valueunion.val_string, "AASId: %s%s and AASId: %s%s unplugged", tmpString1, pinst->v_AASIdString1, tmpString2, pinst->v_AASIdString2);

	Ov_SetAnyValue(&lce1.data.Value, &tmpany);
	Ov_SetAnyValue(&lce2.data.Value, &tmpany);

	switch(pinst->v_State){
	case 0:
		if(pinst->v_Generate == TRUE)
			pinst->v_State = 1;
		break;
	case 1:
		pinst->v_Status = openaas_modelmanager_createLCE(aasId1, lce1);
		pinst->v_Status |= openaas_modelmanager_createLCE(aasId2, lce2);
		pinst->v_Status |= openaas_modelmanager_getPVS(aasId1, pinst->v_PVSLName1, pinst->v_PVSName1, &pvs1);
		if ((pvs1.value.Value.value.vartype & OV_VT_KSMASK) == OV_VT_BOOL){
			pvs1.value.Value.value.valueunion.val_bool = pinst->v_Plugged;
			pinst->v_Status |= openaas_modelmanager_setPVS(aasId1, pinst->v_PVSLName1, pvs1);
		}
		pinst->v_Status |= openaas_modelmanager_getPVS(aasId2, pinst->v_PVSLName2, pinst->v_PVSName2, &pvs2);
		if ((pvs2.value.Value.value.vartype & OV_VT_KSMASK) == OV_VT_BOOL){
			pvs2.value.Value.value.valueunion.val_bool = pinst->v_Plugged;
			pinst->v_Status |= openaas_modelmanager_setPVS(aasId2, pinst->v_PVSLName2, pvs2);
		}
		pinst->v_State = 2;
		break;
	case 2:
		if(pinst->v_Generate == FALSE)
			pinst->v_State = 0;
		break;
	}

	PropertyValueStatement_deleteMembers(&pvs1);
	PropertyValueStatement_deleteMembers(&pvs2);
	LifeCycleEntry_deleteMembers(&lce1);
	LifeCycleEntry_deleteMembers(&lce2);
	IdentificationType_deleteMembers(&aasId1);
	IdentificationType_deleteMembers(&aasId2);
	ov_database_free(tmpString1);
	ov_database_free(tmpString2);

    return;
}

