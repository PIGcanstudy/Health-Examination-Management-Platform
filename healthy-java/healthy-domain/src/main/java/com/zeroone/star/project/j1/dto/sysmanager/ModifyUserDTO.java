package com.zeroone.star.project.j1.dto.sysmanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("修改用户信息时获取当前用户信息数据对象")
public class ModifyUserDTO {
	@ApiModelProperty(value = "登录账号", example = "test1")
	private String username;
	@ApiModelProperty(value = "用户名", example = "test1")
	private String nickName;
	@ApiModelProperty(value = "邮箱", example = "6666666@qq.com")
	private String email;
	@ApiModelProperty(value = "手机号", example = "18428385266")
	private String mobile;
	@ApiModelProperty(value = "性别", example = "男")
	private String sex;
	@ApiModelProperty(value = "所属部门id", example = "40322777781112832")
	private String departmentId;
	@ApiModelProperty(value = "用户类型", example = "普通用户")
	private String type;
	@ApiModelProperty(value = "头像", example = "/photos/photo1.jpg")
	private String avatar;
//	@ApiModelProperty(value = "角色分配", example = "检验科,眼科,电测听,内科,皮肤科,DR室,心电图")
	@ApiModelProperty(value = "角色分配")
	private List<String> roles;
	@ApiModelProperty(value = "所在地区", example = "北京市,市辖区,东城区")
	private String address;
	@ApiModelProperty(value = "街道地址", example = "故宫路翻斗花园")
	private String street;
	@ApiModelProperty(value = "签名文件")
	private String autograph;
	@ApiModelProperty(value = "生日", example = "2000/1/1")
	private String birth;
	@ApiModelProperty(value = "简介", example = "我很帅")
	private String description;
}
