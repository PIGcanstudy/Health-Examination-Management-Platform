#include "stdafx.h"
#include "Controller.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/xiebao/DeleteTBPService.h"
#include "../../service/xiebao/UpdateTBPService.h"

DeleteTBPJsonVO::Wrapper XiebaoController::execDelTBP(const DeleteTBPDTO::Wrapper& dto)
{
    // ���巵�����ݶ���
    auto jvo = DeleteTBPJsonVO::createShared();
    // ����У��
    if (!dto->code)
    {
        jvo->init(UInt64(-1), RS_PARAMS_INVALID);
        return jvo;
    }
    // ����һ��Service
    DeleteTBPService service;
    // ִ������ɾ��
    if (service.DeleteTBP(dto){
        jvo->success(dto->code);
    }
    else
    {
        jvo->fail(dto->code);
    }
    // ��Ӧ���
    return jvo;
}

UpdateTBPJsonVO::Wrapper XiebaoController::execUpdateTBP(const UpdateTBPDTO::Wrapper& dto)
{
    // ���巵�����ݶ���
    auto jvo = Uint64JsonVO::createShared();
    // ����У��
    if (!dto->code)
    {
        jvo->init(UInt64(-1), RS_PARAMS_INVALID);
        return jvo;
    }
    // ����һ��Service
    UpdateTBPService service;
    // ִ�������޸�
    if (service.updateTBP(dto)) {
        jvo->success(dto->code);
    }
    else
    {
        jvo->fail(dto->code);
    }
    // ��Ӧ���
    return jvo;
}
