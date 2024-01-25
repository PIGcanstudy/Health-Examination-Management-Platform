#pragma once
#ifndef _HealthCertiListQuery_
#define _HealthCertiListQuery_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class HealthCertiListQuery : public PageQuery
{
	DTO_INIT(HealthCertiListQuery, PageQuery);
	// ���
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("herlthcertilist.field.id");
	}
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("herlthcertilist.field.name");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("herlthcertilist.field.sex");
	}
	// ����
	DTO_FIELD(UInt32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("herlthcertilist.field.age");
	}
	// ��ӡ״̬
	DTO_FIELD(UInt32, print_statu);
	DTO_FIELD_INFO(print_statu) {
		info->description = ZH_WORDS_GETTER("herlthcertilist.field.print_statu");
	}
	// �Ǽ�ʱ��
	DTO_FIELD(String, register_date);
	DTO_FIELD_INFO(register_date) {
		info->description = ZH_WORDS_GETTER("herlthcertilist.field.register_date");
	}
	// �ϴ�״̬
	DTO_FIELD(UInt32, upload_statu);
	DTO_FIELD_INFO(upload_statu) {
		info->description = ZH_WORDS_GETTER("herlthcertilist.field.upload_statu");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_