/******************************************************************************
 *
 *   FILE
 *   ----
 *   nodeStoreFunctions.c
 *
 *   History
 *   -------
 *   2014-10-21   File created
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


OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_AASIdString_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_AASIdString,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_AASIdType_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_UINT  value
) {
    pobj->v_AASIdType = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_AASName_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_AASName,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_AASAssetIdString_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_STRING  value
) {
    return ov_string_setvalue(&pobj->v_AASAssetIdString,value);
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_AASAssetIdType_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_UINT  value
) {
    pobj->v_AASAssetIdType = value;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_AASCreate_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_BOOL  value
) {
	AASStatusCode result = AASSTATUSCODE_GOOD;
    pobj->v_AASCreate = value;
    if (pobj->v_AASCreate == true){
    	IdentificationType tmpAASId;
    	tmpAASId.IdSpec = pobj->v_AASIdString;
    	tmpAASId.IdType = pobj->v_AASIdType;

    	IdentificationType tmpAssetId;
    	tmpAssetId.IdSpec = pobj->v_AASAssetIdString;
    	tmpAssetId.IdType = pobj->v_AASAssetIdType;

    	result = openaas_modelmanager_createAAS(tmpAASId, pobj->v_AASName, tmpAssetId);
    }
    pobj->v_AASCreate = false;
    pobj->v_AASStatus = result;
    return OV_ERR_OK;
}

OV_DLLFNCEXPORT OV_RESULT openaas_modelmanager_AASDelete_set(
    OV_INSTPTR_openaas_modelmanager          pobj,
    const OV_BOOL  value
) {
	AASStatusCode result = AASSTATUSCODE_GOOD;
    pobj->v_AASDelete = value;
    if (pobj->v_AASDelete == true){
    	IdentificationType tmpAASId;
    	tmpAASId.IdSpec = pobj->v_AASIdString;
		tmpAASId.IdType = pobj->v_AASIdType;
    	result = openaas_modelmanager_deleteAAS(tmpAASId);
    }
    pobj->v_AASDelete = false;
    pobj->v_AASStatus = result;
    return OV_ERR_OK;
}



OV_DLLFNCEXPORT AASStatusCode openaas_modelmanager_createAAS(IdentificationType aasId, OV_STRING aasName, IdentificationType assetId) {
	OV_RESULT result = OV_ERR_OK;
	OV_INSTPTR_ov_domain ptr = NULL;
	OV_INSTPTR_openaas_aas paas = NULL;
	OV_INSTPTR_openaas_PropertyValueStatement pPropertyValueStatement = NULL;
	OV_INSTPTR_ov_object ptr2 = NULL;
	ptr2 = ov_path_getobjectpointer(openaas_modelmanager_AASConvertListGet(aasId), 2);
	if (ptr2)
		return AASSTATUSCODE_BADAASID;
	ptr = Ov_StaticPtrCast(ov_domain, Ov_SearchChild(ov_containment, &pdb->root, "TechUnits"));
	ptr = Ov_StaticPtrCast(ov_domain, Ov_SearchChild(ov_containment, ptr, "openAAS"));
	ptr = Ov_StaticPtrCast(ov_domain, Ov_SearchChild(ov_containment, ptr, "AASFolder"));
	if(ptr){
		paas = Ov_StaticPtrCast(openaas_aas, Ov_SearchChild(ov_containment, ptr, aasName));
		if (paas)
			return AASSTATUSCODE_BADAASNAME;
		result = Ov_CreateObject(openaas_aas, paas, ptr, aasName);
		if(Ov_Fail(result)){
			ov_logfile_error("Fatal: could not create AAS object - reason: %s", ov_result_getresulttext(result));
			return openaas_modelmanager_ovresultToAASStatusCode(result);
		}
		openaas_modelmanager_AASConvertListAdd(aasId, aasName);
		paas->p_Header.p_Config.v_CarrierIdString = NULL;
		ov_string_setvalue(&paas->p_Header.p_Config.v_CarrierIdString, aasId.IdSpec);
		paas->p_Header.p_Config.v_CarrierIdType = aasId.IdType;
		ov_string_setvalue(&paas->p_Header.p_Config.v_CreatingInstanceIdString, aasId.IdSpec);
		paas->p_Header.p_Config.v_CreatingInstanceIdType = aasId.IdType;
		ov_time_gettime(&paas->p_Header.p_Config.v_CreationTime);

		result = Ov_CreateObject(openaas_PropertyValueStatement, pPropertyValueStatement, Ov_StaticPtrCast(ov_domain, &paas->p_Header.p_Config), "Asset");
		if(Ov_Fail(result)){
			ov_logfile_error("Fatal: could not create AssetPVS object - reason: %s", ov_result_getresulttext(result));
			return openaas_modelmanager_ovresultToAASStatusCode(result);
		}
		pPropertyValueStatement->v_ExpressionSemantic = SETTING;
		pPropertyValueStatement->v_ExpressionLogic = EQUAL;
		pPropertyValueStatement->v_Unit = "";
		OV_STRING tmpString = NULL;
		if (assetId.IdType == URI)
			ov_string_setvalue(&tmpString, "URI:");
		else
			ov_string_setvalue(&tmpString, "ISO:");
		ov_string_append(&tmpString, assetId.IdSpec);
		OV_ANY tmpAny;
		tmpAny.value.valueunion.val_string = NULL;
		ov_string_setvalue(&tmpAny.value.valueunion.val_string, tmpString);
		tmpAny.value.vartype = OV_VT_STRING;
		Ov_SetAnyValue(&pPropertyValueStatement->v_Value, &tmpAny);
		pPropertyValueStatement->v_IDIdString = "http://openaas.org/properties/assetId";
		pPropertyValueStatement->v_IDIdType = URI;
		pPropertyValueStatement->v_View = FUNCTIONAL;
		ov_time_gettime(&pPropertyValueStatement->v_TimeStamp);
	}else{
		return AASSTATUSCODE_BADUNEXPECTEDERROR;
	}

	return AASSTATUSCODE_GOOD;
}


OV_DLLFNCEXPORT AASStatusCode openaas_modelmanager_deleteAAS(IdentificationType aasId) {
	OV_INSTPTR_ov_object ptr = NULL;
	OV_INSTPTR_openaas_aas paas = NULL;
	OV_RESULT result = OV_ERR_OK;

	ptr = ov_path_getobjectpointer(openaas_modelmanager_AASConvertListGet(aasId), 2);
	if(ptr){
		paas = Ov_StaticPtrCast(openaas_aas, ptr);
		if (paas){
			result = Ov_DeleteObject(paas);
			if(Ov_Fail(result)){
				ov_logfile_error("Fatal: could not delete AAS object - reason: %s", ov_result_getresulttext(result));
				return openaas_modelmanager_ovresultToAASStatusCode(result);
			}
			openaas_modelmanager_AASConvertListDelete(aasId);
		}else{
			return AASSTATUSCODE_BADUNEXPECTEDERROR;
		}
	}else{
		return AASSTATUSCODE_BADAASID;
	}

	return AASSTATUSCODE_GOOD;
}



