#include "stdafx.h"
#include "perdelService.h"
#include "../../dao/questatistics/perdelDAO.h"

// ͨ��idɾ�������Ա
bool perdelService::removeData(const string& id)
{
	perdelDAO dao;
	return dao.deleteByPersonId(id) > 0;
}
