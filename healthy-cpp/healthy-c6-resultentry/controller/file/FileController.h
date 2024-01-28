#pragma once

#ifndef _FILECONTROLLER_H_
#define _FILECONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/file/FileVO.h"
#include "domain/dto/file/FileDTO.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class FileController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(FileController);
	// 3 ����ӿ�
public:
	
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("file.upload.summary"), modifySample, Uint64JsonVO::Wrapper);
	
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/file/upload", modifySample, BODY_DTO(FileDTO::Wrapper, dto), execModifySample(dto, authObject->getPayload()));

	
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifySample(const FileDTO::Wrapper& dto, const PayloadDTO& payload);
	
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_FILECONTROLLER_H_