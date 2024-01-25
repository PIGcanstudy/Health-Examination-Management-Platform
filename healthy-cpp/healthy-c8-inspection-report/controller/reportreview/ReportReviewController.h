#pragma once
#ifndef _ReportReviewController_
#define _ReportReviewController_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/reportreview/ReportReviewDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class ReportReviewController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ReportReviewController);
	// 3 ����ӿ�
public:
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("reportreview.put.summary"), modifyReportReview, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/inspection-report/modify-reportreview", modifyReportReview, BODY_DTO(ReportReviewDTO::Wrapper, dto), execModifyReportReview(dto));
private:
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyReportReview(const ReportReviewDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_