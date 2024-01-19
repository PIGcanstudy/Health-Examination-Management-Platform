#ifndef _RESULTLISTQUERY_H_
#define _RESULTLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���Խ���б��ѯ����
 */
class resultListQuery : public PageQuery
{
	DTO_INIT(resultListQuery, PageQuery);
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("positive.result.field.name");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RESULTLISTQUERY_H_