#pragma once
#ifndef _DeleteTBPDTO_H_
#define _DeleteTBPDTO_H_
#include"../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ��ʾ���˵���ʾJsonVO����������Ӧ��ǰ��
 */
class DeleteTBPDTO : public oatpp::DTO,public TreeNode
{
    DTO_INIT(DeleteTBPDTO, DTO);

    // ��Ŀ����
    API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("code"));
    // �Ƿ���ɾ��
    API_DTO_FIELD_DEFAULT(int, del_flag, ZH_WORDS_GETTER("del_flag"));
public:
    void addChild(shared_ptr<TreeNode> child) override
    {
        children->push_back(Wrapper(dynamic_pointer_cast<DeleteTBPDTO>(child), Wrapper::Class::getType()));
    }
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_DeleteTBPDTO_H_
