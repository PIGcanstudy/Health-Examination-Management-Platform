#pragma once
#ifndef _UPLOADMORECONTROLLER_
#define _UPLOADMORECONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/uploadmore/UploadMoreDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ����֤�����ϴ�������
 */
class UploadMoreController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ���������ϴ��������������
	API_ACCESS_DECLARE(UploadMoreController);
	// 3 ����ӿ�
public:
	// 3.1 ���������ϴ��ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("uploadmore.post.summary"), uploadHealthCertiMore, Uint64JsonVO::Wrapper);
	// 3.2 ���������ϴ��ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/healthcertificate-manage/uploadmore", uploadHealthCertiMore, BODY_DTO(List<UploadMoreDTO::Wrapper>, dtoArray), execUploadHealthCertiMore(dtoArray));
private:
	// 3.3 �����ϴ�
	StringJsonVO::Wrapper execUploadHealthCertiMore(const List<UploadMoreDTO::Wrapper>& dtoArray);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif 