#include "stdafx.h"
#include "DeleteSampleService.h"
#include "../../dao/sample/DeleteSampleDAO.h"

bool DeleteSampleService::removeData(const string& id)
{
	DeleteSampleDAO dao;
	return dao.deleteById(id) == 1;
}
