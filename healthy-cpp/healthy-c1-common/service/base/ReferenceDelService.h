#pragma once


#ifndef _REFERENCEDELSERVICE_H_
#define _REFERENCEDELSERVICE_H_
#include <list>
#include "domain/vo/base/ReferenceDelVO.h"
//#include "domain/query/sample/SampleQuery.h"
#include "domain/dto/base/ReferenceDelDTO.h"

/**
 * ɾ������ʵ��
 */
class ReferenceDelService
{
public:
	
	// ��������
	//uint64_t saveData(const ReferenceDelDTO::Wrapper& dto);
	
	// ͨ��IDɾ������
	bool removeData(string id);
};

#endif // !_REFERENCEDELSERVICE_H_