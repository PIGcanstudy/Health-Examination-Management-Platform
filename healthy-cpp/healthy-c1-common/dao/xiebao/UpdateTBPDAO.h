#pragma once
#ifndef _UpdateTBPDTO_H_
#define _UpdateTBPDTO_H_
#include "BaseDAO.h"
#include "../../domain/do/xiebao/UpdateTBPDO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class UpdateTBPDAO : public BaseDAO
{
public:
    // ͨ��codeɾ������
    int UpdateTBP(const UpdateTBPDO& uObj);
};
#endif // !_UpdateTBPDTO_H_

