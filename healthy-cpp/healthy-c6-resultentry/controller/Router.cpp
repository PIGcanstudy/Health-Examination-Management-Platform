/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 14:58:34

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
#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"
#include "unknownmodulebasicinformation/BasicInformationController.h"
#include "unknownmodulelifehistory/LifeHistoryController.h"
#include "unknownmodulepastmedicalhistory/PastMedicalHistoryController.h"
#include "unknownmoduleprofessionalhistory/ProfessionalHistoryController.h"
#include "GroupPerson/GroupPersonController.h"

#include"samplebarcodesview/SampleBarcodesBiewController.h"
#include"reportpreview/ReportPreviewController.h"
#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "uselib/ws/WSController.h"
#endif
#include "controller/interro/InterroController.h"
#include "saveRes/saveResController.h"
#include "checkitem/BaseProjectController.h"
#include "checkitem/PersonController.h"

#include "controller/interro/InterroController.h"
#include "result-entry/ClAbanProjController.h"

#include "file_chengfeng/UpFileController.h"

// 濡傛灉瀹氫箟浜嗗叧闂璖wagger鏂囨。瀹?
#ifdef CLOSE_SWAGGER_DOC
// 绠€鍖栫粦瀹氭帶鍒跺櫒瀹忓畾涔?
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// 绠€鍖栫粦瀹氭帶鍒跺櫒瀹忓畾涔?
#define ROUTER_SIMPLE_BIND(__CLASS__) \
BIND_CONTROLLER(docEndpoints, router, __CLASS__)
#endif

Router::Router(Endpoints* docEndpoints, HttpRouter* router)
{
	this->docEndpoints = docEndpoints;
	this->router = router;
}

void Router::initRouter()
{
#ifdef HTTP_SERVER_DEMO
	createSampleRouter();
#endif

	//#TIP :绯荤粺鎵╁睍璺敱瀹氫箟锛屽啓鍦ㄨ繖涓悗闈?
	//ROUTER_SIMPLE_BIND(SaveResController);
	ROUTER_SIMPLE_BIND(SaveResController);
	ROUTER_SIMPLE_BIND(GroupPersonController);
	ROUTER_SIMPLE_BIND(ClAbanProjController);
	ROUTER_SIMPLE_BIND(BasicInformationController);
	ROUTER_SIMPLE_BIND(LifeHistoryController);
	ROUTER_SIMPLE_BIND(PastMedicalHistoryController);
	ROUTER_SIMPLE_BIND(ProfessionalHistoryController);
	ROUTER_SIMPLE_BIND(InterroController);
	ROUTER_SIMPLE_BIND(SampleBarcodesViewController);//地灵殿
	ROUTER_SIMPLE_BIND(ReportPreviewController);//地灵殿
	ROUTER_SIMPLE_BIND(InterroController);
	ROUTER_SIMPLE_BIND(BaseProjectController);
	ROUTER_SIMPLE_BIND(PersonController);
	ROUTER_SIMPLE_BIND(UpFileController);

}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// 缁戝畾绀轰緥鎺у埗鍣?
	ROUTER_SIMPLE_BIND(SampleController);
	// 缁戝畾鐢ㄦ埛鎺у埗鍣?
	ROUTER_SIMPLE_BIND(UserController);
	// 缁戝畾鏂囦欢鎺у埗鍣?
	ROUTER_SIMPLE_BIND(FileController);

	// 缁戝畾WebSocket鎺у埗鍣?
	router->addController(WSContorller::createShared());
}
#endif
