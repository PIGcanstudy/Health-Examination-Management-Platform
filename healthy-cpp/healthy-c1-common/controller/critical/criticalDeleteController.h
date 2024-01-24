#pragma once
#ifndef _CRITICALDELETECONTROLLER_H_
#define _CRITICALDELETECONTROLLER_H_


#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/critical/CriticalDeleteVO.h"
#include "../../domain/query/critical/CriticalQuery.h"



#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class CriticalDeleteController : public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(CriticalDeleteController);
public:

	// ����Σ��ֵ�б��ѯ�ӿ�����
	ENDPOINT_INFO(deleteCritical) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("crtical.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("critical.field.id"), 1, true);
	}
	//����Σ��ֵɾ���б�ӿ�
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/critical/query-delete-critical", deleteCritical, PATH(UInt64, id), execDeleteCritical(id));
	
private:
	//����ӿ�ִ�к���
	CriticalDeleteListJsonVO::Wrapper execDeleteCritical(const UInt64& id);
};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _USERCONTROLLER_H_
