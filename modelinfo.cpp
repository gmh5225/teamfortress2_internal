#include "pch.h"
#include "modelinfo.h"

studiohdr_t* CModelInfoClient::get_studio_model(model_t* model) noexcept
{
	return call_vfunc<studiohdr_t*>(this, 28, model);
}
