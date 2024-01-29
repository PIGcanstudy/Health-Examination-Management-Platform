#pragma once
#ifndef _UP_FILE_DO_
#define _UP_FILE_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class UpFileDO
{
	// 主键
	CC_SYNTHESIZE(string, id, Id);
	// 图片src
	CC_SYNTHESIZE(string, url, Url);
	
public:
	UpFileDO() {
		id = "";
		url = "";
	}
};

#endif // !_UP_FILE_DO_
