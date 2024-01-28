#pragma once
#ifndef _FILE_SERVICE_
#define _FILE_SERVICE_
#include <list>
#include "domain/vo/file/FileVO.h"
#include "domain/dto/file/FileDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class FileService
{
public:
	
	// 保存数据
	//uint64_t saveData(const EditorImageDTO::Wrapper& dto);
	
	// 修改数据
	bool updateData(const FileDTO::Wrapper& dto, const PayloadDTO& payload);

	// 通过ID删除数据
	//bool removeData(uint64_t id);
};

#endif // !_FILE_SERVICE_
