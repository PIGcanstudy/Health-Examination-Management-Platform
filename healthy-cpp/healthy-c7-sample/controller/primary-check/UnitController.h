#pragma once
#ifndef _UNITCONTROLLER_H_
#define _UNITCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include"../../domain/vo/primary-check/UnitVO.h"
#include"../../domain/query/"

#include OATPP_CODEGEN_BEGIN(ApiController)

class UnitConrtoller : public oatpp::web::server::api::ApiController
{
	//����������������
	API_ACCESS_DECLARE(UnitConrtoller);
public: //����ӿ�
	ENDPOINT(API_M_GET,"/primary-check/query-unit",queryUnit,QUERIES(QueryParams,params),api_handler_aut){}
private: //����ӿ�ִ�к���

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_UNITCONTROLLER_H_ 