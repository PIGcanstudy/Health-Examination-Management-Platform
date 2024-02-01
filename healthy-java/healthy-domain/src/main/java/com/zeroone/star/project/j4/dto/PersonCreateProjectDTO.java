package com.zeroone.star.project.j4.dto;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * @author rakkaus
 * 2024年1月22日 03:01:13
 */
@Data
@ApiModel(value = "零星新增", description = "获取新增体检数据传输对象")
public class PersonCreateProjectDTO {

        @ApiModelProperty(value = "身份证号", required = true)
        private String nameID;

        @ApiModelProperty(value = "姓名", required = true)
        private String name;

        @ApiModelProperty(value = "性别", required = true)
        private String sex;

        @ApiModelProperty(value = "年龄", required = true)
        private String age;

        @ApiModelProperty(value = "体检类型", required = true)
        private String type;

        @ApiModelProperty(value = "电话",required = true)
        private String mobile;

        @ApiModelProperty(value = "单位名称",required = true)
        private String unitname;

        @ApiModelProperty(value = "危害因素")
        private String endangerfactor;

        @ApiModelProperty(value = "工种名称",required = true)
        private String jobtitle;

        @ApiModelProperty(value = "检查种类")
        private String inspectiontype;

        @ApiModelProperty(value = "分组名称")
        private String groupname;



        public PersonCreateProjectDTO() {
        }
}
