#pragma once
#ifndef _FILE_DAO_
#define _FILE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/file/FileDO.h"
#include "../../domain/dto/file/FileDTO.h"

/**
 * 示例表数据库操作实现
 */
class FileDAO : public BaseDAO
{
public:

	
	// 修改数据
	int update(const FileDO& uObj);
	
};
#endif // !_SAMPLE_DAO_
