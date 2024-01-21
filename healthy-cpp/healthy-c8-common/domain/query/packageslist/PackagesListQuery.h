#pragma once


#ifndef _COMMON_QUERY_
#define _COMMON_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ�����Ŀ�б��ҳ��ѯ����
 */
class PackagesListQuery : public PageQuery
{
	DTO_INIT(PackagesListQuery, PageQuery);
	// �ؼ���
	DTO_FIELD(String, keywords);
	DTO_FIELD_INFO(keywords) {
		info->description = ZH_WORDS_GETTER("common.field.keywords");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif