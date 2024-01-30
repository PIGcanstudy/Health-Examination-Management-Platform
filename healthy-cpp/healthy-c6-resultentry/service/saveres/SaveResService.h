#pragma once
#include "../../domain/dto/saveres/SaveResDTO.h"
#include "../../../lib-common/include/SnowFlake.h"
#include "../../domain/do/saveres/saveresDO.h"
#ifndef _SAVERES_SERVICE_
#define _SAVERES_SERVICE_



/*
* 保存结果服务实现
*/
class  SaveResService {
public:
	uint64_t saveData(const SaveResDTO::Wrapper& dto, const string createId);
	uint64_t updateData(const SaveResDTO::Wrapper& dto, const string createId);
};


#endif // !_SAVERES_SERVICE_


