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
	private String account;
	@ApiModelProperty(value = "用户名", example = "test1")
	private String username;
	@ApiModelProperty(value = "邮箱", example = "6666666@qq.com")
	private String email;
	@ApiModelProperty(value = "手机号", example = "18428385266")
	private String phoneNumber;
	@ApiModelProperty(value = "性别", example = "男")
	private String sex;
	@ApiModelProperty(value = "所属部门", example = "宜宾美年大健康体检中心")
	private String department;
	@ApiModelProperty(value = "用户类型", example = "普通用户")
	private String userType;
	@ApiModelProperty(value = "头像", example = "/photos/photo1.jpg")
	private String profilePhoto;
	@ApiModelProperty(value = "角色分配", example = "检验科,眼科,电测听,内科,皮肤科,DR室,心电图")
	private List<String> roles;
	@ApiModelProperty(value = "所在地区", example = "北京市,市辖区,东城区")
	private String area;
	@ApiModelProperty(value = "街道地址", example = "故宫路翻斗花园")
	private String address;
	@ApiModelProperty(value = "签名文件")
	private String signatureFile;
	@ApiModelProperty(value = "生日", example = "2000/1/1")
	private String birthday;
	@ApiModelProperty(value = "简介", example = "我很帅")
	private String briefIntroduction;
}
