#pragma once
#ifndef _FILEVO_H_
#define _FILEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/file/FileDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * editor��ӦͼƬ�ϴ��������
 */
//class FileVO : public JsonVO<FileDTO::Wrapper>
//{
//	DTO_INIT(FileVO, JsonVO<FileDTO::Wrapper>);
//};

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class FileJsonVO : public JsonVO<FileDTO::Wrapper> {
	DTO_INIT(FileJsonVO, JsonVO<FileDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_FILEVO_H_
