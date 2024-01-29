#pragma once
#ifndef _UP_FILE_SERVICE_
#define _UP_FILE_SERVICE_
#include <list>
#include "domain/dto/file_chengfeng/UpFileDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class UpFileService
{
public:
	
	
	// 修改数据
	bool updateData(const UpFileDTO::Wrapper& dto,const string download, const PayloadDTO& payload);
	

};

#endif // !_UP_FILE_SERVICE_
