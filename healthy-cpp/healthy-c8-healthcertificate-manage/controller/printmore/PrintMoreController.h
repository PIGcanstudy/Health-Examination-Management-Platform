#pragma once
#ifndef _PrintMoreController_
#define _PrintMoreController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/printmore/PrintMoreDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class PrintMoreController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PrintMoreController);
	// 3 ����ӿ�
public:
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("printmore.put.summary"), modifyPrintMore, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/healthcertificate-manage/modify-printmore", modifyPrintMore, BODY_DTO(PrintMoreDTO::Wrapper, dto), execModifyPrintMore(dto));
private:
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyPrintMore(const PrintMoreDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_