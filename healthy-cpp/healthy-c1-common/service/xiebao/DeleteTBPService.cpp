#include "DeleteTBPService.h"
#include "stdafx.h"
#include "../../dao/xiebao/DeleteTBPDAO.h"
bool DeleteTBPService::DeleteTBP(const DeleteTBPDTO::Wrapper& dto)
{
    // ��װDO����
    DeleteTBPDO data;
    data.setCode(dto->code.getValue(""));
    // ִ�������޸�
    DeleteTBPDAO dao;
    return dao.DeleteTBP(data) == 1;
}
