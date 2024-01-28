#pragma once
#ifndef _FILE_DO_
#define _FILE_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class FileDO
{
	// 主键
	CC_SYNTHESIZE(string, id, Id);
	// 图片src
	CC_SYNTHESIZE(string, url, Url);
	
public:
	FileDO() {
		id = "";
		url = "";
	}
};

#endif // !_FILE_DO_
