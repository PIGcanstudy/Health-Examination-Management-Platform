#pragma once
#ifndef _UP_FILE_DO_
#define _UP_FILE_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class UpFileDO
{
	// ����
	CC_SYNTHESIZE(string, id, Id);
	// ͼƬsrc
	CC_SYNTHESIZE(string, url, Url);
	
public:
	UpFileDO() {
		id = "";
		url = "";
	}
};

#endif // !_UP_FILE_DO_
