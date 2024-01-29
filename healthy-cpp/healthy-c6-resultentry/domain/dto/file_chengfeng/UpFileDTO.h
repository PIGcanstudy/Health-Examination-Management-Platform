#pragma once
#ifndef _UP_FILE_DTO_
#define _UP_FILE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * editorͼƬ��Ϣ�������ݶ���
 */
class UpFileDTO : public oatpp::DTO
{
	DTO_INIT(UpFileDTO, DTO);
	// ����
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("file_chengfeng.field.id");
	}
	// url
	DTO_FIELD(String, url);
	DTO_FIELD_INFO(url) {
		info->description = ZH_WORDS_GETTER("file_chengfeng.field.img-url");
	}

public:
	UpFileDTO() {}
	UpFileDTO(String id, String url) {
		this->id = id;
		this->url = url;
	}
	
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_UP_FILE_DTO_