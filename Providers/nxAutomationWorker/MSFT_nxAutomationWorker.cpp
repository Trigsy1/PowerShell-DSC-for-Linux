/* @migen@ */
#include "MSFT_nxAutomationWorker.h"


#include "debug_tags.hpp"
#include "MI.h"
#include <common/common.h>
#include <xmlserializer/xmlserializer.h>
#include "PythonProvider.hpp"
#include <dsc_config.h>

#include <cstdlib>


typedef struct _MSFT_nxAutomationWorker_Self : public scx::PythonProvider
{
    /*ctor*/ _MSFT_nxAutomationWorker_Self ()
        : scx::PythonProvider ("nxPackage")
    {
        // empty
    }
} MSFT_nxAutomationWorker_Self;


void MI_CALL MSFT_nxAutomationWorker_Load(
    _Outptr_result_maybenull_ MSFT_nxAutomationWorker_Self** self,
    _In_opt_ MI_Module_Self* selfModule,
    _In_ MI_Context* context)
{
    SCX_BOOKEND_EX ("Load", " name=\"nxPackage\"");
    MI_UNREFERENCED_PARAMETER(selfModule);
    MI_Result res = MI_RESULT_OK;
    if (0 != self)
    {
        if (0 == *self)
        {
            *self = new MSFT_nxAutomationWorker_Self;
            if (EXIT_SUCCESS != (*self)->init ())
            {
                delete *self;
                *self = 0;
                res = MI_RESULT_FAILED;
            }
        }
    }
    else
    {
        res = MI_RESULT_FAILED;
    }
    MI_Context_PostResult(context, res);
}

void MI_CALL MSFT_nxAutomationWorker_Unload(
    _In_opt_ MSFT_nxAutomationWorker_Self* self,
    _In_ MI_Context* context)
{
    SCX_BOOKEND_EX ("Unload", " name=\"nxPackage\"");
    if (self)
    {
        delete self;
    }
    MI_Context_PostResult(context, MI_RESULT_OK);
}

void MI_CALL MSFT_nxAutomationWorker_EnumerateInstances(
    _In_opt_ MSFT_nxAutomationWorker_Self* self,
    _In_ MI_Context* context,
    _In_opt_z_ const MI_Char* nameSpace,
    _In_opt_z_ const MI_Char* className,
    _In_opt_ const MI_PropertySet* propertySet,
    _In_ MI_Boolean keysOnly,
    _In_opt_ const MI_Filter* filter)
{
    MI_UNREFERENCED_PARAMETER(self);
    MI_UNREFERENCED_PARAMETER(nameSpace);
    MI_UNREFERENCED_PARAMETER(className);
    MI_UNREFERENCED_PARAMETER(propertySet);
    MI_UNREFERENCED_PARAMETER(keysOnly);
    MI_UNREFERENCED_PARAMETER(filter);

    MI_Context_PostResult(context, MI_RESULT_NOT_SUPPORTED);
}

void MI_CALL MSFT_nxAutomationWorker_GetInstance(
    _In_opt_ MSFT_nxAutomationWorker_Self* self,
    _In_ MI_Context* context,
    _In_opt_z_ const MI_Char* nameSpace,
    _In_opt_z_ const MI_Char* className,
    _In_ const MSFT_nxAutomationWorker* instanceName,
    _In_opt_ const MI_PropertySet* propertySet)
{
    MI_UNREFERENCED_PARAMETER(self);
    MI_UNREFERENCED_PARAMETER(nameSpace);
    MI_UNREFERENCED_PARAMETER(className);
    MI_UNREFERENCED_PARAMETER(instanceName);
    MI_UNREFERENCED_PARAMETER(propertySet);

    MI_Context_PostResult(context, MI_RESULT_NOT_SUPPORTED);
}

void MI_CALL MSFT_nxAutomationWorker_CreateInstance(
    _In_opt_ MSFT_nxAutomationWorker_Self* self,
    _In_ MI_Context* context,
    _In_opt_z_ const MI_Char* nameSpace,
    _In_opt_z_ const MI_Char* className,
    _In_ const MSFT_nxAutomationWorker* newInstance)
{
    MI_UNREFERENCED_PARAMETER(self);
    MI_UNREFERENCED_PARAMETER(nameSpace);
    MI_UNREFERENCED_PARAMETER(className);
    MI_UNREFERENCED_PARAMETER(newInstance);

    MI_Context_PostResult(context, MI_RESULT_NOT_SUPPORTED);
}

void MI_CALL MSFT_nxAutomationWorker_ModifyInstance(
    _In_opt_ MSFT_nxAutomationWorker_Self* self,
    _In_ MI_Context* context,
    _In_opt_z_ const MI_Char* nameSpace,
    _In_opt_z_ const MI_Char* className,
    _In_ const MSFT_nxAutomationWorker* modifiedInstance,
    _In_opt_ const MI_PropertySet* propertySet)
{
    MI_UNREFERENCED_PARAMETER(self);
    MI_UNREFERENCED_PARAMETER(nameSpace);
    MI_UNREFERENCED_PARAMETER(className);
    MI_UNREFERENCED_PARAMETER(modifiedInstance);
    MI_UNREFERENCED_PARAMETER(propertySet);

    MI_Context_PostResult(context, MI_RESULT_NOT_SUPPORTED);
}

void MI_CALL MSFT_nxAutomationWorker_DeleteInstance(
    _In_opt_ MSFT_nxAutomationWorker_Self* self,
    _In_ MI_Context* context,
    _In_opt_z_ const MI_Char* nameSpace,
    _In_opt_z_ const MI_Char* className,
    _In_ const MSFT_nxAutomationWorker* instanceName)
{
    MI_UNREFERENCED_PARAMETER(self);
    MI_UNREFERENCED_PARAMETER(nameSpace);
    MI_UNREFERENCED_PARAMETER(className);
    MI_UNREFERENCED_PARAMETER(instanceName);

    MI_Context_PostResult(context, MI_RESULT_NOT_SUPPORTED);
}

void MI_CALL MSFT_nxAutomationWorker_Invoke_GetTargetResource(
    _In_opt_ MSFT_nxAutomationWorker_Self* self,
    _In_ MI_Context* context,
    _In_opt_z_ const MI_Char* nameSpace,
    _In_opt_z_ const MI_Char* className,
    _In_opt_z_ const MI_Char* methodName,
    _In_ const MSFT_nxAutomationWorker* instanceName,
    _In_opt_ const MSFT_nxAutomationWorker_GetTargetResource* in)
{
    SCX_BOOKEND_EX ("Get", " name=\"nxPackage\"");
    MI_Result result = MI_RESULT_FAILED;
    if (self)
    {
        MI_Instance* retInstance;
        MI_Instance_Clone (&in->InputResource.value->__instance, &retInstance);
        result = self->get (in->InputResource.value->__instance, context,
                            retInstance);
        if (MI_RESULT_OK == result)
        {
            SCX_BOOKEND_PRINT ("packing succeeded!");
            MSFT_nxAutomationWorker_GetTargetResource out;
            MSFT_nxAutomationWorker_GetTargetResource_Construct (&out, context);
            MSFT_nxAutomationWorker_GetTargetResource_Set_MIReturn (&out, 0);
            MI_Value value;
            value.instance = retInstance;
            MI_Instance_SetElement (&out.__instance, "OutputResource", &value,
                                    MI_INSTANCE, 0);
            result = MSFT_nxAutomationWorker_GetTargetResource_Post (&out, context);
            if (MI_RESULT_OK != result)
            {
                SCX_BOOKEND_PRINT ("post Failed");
            }
            MSFT_nxAutomationWorker_GetTargetResource_Destruct (&out);
        }
        else
        {
            SCX_BOOKEND_PRINT ("get FAILED");
        }
        MI_Instance_Delete (retInstance);
    }
    MI_Context_PostResult (context, result);
}

void MI_CALL MSFT_nxAutomationWorker_Invoke_InventoryTargetResource(
    _In_opt_ MSFT_nxAutomationWorker_Self* self,
    _In_ MI_Context* context,
    _In_opt_z_ const MI_Char* nameSpace,
    _In_opt_z_ const MI_Char* className,
    _In_opt_z_ const MI_Char* methodName,
    _In_ const MSFT_nxAutomationWorker* instanceName,
    _In_opt_ const MSFT_nxAutomationWorker_InventoryTargetResource* in)
{
    SCX_BOOKEND_EX ("Inventory", " name=\"nxPackage\"");
    MI_Result result = MI_RESULT_FAILED;
    if (self)
    {
        MI_Instance* retInstance;
	MI_NewDynamicInstance (
	    context, className,
	    0, &retInstance);

        result = self->inventory (in->InputResource.value->__instance, context,
                            retInstance);
        if (MI_RESULT_OK == result)
        {
            SCX_BOOKEND_PRINT ("packing succeeded!");
            MSFT_nxAutomationWorker_InventoryTargetResource out;
            MSFT_nxAutomationWorker_InventoryTargetResource_Construct (&out, context);
            MSFT_nxAutomationWorker_InventoryTargetResource_Set_MIReturn (&out, 0);


 {
		const MI_Uint32 c_initBufferLength = 1000000;
		MI_Application application;
		MI_Serializer serializer;
		MI_Uint8 *clientBuffer;
		MI_Uint32 clientBufferLength = c_initBufferLength;
		MI_Uint32 clientBufferNeeded = 0;
		const char * reportTemplateBase = DSC_ETC_PATH "/InventoryReports/nxPackage_XXXXXX";

		FILE *fp = NULL;
		
		clientBuffer = (MI_Uint8*)malloc(clientBufferLength + 1);
		MI_Application_Initialize(0,NULL,NULL, &application);
		result = XmlSerializer_Create(&application, 0, "MI_XML", &serializer);
		if (result != MI_RESULT_OK)
		{
		    MI_Application_Close(&application);
		    MI_Context_PostResult (context, result);
		    return;
		}
		
		result = XmlSerializer_SerializeInstance( &serializer, 0, retInstance, clientBuffer, clientBufferLength, &clientBufferNeeded);
		if (result != MI_RESULT_OK)
		{
		    free(clientBuffer);
		    if (clientBufferNeeded > 0)
		    {
			// Try again with a buffer given to us by the clientBufferNeeded field
			clientBufferLength = clientBufferNeeded;
			clientBuffer = (MI_Uint8*)malloc(clientBufferLength + 1);
			result = XmlSerializer_SerializeInstance( &serializer, 0, retInstance, clientBuffer, clientBufferLength, &clientBufferNeeded);
		    }
		    else
		    {
			XmlSerializer_Close(&serializer);
			MI_Application_Close(&application);
			MI_Context_PostResult (context, result);
			return;
		    }
		}
		
		XmlSerializer_Close(&serializer);
		MI_Application_Close(&application);
		if (result == MI_RESULT_OK)
		{
		    clientBuffer[clientBufferNeeded] = '\0';
		    printf((char*)clientBuffer);
		}

		
		{
		    char * reportTemplate = (char*)malloc(strlen(reportTemplateBase));
		    strcpy(reportTemplate, reportTemplateBase);
		    int fd = mkstemp(reportTemplate);
		    if (fd == -1)
		    {
			std::cerr << std::endl << "Error running mkstemp, errno = " << errno << std::endl;
		    }
		    fp = fdopen(fd, "w");
		    if( fp != NULL )
		    {
			fwrite(clientBuffer, 1, clientBufferNeeded, fp);
			fclose(fp);
		    }
		    else
		    {
			std::cerr << std::endl << "Error opening file descriptor for reportTemplate, errno = " << errno << std::endl;
		    }
		    free(reportTemplate);
		}
		
		free(clientBuffer);
	    }

            result = MSFT_nxAutomationWorker_InventoryTargetResource_Post (&out, context);
            if (MI_RESULT_OK != result)
            {
                SCX_BOOKEND_PRINT ("post Failed");
            }
            MSFT_nxAutomationWorker_InventoryTargetResource_Destruct (&out);
        }
        else
        {
            SCX_BOOKEND_PRINT ("inventory FAILED");
        }
        MI_Instance_Delete (retInstance);
    }
    MI_Context_PostResult (context, result);
}

void MI_CALL MSFT_nxAutomationWorker_Invoke_TestTargetResource(
    _In_opt_ MSFT_nxAutomationWorker_Self* self,
    _In_ MI_Context* context,
    _In_opt_z_ const MI_Char* nameSpace,
    _In_opt_z_ const MI_Char* className,
    _In_opt_z_ const MI_Char* methodName,
    _In_ const MSFT_nxAutomationWorker* instanceName,
    _In_opt_ const MSFT_nxAutomationWorker_TestTargetResource* in)
{
    MI_Result result = MI_RESULT_FAILED;
    if (self)
    {
        MI_Boolean testResult = MI_FALSE;
        result = self->test (in->InputResource.value->__instance, &testResult);
        if (MI_RESULT_OK == result)
        {
            MSFT_nxAutomationWorker_TestTargetResource out;
            MSFT_nxAutomationWorker_TestTargetResource_Construct (&out, context);
            MSFT_nxAutomationWorker_TestTargetResource_Set_Result (
                &out, testResult);
            MSFT_nxAutomationWorker_TestTargetResource_Set_MIReturn (&out, 0);
            MSFT_nxAutomationWorker_TestTargetResource_Post (&out, context);
            MSFT_nxAutomationWorker_TestTargetResource_Destruct (&out);
        }
    }
    MI_Context_PostResult (context, result);
}

void MI_CALL MSFT_nxAutomationWorker_Invoke_SetTargetResource(
    _In_opt_ MSFT_nxAutomationWorker_Self* self,
    _In_ MI_Context* context,
    _In_opt_z_ const MI_Char* nameSpace,
    _In_opt_z_ const MI_Char* className,
    _In_opt_z_ const MI_Char* methodName,
    _In_ const MSFT_nxAutomationWorker* instanceName,
    _In_opt_ const MSFT_nxAutomationWorker_SetTargetResource* in)
{
    MI_Result result = MI_RESULT_FAILED;
    if (self)
    {
        MI_Result setResult = MI_RESULT_FAILED;
        result = self->set (in->InputResource.value->__instance, &setResult);
        if (MI_RESULT_OK == result)
        {
            result = setResult;
            MSFT_nxAutomationWorker_SetTargetResource out;
            MSFT_nxAutomationWorker_SetTargetResource_Construct (&out, context);
            MSFT_nxAutomationWorker_SetTargetResource_Set_MIReturn (
                &out, setResult);
            MSFT_nxAutomationWorker_SetTargetResource_Post (&out, context);
            MSFT_nxAutomationWorker_SetTargetResource_Destruct (&out);
        }
    }
    MI_Context_PostResult (context, result);
}
