#pragma once
#ifndef _FILE_DAO_
#define _FILE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/file/FileDO.h"
#include "../../domain/dto/file/FileDTO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class FileDAO : public BaseDAO
{
public:

	
	// �޸�����
	int update(const FileDO& uObj);
	
};
#endif // !_SAMPLE_DAO_
