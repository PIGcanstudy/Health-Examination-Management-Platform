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

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "uselib/ws/WSController.h"
#endif
#include "Exalanding/PeopleListController.h"
#include"registration/ModifyInformationController.h"
#include"questatistics/perdelController.h"
#include"Exalanding/GroupOrderListController.h"
#include"Exalanding/SaveInfoController.h"
#include "GetPD/GetPDController.h"
#include "Pic/PicController.h"
#include "Exalanding/TicketGroupNameListController.h"
#include "Exalanding/GroupPersonController.h"
#include "Exalanding/FileController.h"
#include "add/AddController.h"
#include "Exalanding/CheckListController.h"


// ��������˹ر�Swagger�ĵ���
#ifdef CLOSE_SWAGGER_DOC
// �򻯰󶨿������궨��
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// �򻯰󶨿������궨��
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

	//#TIP :ϵͳ��չ·�ɶ��壬д���������
	ROUTER_SIMPLE_BIND(PeopleListController);
	ROUTER_SIMPLE_BIND(ModifyInformationController);
	ROUTER_SIMPLE_BIND(perdelController);
	ROUTER_SIMPLE_BIND(GroupOrderListController);
	ROUTER_SIMPLE_BIND(SaveInfoController);
	ROUTER_SIMPLE_BIND(GetPDController);
	// ���ļ�������
	ROUTER_SIMPLE_BIND(PicController);
	ROUTER_SIMPLE_BIND(TicketGroupNameListController);
	ROUTER_SIMPLE_BIND(GroupPersonController);
	ROUTER_SIMPLE_BIND(FileController);
	ROUTER_SIMPLE_BIND(AddController);
	ROUTER_SIMPLE_BIND(CheckListController);

}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// ��ʾ��������
	ROUTER_SIMPLE_BIND(SampleController);
	// ���û�������
	ROUTER_SIMPLE_BIND(UserController);
	// ���ļ�������
	ROUTER_SIMPLE_BIND(FileController);
	
	// ��WebSocket������
	router->addController(WSContorller::createShared());
}
#endif