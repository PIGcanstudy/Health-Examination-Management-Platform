#pragma once
#ifndef _FILE_DO_
#define _FILE_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class FileDO
{
	// ����
	CC_SYNTHESIZE(string, id, Id);
	// ͼƬsrc
	CC_SYNTHESIZE(string, url, Url);
	
public:
	FileDO() {
		id = "";
		url = "";
	}
};

#endif // !_FILE_DO_
