#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/09/26 16:29:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _PRINTREPORTAPICLIENT_H_
#define _PRINTREPORTAPICLIENT_H_


#include "oatpp/web/client/ApiClient.hpp"
#include "ApiHelper.h"


class printReportApiClient : public oatpp::web::client::ApiClient 
{

#include OATPP_CODEGEN_BEGIN(ApiClient)
	

	API_CLIENT_INIT(printReportApiClient);

	// Í¨¹ýID²éÑ¯
	API_CALL(API_M_GET, "/query-one", queryById, API_HANDLER_AUTN_HEADER, QUERY(String, id));
	
#include OATPP_CODEGEN_END(ApiClient)
	
};

#endif // !_PRINTREPORTAPICLIENT_H_